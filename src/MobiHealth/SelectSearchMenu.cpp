#include "SelectSearchMenu.h"
#include "buttonlabel.h"
#include "PatientSearchForm.h"
#include "PatientSearchResultForm.h"
#include "CreditsFooterWidget.h"
#include "soapMobiBindingProxy.h"
#include "MobiState.h"
#include "MobiError.h"
#include "ErrorForm.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPalette>
#include <QPixmap>

//QuickMarkMessenger
#include <apgcli.h>
#include <EikDll.h>
#include <apacmdln.h>
#include <eikenv.h>  
#include <apgtask.h>
#include <utf.h>    //convert UTF8 to unicode

SelectSearchMenu::SelectSearchMenu(QWidget *parent)
    : QWidget(parent)
{
	/* add the widget to the window server observer list */
	CEikonEnv::Static()->AddMessageObserverL(*this);
	
	ui.setupUi(this);
	
	this->setContentsMargins(0,0,0,0);
	
	/* set the background image */
	this->setBackgroundImage();
	
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	//logoutButton = new ButtonLabel(QPixmap(":/icons/logoutButton.png"), QPixmap(":/icons/logoutButtonPushed.png"), this);
	qrCodeButton = new QPushButton("QRCode");
	searchButton = new QPushButton("Cerca");
	
	label = new QLabel("TEST", this);
	
	connect(qrCodeButton, SIGNAL(clicked()), this, SLOT(qrCodeButtonSlot()));
	connect(searchButton, SIGNAL(clicked()), this, SLOT(searchButtonSlot()));
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	
	/* layout operation */
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	headerLayout->addStretch();
	//headerLayout->addWidget(logoutButton);
	//headerLayout->addStretch(1);
	headerLayout->addWidget(quitButton);
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	mainLayout->addLayout(headerLayout);
	mainLayout->addStretch();
	mainLayout->addWidget(qrCodeButton);
	mainLayout->addSpacing(5);
	mainLayout->addWidget(searchButton);
	mainLayout->addSpacing(5);
	mainLayout->addWidget(label);
	mainLayout->addStretch();
	mainLayout->setAlignment(Qt::AlignTop);
	
	/* add credits footer */
	creditsFooter = new CreditsFooterWidget();
	creditsFooter->setMinimumHeight(43);
	creditsFooter->setMaximumHeight(43);
	creditsFooter->setBackgroundImage();
	mainLayout->addWidget(creditsFooter);
	
	setLayout(mainLayout);
	
	/* when user change/select patient, close this widget */
	connect(MobiState::getInstance(), SIGNAL(changeCurrentPatientSignal()), this, SLOT(close()));
	
	/* initialize the loading image */
	loadingImage = new QLabel(this);
	loadingImage->setPixmap(QPixmap(":/icons/loadingBg.png"));
	loadingImage->setFixedSize(360, 640);
	loadingImage->setVisible(false);
}

void SelectSearchMenu::qrCodeButtonSlot()
{
	/* start qrcode decode external application */
	StartQRDecoder();
}

void SelectSearchMenu::searchButtonSlot()
{
	/* show the patient search form */
	PatientSearchForm *patientSearchForm = new PatientSearchForm();
	patientSearchForm->setAttribute(Qt::WA_DeleteOnClose, true);
	patientSearchForm->showFullScreen();
}

void SelectSearchMenu::setBackgroundImage()
{
	QPalette p = palette();
	QPixmap pixmap(":/icons/background.png"); 
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}

void SelectSearchMenu::StartQRDecoder()

{
	// QuickMark constants UID
	const TInt KQuickmarkUid = 0x20004FFE;
	TUid id( TUid::Uid( KQuickmarkUid ) ); // qrcode reader uid
	
	TUid msgapid(TUid::Uid( 0xEAF4030A )); // application qrcode

	/* get the tasks list and search the qrcode reader */
	TApaTaskList taskList( CEikonEnv::Static()->WsSession() );
	TApaTask task = taskList.FindApp( id );

	/* check if qrcode application is already running, if so bring it to foreground */
	if ( task.Exists() )
	{
		_LIT8(params,"");
		task.SendMessage( msgapid, params);
	    task.BringToForeground();
	}
	else
	{
		/* if the task doesn't exists, create it, passing application uid to wait for callback */

		HBufC* param = HBufC::NewLC( 256 );
		param->Des().AppendNum(msgapid.iUid);

		RApaLsSession appArcSession;
		User::LeaveIfError(appArcSession.Connect()); // connect to AppArc server
		TThreadId idt;
		appArcSession.StartDocument( *param, TUid::Uid( KQuickmarkUid ), idt );
		appArcSession.Close();
		CleanupStack::PopAndDestroy(); // param
	}
}

MCoeMessageObserver::TMessageResponse SelectSearchMenu::HandleMessageL(TUint32 aClientHandleOfTargetWindowGroup, TUid aMessageUid, const TDesC8 &aMessageParameters)
{
	/* show the loading picture */
	loadingImage->setVisible(true);
	
	TBuf<1024> iQuickMarkResult;  
	iQuickMarkResult.Zero();

	//convert UTF8 to UCS2
	//The result from quickmark is encoded using UTF8.
	CnvUtfConverter::ConvertToUnicodeFromUtf8(iQuickMarkResult,aMessageParameters);
	//iEikonEnv->InfoWinL( _L("Result"), iQuickMarkResult);
	
	QString patientCode((QChar*)iQuickMarkResult.Ptr(),iQuickMarkResult.Length());
	label->setText(patientCode);
	
	/* search the patient using his decoded patient id */
	/* invoke the web method to search patients */
	MobiBinding server;
	ns1__searchPatientResponse responce;
		
	int err = server.ns1__searchPatient("", "", "", patientCode.toLocal8Bit().data(), responce);
	if(err == SOAP_OK)
	{
		SimplePatientArray *simplePatientArray = responce.searchPatientReturn;
		ns1__SimplePatient **patientArray = simplePatientArray->__ptr;
		int arraySize = simplePatientArray->__size;
	
		/* initialize the field resultsForm creating the PatientSearchResultsForm, passing che SimplePatient array returned */
		PatientSearchResultForm *resultsForm = new PatientSearchResultForm(patientArray, arraySize, this);
		resultsForm->setAttribute(Qt::WA_DeleteOnClose, true);
		resultsForm->showFullScreen();
	}
	else // web service error!
	{
		ErrorForm *error = new ErrorForm(err);
		error->setAttribute(Qt::WA_DeleteOnClose, true);
		error->showFullScreen();
	}
	
	/* hide the loading picture */
	loadingImage->setVisible(false);
	
	return MCoeMessageObserver::EMessageHandled;
}

SelectSearchMenu::~SelectSearchMenu()
{
	/* remove the widget from the window server observer list */
	CEikonEnv::Static()->RemoveMessageObserver(*this);
}

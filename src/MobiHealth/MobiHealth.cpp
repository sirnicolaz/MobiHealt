/****************************************************************************
**
** Trolltech hereby grants a license to use the Qt/Eclipse Integration
** plug-in (the software contained herein), in binary form, solely for the
** purpose of creating code to be used with Trolltech's Qt software.
**
** Qt Designer is licensed under the terms of the GNU General Public
** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
** right to use certain no GPL licensed software under the terms of its GPL
** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
**
** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** Since we now have the GPL exception I think that the "special exception
** is no longer needed. The license text proposed above (other than the
** special exception portion of it) is the BSD license and we have added
** the BSD license as a permissible license under the exception.
**
****************************************************************************/

#include "MobiHealth.h"
#include <QPalette>
#include <QPixmap>
#include <QLabel>
#include <QDesktopWidget>
#include <QPushButton>
#include <QSpacerItem>
#include <QRect>
#include <QSize>
#include <QHBoxLayout>
#include "buttonlabel.h"
#include <QLineEdit>
#include "creditswidget.h"
#include "MainMenuForm.h"
#include "CreditsFooterWidget.h"
#include "MobiError.h"

MobiHealth::MobiHealth(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	/* set the image background */
	this->setBackgroundImage();
	
	/* set the style sheet for rounded label */
	this->setStyleSheet("QLineEdit { font-family: helvetica; color: red; background-color: white; border: 1px solid gray; border-radius: 8px;}");
	this->setContentsMargins(0,0,0,0);
	
	/* create the GUI objects */
	personLogo = new QLabel(this);
	quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	loginButton = new ButtonLabel(QPixmap(":/icons/loginButton.png"), QPixmap(":/icons/loginButtonPushed.png"), this);
	creditsFooter = new CreditsFooterWidget(this);
	creditsFooter->setMinimumHeight(43);
	creditsFooter->setMaximumHeight(43);
	creditsFooter->setBackgroundImage();
	mobiLogo = new QLabel(this);
	userName = new QLineEdit("username", this);
	password = new QLineEdit("password", this);
	userName->setFixedWidth(300);
	password->setFixedWidth(300);

	/* connect buttons to their slots */
	connect(quitButton, SIGNAL(released()), QApplication::instance(), SLOT(quit()));
	connect(loginButton, SIGNAL(released()), this, SLOT(loginSlot()));
		
	/* set the icons */
	personLogo->setPixmap(QPixmap(":/icons/userIcon.png"));
	mobiLogo->setPixmap(QPixmap(":/icons/logomobi.png"));
	
	/* layout operations */
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 13, 13, 0);
	QVBoxLayout *centerLayout = new QVBoxLayout();
	centerLayout->setContentsMargins(0,0,0,0);
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	
	
	headerLayout->addWidget(personLogo);
	headerLayout->addStretch();
	headerLayout->addWidget(quitButton);
	
	
	mainLayout->setAlignment(Qt::AlignTop);

	/* add mobi logo, username and password textbox and login button to center layout */
	centerLayout->addWidget(mobiLogo);
	centerLayout->setAlignment(mobiLogo, Qt::AlignHCenter);
	//centerLayout->addStretch(5);
	centerLayout->addSpacing(20);
	centerLayout->addWidget(userName);
	centerLayout->setAlignment(userName, Qt::AlignHCenter);
	centerLayout->addSpacing(9);
	centerLayout->addWidget(password);
	centerLayout->setAlignment(password, Qt::AlignHCenter);
	centerLayout->addSpacing(20);
	centerLayout->addWidget(loginButton);
	centerLayout->setAlignment(loginButton, Qt::AlignHCenter);
	
	/* add layout to main layout */
	mainLayout->addLayout(headerLayout);
	mainLayout->addStretch(2);
	mainLayout->addLayout(centerLayout);
	mainLayout->addStretch(1);
	mainLayout->addWidget(creditsFooter);
	
	setLayout(mainLayout);
}

void MobiHealth::setBackgroundImage()
{
	QPalette p = palette();
	QPixmap pixmap(":/icons/loginBg.png");
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}

/* login button slot */
void MobiHealth::loginSlot()
{
	/* get username and password from form */
	QString userNameString = userName->text();
	QString passwordString = password->text();
	
	/* fake login operations */
	if (userNameString == "Admin" and passwordString == "Admin")
	{
		/* login done, show main menu */
		mainMenuForm = new MainMenuForm(this);
		mainMenuForm->setAttribute(Qt::WA_DeleteOnClose, true);
		mainMenuForm->showFullScreen();
	}
	else
	{
		/* login error */
		MobiError *errorForm = new MobiError(this);
		errorForm->setAttribute(Qt::WA_DeleteOnClose, true);
		errorForm->showFullScreen();
	}
}

void MobiHealth::resetText()
{
	userName->setText("username");
	password->setText("password");
}

MobiHealth::~MobiHealth()
{

}

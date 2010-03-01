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

#include "ActionsMenu.h"

#include "DescriptorHandler.h"
#include "DescriptorElements.h"
#include "Action.h"
#include <QPushButton>
#include <vector>

using namespace std;

ActionsMenu::ActionsMenu(vector<QString> actionDescriptorFileNames, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	mainLayout = new QVBoxLayout();
	mainLayout->setAlignment(Qt::AlignCenter);
	descriptors = actionDescriptorFileNames;
	
	for(int i=0; i<actionDescriptorFileNames.size(); i++){
		QString currentFileName = actionDescriptorFileNames[i];
		DescriptorHandler * actionDescriptor = new DescriptorHandler(currentFileName);
		menuButtons.push_back(new QPushButtonWithID(actionDescriptor->getActionTitle(), i, this));
		mainLayout->addWidget(menuButtons[i]);
		
		//A tricky tricky tricky way to identify the button that sends the signal:
			//When the button is clicked, the signal is sent to a method defined for the derived class QPushButtonWithID
			//The slot clickWithID sends a signal to clickedWithID specifying its ID
			//The ActionsMenu takes the signal with the slot showAction where, now, there is the ID of the
			//action it has to show. Fiuu.
		connect(menuButtons[i], SIGNAL(clicked()), menuButtons[i], SLOT(clickWithID()));
		connect(menuButtons[i], SIGNAL(clickedWithID(int)), this, SLOT(showAction(int)));
	}
	
	setLayout(mainLayout);
}

/* show action1 slot implementation */
void ActionsMenu::showAction(int who)
{
	/* create action1 widget as a main widget (aka without a parent) to have fullscreen widget (todo) */
	/* --> ATTENTION: needs explicit deallocation (deleteOnClose)!!! <-- */
	DescriptorHandler * actionDescriptor = new DescriptorHandler(descriptors[who]); 
	testAction = new Action(actionDescriptor,this);
	testAction->showMaximized(); /* works only with main widget */
	
}

ActionsMenu::~ActionsMenu()
{

}


QPushButtonWithID::QPushButtonWithID(QString title, int ID, QWidget * parent) :
		QPushButton(title,parent){
	this->ID = ID;
}

void QPushButtonWithID::clickWithID(){
	emit clickedWithID(this->ID);
}



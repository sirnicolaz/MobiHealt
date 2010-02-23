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

ActionsMenu::ActionsMenu(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	mainLayout = new QVBoxLayout();
	mainLayout->setAlignment(Qt::AlignCenter);
	
	menuButtons.push_back(new QPushButton("Action 1", this));
	menuButtons.push_back(new QPushButton("Action 2", this));
	menuButtons.push_back(new QPushButton("Action 3", this));
	mainLayout->addWidget(menuButtons[0]);
	mainLayout->addWidget(menuButtons[1]);
	mainLayout->addWidget(menuButtons[2]);
	
	connect(menuButtons[0], SIGNAL(clicked()), this, SLOT(showAction()));
	connect(menuButtons[1], SIGNAL(clicked()), this, SLOT(showAction()));
	connect(menuButtons[2], SIGNAL(clicked()), this, SLOT(showAction()));
	
	setLayout(mainLayout);
}

/* show action1 slot implementation */
void ActionsMenu::showAction()
{
	/* create action1 widget as a main widget (aka without a parent) to have fullscreen widget (todo) */
	/* --> ATTENTION: needs explicit deallocation (deleteOnClose)!!! <-- */
	DescriptorHandler * actionDescriptor = new DescriptorHandler("action-descriptor.xml"); 
	testAction = new Action(actionDescriptor,this);
	testAction->showMaximized(); /* works only with main widget */
}

ActionsMenu::~ActionsMenu()
{

}

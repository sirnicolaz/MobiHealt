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

#include "ActionHandler.h"

#include "descriptorhandler.h"
#include "descriptorelements.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>
#include "GenericStep.h"

using namespace std;

ActionHandler::ActionHandler(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->setAlignment(Qt::AlignCenter);
		
	vector<StepGenericElement*> elementsTest;
	DescriptorHandler * descrTest = new DescriptorHandler("action-descriptor.xml");
	elementsTest.push_back(descrTest->getStepChild(1,0));
	elementsTest.push_back(descrTest->getStepChild(1,1));
	
	GenericStep * genericStepTest = new GenericStep(true,elementsTest,this);
	
	QWidget * testStep = genericStepTest;
	
	
	//button1 = new QPushButton("Action1", this);
	//button2 = new QPushButton("Action2", this);
	//button3 = new QPushButton("Action3", this);
	//mainLayout->addWidget(button1);
	//mainLayout->addWidget(button2);
	//mainLayout->addWidget(button3);
		
	mainLayout->addWidget(testStep);
	testStep->show();
	
	setLayout(mainLayout);
}


ActionHandler::~ActionHandler()
{

}

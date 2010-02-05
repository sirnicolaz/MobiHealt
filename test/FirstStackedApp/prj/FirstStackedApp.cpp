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

#include "FirstStackedApp.h"
#include "action1Widget.h"

#include <QPushButton>
#include <QVBoxLayout>



/* main widget constructor implementation */
FirstStackedApp::FirstStackedApp(QWidget *parent)
    : QWidget(parent)
{
	/* GUI initialization (only for QtDesigner) */
	ui.setupUi(this);
	
	/* start GUI adds */
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->setAlignment(Qt::AlignCenter);
	
	/* populate the action buttons list */
	/*
	 * for each action in xml config file, create a button 
	 * and connect it to the correct slot (how?), and add the buttons to main layout
	 * 
	 * */
	button1 = new QPushButton("Action1", this);
	button2 = new QPushButton("Action2", this);
	button3 = new QPushButton("Action3", this);
	mainLayout->addWidget(button1);
	mainLayout->addWidget(button2);
	mainLayout->addWidget(button3);
	
	connect(button1, SIGNAL(clicked()), this, SLOT(showAction1()));
	/* one connection for each button (aka for each action in the xml config file) */
	
	setLayout(mainLayout);

}

/* show action1 slot implementation */
void FirstStackedApp::showAction1()
{
	/* create action1 widget as a main widget (aka without a parent) to have fullscreen widget (todo) */
	/* --> ATTENTION: needs explicit deallocation (deleteOnClose)!!! <-- */
	action1 = new Action1Widget();
	action1->showMaximized(); /* works only with main widget */
}

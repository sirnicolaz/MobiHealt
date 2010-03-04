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

#include "ProvaFirst.h"
#include "mainmenuform.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPalette>
#include <QDesktopWidget>


ProvaFirst::ProvaFirst(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	// this->SetBackgroundImage();
	
loginButton = new QPushButton("Login", this);
connect(loginButton, SIGNAL(clicked()),
                      this, SLOT(loginSlot()));

userLabel = new QLabel("Username", this);
passwordLabel = new QLabel("Password", this);
userText = new QLineEdit(this);
passwordText = new QLineEdit(this);

QGridLayout *princLayout = new QGridLayout;
princLayout->addWidget(userLabel, 0, 0, Qt::AlignCenter);
princLayout->addWidget(userText, 1, 0, Qt::AlignCenter);
princLayout->addWidget(passwordLabel, 2, 0, Qt::AlignCenter);
princLayout->addWidget(passwordText, 3, 0, Qt::AlignCenter);
princLayout->addWidget(loginButton, 4, 0, Qt::AlignCenter);
setLayout(princLayout);
}

void ProvaFirst::SetBackgroundImage()
{
	//Using QPalette you can set background image as follows.
	 QPalette p = palette();
	 
	 //Load image to QPixmap, Give full path of image
	QPixmap pixmap1("c://01.JPG"); //For emulator C: is ..\epoc32\winscw\c so image must be at that location
	
	//resize image if it is larger than screen size.
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect rect = desktopWidget->availableGeometry();
	
	QSize size(rect.width() , rect.height());
	//resize as per your reqirement..
	QPixmap pixmap(pixmap1.scaled(size));
	
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}


ProvaFirst::~ProvaFirst()
{

}

void ProvaFirst::creditsSlot(){
}

void ProvaFirst::loginSlot(){
	
	mainMenu = new MainMenuForm();
	mainMenu->showFullScreen();
}

#ifndef IMAGESFORM_H
#define IMAGESFORM_H

#include <QtGui/QWidget>
#include "ui_ImagesForm.h"

class ButtonLabel;
class QLabel;
class ChangePatientFooter;
class QString;
class ImageWidget;
class NoteWidget;
class PatientMenuForm;

class ImagesForm : public QWidget
{
    Q_OBJECT

public:
    ImagesForm(QWidget *parent = 0);
    ~ImagesForm();

private:
    Ui::ImagesFormClass ui;
    
    /* reference to the parent widget */
    PatientMenuForm *parent;
    
    /* reference to the GUI objects */
    ButtonLabel *backButton;
    ButtonLabel *quitButton;
    QLabel *patientIcon;
        
    /* reference to the footer objects */
    ChangePatientFooter *footer;
    
    /* references to the sub-form */
    NoteWidget *noteForm;
    ImageWidget *imageForm;
    
    void setBackgroundImage();
    
private slots:
	void backButtonSlot();
    
};

#endif // IMAGESFORM_H

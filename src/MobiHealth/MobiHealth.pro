TEMPLATE = app
TARGET = MobiHealth
QT += core \
    gui \
    xml \
    xmlpatterns
HEADERS += MobiError.h \
    soapH.h \
    soapMobiBindingProxy.h \
    soapProxy.h \
    soapStub.h \
    SelectSearchMenu.h \
    ImageReader.h \
    CameraWidget.h \
    CameraObserver.h \
    ViewFinder.h \
    ScrollFrame.h \
    Patient.h \
    MobiState.h \
    TextBoxWidget.h \
    CreditsFooterWidget.h \
    ErrorForm.h \
    stdsoap2.h \
    ActionItemWidget.h \
    GenericStep.h \
    Action.h \
    DescriptorElements.h \
    DescriptorHandler.h \
    ActionsMenu.h \
    NoteWidget.h \
    ImageWidget.h \
    ImageItemWidget.h \
    HistoryForm.h \
    PathologiesForm.h \
    ContactsForm.h \
    ImagesForm.h \
    AnagraficaForm.h \
    PatientNumberLabel.h \
    PatientItemWidget.h \
    LabelWidget.h \
    PatientSearchResultForm.h \
    AccountForm.h \
    ChangePatientFooter.h \
    PatientSearchForm.h \
    NotesForm.h \
    PatientMenuForm.h \
    MainMenuForm.h \
    CreditsWidget.h \
    buttonlabel.h \
    MobiHealth.loc \
    MobiHealth.h
SOURCES += MobiError.cpp \
    soapC.cpp \
    soapClient.cpp \
    SelectSearchMenu.cpp \
    ImageReader.cpp \
    CameraWidget.cpp \
    CameraObserver.cpp \
    ViewFinder.cpp \
    ScrollFrame.cpp \
    Patient.cpp \
    MobiState.cpp \
    TextBoxWidget.cpp \
    CreditsFooterWidget.cpp \
    ErrorForm.cpp \
    stdsoap2.cpp \
    ActionItemWidget.cpp \
    GenericStep.cpp \
    Action.cpp \
    DescriptorElements.cpp \
    DescriptorHandler.cpp \
    ActionsMenu.cpp \
    NoteWidget.cpp \
    ImageWidget.cpp \
    ImageItemWidget.cpp \
    HistoryForm.cpp \
    PathologiesForm.cpp \
    ContactsForm.cpp \
    ImagesForm.cpp \
    AnagraficaForm.cpp \
    PatientNumberLabel.c++ \
    PatientItemWidget.cpp \
    LabelWidget.cpp \
    PatientSearchResultForm.cpp \
    AccountForm.cpp \
    ChangePatientFooter.cpp \
    PatientSearchForm.cpp \
    NotesForm.cpp \
    PatientMenuForm.cpp \
    MainMenuForm.cpp \
    CreditsWidget.cpp \
    buttonlabel.cpp \
    MobiHealth.rss \
    MobiHealth_reg.rss \
    main.cpp \
    MobiHealth.cpp
FORMS += MobiError.ui \
    SelectSearchMenu.ui \
    CameraWidget.ui \
    ErrorForm.ui \
    LoadingForm.ui \
    GenericStep.ui \
    Action.ui \
    ActionsMenu.ui \
    NoteWidget.ui \
    ImageWidget.ui \
    ImageItemWidget.ui \
    HistoryForm.ui \
    PathologiesForm.ui \
    ContactsForm.ui \
    ImagesForm.ui \
    AnagraficaForm.ui \
    PatientSearchResultsForm.ui \
    PatientSearchResultForm.ui \
    AccountForm.ui \
    PatientSearchForm.ui \
    NotesForm.ui \
    PatientMenuForm.ui \
    MainMenuForm.ui \
    creditswidget.ui \
    MobiHealth.ui
MMP_RULES += "LIBRARY aknskins.lib"
MMP_RULES += "LIBRARY avkon.lib"
MMP_RULES += "LIBRARY bitgdi.lib"
MMP_RULES += "LIBRARY ecam.lib"
MMP_RULES += "LIBRARY efsrv.lib"
MMP_RULES += "LIBRARY eikcore.lib"
MMP_RULES += "LIBRARY cone.lib"
MMP_RULES += "LIBRARY fbscli.lib"
MMP_RULES += "LIBRARY ws32.lib"
MMP_RULES += "LIBRARY camerawrapper.lib"
MMP_RULES += "LIBRARY PlatformEnv.lib"
MMP_RULES += "LIBRARY bafl.lib"
MMP_RULES += "LIBRARY imageconversion.lib"
MMP_RULES += "LIBRARY apgrfx.lib"
MMP_RULES += "LIBRARY charconv.lib"
RESOURCES += resources.qrc
symbian:TARGET.UID3 = 0xEAF4030A
symbian:TARGET.CAPABILITY = "NetworkServices UserEnvironment"

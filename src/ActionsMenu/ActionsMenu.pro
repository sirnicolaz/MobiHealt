TEMPLATE = app
TARGET = ActionsMenu
QT += core \
    gui \
    xml \
    xmlpatterns
HEADERS += Action.h \
    DescriptorElements.h \
    DescriptorHandler.h \
    GenericStep.h \
    ActionsMenu.h
SOURCES += Action.cpp \
    DescriptorElements.cpp \
    DescriptorHandler.cpp \
    GenericStep.cpp \
    ActionsMenu_reg.rss \
    main.cpp \
    ActionsMenu.cpp
FORMS += Action.ui \
    GenericStep.ui \
    ActionsMenu.ui
MMP_RULES += "LIBRARY efsrv.lib"
MMP_RULES += "LIBRARY cone.lib"
MMP_RULES += "LIBRARY estor.lib"
RESOURCES +=
symbian:TARGET.UID3 = 0xEC08430B

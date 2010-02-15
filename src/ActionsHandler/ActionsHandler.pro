TEMPLATE = app
TARGET = ActionsHandler
QT += core \
    gui \
    xml \
    xmlpatterns
HEADERS += Action.h \
    DescriptorElements.h \
    DescriptorHandler.h \
    GenericStep.h \
    ActionsHandler.h
SOURCES += Action.cpp \
    DescriptorElements.cpp \
    DescriptorHandler.cpp \
    GenericStep.cpp \
    ActionsHandler_reg.rss \
    main.cpp \
    ActionsHandler.cpp
FORMS += Action.ui \
    GenericStep.ui \
    ActionsHandler.ui
MMP_RULES += "LIBRARY efsrv.lib"
MMP_RULES += "LIBRARY cone.lib"
MMP_RULES += "LIBRARY estor.lib"
RESOURCES += 
symbian:TARGET.UID3 = 0xEC08430B

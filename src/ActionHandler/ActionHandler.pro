TEMPLATE = app
TARGET = ActionHandler
QT += core \
    gui \
    xml \
    xmlpatterns
HEADERS += GenericStep.h \
    DescriptorHandler.h \
    DescriptorElements.h \
    ActionHandler.loc \
    ActionHandler.h
SOURCES += GenericStep.cpp \
    DescriptorHandler.cpp \
    DescriptorElements.cpp \
    dhMain.cpp \
    ActionHandler.rss \
    ActionHandler_reg.rss \
    main.cpp \
    ActionHandler.cpp
FORMS += GenericStep.ui \
    ActionHandler.ui
MMP_RULES += "LIBRARY efsrv.lib"
MMP_RULES += "LIBRARY cone.lib"
MMP_RULES += "LIBRARY estor.lib"
RESOURCES += 
symbian:TARGET.UID3 = 0xEC08430B

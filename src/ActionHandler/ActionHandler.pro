TEMPLATE = app
TARGET = ActionHandler
QT += core \
    gui \
    xml \
    xmlpatterns
HEADERS += descriptorelements.h \
    descriptorhandler.h \
    ActionHandler.loc \
    ActionHandler.h
SOURCES += descriptorelements.cpp \
    dhMain.cpp \
    descriptorhandler.cpp \
    ActionHandler.rss \
    ActionHandler_reg.rss \
    main.cpp \
    ActionHandler.cpp
FORMS += ActionHandler.ui
MMP_RULES += "LIBRARY efsrv.lib"
MMP_RULES += "LIBRARY cone.lib"
MMP_RULES += "LIBRARY estor.lib"
RESOURCES += 
symbian:TARGET.UID3 = 0xEC08430B

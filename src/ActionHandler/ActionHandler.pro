TEMPLATE = app
TARGET = ActionHandler
QT += core \
    gui \
    xml \
    xmlpatterns
HEADERS += descriptorhandler.h \
    ActionHandler.loc \
    ActionHandler.h
SOURCES += descriptorhandler.cpp \
    ActionHandler.rss \
    ActionHandler_reg.rss \
    main.cpp \
    ActionHandler.cpp
FORMS += ActionHandler.ui
RESOURCES += 
symbian:TARGET.UID3 = 0xEC08430B

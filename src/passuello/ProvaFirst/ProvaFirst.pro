TEMPLATE = app
TARGET = ProvaFirst
QT += core \
    gui
HEADERS += mainmenuform.h \
    ProvaFirst.loc \
    ProvaFirst.h
SOURCES += mainmenuform.cpp \
    ProvaFirst.rss \
    ProvaFirst_reg.rss \
    main.cpp \
    ProvaFirst.cpp
FORMS += mainmenuform.ui \
    ProvaFirst.ui
RESOURCES += 
symbian:TARGET.UID3 = 0xEE1E8E04

TEMPLATE = app
TARGET = FirstStackedApp
QT += core \
    gui
HEADERS += simpleoptionstep.h \
    simpletextstep.h \
    descriptionstep.h \
    action1widget.h \
    FirstStackedApp.loc \
    FirstStackedApp.h
SOURCES += simpleoptionstep.cpp \
    simpletextstep.cpp \
    descriptionstep.cpp \
    action1widget.cpp \
    FirstStackedApp.rss \
    FirstStackedApp_reg.rss \
    main.cpp \
    FirstStackedApp.cpp
FORMS += simpleoptionstep.ui \
    simpletextstep.ui \
    descriptionstep.ui \
    action1widget.ui \
    FirstStackedApp.ui
RESOURCES += 
symbian:TARGET.UID3 = 0xED5BBCC3

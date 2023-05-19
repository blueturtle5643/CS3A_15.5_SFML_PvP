TEMPLATE = app
CONFIG += console
#CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

CONFIG += c++11
#------------------------------------------
##Add these lines for SFML:



#WINDOWS
# put SFML file in the same location as project
#LIBS += -L"..\..\SFML-2.0\lib" #change this
#LIBS += -L"..\..\SFML-2.0\bin" #change this

LIBS += -L"C:\Qt\SFML-2.5.1\lib"
LIBS += -L"C:\Qt\SFML-2.5.1\bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
#INCLUDEPATH += "C:\Users\User\Desktop\SFML-2.5.1\include" #change this
#DEPENDPATH += "C:\Users\User\Desktop\SFML-2.5.1\include" #change this

INCLUDEPATH += "C:\Qt\SFML-2.5.1\include" #change this
DEPENDPATH += "C:\Qt\SFML-2.5.1\include" #change this


#-----------------------------------------

SOURCES += main.cpp \
    Creature.cpp \
    Grid.cpp \
    Predator.cpp \
    Prey.cpp \
    Wall.cpp \
    system.cpp \
    random.cpp \
    sidebar.cpp \
    animate.cpp


HEADERS += \
    Creature.h \
    Grid.h \
    Predator.h \
    Prey.h \
    Wall.h \
    constants.h \
    system.h \
    random.h \
    sidebar.h \
    animate.h \
    z_output.h \
    z_work_report.h

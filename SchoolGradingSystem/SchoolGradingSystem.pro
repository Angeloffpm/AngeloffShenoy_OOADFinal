QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    assignment.cpp \
    course.cpp \
    datatest.cpp \
    main.cpp \
    mainwindow.cpp \
    student.cpp \
    studentwindow.cpp \
    teacher.cpp \
    teacherviewcoursebutton.cpp \
    teacherwindow.cpp

HEADERS += \
    assignment.h \
    course.h \
    datatest.h \
    mainwindow.h \
    student.h \
    studentwindow.h \
    teacher.h \
    teacherviewcoursebutton.h \
    teacherwindow.h

FORMS += \
    mainwindow.ui \
    studentwindow.ui \
    teacherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

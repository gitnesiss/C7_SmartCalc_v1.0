QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calc.c \
    calc_pars.c \
    calc_pars_alpha.c \
    calc_pars_digit.c \
    calc_pars_punct.c \
    calc_rpn.c \
    calc_rpn_stack.c \
    calc_solve_rpn.c \
    calc_solve_rpn_solve_one_op.c \
    calc_solve_rpn_solve_two_op.c \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    calc.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

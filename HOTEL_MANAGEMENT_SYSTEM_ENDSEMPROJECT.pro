QT       += core gui
QT += sql
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminpage.cpp \
    attributes.cpp \
    availablerooms.cpp \
    checkout.cpp \
    checkout2.cpp \
    comp2.cpp \
    complaints.cpp \
    complaintsadmin.cpp \
    customer.cpp \
    information.cpp \
    main.cpp \
    mainclass.cpp \
    mainwindow.cpp\
    roombooking.cpp \
    sign.cpp \
    transactions.cpp \
    transactions2.cpp \
    user.cpp




HEADERS += \
    admin.h \
    adminpage.h \
    attributes.h \
    availablerooms.h \
    checkout.h \
    checkout2.h \
    comp2.h \
    complaints.h \
    complaintsadmin.h \
    customer.h \
    information.h \
    mainclass.h \
    mainwindow.h \
    roombooking.h \
    sign.h \
    transactions.h \
    transactions2.h \
    user.h

FORMS += \
    admin.ui \
    adminpage.ui \
    attributes.ui \
    availablerooms.ui \
    checkout.ui \
    checkout2.ui \
    comp2.ui \
    complaints.ui \
    complaintsadmin.ui \
    customer.ui \
    information.ui \
    mainwindow.ui \
    roombooking.ui \
    sign.ui \
    transactions.ui \
    transactions2.ui \
    user.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc \
    resourse.qrc

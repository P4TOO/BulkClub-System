QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += "C://Users/luisr/OneDrive/Desktop/QT stuff/BulkClub-System_v3"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmember.cpp \
    admin.cpp \
    itemdisplay.cpp \
    logindialog.cpp \
    main.cpp \
    manageinventory.cpp \
    memberpurchases.cpp \
    membershipexpiry.cpp \
    managemembers.cpp \
    memberupgrade.cpp \
    rebatewindow.cpp \
    salesreport.cpp \
    storemanager.cpp

HEADERS += \
    addmember.h \
    admin.h \
    itemdisplay.h \
    logindialog.h \
    manageinventory.h \
    memberpurchases.h \
    membershipexpiry.h \
    managemembers.h \
    memberupgrade.h \
    picosha2.h \
    rebatewindow.h \
    salesreport.h \
    storemanager.h

FORMS += \
    addmember.ui \
    admin.ui \
<<<<<<< HEAD
    manageinventory.ui \
=======
    itemdisplay.ui \
>>>>>>> a48879b9c033f01e86ea324fa9739fcb33c354c8
    memberpurchases.ui \
    membershipexpiry.ui \
    managemembers.ui \
    memberupgrade.ui \
    rebatewindow.ui \
    salesreport.ui \
    storemanager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    users.db

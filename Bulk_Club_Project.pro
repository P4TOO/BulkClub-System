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
    logindialog.cpp \
    main.cpp \
<<<<<<< HEAD
    membershipexpiry.cpp \
=======
    managemembers.cpp \
>>>>>>> e1b89ec015e8762c85e2ce368e9ebce8fec3d026
    salesreport.cpp \
    storemanager.cpp

HEADERS += \
    addmember.h \
    admin.h \
    logindialog.h \
<<<<<<< HEAD
    membershipexpiry.h \
=======
    managemembers.h \
>>>>>>> e1b89ec015e8762c85e2ce368e9ebce8fec3d026
    picosha2.h \
    salesreport.h \
    storemanager.h

FORMS += \
    addmember.ui \
    admin.ui \
<<<<<<< HEAD
    membershipexpiry.ui \
=======
    managemembers.ui \
>>>>>>> e1b89ec015e8762c85e2ce368e9ebce8fec3d026
    salesreport.ui \
    storemanager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    users.db

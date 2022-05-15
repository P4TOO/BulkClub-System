QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += "/Users/adriangomez/desktop/Bulk Project/BulkClub-System"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    logindialog.cpp \
    main.cpp \
    membershipexpiry.cpp \
    salesreport.cpp \
    storemanager.cpp

HEADERS += \
    admin.h \
    logindialog.h \
    membershipexpiry.h \
    picosha2.h \
    salesreport.h \
    storemanager.h

FORMS += \
    admin.ui \
    membershipexpiry.ui \
    salesreport.ui \
    storemanager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    users.db

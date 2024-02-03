QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/main.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Utilsateur.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/exception.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexbdd.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexdeconnection.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexhome.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexprofil.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainconnection.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.cpp

HEADERS += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Utilisateur.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/exception.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexbdd.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexdeconnection.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexhome.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexprofil.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainconnection.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.h

FORMS += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexbdd.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexdeconnection.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexhome.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexprofil.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainconnection.ui \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

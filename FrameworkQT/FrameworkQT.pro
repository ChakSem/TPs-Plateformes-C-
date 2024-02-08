QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/main.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Administrator.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Profile.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/User.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/data.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/encryption.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/exception.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexbdd.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexdeconnection.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexhome.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexprofil.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainconnection.cpp \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.cpp

HEADERS += \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Administrator.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Profile.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/Rights.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/UUID.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/User.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/model/data.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/encryption.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/utils/exception.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexbdd.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexdeconnection.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexhome.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/indexprofil.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainconnection.h \
    src/main/c++/fr/univtours/polytech/FrameworkQT/view/mainwindow.h
    QT+=widgets
    QT+=core
    QT+=gui

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

DISTFILES += \
    .gitignore \
    glog/uml/Choix.md \
    glog/uml/PUML.md \
    glog/uml/Rapport_TP8_1.md \
    glog/uml/TO_DO.md \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/Adminstateur.json \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/ProfilUser.json \
    src/main/c++/fr/univtours/polytech/FrameworkQT/parseurJson/Utilsateur.json

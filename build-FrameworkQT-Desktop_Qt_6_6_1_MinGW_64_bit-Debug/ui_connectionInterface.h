/********************************************************************************
** Form generated from reading UI file 'connectionInterface.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONINTERFACE_H
#define UI_CONNECTIONINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connection
{
public:
    QFrame *frame;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *passwordLogin;
    QLineEdit *idLogin;
    QLabel *labelMdp;
    QLabel *labelId;
    QPushButton *pushButton;
    QLabel *labelConnection;

    void setupUi(QWidget *Connection)
    {
        if (Connection->objectName().isEmpty())
            Connection->setObjectName("Connection");
        Connection->resize(800, 500);
        frame = new QFrame(Connection);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(100, 50, 600, 400));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"background : #333;\n"
"}\n"
"\n"
"QLineEdit {\n"
"	background : transparent;\n"
"	border : none;\n"
"    color :  #710702;\n"
"border-bottom : 1px solid #717072;\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(100, 110, 371, 161));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        passwordLogin = new QLineEdit(widget);
        passwordLogin->setObjectName("passwordLogin");

        gridLayout->addWidget(passwordLogin, 3, 1, 1, 1);

        idLogin = new QLineEdit(widget);
        idLogin->setObjectName("idLogin");
        idLogin->setProperty("long", QVariant(Q_INT64_C(0)));

        gridLayout->addWidget(idLogin, 2, 1, 1, 1);

        labelMdp = new QLabel(widget);
        labelMdp->setObjectName("labelMdp");
        QFont font;
        font.setPointSize(12);
        labelMdp->setFont(font);

        gridLayout->addWidget(labelMdp, 3, 0, 1, 1);

        labelId = new QLabel(widget);
        labelId->setObjectName("labelId");
        labelId->setFont(font);

        gridLayout->addWidget(labelId, 2, 0, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 340, 411, 31));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background : grey;\n"
"border-radius:15px;\n"
"\n"
"color : white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"}"));
        labelConnection = new QLabel(frame);
        labelConnection->setObjectName("labelConnection");
        labelConnection->setGeometry(QRect(210, 50, 141, 26));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelConnection->sizePolicy().hasHeightForWidth());
        labelConnection->setSizePolicy(sizePolicy);
        labelConnection->setMinimumSize(QSize(0, 13));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        labelConnection->setFont(font1);

        retranslateUi(Connection);

        QMetaObject::connectSlotsByName(Connection);
    } // setupUi

    void retranslateUi(QWidget *Connection)
    {
        Connection->setWindowTitle(QCoreApplication::translate("Connection", "Form", nullptr));
        labelMdp->setText(QCoreApplication::translate("Connection", "Mot de Passe :", nullptr));
        labelId->setText(QCoreApplication::translate("Connection", "Identifiant :", nullptr));
        pushButton->setText(QCoreApplication::translate("Connection", "Connexion", nullptr));
        labelConnection->setText(QCoreApplication::translate("Connection", "Connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Connection: public Ui_Connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONINTERFACE_H

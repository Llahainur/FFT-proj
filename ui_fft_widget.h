/********************************************************************************
** Form generated from reading UI file 'fft_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FFT_WIDGET_H
#define UI_FFT_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FFT_Widget
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *FFT_Widget)
    {
        if (FFT_Widget->objectName().isEmpty())
            FFT_Widget->setObjectName(QString::fromUtf8("FFT_Widget"));
        FFT_Widget->resize(649, 479);
        graphicsView = new QGraphicsView(FFT_Widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(100, 130, 256, 192));

        retranslateUi(FFT_Widget);

        QMetaObject::connectSlotsByName(FFT_Widget);
    } // setupUi

    void retranslateUi(QWidget *FFT_Widget)
    {
        FFT_Widget->setWindowTitle(QCoreApplication::translate("FFT_Widget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FFT_Widget: public Ui_FFT_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FFT_WIDGET_H

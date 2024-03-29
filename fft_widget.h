/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef FFT_WIDGET_H
#define FFT_WIDGET_H

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>

QT_BEGIN_NAMESPACE
class QLineSeries;
class QChart;
QT_END_NAMESPACE

QT_USE_NAMESPACE

class XYSeriesIODevice_FFT;

QT_BEGIN_NAMESPACE
class QAudioInput;
class QAudioDevice;
class QAudioSource;
QT_END_NAMESPACE

class FFT_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit FFT_Widget(const QAudioDevice &deviceInfo, QWidget *parent = nullptr);
    ~FFT_Widget();
    const double maxAmpl=0.04;
    const int sampleRate = 20000;
    const int maxFreq=2048;
private:
    XYSeriesIODevice_FFT *m_device = nullptr;
    QChart *m_chart;
    QLineSeries *m_series ;
    QAudioInput *m_audioInput = nullptr;
    QAudioSource *m_audioSource = nullptr;
};

#endif // WIDGET_H

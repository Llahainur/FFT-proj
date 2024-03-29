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

#ifndef XYSERIESIODEVICE_FFT_H
#define XYSERIESIODEVICE_FFT_H

#include <QtCore/QIODevice>
#include <QtCore/QPointF>
#include <QtCore/QList>
#include <QtCharts/QChartGlobal>
#include <stdio.h>
#include <QtCharts/QXYSeries>
#include <QList>
#include "converter.h"
//#include "fft.h"

QT_BEGIN_NAMESPACE
class QXYSeries;
QT_END_NAMESPACE

QT_USE_NAMESPACE

class XYSeriesIODevice_FFT : public QIODevice
{
    Q_OBJECT
public:
    explicit XYSeriesIODevice_FFT(QXYSeries *series, QObject *parent = nullptr);

    static const int sampleCount = 8192;

protected:
    qint64 readData(char *data, qint64 maxSize) override;
    qint64 writeData(const char *data, qint64 maxSize) override;

private:
    QXYSeries *m_series;
    QList<QPointF> m_buffer;
    Converter Conv;
    //FFT Fft;
};

#endif // XYSERIESIODEVICE_FFT_H

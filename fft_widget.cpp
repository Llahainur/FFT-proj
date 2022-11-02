#include "fft_widget.h"
#include "xyseriesiodevice_fft.h"
#include <QtMultimedia/QAudioDevice>
#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioSource>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>

#include <QtWidgets/QVBoxLayout>

QT_USE_NAMESPACE

FFT_Widget::FFT_Widget(const QAudioDevice &deviceInfo, QWidget *parent) :
    QWidget(parent),
    m_chart(new QChart),
    m_series(new QLineSeries)
{
    QChartView *chartView = new QChartView(m_chart);
    chartView->setMinimumSize(1000, 600);
    m_chart->addSeries(m_series);
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(-2048, 2048);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Samples");
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 0.025);
    axisY->setTitleText("Spectrum");
    m_chart->addAxis(axisX, Qt::AlignBottom);
    m_series->attachAxis(axisX);
    m_chart->addAxis(axisY, Qt::AlignLeft);
    m_series->attachAxis(axisY);
    m_chart->legend()->hide();
    m_chart->setTitle("Data from the microphone (" + deviceInfo.description() + ')');

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(chartView);

    m_audioInput = new QAudioInput(deviceInfo, this);

    QAudioFormat formatAudio;
    formatAudio.setSampleRate(5000);
    formatAudio.setChannelCount(1);
    formatAudio.setSampleFormat(QAudioFormat::UInt8);

    m_audioSource = new QAudioSource(deviceInfo, formatAudio);
    m_audioSource->setBufferSize(200);

    m_device = new XYSeriesIODevice_FFT(m_series, this);
    m_device->open(QIODevice::WriteOnly);

    m_audioSource->start(m_device);//добавить FFT и вывести на один график


}

FFT_Widget::~FFT_Widget()
{
    m_audioSource->stop();
    m_device->close();
    delete m_audioInput;
    delete m_device;
}

QT += charts multimedia
#TEMPLATE = subdirs

HEADERS += \
    converter.h \
    fft.h \
    fft_widget.h \
    widget.h \
    xyseriesiodevice.h \
    xyseriesiodevice_fft.h

SOURCES += \
    converter.cpp \
    fft.cpp \
    fft_widget.cpp \
    main.cpp\
    widget.cpp \
    xyseriesiodevice.cpp \
    xyseriesiodevice_fft.cpp


# Ensure that library is built before application
#CONFIG  += ordered

#SUBDIRS += ./fftreal

FORMS += \
    fft_widget.ui


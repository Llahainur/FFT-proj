QT += charts multimedia
#TEMPLATE = subdirs

HEADERS += \
    fft.h \
    widget.h \
    xyseriesiodevice.h

SOURCES += \
    fft.cpp \
    main.cpp\
    widget.cpp \
    xyseriesiodevice.cpp


# Ensure that library is built before application
#CONFIG  += ordered

#SUBDIRS += ./fftreal


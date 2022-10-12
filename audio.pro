QT += charts multimedia
#TEMPLATE = subdirs

HEADERS += \
    converter.h \
    fft.h \
    widget.h \
    xyseriesiodevice.h

SOURCES += \
    converter.cpp \
    fft.cpp \
    main.cpp\
    widget.cpp \
    xyseriesiodevice.cpp


# Ensure that library is built before application
#CONFIG  += ordered

#SUBDIRS += ./fftreal


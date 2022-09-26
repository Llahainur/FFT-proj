QT += charts multimedia
#TEMPLATE = subdirs

HEADERS += \
    widget.h \
    xyseriesiodevice.h

SOURCES += \
    main.cpp\
    widget.cpp \
    xyseriesiodevice.cpp


# Ensure that library is built before application
#CONFIG  += ordered

#SUBDIRS += ./fftreal


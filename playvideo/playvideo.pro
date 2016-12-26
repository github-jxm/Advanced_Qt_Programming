!exists($$QMAKE_LIBDIR_QT/libphonon.prl) {
    error(Cannot build this example since it needs Phonon support)
}
CONFIG	    += console debug
QT	    += phonon
HEADERS	    += ../aqp/aqp.hpp
SOURCES	    += ../aqp/aqp.cpp
RESOURCES   += ../aqp/aqp.qrc
INCLUDEPATH += ../aqp
HEADERS	    += mainwindow.hpp
SOURCES     += mainwindow.cpp
SOURCES     += main.cpp
RESOURCES   += playvideo.qrc

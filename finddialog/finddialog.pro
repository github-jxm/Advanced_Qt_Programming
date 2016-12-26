IS_GE_QT_46 = $$find(QT_VERSION, "^4\.[6-9]\.*")
isEmpty(IS_GE_QT_46) {
    error(Cannot build this example since it needs Qt 4.6 or higher)
}
CONFIG	    += console debug
HEADERS	    += ../aqp/kuhn_munkres.hpp
SOURCES	    += ../aqp/kuhn_munkres.cpp
HEADERS	    += ../aqp/alt_key.hpp
SOURCES	    += ../aqp/alt_key.cpp
HEADERS	    += ../aqp/aqp.hpp
SOURCES	    += ../aqp/aqp.cpp
RESOURCES   += ../aqp/aqp.qrc
INCLUDEPATH += ../aqp
HEADERS	    += finddialog.hpp
SOURCES     += finddialog.cpp
SOURCES     += main.cpp
#DEFINES     += SCREENSHOTS

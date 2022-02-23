QT += testlib
QT -= gui

QT += widgets # agrego esto
LIBS += -lopengl32 # agrego esto

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ei_autotest.cpp \
    ../../finalPA/LUT.cpp \
    ../../finalPA/administradorArchivos.cpp \
    ../../finalPA/archivoAIC.cpp \
    ../../finalPA/archivoPNM.cpp \
    ../../finalPA/deteccion.cpp \
    ../../finalPA/estadistica.cpp \
    ../../finalPA/filtro.cpp \
    ../../finalPA/filtroMediana.cpp \
    ../../finalPA/filtroPasaAltos.cpp \
    ../../finalPA/filtroPasaBajos.cpp \
    ../../finalPA/graficador.cpp \
    ../../finalPA/imagen.cpp \
    ../../finalPA/interfaz.cpp \
    ../../finalPA/pixel.cpp \
    ../../finalPA/sistema.cpp


HEADERS += \ \
    ../../finalPA/LUT.h \
    ../../finalPA/administradorArchivos.h \
    ../../finalPA/archivoAIC.h \
    ../../finalPA/archivoPNM.h \
    ../../finalPA/estadistica.h \
    ../../finalPA/filtro.h \
    ../../finalPA/filtroMediana.h \
    ../../finalPA/filtroPasaAltos.h \
    ../../finalPA/filtroPasaBajos.h \
    ../../finalPA/graficador.h \
    ../../finalPA/imagen.h \
    ../../finalPA/interfaz.h \
    ../../finalPA/pixel.h \
    ../../finalPA/sistema.h


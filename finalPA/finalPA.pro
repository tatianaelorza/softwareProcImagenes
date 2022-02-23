QT -= gui
QT += widgets


CONFIG += c++11 console
CONFIG -= app_bundle

LIBS += -lOpengl32

QT += opengl

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        LUT.cpp \
        administradorArchivos.cpp \
        archivoAIC.cpp \
        archivoPNM.cpp \
        deteccion.cpp \
        estadistica.cpp \
        filtro.cpp \
        filtroMediana.cpp \
        filtroPasaAltos.cpp \
        filtroPasaBajos.cpp \
        graficador.cpp \
        imagen.cpp \
        interfaz.cpp \
        main.cpp \
        pixel.cpp \
        sistema.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    LUT.h \
    administradorArchivos.h \
    archivoAIC.h \
    archivoPNM.h \
    deteccion.h \
    estadistica.h \
    filtro.h \
    filtroMediana.h \
    filtroPasaAltos.h \
    filtroPasaBajos.h \
    graficador.h \
    imagen.h \
    interfaz.h \
    pixel.h \
    sistema.h

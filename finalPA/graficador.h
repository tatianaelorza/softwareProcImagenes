#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QApplication>
#include <QKeyEvent>
#include <QMouseEvent>
#include <stdlib.h>
#include "estadistica.h"
#include "administradorArchivos.h"
#include "archivoAIC.h"
#include "archivoPNM.h"
#include "filtro.h"
#include "filtroMediana.h"
#include "filtroPasaAltos.h"
#include "filtroPasaBajos.h"
#include "interfaz.h"
#include "LUT.h"
#include "deteccion.h"

#include "imagen.h"
#include "pixel.h"

class Graficador : public QOpenGLWidget , protected QOpenGLFunctions
{
    public:
        Graficador();

        /**
         * @brief getImagenOriginal permite que la imagen vuelva a sus valores originales, previos a la
         * utilizacion del software.
         */
        void getImagenOriginal();

        /**
         * @brief setImagen permite cargar la imagen que se va a utilizar
         * @param pimagen
         * @param pDirectorio
         */
        void setImagen(string pimagen, string pDirectorio);
        /**
         * @brief setListadoImagenes
         * @param pListado
         */
        void setListadoImagenes(vector<string> pListado);
        /**
         * @brief setListadoLUT permite settear los nombres de los archivos de las LUT que se enceuntran
         * en el directorio LUT elegido.
         * @param pdirectorio ruta del directorio elegido
         */
        void setListadoLUT(string pdirectorio);
        /**
         * @brief initializeGL permite inicializar las funciones de OpenGL.
         */
        void initializeGL();
        /**
         * @brief resizeGL permite definir le ventana y espacio de graficación.
         * @param pAncho define el ancho de la ventana de graficación.
         * @param pAlto define el alto de la ventana de graficación.
         */
        void resizeGL(int pAncho, int pAlto);
        /**
         * @brief paintGL permite graficar en la ventana de graficación.
         */
        void paintGL();
        /*!
         * \brief   keyPressEvent permite la utilización de diversas funciones cuando las teclas que se presionen.
         */
        void keyPressEvent(QKeyEvent *pEvent);
        /*!
         * \brief   keyReleaseEvent permite que se deshabiliten las funciones prevamiente utilizados.
         */
        void keyReleaseEvent(QKeyEvent *pEvent);
        /*!
         * \brief   mousePressEvent permite la utilización de diversas funciones cuando los clicks que se presionen.
         */
        void mousePressEvent(QMouseEvent *pEvent);
        /*!
         * \brief   mouseMoveEvent permite la utilización de diversas funciones cuando haya movimiento del mouse.
         */
        void mouseMoveEvent(QMouseEvent *pEvent);
        /*!
         * \brief   mouseReleaseEvent permite que se deshabiliten las funcioens que se utilizaban previamente utilizados.
         */
        void mouseReleaseEvent(QMouseEvent *pEvent);

        ~Graficador();

    private:

        /**
         * @brief archivo es un puntero a la clase AdminArchivos, permite el polimorfismo con las clases hijas (archivoPNM y archivoAIC).
         */
        AdministradorArchivos *archivo=NULL;
        /**
         * @brief imagen
         */
        Imagen imagen;
        /**
         * @brief imagenOriginal
         */
        Imagen imagenOriginal;
        /**
         * @brief estadistica
         */
        Estadistica estadistica;

        FiltroMediana filtroMediana;
        FiltroPasaAltos filtroPasaAltos;
        FiltroPasaBajos filtroPasaBajos;
        /**
         * @brief interfaz
         */
        Interfaz interfaz;
        /**
         * @brief lut
         */
        LUT lut;
        /**
         * @brief deteccion
         */
        Deteccion deteccion;

        /**
         * @brief listadoDeImagenes
         */
        vector<string> listadoDeImagenes;
        /**
         * @brief listadoLUT
         */
        vector<string> listadoLUT;

        /**
         * @brief auxDirectorio
         */
        string auxDirectorio;
        /**
         * @brief auxDirectorioLUT
         */
        string auxDirectorioLUT;
        /**
         * @brief indiceImagen
         */
        int indiceImagen;
        /**
         * @brief opcionLUT
         */
        int opcionLUT;
        /**
         * @brief formatoArchivo
         */
        string formatoArchivo;
        /**
         * @brief indiceLUT indica la LUT que se desea utilizar dle listado de LUT.
         */
        int indiceLUT=-1;
        /**
         * @brief desplazamientoY permite desplazar la imagen cuando se modifica la ventana de graficación.
         */
        float desplazamientoY,
        /**
         * @brief desplazamientoX permite desplazar la imagen cuando se modifica la ventana de graficación.
         */
        desplazamientoX,

        tolerancia,

        escala,

        escalaAncho,

        escalaAlto;
        /**
         * @brief posicionMomentaneaX permite el seguimiento momentaneo del mouse en el eje X.
         */
        int posicionMomentaneaX,
        /**
         * @brief posicionMomentaneaY permite el seguimiento momentaneo del mouse en el eje Y.
         */
        posicionMomentaneaY,
        /**
         * @brief posicionInicialX permite el seguimiento inicial del mouse en el eje X.
         */
        posicionInicialX,
        /**
         * @brief posicionInicialY permite el seguimiento inicial del mouse en el eje Y.
         */
        posicionInicialY,
        /**
         * @brief posicionFinalX permite el seguimiento final del mouse en el eje X.
         */
        posicionFinalX,
        /**
         * @brief posicionFinalY permite el seguimiento final del mouse en el eje Y.
         */
        posicionFinalY,

        posicionVentanaInicialX,

        posicionVentanaInicialY,

        posicionVentanaFinalX,

        posicionVentanaFinalY,

        altoVentana,

        anchoVentana,

        anchoImagen,

        altoImagen;

        /// atributos para atajos

        bool controlPresionado = false,

        controlMouseMove = false,

        clickIzquierdoPresionado = false,

        flechaArribaPresionada = false,

        flechaAbajoPresionada = false,

        flechaIzquierdaPresionada = false,

        flechaDerechaPresionada = false,

        plusPresionada = false,

        minusPresionada = false,

        hPresionada = false,

        gPresionada = false,

        oPresionada = false,

        bPresionada = false,

        aPresionada = false,

        sPresionada = false,

        mPresionada = false,

        cPresionada = false,

        nPresionada = false,

        controlGraficarZoom = false,

        controlGraficarHistograma = false,

        escapePresionado = false;

        /**
         * @brief graficarHistograma permite graficar el histograma.
         */
        void graficarHistograma();
        /**
         * @brief graficarLimites permite graficar los limites de la imagen
         */
        void graficarLimites();
        /**
         * @brief graficarImagen permite graficar la imagen de interes.
         */
        void graficarImagen();
        /**
         * @brief graficarRectanguloZoom permite graficar el rectangulo del zoom.
         */
        void graficarRectanguloZoom();

};

#endif // GRAFICADOR_H

#ifndef SISTEMA_H
#define SISTEMA_H
#include <QApplication>
#include <iostream>
#include <dirent.h>
#include "graficador.h"
#include "interfaz.h"

using namespace std;

class Sistema{
    public:

        Sistema();

        /**
         * @brief interfaz
         */
        Interfaz interfaz;
        /**
         * @brief graficador
         */
        Graficador graficador;
        /**
         * @brief getListadoDeArchivos permite devolver el listado de archivos de un directorio.
         * @param pRutaDirectorio es la ruta del directorio dle cual queremos conocer los archivos.
         * @return retorna un vector de string con los nombres de los archivos del directorio.
         */
        vector<string>getListadoDeArchivos(string pRutaDirectorio);
        /**
         * @brief ejecutar se encarga del manejo de as opciones elegidas por el usuario en
         * las primeras interacciones, así como permite la graficación de la imagen elegida.
         */
        void ejecutar();
    private:

        /**
         * @brief opcionLUT guarda la eleccion del usuario sobre cual carpeta de tablas de conversion utilizar.
         */
        int opcionLUT,
        /**
         * @brief opcionMenu guarda la eleccion del usuario sobre la ejecuccion del programa.
         */
        opcionMenu = 0,
        /**
         * @brief opcionDirectorio guarda la eleccion del usuario sobre el directorio que eligió
         *      para utilizar sus imagense.
         */
        opcionDirectorio = 0,
        /**
         * @brief opcionImagen guarda la eleccion del usuario sobre la imagen que desea graficar.
         */
        opcionImagen;
        /**
         * @brief listadoImagenes es un vector en el cual se guardan los nombres d elos archivos
         *      de las imagenes del directorio que eligió el usuario.
         */
        vector<string> listadoImagenes;
        /**
         * @brief rutaArchivosNuevos almacena la ruta de la carpeta donde se encuentran las imagenes nuevas.
         */
        string rutaArchivosNuevos = "grupo_imagenes_nuevas/",
        /**
         * @brief rutaArchivosCarpeta1 almacena la ruta de la carpeta grupo_imagenes_1.
         */
        rutaArchivosCarpeta1 = "grupo_imagenes_1/",
        /**
         * @brief rutaArchivosCarpeta2 almacena la ruta de la carpeta grupo_imagenes_2.
         */
        rutaArchivosCarpeta2 ="grupo_imagenes_2/",
        /**
         * @brief rutaArchivosCarpeta3 almacena la ruta de la carpeta grupo_imagenes_3_corruptas.
         */
        rutaArchivosCarpeta3 ="grupo_imagenes_3_corruptas/",
        /**
         * @brief rutaArchivosCarpeta5 almacena la ruta de la carpeta ij_image_samples.
         */
        rutaArchivosCarpeta5 = "ij_image_samples/",
        /**
         * @brief directorio almacena la ruta a la carpeta pei-2021-2022-entrega_autotest_01, que almacena el resto de las carpetas con imagenes.
         */
        directorio = "../pei-2021-2022-entrega_autotest_01/",
        /**
         * @brief directorioLUT1 almacena la ruta de la carpeta de tablas de conversiones grupo_luts.
         */
        directorioLUT1 = "../pei-2021-2022-entrega_autotest_01/grupo_luts/",
        /**
         * @brief directorioLUT2 almacena la ruta de la carpeta de tablas de conversiones ij_luts.
         */
        directorioLUT2 = "../pei-2021-2022-entrega_autotest_01/ij_luts/";

};
#endif // SISTEMA_H

#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QApplication>
#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>
#include <stdlib.h>
#include <windows.h>
#include "administradorArchivos.h"
#include "archivoAIC.h"
#include "archivoPNM.h"
#include "imagen.h"


class Interfaz
{
    public:
        Interfaz();
        /**
         * @brief guardarImagen gertiona el tipo y formato en el cual se guardará una imagen.
         * @param pImagen es un puntero a la imagen que se desea guardar.
         */
        void guardarImagen(Imagen *pImagen);

        /**
         * @brief getListaDeAtajos muestra por pantalla la lista de atajos para el usuario.
         */
        void getListaDeAtajos();
        /**
         * @brief getListadoDeArchivos retorna un listado de string que muestra los archivos que
         *      forman parte de un directorio puntual.
         * @param pRutaDirectorio es el directorio del cual se quieren conocer los archivows.
         * @return retorna un vector de string con los nombres de los archivos del directorio.
         */
        vector<string> getListadoDeArchivos(string pRutaDirectorio);

        ~Interfaz();
    private:
        /**
         * @brief archi es un puntero que hace referencia al archivo que posteriormente guardaremos.
         */
        AdministradorArchivos *archi;
        /**
         * @brief imagen
         */
        Imagen imagen;
        /**
         * @brief opcArchivoNuevo guarda la opcion elegida del tipo de archivo que el usuario desea guardar.
         */
        int opcArchivoNuevo =0;
        /**
         * @brief opcTipoArchivoPNM guarda la opciónes elegida del tipo de archivo PNM que el usuario desea guardar.
         */
        int opcTipoArchivoPNM =0;

        /**
         * @brief raiz es la raiz hace el directorio de carpetas de imagenes
         */
        string raiz = "../pei-2021-2022-entrega_autotest_01/";
        /**
         * @brief rutaArchivosNuevos almacena la ruta de la carpeta donde se guardaran las imagenes nuevas.
         */
        string rutaArchivosNuevos = "grupo_imagenes_nuevas/";

        /**
         * @brief nombreDelArchivoNuevo almacena el nombre del nuevo archivo que elegió el usuario.
         */
        string nombreDelArchivoNuevo;

};
#endif // INTERFAZ_H

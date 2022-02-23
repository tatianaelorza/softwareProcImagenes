#ifndef ADMINISTRADORARCHIVOS_H
#define ADMINISTRADORARCHIVOS_H
#include <string>
#include "imagen.h"
#include <fstream>
#include <iostream>
using namespace std;


class AdministradorArchivos
{
    public:
        AdministradorArchivos();

        /**
         * @brief leer es un método virtual que va a ser redefinido por sus clases hijas para leer los datos de las imagenes.
         * @param pNombreArchivo es el nombre del archivo (imagen) que se quiere leer.
         * @return este método retorna un objeto del tipo Imagen.
         */
        virtual Imagen leer(string pNombreArchivo) = 0;
        /**
         * @brief escribir es un método virtual que va a ser redefinido por sus clases hijas para escribir los datos de las imagenes.
         * @param pNombreArchivo es el nombre del archivo que se va a escribir.
         * @param imagen_ es un puntero a la imagen que se desea escribir.
         * @param tipoArchivo_ señala el tipo de archivo que se va a escribir.
         */
        virtual void escribir(string pNombreArchivo, Imagen *imagen_, int pTipoArchivo_) = 0;
        /**
         * @brief getTipoArchivo es un método virtual que va a ser redefinido por sus clases hijas para leer el tipo de archivo que es la imagen que se desea leer.
         * @return este método retorna un string con el tipo de archivo.
         */
        virtual string getTipoArchivo() = 0;

        virtual ~AdministradorArchivos();
};
#endif // ADMINISTRADORARCHIVOS_H

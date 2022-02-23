#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H
#include "administradorArchivos.h"
#include <fstream>
class ArchivoPNM : public AdministradorArchivos
{
    public:
        ArchivoPNM();

        /**
         * @brief leer es un método redefinido de AdministradorArchivos para leer los datos de las imagenes en formato PNM.
         * @param pNombreArchivo es el nombre del archivo (imagen) que se quiere leer.
         * @return este método retorna un objeto del tipo Imagen.
         */
        Imagen leer(string pNombreArchivo) override;
        /**
         * @brief escribir es un método redefinido de AdministradorArchivos para escribir los datos de una imagen de formato PNM.
         * @param pNombreArchivo es el nombre del archivo que se desea escribir.
         * @param imagen_ es un puntero a la imagen que se desea escribir.
         * @param tipoArchivo_ señala el tipo de archivo que se va a escribir.
         */
        void escribir(string pNombreArchivo, Imagen *imagen_, int pTipoArchivo_) override;
        /**
         * @brief getTipoArchivo es un método redefinido de AdministradorArchivos para conocer el tipo de archivo que se desea leer.
         * @return este método retorna un string con el tipo de archivo.
         */
        string getTipoArchivo() override;

        ~ArchivoPNM();

    private:
        string tipoArchivo;
};
#endif // ARCHIVOPNM_H

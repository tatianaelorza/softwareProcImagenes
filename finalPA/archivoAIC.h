#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H
#include "administradorArchivos.h"

class ArchivoAIC : public AdministradorArchivos
{
    public:
        ArchivoAIC();
        /**
         * @brief leer es un método redefinido de AdministradorArchivos para leer los datos de una imagen de formato AIC.
         * @param nombreArchivo_ nombre del archivo que se desea leer.
         * @return
         */
        Imagen leer(string pNombreArchivo) override;
        /**
         * @brief escribir es un método redefinido de AdministradorArchivos para escribir los datos de una imagen de formato AIC.
         * @param pNombreArchivo es el nombre del archivo que se va a escribir.
         * @param imagen_ es un puntero a la imagen que se desea escribir.
         * @param tipoArchivo_ señala el tipo de archivo que se va a escribir.
         */
        void escribir(string pNombreArchivo, Imagen *imagen_, int pTipoArchivo_) override;
        /**
         * @brief getTipoArchivo es un método redefinido de AdministradorArchivos para conocer el tipo de archivo que se desea leer.
         * @return este método retorna un string con el tipo de archivo.
         */
        string getTipoArchivo() override;

        ~ArchivoAIC();

    private:
        string tipoArchivo;
};
#endif // ARCHIVOAIC_H

#ifndef FILTROMEDIANA_H
#define FILTROMEDIANA_H
#include "filtro.h"

class FiltroMediana : public Filtro
{
    public:
        FiltroMediana();
        /**
         * @brief procesarImagen es un método redefinido de Filtro para aplicar el filtro de mediana a la imagen,
         *      este filtro tiene el objetivo de eliminar el ruido, a partir de analizar un pixel central y sus respectivos pixeles
         *      vecinos.
         * @param pImagen  es un puntero a la imagen que se quiere procesar.
         */
        void procesarImagen(Imagen *pImagen) override;

};
#endif // FILTROMEDIANA_H

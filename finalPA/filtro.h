#ifndef FILTRO_H
#define FILTRO_H
#include "imagen.h"
#include "pixel.h"

class Filtro
{
    public:
        Filtro();
        /**
         * @brief procesarImagen es un método virtual que va a ser redefinido por sus clases hijas para aplicar los distintos filtros a las imagenes.
         * @param pImagen es un puntero a la imagen que se desea procesar.
         */
        virtual void procesarImagen(Imagen *pImagen) = 0;

        ~Filtro();

};
#endif // FILTRO_H

#ifndef FILTROPASAALTOS_H
#define FILTROPASAALTOS_H
#include "filtro.h"

class FiltroPasaAltos : public Filtro
{
    public:
        FiltroPasaAltos();
        /**
         * @brief procesarImagen es un método redefinido de Filtro para aplicar el filtro pasa altos a la imagen,
         *      este filtro tiene el objetivo de realzar los bordes, a partir de analizar un pixel central y sus respectivos pixeles
         *      vecinos.
         * @param pImagen  es un puntero a la imagen que se quiere procesar.
         */
        void procesarImagen(Imagen *pImagen) override;
};
#endif // FILTROPASAALTOS_H

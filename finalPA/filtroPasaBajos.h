#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H
#include "filtro.h"
#include <iostream>
using namespace std;
class FiltroPasaBajos : public Filtro
{
    public:
        FiltroPasaBajos();
        /**
         * @brief procesarImagen es un método redefinido de Filtro para aplicar el filtro pasa bajos a la imagen,
         *      este filtro tiene el objetivo de reducir las diferencia de intensidad entre las areas, a partir de analizar
         *      un pixel central y sus respectivos pixeles vecinos.
         * @param pImagen  es un puntero a la imagen que se quiere procesar.
         */
        void procesarImagen(Imagen *pImagen) override;
};
#endif // FILTROPASABAJOS_H

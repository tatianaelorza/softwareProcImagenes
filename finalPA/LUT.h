#ifndef LUT_H
#define LUT_H
#include <vector>
#include <string>
#include "imagen.h"

using namespace std;

class LUT
{
    public:
        LUT();

        /**
         * @brief pseudocolorear permite modificar los colores de los pixeles.
         * @param pImagen es un puntero a la imagen que se quiere pseudocolorear.
         */
        void pseudocolorear(Imagen *pImagen);

        /**
         * @brief leerArchivoLUT permite leer los dato de la tabla de conversión.
         * @param pNombreArchivoLUT es el nombre de la table de conversión que se leerá.
         */
        void leerArchivoLUT(string pNombreArchivoLUT);

    private:
        /**
         * @brief matrizLUT almacena los valores de los colores que formar la tabla de conversión.
         */
        vector<vector<float>> matrizLUT;

};
#endif // LUT_H

#ifndef IMAGEN_H
#define IMAGEN_H
#include <vector>
#include <string>

#include "pixel.h"

using namespace std;

class Imagen
{
    public:
        Imagen();
        /**
         * @brief generarMatriz permite generar la matriz imagen para poder representar la misma
         * @param pAltoImagen define la cantidad de filas de la matriz
         * @param pAnchoImagen define la cantidad de columnas que tendrá la matriz
         */
        void generarMatriz(int pAltoImagen, int pAnchoImagen);
        /**
         * @brief modificarRGBij permite modificar los tres valores de la terna de un pixel
         * en una ubicacion (i,j) de la matriz que forma una imagen.
         * @param i posición i del pixel que queremos modificar.
         * @param j posicion j del pixel que queremos modificar.
         * @param r nuevo valor para el color rojo.
         * @param g nuevo valor para el color verde.
         * @param b nuevo valor para el color azul.
         */
        void modificarRGBij(int pFila, int pColumna, float r, float g, float b);
        /**
         * @brief getMaxRangoDinamico permite retornar el valor máximo que puede
         *      tomar el rango dinamico de la imagen.
         * @return
         */
        int getMaxRangoDinamico();
        /**
         * @brief setMaxRangoDinamico permite establecer el valor máximo que puede
         *      tomar el rango dinamico de la imagen.
         * @param pRango será el valor máximo del rango dinamico de la imagen-
         */
        void setMaxRangoDinamico(int pRango);
        /**
         * @brief setAltoImagen permite modificar el valor del alto de la imagen,
         *      es decir, la cantidad de filas que tendra la matriz de la imagen.
         * @param pAltoImagen será el nuevo valor de altoImagen.
         */
        void setAltoImagen(int pAltoImagen);
        /**
         * @brief getAltoImagen permite retornar el valor del alto de la imagen.
         * @return retorna el valor entero que tiene el alto de la imagen.
         */
        int getAltoImagen();
        /**
         * @brief setAnchoImagen permite modificar el valor del ancho de la imagen,
         *      es decir, la cantidad de columnas que tendra la matriz de la imagen.
         * @param pAnchoImagen será el nuevo valor de anchoImagen.
         */
        void setAnchoImagen(int pAnchoImagen);
        /**
         * @brief getAnchoImagen permite retornar el valor del ancho de la imagen.
         * @return retorna el valor entero que tiene el ancho de la imagen.
         */
        int getAnchoImagen();
        /**
         * @brief setMetadatos permite modificar el valor de los metadatos en una imagen.
         * @param pMetadatos será el nuevo valor de los metadatos de la imagen.
         */
        void setMetadatos(string pMetadatos);
        /**
         * @brief getMetadatos permite retornar el valor de los metadatos de una imagen.
         * @return retorna el valor que tienen los metadatos de la imagen.
         */
        string getMetadatos();

        /**
         * @brief getPixel permite retornar un objeto de la clase Pixel en una ubicacion (i,j)
         *      dentro de la matrizImagen.
         * @param i será el valor dentro de las filas de la matriz donde se quiere obtener el Pixel.
         * @param j será el valor dentro de las columnas de la matriz donde se quiere obtener el Pixel.
         * @return retorna un objeto de la clase Pixel.
         */
        Pixel getPixel(int pFila, int pColumna);
        /**
         * @brief setPixel permite modificar el valor de un objeto de la clase Pixel que se encuentra
         *      en la posición (i,j) que pasemos como parametro.
         * @param i será la posición del nuevo Pixel dentro de las filas de la matrizImagen.
         * @param j será la posicion del nuevo Pixel dentro de las columas de la matrizImagen.
         * @param pPixel será el nuevo valor del pixel en la posición (i,j) dentro de la matrizImagen.
         */
        void setPixel(int pFila, int pColumna, Pixel pPixel);
        /**
         * @brief getValorR permite retornar el valor del color rojo en un pixel dentro de la matrizImagen
         *      en la posicion (i,j) que se señale.
         * @param pFila posición i del color rojo del pixel dentro de la matrizImagen.
         * @param pFila posición j del color rojo del pixel dentro de la matrizImagen.
         * @return retorna el valor flotante que tenga el color rojo en la posición (i,j) que se indique.
         */
        float getValorR(int pFila, int pColumna);
        /**
         * @brief getValorG permite retornar el valor del color verde en un pixel dentro de la matrizImagen
         *      en la posicion (i,j) que se señale.
         * @param pFila posición i del color verde del pixel dentro de la matrizImagen.
         * @param pFila posición j del color verde del pixel dentro de la matrizImagen.
         * @return retorna el valor flotante que tenga el color verde en la posición (i,j) que se indique.
         */
        float getValorG(int pFila, int pColumna);
        /**
         * @brief getValorB permite retornar el valor del color azul en un pixel dentro de la matrizImagen
         *      en la posicion (i,j) que se señale.
         * @param pFila posición i del color azul del pixel dentro de la matrizImagen.
         * @param pFila posición j del color azul del pixel dentro de la matrizImagen.
         * @return retorna el valor flotante que tenga el valor azul en la posición (i,j) que se indique.
         */
        float getValorB(int pFila, int pColumna);

        /**
         * @brief cambiarBrillo permite realizar un cambio en el brillo en la imagen
         * @param pCantBrillo parametro de cantidad de brillo que se desea cambiar
         */
        void cambiarBrillo(float pCantBrillo);
        /**
         * @brief ajustarContrasteImagen permite ajustar el contraste de la imagen
         */
        void ajustarContrasteImagen();
        /**
         * @brief negativizarImagen permite negativizar la imagen
         */
        void negativizarImagen();
        /**
         * @brief binarizarImagen
         * @param pIntensidad
         */
        void binarizarImagen(float pIntensidad);
        /**
         * @brief controlMaxRangoDinamico realiza un control en un pixel para saber si su valor
         *      se encuentra por debajo del rango dinamico y mayor a 0.
         * @param pfila posición i del pixel dentro de la matrizImagen.
         * @param pcolumna posición j del pixel dentro de la matrizImagen.
         */
        void controlMaxRangoDinamico(int pfila, int pcolumna);

        ~Imagen();
    private:
        /**
         * @brief imagen es la matriz de pixeles que hace a la imagen.
         */
        vector<vector<Pixel>> imagen;

        /**
         * @brief anchoImagen almacena la cantidad de pixeles de ancho que tiene la imagen.
         */
        int anchoImagen;
        /**
         * @brief altoImagen almacena la cantidad de pixeles de alto que tiene la imagen.
         */
        int altoImagen;
        /**
         * @brief metadatos almacena los metadatos extraidos del archivo de lectura de la imagen
         */
        string metadatos;

        /**
         * @brief maxRangoDinamico almacena el valor maximo del rango dinamico que puede tomar cada pixel
         */
        int maxRangoDinamico;

};
#endif // IMAGEN_H

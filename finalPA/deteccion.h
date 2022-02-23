#ifndef DETECCION_H
#define DETECCION_H


#include "imagen.h"

class Deteccion{
    public:
    Deteccion();

    /**
     * @brief procesarImagen
     * @param pFila
     * @param pColumna
     * @param pImagen
     */
    void procesarImagen(int pFila, int pColumna, Imagen *pImagen);
    /**
     * @brief algoritmoDelPintor analiza os pixeles vecinos al pixel central
     * y modifica los valores de la region de interes en función del resultado del analisis.
     * @param pFila es una fila en la imagen que se utiliza.
     * @param pColumna es una columna en la imagen que se utiliza.
     * @param pLado selecciona los pixeles vecinos que se van a analizar.
     */
    void algoritmoDelPintor(int pFila, int pColumna, char pLado);
    /**
     * @brief diferenciaColor permite retornar la diferencia de colores entre el pixel central y el pixel vecino.
     * @param pPixel1 es el pixel central.
     * @param pPixel2 es el pixel vecino.
     * @param maxRangoDinamico
     * @return devuelve un valor flotante que representa la diferencia de color entre los pixeles ya mencionados.
     */
    float diferenciaColor(Pixel pPixel1, Pixel pPixel2);
    /**
     * @brief getAreaPintada retorna el area pintada.
     * @return retorna un valor entero que representa la cantidad de pixeles pintados en la imagen.
     */
    int getAreaPintada();
    /**
     * @brief pintarImagen permite pintar la estructura detecada en la imagen.
     */
    void pintarImagen(Imagen *pImagen);

    private:

    /**
     * @brief regionInteres almacena información al respecto de los pixeles. Si fueron pintados,
     * esas posiciones tendrán un valor true.
     */
    vector<vector<bool>> mascara;
    /**
     * @brief auxImagen es un puntero que hace referencia a la imagen qie queremos procesar.
     */
    Imagen *auxImagen;

    /**
     * @brief pixelInicial es el pixel central, que se utilizar para comparar con los pixeles vecinos.
     */
    Pixel pixelInicial;

    /**
     * @brief areaPintada almacena información respecto de la cantidad de pixeles que fueron pintados.
     */
    int areaPintada=0;

    /**
     * @brief tolerancia permite establecer un rango de intensidades que serán detectadas como iguales.
     */
    float tolerancia;
};

#endif // DETECCION_H

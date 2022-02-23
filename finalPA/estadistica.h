#ifndef ESTADISTICA_H
#define ESTADISTICA_H
#include <vector>
#include <map>
#include <iostream>
#include <math.h>
#include <algorithm>
#include "imagen.h"

class Estadistica{
    public:
    Estadistica();

    /**
     * @brief setImagen permite utilizar una imagen para extraer los datos estadsiticos necesarios.
     * @param pImagen puntero a la imagen que se desea analizar.
     */
    void setImagen(Imagen *pImagen);

    /**
     * @brief getPromedio
     * @return retorna el atributo promedio.
     */
    float getPromedio();
    /**
     * @brief getDesviacionEstandar
     * @return retorna el atributo desviacionEstandar.
     */
    float getDesviacionEstandar();
    /**
     * @brief getValorMin
     * @return retorna el atributo valorMin.
     */
    float getValorMin();
    /**
     * @brief getCantidadVecesValorMin.
     * @return retorna la cantidad de veces que se repite la intensidad minima.
     */
    int getCantidadVecesValorMin();
    /**
     * @brief getValorMax
     * @return retorna el atributo valorMax.
     */
    float getValorMax();
    /**
     * @brief getCantidadVecesValorMax
     * @return retorna la cantidad de veces que se repite la intensidad máxima.
     */
    int getCantidadVecesValorMax();
    /**
     * @brief getModa
     * @return retorna el valor más repetido.
     */
    float getModa();
    /**
     * @brief getVecesValorMasRepetido
     * @return retorna el atributo
     */
    int getVecesValorMasRepetido();

    /**
     * @brief getValorRojoMasRepetido
     * @return retorna el valor rojo más repetido en la imagen.
     */
    float getValorRojoMasRepetido();
    /**
     * @brief getVecesValorRojoMasRepetido
     * @return retorna la cantidad de veces que se repite el valor rojo más repetido.
     */
    int getVecesValorRojoMasRepetido();
    /**
     * @brief getValorAzulMasRepetido
     * @return retorna el valor azul más repetido en la imagen.
     */
    float getValorAzulMasRepetido();
    /**
     * @brief getVecesValorAzulMasRepetido
     * @return retorna la cantidad de veces que se repite el valor azul más repetido.
     */
    int getVecesValorAzulMasRepetido();
    /**
     * @brief getValorVerdeMasRepetido
     * @return retorna el valor verde más repetido en la imagen.
     */
    float getValorVerdeMasRepetido();
    /**
     * @brief getVecesValorVerdeMasRepetido
     * @return retorna la cantidad de veces que se repito el valor verde más repetido.
     */
    int getVecesValorVerdeMasRepetido();

    /**
     * @brief getRepeticionesPromedioIntensidades
     * @return retorna un vector que contiene las veces que se repite cada valor promedio.
     */
    vector<int> getRepeticionesPromedioIntensidades();
    /**
     * @brief getRepeticionesValoresR
     * @return retorna un vector que contiene las veces que se repite cada valor del color rojo.
     */
    vector<int> getRepeticionesValoresR();
    /**
     * @brief getRepeticionesValoresG
     * @return retorna retorna un vector que contiene las veces que se repite cada valor del color verde.
     */
    vector<int> getRepeticionesValoresG();
    /**
     * @brief getRepeticionesValoresB
     * @return retorna un vector que contiene las veces que se repite cada valor del color azul.
     */
    vector<int> getRepeticionesValoresB();

    void informarDatos();
    /**
     * @brief procesarImagen
     */
    void procesarImagen();

    private:

         /**
         * @brief promedioIntensidades almacena la intensidad promedio de los tres colores de cada uno de los pixeles,
        ///     donde la clave es la cuantificación de la intensidad y el valor representa la cantidad
        ///     de veces que dicho valor se repite. Se utiliza para los calculos estadistico
         */
        map<float, int> promedioIntensidades;

        /**
        * @brief valoresR almacena información del color rojo, lo principal es la
        ///     cuantificación de este color y el valor representa la cantidad de veces que dicho
        ///     valor se repite. Se utiliza para los calculos estadisticos
        */
        map<float, int> valoresR;

        /**
        * @brief valoresG almacena información del color verde, lo principal es la
        ///     cuantificación de este color y el valor representa la cantidad de veces que dicho
        ///     valor se repite. Se utiliza para los calculos estadisticos
        */
        map<float, int> valoresG;

        /**
        * @brief valoresB almacena información del color azul, lo principal es la
        ///     cuantificación de este color y el valor representa la cantidad de veces que dicho
        ///     valor se repite. Se utiliza para los calculos estadisticos
        */
        map<float, int> valoresB;

        /**
         * @brief vectorRepeticionesPromedioIntensidades se almacena la cantidad de veces que
         * se repite cada promedio de intensidad.
         */
        vector<int> vectorRepeticionesPromedioIntensidades;
        /**
         * @brief vectorRepeticionesValoresR se almacena la cantidad de veces que se repite
         *      cada valor del color rojo.
         */
        vector<int> vectorRepeticionesValoresR;
        /**
         * @brief vectorRepeticionesValoresG se almacena la cantidad de veces que se repite
         *      cada valor del color verde.
         */
        vector<int> vectorRepeticionesValoresG;
        /**
         * @brief vectorRepeticionesValoresB se almacena la cantidad de veces que se repite
         *      cada valor del color azul.
         */
        vector<int> vectorRepeticionesValoresB;
        /**
         * @brief auxiliarModa permite alojar las modas del valor rojo, verde, azul y el promedio de intensidad.
         */
        vector<int> auxiliarModa;
        /**
         * @brief promedio almacena la intesidad promedio de un pixel.
         */
        float promedio=0;
        /**
         * @brief valorMin almacena el valor mínimo de intensidad de un pixel en toda la imagen.
         */
        float valorMin = 0;
        /**
         * @brief valorMax almacena el valor máximo de intensidad de un pixel en toda la imagen.
         */
        float valorMax = 0;
        /**
         * @brief valorMasRepetidoIntensidadPromedio almacena el valor de intensidad que más se repite en toda la imagen.
         */
        float valorMasRepetidoIntensidadPromedio = 0;
        /**
         * @brief desviacionEstandar almacena el valor de la desviación estandar.
         */
        float desviacionEstandar=0;
        /**
         * @brief valorRojoMasRepetido almacena el valor del color rojo que más se repite en toda la imagen.
         */
        float valorRojoMasRepetido = 0;
        /**
         * @brief valorVerdeMasRepetido almacena el valor del color verde que más se repite en toda la imagen.
         */
        float valorVerdeMasRepetido = 0;
        /**
         * @brief valorAzulMasRepetido almacena el valor del color azul que más se repite en toda la imagen.
         */
        float valorAzulMasRepetido = 0;
        /**
         * @brief valorMasRepetido almacena el valor de rojo, verde, azul o promedio que más se repite en toda la imagen.almacena el valor de rojo, verde, azul o promedio que más se repite en toda la imagen.
         */
        float valorMasRepetido=0;
        /**
         * @brief vecesValorMin almacena la cantidad de veces que se repite el atributo valorMin.
         */
        int vecesValorMin = 0;
        /**
         * @brief vecesValorMax almacena la cantidad de veces que se repite el atributo valorMax.
         */
        int vecesValorMax = 0;
        /**
         * @brief vecesValorMasRepetidoIntensidadPromedio almacena la cantidad de veces que se repite el atributo valorMasRepetido.
         */
        int vecesValorMasRepetidoIntensidadPromedio = 0;
        /**
         * @brief vecesValorRojoMasRepetido almacena la cantidad de veces que se repite el atributo valorRojoMasRepetido.
         */
        int vecesValorRojoMasRepetido = 0;
        /**
         * @brief vecesValorVerdeMasRepetido almacena la cantidad de veces que se repite el atributo valorVerdeMasRepetido.
         */
        int vecesValorVerdeMasRepetido = 0;
        /**
         * @brief vecesValorAzulMasRepetido almacena la cantidad de veces que se repite el atributo valorAzulMasRepetido.
         */
        int vecesValorAzulMasRepetido = 0;
        /**
         * @brief vecesValorMasRepetido almacena la cantidad de veces que se repite el atributo valorMasRepetido.
         */
        int vecesValorMasRepetido = 0;
        /**
         * @brief imagen es la imagen de interes.
         */
        Imagen *imagen=NULL;
};
#endif // ESTADISTICA_H

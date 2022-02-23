#ifndef PIXEL_H
#define PIXEL_H
#include <vector>

using namespace std;

class Pixel
{
    public:
        Pixel();

        /**
         * @brief getRGB permite retornar el atributo RGB.
         * @return retorna un vector de valores flotantes que contienen los valores de los colores RGB (red (rojo), green (verde) y blue (azul).
         */
        vector<float> getRGB();
        /**
         * @brief modificarRGB modificar el vector con los tres valores que toma cada pixel.
         * @param r este será el nuevo valor del color rojo.
         * @param g este será el nuevo valor del color verde.
         * @param b este será el nuevo valor del color azul.
         */
        void modificarRGB(float r, float g, float b);

        /**
         * @brief setR permite modificar el valor red (color rojo) del vector RGB.
         * @param r este será el nuevo valor del color rojo.
         */
        void setR(float r);
        /**
         * @brief getR permite retornar el valor red (color rojo) del vector RGB.
         * @return Retorna un valor flotante que reprenseta el valor del color rojo.
         */
        float getR();
        /**
         * @brief setG permite modificar el valor green (color verde) del vector RGB.
         * @param g este será el nuevo valor del color verde.
         */
        void setG(float g);
        /**
         * @brief getG permite retornar el valor green (color verde) del vector RGB.
         * @return Retorna un valor flotante que reprenseta el valor del color verde.
         */
        float getG();
        /**
         * @brief setB permite modificar el valor blue (color azul) del vector RGB.
         * @param b este será el nuevo valor del color azul.
         */
        void setB(float b);
        /**
         * @brief getB permite retornar el valor blue (color azul) del vector RGB.
         * @return Retorna un valor flotante que reprenseta el valor del color azul.
         */
        float getB();
        /**
         * @brief operator ==
         * @param pPixel
         * @return
         */
        bool operator==(Pixel pPixel);
        /**
         * @brief      operator + permite retornar un pixel el cual será la suma de los componentes de dos pixeles.
         * @param      pPixel será el pixel actue como el sumando.
         * @return     Retorna un pixel que representa la suma de dos pixeles.
         */
        Pixel operator+(Pixel pPixel);
        /**
         * @brief      operator - permite retornar un pixel el cual será la resta de los componentes de dos pixeles.
         * @param      pPixel será el pixel actue como el sustraendo.
         * @return     Retorna un pixel que representa la resta de dos pixeles.
         */
        Pixel operator-(Pixel pPixel);
        /**
         * @brief operator * permite retornar un pixel que será la solución de la multiplicación de un pixel por un valor flotante.
         * @param pValor será el valor flotante por el cual se multiplicará el valor.
         * @return Retorna un pixel que representa la multiplicación del pixel por el valor flotante.
         */
        Pixel operator*(float pValor);

    private:
        /**
         * @brief RGB almacena los valores de red, green y blue que componen el color de un pixel.
         */
        vector<float> RGB;

};
#endif // PIXEL_H

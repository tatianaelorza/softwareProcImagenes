#include "pixel.h"
Pixel::Pixel()
{
   RGB.resize(3);
}
vector<float> Pixel::getRGB()
{
    return RGB;
}
void Pixel::modificarRGB(float r, float g, float b)
{
    RGB[0] = r;
    RGB[1] = g;
    RGB[2] = b;
}
void Pixel::setR(float r)
{
    RGB[0] = r;
}
float Pixel::getR()
{
    return RGB[0];
}
void Pixel::setG(float g)
{
    RGB[1] = g;
}
float Pixel::getG()
{
    return RGB[1];
}
void Pixel::setB(float b)
{
    RGB[2] = b;
}
float Pixel::getB()
{
    return RGB[2];
}

Pixel Pixel::operator+(Pixel pPixel)
{
    float r = RGB[0] + pPixel.getR();
    float g = RGB[1] + pPixel.getG();
    float b = RGB[2] + pPixel.getB();

    Pixel nuevoPixel;
    nuevoPixel.setR(r);
    nuevoPixel.setG(g);
    nuevoPixel.setB(b);

    return (nuevoPixel);
}
Pixel Pixel::operator-(Pixel pPixel)
{
    int r = RGB[0] - pPixel.getR();
    int g = RGB[1] - pPixel.getG();
    int b = RGB[2] - pPixel.getB();

    Pixel nuevoPixel;
    nuevoPixel.setR(r);
    nuevoPixel.setG(g);
    nuevoPixel.setB(b);

    return (nuevoPixel);
}
Pixel Pixel::operator*(float pValor)
{
    int r = RGB[0] * pValor;
    int g = RGB[1] * pValor;
    int b = RGB[2] * pValor;

    Pixel nuevoPixel;
    nuevoPixel.setR(r);
    nuevoPixel.setG(g);
    nuevoPixel.setB(b);

    return (nuevoPixel);
}

#include "deteccion.h"
#include <cmath>
Deteccion::Deteccion(){

}
void Deteccion::procesarImagen(int pFila, int pColumna, Imagen *pImagen)
{
    mascara.clear();
    auxImagen=pImagen;

    mascara.resize(pImagen->getAltoImagen(), vector<bool>(pImagen->getAnchoImagen(),false));
    tolerancia =0.15;
    pixelInicial=pImagen->getPixel(pFila,pColumna);
    algoritmoDelPintor(pFila,pColumna,1);
    algoritmoDelPintor(pFila,pColumna-1,2);

    pintarImagen(pImagen);
}
void Deteccion::algoritmoDelPintor(int pFila, int pColumna, char pLado)
{
    int &fila = pFila;

    int &columna = pColumna;

    if(fila < auxImagen->getAltoImagen() && columna < auxImagen->getAnchoImagen())
    {
        if(diferenciaColor(pixelInicial, auxImagen->getPixel(pFila, pColumna))<= tolerancia && mascara[fila][columna]==false)
        {
            mascara[fila][columna] = true;
            ++areaPintada;

            if(pLado == 1)
            {
                algoritmoDelPintor(fila-1,columna-1,pLado);
                algoritmoDelPintor(fila-1,columna,pLado);
                algoritmoDelPintor(fila-1,columna+1,pLado);
                algoritmoDelPintor(fila,columna+1,pLado);
                algoritmoDelPintor(fila+1,columna+1,pLado);
            }else if(pLado == 2)
            {
                algoritmoDelPintor(fila-1,columna-1,pLado);
                algoritmoDelPintor(fila+1,columna,pLado);
                algoritmoDelPintor(fila+1,columna-1,pLado);
                algoritmoDelPintor(fila,columna-1,pLado);
                algoritmoDelPintor(fila+1,columna+1,pLado);
            }
        }
    }
}
int Deteccion::getAreaPintada()
{
    return areaPintada;
}
void Deteccion::pintarImagen(Imagen *pImagen)
{
    Pixel pixel;
    for(int i = 0; i<pImagen->getAltoImagen(); i++)
    {
        for(int j = 0; j<pImagen->getAnchoImagen(); j++)
        {
            pixel = pImagen->getPixel(i,j);

            if(mascara[i][j] == true)
            {
               auxImagen->modificarRGBij(i,j,255.0,255.0,0.0);
            }
        }
    }
}
float Deteccion::diferenciaColor(Pixel pPixel1, Pixel pPixel2)
{
    float aux=0.0;
    aux=(pPixel1.getR()-pPixel2.getR())*(pPixel1.getR()-pPixel2.getR())+((pPixel1.getG()-pPixel2.getG())*(pPixel1.getG()-pPixel2.getG()))+((pPixel1.getB()-pPixel2.getB())*pPixel1.getB()-pPixel2.getB());

    sqrt(aux);

    return aux;
}

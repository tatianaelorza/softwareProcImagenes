#include "imagen.h"
#include <algorithm>

Imagen::Imagen()
{

}
void Imagen::generarMatriz(int pAltoImagen, int pAnchoImagen)
{
    setAltoImagen(pAltoImagen);
    setAnchoImagen(pAnchoImagen);

    imagen.resize(getAltoImagen());

    for(int i=0;i<getAltoImagen();i++)
    {
        imagen[i].resize(getAnchoImagen());
    }
}
void Imagen::setAltoImagen(int pAltoImagen)
{
    altoImagen= pAltoImagen;
}
int Imagen::getAltoImagen()
{
    return altoImagen;
}
void Imagen::setAnchoImagen(int pAnchoImagen)
{
    anchoImagen= pAnchoImagen;
}
int Imagen::getAnchoImagen()
{
    return anchoImagen;
}
void Imagen::setMetadatos(string pMetadatos)
{
    metadatos= pMetadatos;
}
string Imagen::getMetadatos()
{
    return metadatos;
}
Pixel Imagen::getPixel(int pFila, int pColumna)
{
    return imagen[pFila][pColumna];
}
void Imagen::setPixel(int pFila, int pColumna, Pixel pPixel)
{
    modificarRGBij(pFila,pColumna,pPixel.getR(),pPixel.getG(),pPixel.getB());
}
void Imagen::setMaxRangoDinamico(int pRango)
{
    maxRangoDinamico = pRango;
}
int Imagen::getMaxRangoDinamico()
{
    return maxRangoDinamico;
}
void Imagen::modificarRGBij(int pFila, int pColumna, float r, float g, float b)
{
    imagen[pFila][pColumna].setR(r);
    imagen[pFila][pColumna].setG(g);
    imagen[pFila][pColumna].setB(b);
}
float Imagen::getValorR(int pFila, int pColumna)
{
    return (imagen[pFila][pColumna].getRGB()[0]);
}
float Imagen::getValorG(int pFila, int pColumna)
{
    return (imagen[pFila][pColumna].getRGB()[1]);
}
float Imagen::getValorB(int pFila, int pColumna)
{
    return (imagen[pFila][pColumna].getRGB()[2]);
}
void Imagen::cambiarBrillo(float pCantBrillo)
{
    for(int i=0; i<getAltoImagen(); i++)
    {
        for(int j=0; j<getAnchoImagen(); j++)
        {
            float auxR= imagen[i][j].getR()+pCantBrillo;
            float auxG= imagen[i][j].getG()+pCantBrillo;
            float auxB= imagen[i][j].getB()+pCantBrillo;

            modificarRGBij(i,j,auxR,auxG,auxB);
            controlMaxRangoDinamico(i,j);
        }
    }
}
void Imagen::ajustarContrasteImagen()
{
    vector<vector<Pixel>> auxiliarImagen;

    float valorMin, valorMax;

    float valorR, valorG, valorB, promedio;

    vector<float> auxiliarRGB;

    auxiliarRGB.resize(0);

    for(int i = 0; i<getAltoImagen();++i)
    {
        for(int j = 0; j<getAnchoImagen();j++)
        {
            valorR = getValorR(i,j);
            valorG = getValorG(i,j);
            valorB = getValorB(i,j);

            promedio = (valorR+valorG+valorB)/3.0f;

            auxiliarRGB.push_back(promedio);
        }
    }

    valorMin = *min_element(auxiliarRGB.begin(),auxiliarRGB.end());

    valorMax = *max_element(auxiliarRGB.begin(),auxiliarRGB.end());

    for(int i = 0; i<altoImagen; i++)
    {
        for(int j = 0; j<anchoImagen; j++)
        {
            modificarRGBij(i,j, (float)((getValorR(i,j) - valorMin)/(valorMax - valorMin))*getMaxRangoDinamico(),
                    (float)((getValorG(i,j) - valorMin)/(valorMax - valorMin))*getMaxRangoDinamico(),
                    (float)((getValorB(i,j) - valorMin)/(valorMax - valorMin))*getMaxRangoDinamico());
            controlMaxRangoDinamico(i,j);
        }
    }
}
void Imagen::negativizarImagen()
{
    int r=0, g=0, b=0;

    for(int i= 0; i < getAltoImagen(); i++)
    {
        for(int j = 0; j < getAnchoImagen(); j++)
        {
            r = getMaxRangoDinamico() - getPixel(i,j).getR();
            g = getMaxRangoDinamico() - getPixel(i,j).getG();
            b = getMaxRangoDinamico() - getPixel(i,j).getB();

            modificarRGBij(i,j,r,g,b);
            controlMaxRangoDinamico(i,j);
        }
    }
}
void Imagen::binarizarImagen(float pIntensidad)
{
    float auxIntensidad= (float)maxRangoDinamico*(pIntensidad/100.0);
    float valorR, valorG, valorB, promedio;
    for(int i=0;i<altoImagen;i++)
    {
        for(int j=0;j<anchoImagen;j++)
        {
            valorR=getValorR(i,j);
            valorG=getValorG(i,j);
            valorB=getValorB(i,j);

            promedio=(valorR+valorG+valorB)/3.0;

            if(promedio>=auxIntensidad)
            {
                modificarRGBij(i,j,255.0,255.0,255.0);
            }else
            {
                modificarRGBij(i,j,0.0,0.0,0.0);
            }
        }
    }
}
void Imagen::controlMaxRangoDinamico(int pfila, int pcolumna)
{
    float R,G,B;

    R=getPixel(pfila,pcolumna).getR();
    G=getPixel(pfila,pcolumna).getG();
    B=getPixel(pfila,pcolumna).getB();

    if(R>(float)maxRangoDinamico)
    {
        R=(float)maxRangoDinamico;
    }else if(R<0.0)
    {
        R=0.0;
    }else if(G>(float)maxRangoDinamico)
    {
        G=(float)maxRangoDinamico;
    }else if(G<0.0)
    {
        G=0.0;
    }else if(B>(float)maxRangoDinamico)
    {
        B=(float)maxRangoDinamico;
    }else if(B<0.0)
    {
        B=0.0;
    }

    modificarRGBij(pfila,pcolumna,R,G,B);
}
Imagen::~Imagen()
{

}

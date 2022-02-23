#include "filtroMediana.h"
#include <algorithm>
FiltroMediana::FiltroMediana()
{

}
void FiltroMediana::procesarImagen(Imagen *pImagen)
{

    vector<float> auxiliarColorR;
    auxiliarColorR.resize(0);
    vector<float> auxiliarColorG;
    auxiliarColorG.resize(0);
    vector<float> auxiliarColorB;
    auxiliarColorB.resize(0);

    float medianaR,medianaG,medianaB;

    for(int i = 1; i<pImagen->getAltoImagen()-1; i++)
    {
        for(int j = 1; j<pImagen->getAnchoImagen()-1; j++)
        {

            auxiliarColorR.clear();
            auxiliarColorR.push_back(pImagen->getPixel(i, j).getR());
            auxiliarColorR.push_back(pImagen->getPixel(i-1, j-1).getR());
            auxiliarColorR.push_back(pImagen->getPixel(i-1, j).getR());
            auxiliarColorR.push_back(pImagen->getPixel(i-1, j+1).getR());
            auxiliarColorR.push_back(pImagen->getPixel(i, j+1).getR());
            auxiliarColorR.push_back(pImagen->getPixel(i+1, j+1).getR());
            auxiliarColorR.push_back(pImagen->getPixel(i+1, j).getR());
            auxiliarColorR.push_back(pImagen->getPixel(i+1, j-1).getR());
            auxiliarColorR.push_back(pImagen->getPixel(i, j-1).getR());

            sort(auxiliarColorR.begin(),auxiliarColorR.end());

            medianaR = auxiliarColorR[auxiliarColorR.size()/2];

            auxiliarColorG.clear();
            auxiliarColorG.push_back(pImagen->getPixel(i, j).getG());
            auxiliarColorG.push_back(pImagen->getPixel(i-1, j-1).getG());
            auxiliarColorG.push_back(pImagen->getPixel(i-1, j).getG());
            auxiliarColorG.push_back(pImagen->getPixel(i-1, j+1).getG());
            auxiliarColorG.push_back(pImagen->getPixel(i, j+1).getG());
            auxiliarColorG.push_back(pImagen->getPixel(i+1, j+1).getG());
            auxiliarColorG.push_back(pImagen->getPixel(i+1, j).getG());
            auxiliarColorG.push_back(pImagen->getPixel(i+1, j-1).getG());
            auxiliarColorG.push_back(pImagen->getPixel(i, j-1).getG());

            sort(auxiliarColorG.begin(),auxiliarColorG.end());

            medianaG = auxiliarColorG[auxiliarColorG.size()/2];

            auxiliarColorB.clear();
            auxiliarColorB.push_back(pImagen->getPixel(i, j).getB());
            auxiliarColorB.push_back(pImagen->getPixel(i-1, j-1).getB());
            auxiliarColorB.push_back(pImagen->getPixel(i-1, j).getB());
            auxiliarColorB.push_back(pImagen->getPixel(i-1, j+1).getB());
            auxiliarColorB.push_back(pImagen->getPixel(i, j+1).getB());
            auxiliarColorB.push_back(pImagen->getPixel(i+1, j+1).getB());
            auxiliarColorB.push_back(pImagen->getPixel(i+1, j).getB());
            auxiliarColorB.push_back(pImagen->getPixel(i+1, j-1).getB());
            auxiliarColorB.push_back(pImagen->getPixel(i, j-1).getB());

            sort(auxiliarColorB.begin(),auxiliarColorB.end());

            medianaB = auxiliarColorB[auxiliarColorB.size()/2];

            pImagen->modificarRGBij(i,j,medianaR,medianaG,medianaB);
            pImagen->controlMaxRangoDinamico(i,j);
        }
    }

}

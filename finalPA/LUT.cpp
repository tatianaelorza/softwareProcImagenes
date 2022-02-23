#include "LUT.h"
#include <fstream>
#include <iostream>
using namespace std;

LUT::LUT()
{

}
void LUT::pseudocolorear(Imagen *pImagen)
{
    for(int i = 0; i<pImagen->getAltoImagen(); i++)
    {
        for(int j = 0; j<pImagen->getAnchoImagen(); j++)
        {
            pImagen->modificarRGBij(i,j,matrizLUT[pImagen->getPixel(i, j).getR()][1],matrizLUT[pImagen->getPixel(i, j).getG()][2],matrizLUT[pImagen->getPixel(i, j).getB()][3]);
            pImagen->controlMaxRangoDinamico(i,j);
        }
    }
}
void LUT::leerArchivoLUT(string pNombreArchivoLUT)
{
    matrizLUT.resize(256);

    for(unsigned int i = 0; i<matrizLUT.size();i++)
    {
        matrizLUT[i].resize(4);
    }

    ifstream archivoLUT;
    archivoLUT.open(pNombreArchivoLUT.c_str());
    string auxiliarLectura;

    if(archivoLUT.is_open())
    {
        getline(archivoLUT, auxiliarLectura, '\n');

        for(unsigned int i = 0; i<256;i++)
        {
            for(unsigned int j = 0; j<4;j++)
            {
                archivoLUT>>matrizLUT[i][j];
            }
        }
    }else
    {
        cout<<"no se pudo abrir el archivo";
    }
    archivoLUT.close();
};

#include "filtroPasaBajos.h"

FiltroPasaBajos::FiltroPasaBajos()
{

}

void FiltroPasaBajos::procesarImagen(Imagen *pImagen)
{
    float auxKernel = 0.11;

    Imagen auxImagen = *pImagen;

    Pixel auxPixel, nuevoPixel;

    for(int i = 1; i<auxImagen.getAltoImagen()-1; i++)
    {
        for(int j = 1; j<auxImagen.getAnchoImagen()-1; j++)
        {
            auxPixel = pImagen->getPixel(i,j) + pImagen->getPixel(i-1,j-1)
                    + pImagen->getPixel(i-1,j) + pImagen->getPixel(i-1,j+1)
                    + pImagen->getPixel(i,j+1) + pImagen->getPixel(i+1,j+1)
                    + pImagen->getPixel(i+1,j) + pImagen->getPixel(i+1,j-1)
                    + pImagen->getPixel(i,j-1);

            nuevoPixel = auxPixel*auxKernel;
            auxImagen.modificarRGBij(i,j,nuevoPixel.getR(),nuevoPixel.getG(),nuevoPixel.getB());
            auxImagen.controlMaxRangoDinamico(i,j);
        }
    }
    *pImagen = auxImagen;
}

#include "filtroPasaAltos.h"

FiltroPasaAltos::FiltroPasaAltos()
{

}
void FiltroPasaAltos::procesarImagen(Imagen *pImagen)
{
    Imagen auxImagen = *pImagen;
    Pixel auxPixel, nuevoPixel;

    for(int i = 1; i<auxImagen.getAltoImagen()-1; i++)
    {
        for(int j = 1; j<auxImagen.getAnchoImagen()-1; j++)
        {
            nuevoPixel = pImagen->getPixel(i, j)*(5.0)
                    - pImagen->getPixel(i-1,j)
                    - pImagen->getPixel(i,j-1)
                    - pImagen->getPixel(i,j+1)
                    - pImagen->getPixel(i+1,j);

            auxImagen.setPixel(i,j,nuevoPixel);
            auxImagen.controlMaxRangoDinamico(i,j);
        }
    }
    *pImagen = auxImagen;
}

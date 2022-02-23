#include "archivoAIC.h"

ArchivoAIC::ArchivoAIC()
{

}
Imagen ArchivoAIC::leer(string pNombreArchivo)
{
    Imagen imagenAux;

    unsigned int cantFilas, cantColumnas, maxValorRangoDinamico, auxPosInicial, auxPosFinal, auxPos;

    unsigned int valorIntensidad, repeticion;

    string metadatos, auxMetadatos, auxColumnas, auxFilas;

    ifstream archivoAIC;

    archivoAIC.open(pNombreArchivo.c_str());

    if(archivoAIC.is_open())
    {

        getline(archivoAIC,tipoArchivo,'\n');
        getline(archivoAIC,metadatos,'\n');

        auxPosInicial = metadatos.find("maximo valor del rango dinamico:");
        auxMetadatos = metadatos.substr(auxPosInicial);

        auxPosInicial = auxMetadatos.find(',',0);
        auxMetadatos.erase(auxPosInicial);
        auxMetadatos.erase(0,32);

        maxValorRangoDinamico = stoi(auxMetadatos);

        auxPosInicial = metadatos.find("columnas:");
        auxPosFinal = metadatos.find(",filas:");
        auxMetadatos = metadatos.substr(auxPosInicial, auxPosFinal);

        auxColumnas = auxMetadatos.substr(auxMetadatos.find(':')+1);
        auxFilas = auxMetadatos.substr(auxMetadatos.find("filas:"));

        auxPos = auxColumnas.find(',');
        auxColumnas = auxColumnas.erase(auxPos, auxColumnas.size());
        cantColumnas = stoi(auxColumnas);

        auxPos = auxFilas.find("filas:");
        auxFilas = auxFilas.erase(auxPos, 6);

        auxPos = auxFilas.find('}');
        auxFilas = auxFilas.erase(auxPos, 1);
        cantFilas = stoi(auxFilas);

        try {
            if(cantColumnas == 0 || cantFilas == 0)
            {
                throw cantColumnas;
            }

        } catch (int cantColumnas) {
            cout<<"No es posible realizar la lectura del archivo ya que es un archivo corrupto";
            exit(0);
        }

        imagenAux.generarMatriz(cantFilas,cantColumnas);
        imagenAux.setMaxRangoDinamico(maxValorRangoDinamico);
        imagenAux.setMetadatos(metadatos);

        archivoAIC>>valorIntensidad>>repeticion;

        for(int i = 0; i<imagenAux.getAltoImagen(); ++i)
        {
            for(int j = 0; j<imagenAux.getAnchoImagen(); ++j)
            {
                if(repeticion == 0)
                {
                    archivoAIC>>valorIntensidad>>repeticion;
                }
                imagenAux.getPixel(i,j).modificarRGB(valorIntensidad,valorIntensidad,valorIntensidad);
                imagenAux.controlMaxRangoDinamico(i,j);
                repeticion--;
            }
        }
    }

    archivoAIC.close();
    return imagenAux;
}
void ArchivoAIC::escribir(string pNombreArchivo, Imagen *imagen_, int pTipoArchivo_)
{

    pNombreArchivo = pNombreArchivo + ".aic";

    string auxMetadatos;

    int auxPosMetadatos, auxContador = 0;

    float intensidadPromedio, intensidadPromedioComparar;

    ofstream archivoAIC(pNombreArchivo.c_str());


    if(archivoAIC.is_open())
    {
        archivoAIC<<"P2C\n";
        auxMetadatos = imagen_->getMetadatos();
        auxPosMetadatos = auxMetadatos.find("comprimido:no");
        auxMetadatos.replace(auxPosMetadatos,13,"comprimido:si");

        auxPosMetadatos = auxMetadatos.find("}");
        auxMetadatos.erase(auxPosMetadatos,1);

        auxMetadatos.insert(auxMetadatos.size(),",maximo valor del rango dinamico:");
        auxMetadatos = auxMetadatos + to_string(imagen_->getMaxRangoDinamico());
        auxMetadatos.insert(auxMetadatos.size(), ",columnas:");

        auxMetadatos = auxMetadatos + to_string(imagen_->getAnchoImagen());
        auxMetadatos.insert(auxMetadatos.size(), ",filas:");

        auxMetadatos = auxMetadatos + to_string(imagen_->getAltoImagen());
        auxMetadatos.insert(auxMetadatos.size(),"}");

        archivoAIC<<auxMetadatos;
        archivoAIC<<"\n";

        intensidadPromedio = (imagen_->getPixel(0,0).getR())/3.0;

        for(int i = 0; i<imagen_->getAltoImagen();++i)
        {
            for(int j = 0; j<imagen_->getAnchoImagen();++j)
            {
                intensidadPromedioComparar = (imagen_->getPixel(i,j).getR())/3.0f;
                if(intensidadPromedio == intensidadPromedioComparar)
                {
                    ++auxContador;
                }
                else
                {
                    archivoAIC<<intensidadPromedio<<" "<<auxContador<<" ";
                    intensidadPromedio = intensidadPromedioComparar;
                    auxContador = 1;
                }
            }
            archivoAIC<<intensidadPromedio<<" "<<auxContador<<" ";
            auxContador = 0;
            archivoAIC<<"\n";
        }
    }

    archivoAIC.close();
}
string ArchivoAIC::getTipoArchivo()
{
    return tipoArchivo;
}
ArchivoAIC::~ArchivoAIC()
{

}

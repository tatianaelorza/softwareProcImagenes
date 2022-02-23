#include "archivoPNM.h"

ArchivoPNM::ArchivoPNM()
{

}
Imagen ArchivoPNM::leer(string pNombreArchivo)
{
    Imagen auxImagen;
    int filas, columnas, maxRangoDinamico;

    float valorR = 0 , valorG = 0 , valorB = 0, valorGris = 0;

    string metadatos, auxNombreArchivo, auxPosicion;

    ifstream archivoPNM;
    archivoPNM.open(pNombreArchivo.c_str());

    if(archivoPNM.is_open())
    {
        getline(archivoPNM,tipoArchivo,'\n');
        if("P1" == tipoArchivo)
        {

            int pixelMonocromatico=0;

            getline(archivoPNM, metadatos,'\n');
            archivoPNM>>columnas;
            archivoPNM>>filas;

            try {
                if(columnas == 0 || filas == 0)
                {
                    throw columnas;
                }

            } catch (int columnas) {
                cout<<"No es posible realizar la lectura del archivo ya que es un archivo corrupto";
                exit(0);
            }

            auxImagen.generarMatriz(filas, columnas);
            auxImagen.setMetadatos(metadatos);

            for(int i=0;i<filas;i++)
            {
               for(int j=0; j < columnas;j++)
               {
                   archivoPNM>>pixelMonocromatico;
                   auxImagen.modificarRGBij(i,j,pixelMonocromatico,pixelMonocromatico,pixelMonocromatico);
                   auxImagen.controlMaxRangoDinamico(i,j);
               }
            }

        }
        else if("P2" == tipoArchivo)
        {

            int intensidad=0;

            getline(archivoPNM, metadatos,'\n');
            archivoPNM>>columnas;
            archivoPNM>>filas;
            archivoPNM>>maxRangoDinamico;
            getline(archivoPNM, auxPosicion,'\n');

            try {
                if(columnas == 0 || filas == 0)
                {
                    throw columnas;
                }

            } catch (int columnas) {
                cout<<"No es posible realizar la lectura del archivo ya que es un archivo corrupto";
                exit(0);
            }

            auxImagen.generarMatriz(filas, columnas);
            auxImagen.setMaxRangoDinamico(maxRangoDinamico);
            auxImagen.setMetadatos(metadatos);

            for(int j = 0; j<auxImagen.getAnchoImagen();++j)
            {
                for(int i = 0; i<auxImagen.getAltoImagen();++i)
                {
                    archivoPNM>>intensidad;
                    auxImagen.modificarRGBij(i,j,intensidad,intensidad,intensidad);
                    auxImagen.controlMaxRangoDinamico(i,j);
                }
            }

        }
        else if ("P3" == tipoArchivo)
        {

            unsigned int r=0;
            unsigned int g=0;
            unsigned int b=0;


            getline(archivoPNM, metadatos,'\n');
            archivoPNM>>columnas;
            cout<<"columnas: "<<columnas;
            archivoPNM>>filas;
            cout<<"filas: "<<filas;
            archivoPNM>>maxRangoDinamico;
            getline(archivoPNM, auxPosicion,'\n');

            try {
                if(columnas == 0 || filas == 0)
                {
                    throw columnas;
                }

            } catch (int columnas) {
                cout<<"No es posible realizar la lectura del archivo ya que es un archivo corrupto";
                exit(0);
            }

            auxImagen.generarMatriz(filas, columnas);
            auxImagen.setMaxRangoDinamico(maxRangoDinamico);
            auxImagen.setMetadatos(metadatos);

            for(int i = 0; i<auxImagen.getAltoImagen();++i)
            {
                for(int j = 0; j<auxImagen.getAnchoImagen();++j)
                {
                    archivoPNM>>r>>g>>b;

                    valorR=(float)r;
                    valorG=(float)g;
                    valorB=(float)b;
                    auxImagen.modificarRGBij(i,j,valorR,valorG,valorB);
                    auxImagen.controlMaxRangoDinamico(i,j);

                }
            }

        }
        else if ("P4" == tipoArchivo)
        {
            int pixelMonocromatico=0;

            char posPuntero;


            getline(archivoPNM, metadatos,'\n');
            archivoPNM>>columnas;
            archivoPNM>>filas;

            try {
                if(columnas == 0 || filas == 0)
                {
                    throw columnas;
                }

            } catch (int columnas) {
                cout<<"No es posible realizar la lectura del archivo ya que es un archivo corrupto";
                exit(0);
            }

            posPuntero = archivoPNM.tellg();
            archivoPNM.close();

            auxImagen.generarMatriz(filas, columnas);
            auxImagen.setMetadatos(metadatos);

            fstream archivoPNM(pNombreArchivo.c_str(), ios::binary|ios::in|ios::app);

            archivoPNM.seekg(posPuntero,ios_base::beg);

            for(int i = 0; i<auxImagen.getAltoImagen();++i)
            {
                for(int j = 0; j<auxImagen.getAnchoImagen();++j)
                {
                    archivoPNM.read((char*)&pixelMonocromatico, sizeof(pixelMonocromatico));

                    valorGris = (float)pixelMonocromatico;
                    auxImagen.modificarRGBij(i,j,valorGris,valorGris,valorGris);
                    auxImagen.controlMaxRangoDinamico(i,j);
                }
            }

        }
        else if ("P5" == tipoArchivo)
        {

            unsigned char intensidad;

            char posPuntero;

            getline(archivoPNM, metadatos,'\n');
            archivoPNM>>columnas;
            archivoPNM>>filas;

            try {
                if(columnas == 0 || filas == 0)
                {
                    throw columnas;
                }

            } catch (int columnas) {
                cout<<"No es posible realizar la lectura del archivo ya que es un archivo corrupto";
                exit(0);
            }

            archivoPNM>>maxRangoDinamico;
            getline(archivoPNM, auxPosicion,'\n');
            posPuntero = archivoPNM.tellg();
            archivoPNM.close();

            auxImagen.generarMatriz(filas, columnas);
            auxImagen.setMaxRangoDinamico(maxRangoDinamico);
            auxImagen.setMetadatos(metadatos);


            fstream archivoPNM(pNombreArchivo.c_str(), ios::binary|ios::in|ios::app);
            archivoPNM.seekg(posPuntero,ios_base::beg);

            for(int i = 0; i<auxImagen.getAltoImagen();++i)
            {
                for(int j = 0; j<auxImagen.getAnchoImagen();++j)
                {
                    archivoPNM.read((char*)&intensidad, sizeof(intensidad));
                    valorGris= (float)intensidad;
                    auxImagen.modificarRGBij(i,j,valorGris,valorGris,valorGris);
                    auxImagen.controlMaxRangoDinamico(i,j);
                }
            }

        }
        else if ("P6" == tipoArchivo)
        {

            unsigned char r, g, b;

            char posPuntero;

            getline(archivoPNM, metadatos,'\n');
            archivoPNM>>columnas;
            archivoPNM>>filas;
            archivoPNM>>maxRangoDinamico;

            try {
                if(columnas == 0 || filas == 0)
                {
                    throw columnas;
                }

            } catch (int columnas) {
                cout<<"No es posible realizar la lectura del archivo ya que es un archivo corrupto";
                exit(0);
            }

            getline(archivoPNM, auxPosicion,'\n');
            posPuntero = archivoPNM.tellg();
            archivoPNM.close();

            auxImagen.generarMatriz(filas, columnas);
            auxImagen.setMaxRangoDinamico(maxRangoDinamico);
            auxImagen.setMetadatos(metadatos);

            fstream archivoPNM(pNombreArchivo.c_str(), ios::binary|ios::in|ios::app);
            archivoPNM.seekg(posPuntero,ios_base::beg);

            for(int i = 0; i<auxImagen.getAltoImagen();++i)
            {
                for(int j = 0; j<auxImagen.getAnchoImagen();++j)
                {

                    archivoPNM.read((char*)&r, sizeof(r));
                    archivoPNM.read((char*)&g, sizeof(g));
                    archivoPNM.read((char*)&b, sizeof(b));

                    valorR = (float)r;
                    valorG = (float)g;
                    valorB = (float)b;
                    auxImagen.modificarRGBij(i,j,valorR,valorG,valorB);
                    auxImagen.controlMaxRangoDinamico(i,j);
                }
            }
        }
    }
    else
    {
        cout<<"no se pude abrir el archivo";
    }

    archivoPNM.close();

    return auxImagen;
}

void ArchivoPNM::escribir(string pNombreArchivo, Imagen *imagen_, int pTipoArchivo_)
{
    ofstream archivoPNM;

    string auxMetadatos;

    if(pTipoArchivo_ == 1 || pTipoArchivo_ == 2 || pTipoArchivo_ == 3)
    {
        archivoPNM.open(pNombreArchivo.c_str(), ios::out);

        if(archivoPNM.is_open())
        {
            if(pTipoArchivo_ == 1)
            {

                archivoPNM<<"P1\n";
                archivoPNM<<imagen_->getMetadatos()<<endl;
                archivoPNM<<imagen_->getAnchoImagen()<<" "<<imagen_->getAltoImagen()<<endl;

                for(int i = 0; i<imagen_->getAltoImagen();++i)
                {
                    for(int j = 0; j<imagen_->getAnchoImagen();++j)
                    {
                        archivoPNM<<imagen_->getPixel(i,j).getR()<<" ";
                    }
                }
            }
            else if(pTipoArchivo_ == 2)
            {

                archivoPNM<<"P2\n";
                archivoPNM<<imagen_->getMetadatos()<<endl;
                archivoPNM<<imagen_->getAnchoImagen()<<" "<<imagen_->getAltoImagen()<<endl;
                archivoPNM<<imagen_->getMaxRangoDinamico()<<endl;

                for(int i = 0; i<imagen_->getAltoImagen();++i)
                {
                    for(int j = 0; j<imagen_->getAnchoImagen();++j)
                    {
                        archivoPNM<<imagen_->getPixel(i,j).getR()<<" ";
                    }
                }
            }
            else if(pTipoArchivo_ == 3)
            {
                archivoPNM<<"P3\n";

                archivoPNM<<imagen_->getMetadatos()<<endl;
                archivoPNM<<imagen_->getAnchoImagen()<<" "<<imagen_->getAltoImagen()<<endl;
                archivoPNM<<imagen_->getMaxRangoDinamico()<<endl;

                for(int i = 0; i<imagen_->getAltoImagen();++i)
                {
                    for(int j = 0; j<imagen_->getAnchoImagen();++j)
                    {
                        archivoPNM<<imagen_->getPixel(i,j).getR()<<" "<<imagen_->getPixel(i,j).getG()<<" "<<imagen_->getPixel(i,j).getB()<<" ";
                    }
                }
            }
        }
    }
    if(pTipoArchivo_ == 4 || pTipoArchivo_ == 5 || pTipoArchivo_ == 6)
    {

        archivoPNM.open(pNombreArchivo.c_str(), ios::out|ios::binary);

        if(archivoPNM.is_open())
        {
            if(pTipoArchivo_ == 4)
            {
                unsigned char valorMonocromo;

                archivoPNM<<"P4\n";
                archivoPNM<<imagen_->getMetadatos()<<endl;
                archivoPNM<<imagen_->getAnchoImagen()<<" "<<imagen_->getAltoImagen()<<endl;

                for(int i = 0; i<imagen_->getAltoImagen();++i)
                {
                    for(int j = 0; j<imagen_->getAnchoImagen();++j)
                    {
                        valorMonocromo = imagen_->getPixel(i,j).getR();
                        archivoPNM.write((char*)&valorMonocromo,sizeof(valorMonocromo));
                    }
                }
            }
            else if(pTipoArchivo_ == 5)
            {
                unsigned char valorIntensidad;

                archivoPNM<<"P5\n";
                archivoPNM<<imagen_->getMetadatos()<<endl;
                archivoPNM<<imagen_->getAnchoImagen()<<" "<<imagen_->getAltoImagen()<<endl;
                archivoPNM<<imagen_->getMaxRangoDinamico()<<endl;

                for(int i = 0; i<imagen_->getAltoImagen();++i)
                {
                    for(int j = 0; j<imagen_->getAnchoImagen();++j)
                    {
                        valorIntensidad = imagen_->getPixel(i,j).getR();
                        archivoPNM.write((char*)&valorIntensidad,sizeof(valorIntensidad));
                    }
                }
            }
            else if(pTipoArchivo_ == 6)
            {
                unsigned char R, G, B;

                archivoPNM<<"P6\n";
                archivoPNM<<imagen_->getMetadatos()<<endl;
                archivoPNM<<imagen_->getAnchoImagen()<<" "<<imagen_->getAltoImagen()<<endl;
                archivoPNM<<imagen_->getMaxRangoDinamico()<<endl;

                for(int i = 0; i<imagen_->getAltoImagen();++i)
                {
                    for(int j = 0; j<imagen_->getAnchoImagen();++j)
                    {
                        R = imagen_->getPixel(i,j).getR();
                        G = imagen_->getPixel(i,j).getG();
                        B = imagen_->getPixel(i,j).getB();

                        archivoPNM.write((char*)&R,sizeof(R));
                        archivoPNM.write((char*)&G,sizeof(G));
                        archivoPNM.write((char*)&B,sizeof(B));
                    }
                }

            }
        }
    }
    archivoPNM.close();
}
string ArchivoPNM::getTipoArchivo()
{
    return tipoArchivo;
}
ArchivoPNM::~ArchivoPNM()
{

}

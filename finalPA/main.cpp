#include <QCoreApplication>
#include <imagen.h>
#include <administradorArchivos.h>
#include <archivoPNM.h>
#include <graficador.h>
#include <interfaz.h>
#include <sistema.h>
#include <LUT.h>
#include "deteccion.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//        Imagen imagen_;
//        Imagen *imagen2_;
//        imagen2_ = &imagen_;
//        ArchivoPNM archivoPNM;
//    //prueba lectura
//        imagen_ = archivoPNM.leer("../pei-2021-2022-entrega_autotest_01/grupo_imagenes_1/hospital-robot_01.pgm");
//    //    cout<<imagen_.getValorR(50,60);
//    //    cout<<"alto imagen: "<< imagen_.getAltoImagen()<<endl;
//    //    cout<<"ancho imagen: "<< imagen_.getAnchoImagen()<<endl;
//    //    cout<<"rango dinamico"<< imagen_.getMaxRangoDinamico()<<endl;
//    //PRUEBA DETECCION
//        Deteccion deteccion;
//        deteccion.procesarImagen(50,50,imagen2_);
//        cout<<deteccion.getAreaPintada();
    //Prueba barrido de directorio
    //    Interfaz interfaz;

    //    vector<string> listadoArchivos;
    //    interfaz.getListaDeAtajos();
    //    listadoArchivos=interfaz.getListadoDeArchivos("../pei-2021-2022-entrega_autotest_01/grupo_imagenes_1/");

    //    for(int i=0;i<listadoArchivos.size();i++)
    //    {
    //        cout<<listadoArchivos[i]<<endl;
    //    }

    //    //pruebas estadistica y filtros;
    //    Estadistica estadistica;
    //    estadistica.setImagen(&imagen_);
    //    estadistica.procesarImagen();
    //    estadistica.informarDatos();

    //    for(int i=0;i<10;i++)
    //        for(int j=0;j<10;j++)
    //        {
    //            {
    //                cout<<"primeros diez valores: "<<endl;
    //                cout<<imagen_.getValorR(i,j)<<endl;
    //            }
    //        }

    //    LUT lut;

    //    lut.leerArchivoLUT("../pei-2021-2022-entrega_autotest_01/grupo_luts/glow.lut");
    //    lut.pseudocolorear(&imagen_);

    //    for(int i=0;i<10;i++)
    //        for(int j=0;j<10;j++)
    //        {
    //            {
    //                cout<<"segundos diez valores: "<<endl;
    //                cout<<imagen_.getValorR(i,j)<<endl;
    //            }
    //        }
    //pruba graficador
    //    Graficador graficador;
    //    graficador.setImagen("entre_rios_03.ppm","../pei-2021-2022-entrega_autotest_01/grupo_imagenes_1/");
    //    graficador.resize(600,600);
    //    graficador.show();


    ////    //prueba sisteama PREGUNTAR
    Sistema sis;

    sis.ejecutar();


    return a.exec();
}

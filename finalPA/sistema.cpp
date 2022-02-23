#include "sistema.h"

Sistema::Sistema()
{

}
void Sistema::ejecutar()
{
    cout<<"Software de Procesamiento Digital de Imagenes"<<endl<<endl;

    while(opcionMenu != 9)
    {
        cout<<"Elija una opcion del menu principal: "<<endl<<endl;
        cout<<"1) Ejecutar el programa"<<endl;
        cout<<"9) Salir del programa"<<endl;


        cout<<endl<<"Opcion ingresada: ";
        cin>>opcionMenu;

        if(opcionMenu == 1)
        {
            cout<<endl<<"Elija una carpeta del directorio:"<<endl<<endl;
            cout<<"1 - Carpeta de imagenes 1"<<endl;
            cout<<"2 - Carpeta de imagenes 2"<<endl;
            cout<<"3 - Carpeta de imagenes 3 (corruptas)"<<endl;
            cout<<"4 - Carpeta de imagenes nuevas"<<endl;
            cout<<"5 - Carpeta imagenes extra"<<endl;
            cout<<"9 - Salir del programa"<<endl;

            cout<<endl<<"Opcion ingresada: ";
            cin>>opcionDirectorio;

            if(opcionDirectorio == 1)
            {
                directorio= directorio+rutaArchivosCarpeta1;
                listadoImagenes=interfaz.getListadoDeArchivos(directorio);

            }else if(opcionDirectorio == 2)
            {
                directorio= directorio+rutaArchivosCarpeta2;
                listadoImagenes=interfaz.getListadoDeArchivos(directorio);

            }else if(opcionDirectorio == 3)
            {
                directorio= directorio+rutaArchivosCarpeta3;
                listadoImagenes=interfaz.getListadoDeArchivos(directorio);

            }else if(opcionDirectorio == 4)
            {
                directorio=directorio+rutaArchivosNuevos;
                listadoImagenes=interfaz.getListadoDeArchivos(directorio);

            }else if(opcionDirectorio == 5)
            {
                directorio=directorio+rutaArchivosCarpeta5;
                listadoImagenes=interfaz.getListadoDeArchivos(directorio);
            }else if(opcionDirectorio == 9)
            {
                exit(0);
            }

            cout<<endl<<endl<<"Elegir la carpeta LUT que desea: "<<endl;
            cout<<"0 - grupo_luts"<<endl<<"1 - ij_luts"<<endl;
            cin>>opcionLUT;
            if(opcionLUT == 0)
            {
                graficador.setListadoLUT(directorioLUT1);
            }else if(opcionLUT == 1)
            {
                graficador.setListadoLUT(directorioLUT2);
            }

            cout<<endl<<endl<<"Imagenes del directorio elegido: "<<endl;
            for(int i = 0; i<listadoImagenes.size();i++)
            {
                cout<<i<<" - "<<listadoImagenes[i]<<endl;
            }

            cout<<endl<<endl<<"Elegir el numero de imagen que se desea utilizar: "<<endl;
            cin>>opcionImagen;

            graficador.setListadoImagenes(listadoImagenes);
            interfaz.getListaDeAtajos();
            cout<<endl<<"La imagen elegida es: "<<listadoImagenes[opcionImagen]<<endl<<endl;

            graficador.setImagen(listadoImagenes[opcionImagen], directorio);
            graficador.resize(600,600);
            graficador.show();
            opcionMenu=9;

        }else if(opcionMenu == 9)
        {
            exit(0);
        }else
        {
            cout<<endl<<"La opcion ingresada no es valida";
        }

    }
}


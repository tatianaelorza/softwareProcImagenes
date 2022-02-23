#include "interfaz.h"

Interfaz::Interfaz()
{

}
void Interfaz::guardarImagen(Imagen *pImagen)
{
    cout<<endl<<"Elija el formato del archivo: "<<endl<<endl;
    cout<<"1- Archivo AIC"<<endl;
    cout<<"2- Archivo PNM"<<endl;

    cout<<endl<<"Opción elegida: ";
    cin>>opcArchivoNuevo;
    cout<<endl;

    if(opcArchivoNuevo == 1)
    {
        cout<<"Ingrese el nombre del archivo:";
        cin>>nombreDelArchivoNuevo;

        nombreDelArchivoNuevo = raiz + rutaArchivosNuevos + nombreDelArchivoNuevo;

        archi = new ArchivoAIC();
        archi->escribir(nombreDelArchivoNuevo, pImagen,0);
        cout<<endl<<"Imagen guardada"<<endl;
    }
    else if(opcArchivoNuevo == 2)
    {
        cout<<"Ingrese el nombre del archivo:";
        cin>>nombreDelArchivoNuevo;

        cout<<endl<<"Elija el tipo de archivo PNM: "<<endl<<endl;
        cout<<"1- P1: Imagen monocromatica y pixeles como texto"<<endl;
        cout<<"2- P2: Imagen en escala de grises y pixeles como texto"<<endl;
        cout<<"3- P3: Imagen en color RGB y pixeles como texto"<<endl;
        cout<<"4- P4: Imagen monocromatica y pixeles en formato binario"<<endl;
        cout<<"5- P5: Imagen en escala de grises y pixeles en formato binario"<<endl;
        cout<<"6- P6: Imagen en color RGB y pixeles en binario"<<endl;

        cout<<endl<<"Opción elegida: ";
        cin>>opcTipoArchivoPNM;
        cout<<endl;
        if(opcTipoArchivoPNM == 1 || opcTipoArchivoPNM == 4)
        {
            nombreDelArchivoNuevo = nombreDelArchivoNuevo + ".pbm";
        }
        else if(opcTipoArchivoPNM == 2 || opcTipoArchivoPNM == 5)
        {
            nombreDelArchivoNuevo = nombreDelArchivoNuevo + ".pgm";
        }
        else if(opcTipoArchivoPNM == 3 || opcTipoArchivoPNM == 6)
        {
            nombreDelArchivoNuevo = nombreDelArchivoNuevo + ".ppm";
        }

        nombreDelArchivoNuevo = raiz + rutaArchivosNuevos + nombreDelArchivoNuevo;

        archi = new ArchivoPNM();

        archi->escribir(nombreDelArchivoNuevo, pImagen, opcTipoArchivoPNM);
        nombreDelArchivoNuevo.clear();
        cout<<"Imagen guardada"<<endl;
    }
    else
    {
        cout<< "La opción ingresada no es correcta";
    }
}

vector<string> Interfaz::getListadoDeArchivos(string pRutaDirectorio)
{
    vector<string> lista_de_archivos;
    DIR *dir = opendir(pRutaDirectorio.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                lista_de_archivos.push_back(entry->d_name);
            }
        }
        closedir(dir);
    }
        return lista_de_archivos;
}
void Interfaz::getListaDeAtajos()
{
    cout<<endl<<"Lista de atajos:"<<endl;

    cout<<"'Ctrl' + 'flecha izquierda': desplazarse hacia la imagene previa"<<endl;
    cout<<"'Ctrl' + 'flecha derecha': desplazarse hacia la imagene siguiente"<<endl;
    cout<<"'Ctrl' + 'flecha arriba': desplazarse hacia la siguient LUT"<<endl;
    cout<<"'Ctrl' + 'flecha abajo': desplazarse hacia la anterior LUT"<<endl;
    cout<<"'Ctrl' + 'b': binarizar la imagen"<<endl;
    cout<<"'Ctrl' + 'n': negativizar la imagen"<<endl;
    cout<<"'Ctrl' + 'c': ajustar contraste  de la imagen"<<endl;
    cout<<"'Ctrl' + '+': aumentar el brillo de la imagen"<<endl;
    cout<<"'Ctrl' + '-': disminuir el brillo de la imagen"<<endl;
    cout<<"'Ctrl' + 'm': aplicar filtro de ruido"<<endl;
    cout<<"'Ctrl' + 's': aplicar filtro de suavizado"<<endl;
    cout<<"'Ctrl' + 'a': aplicar filtro de realce de bordes"<<endl;
    cout<<"'Ctrl' + 'g': guardar la imagen en disco"<<endl;
    cout<<"'Ctrl' + 'o': volver a la imagen original"<<endl;
    cout<<"'Ctrl' + 'h': calcular datos estadisticos y graficar el histograma"<<endl;
    cout<<"'Ctrl' + 'click izquierdo': aplicar detección de área"<<endl;
    cout<<"'Ctrl' + 'click izquierdo' + arrastrar sin soltar: aplicar zoom en la imagen"<<endl;
    cout<<"'escape': cerrar ventana de graficación"<<endl<<endl;
}

Interfaz::~Interfaz()
{

}

#include "graficador.h"
#include <iostream>
using namespace std;
Graficador::Graficador()
{

}
void Graficador::getImagenOriginal()
{
    imagen=imagenOriginal;
}
void Graficador::setImagen(string pimagen, string pDirectorio)
{
    string tipoDeArchivo = pimagen.substr(pimagen.find('.',1)+1);

        if(tipoDeArchivo != "aic")
        {
            archivo = new ArchivoPNM();
        }
        else
        {
            archivo = new ArchivoAIC();
        }
        string auxNombreImagen;
        auxNombreImagen=pimagen;
        imagenOriginal = archivo->leer(pDirectorio+pimagen);
        formatoArchivo=archivo->getTipoArchivo();

        delete archivo;

        auxDirectorio=pDirectorio;
        imagen = imagenOriginal;
        for(int i=0;i<listadoDeImagenes.size();i++)
        {
            if(listadoDeImagenes[i] == auxNombreImagen)
            {
                indiceImagen=i;
            }
        }
}
void Graficador::setListadoImagenes(vector<string> pListado)
{
    listadoDeImagenes.resize(pListado.size());
    for(int i=0;i<pListado.size();i++)
    {
        listadoDeImagenes[i]=pListado[i];
    }
}
void Graficador::setListadoLUT(string pdirectorio)
{
    listadoLUT=interfaz.getListadoDeArchivos(pdirectorio);
    for(int i=0; i<listadoLUT.size(); i++){
        cout<<listadoLUT[i]<<endl;
    }
    auxDirectorioLUT=pdirectorio;
}
void Graficador::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0,1.0,1.0,1.0);
    posicionInicialX = 0;
    posicionInicialY = 0;
}
void Graficador::resizeGL(int pAncho, int pAlto)
{
    anchoVentana = pAncho;
    altoVentana = pAlto;
    glViewport(0, 0, anchoVentana, altoVentana);
}
void Graficador::graficarLimites()
{
    glColor3f (1.0 , 1.0 , 1.0);
    glBegin(GL_QUADS);
    glVertex2f(imagen.getAnchoImagen()+0.75 , imagen.getAltoImagen()+0.75 );
    glVertex2f(-0.75, imagen.getAltoImagen()+0.75);
    glVertex2f(-0.75 , -0.75);
    glVertex2f(imagen.getAnchoImagen()+0.75 ,-0.75);
    glEnd();

    glLineWidth(3);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_LINE_LOOP);
    glVertex2f(imagen.getAnchoImagen()+0.5, imagen.getAltoImagen()+0.5);
    glVertex2f(-0.5, imagen.getAltoImagen()+0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(imagen.getAnchoImagen()+0.5, -0.5);
    glEnd();
}
void Graficador::graficarImagen()
{

    glPushMatrix();
    {

        glTranslatef(desplazamientoX,desplazamientoY, 0.0f);
        glScalef(escala,escala, 1.0f);

        graficarLimites();
        glBegin(GL_QUADS);
        for(int i=0;i<imagen.getAltoImagen();i++)
        {
            for(int j=0;j<imagen.getAnchoImagen();j++)
            {
                glColor3f((float)imagen.getPixel(i,j).getR()/(float)imagen.getMaxRangoDinamico(), (float)imagen.getPixel(i,j).getG()/(float)imagen.getMaxRangoDinamico(), (float)imagen.getPixel(i,j).getB()/(float)imagen.getMaxRangoDinamico());

                glVertex2f(j, imagen.getAltoImagen()-i);
                glVertex2f(j, imagen.getAltoImagen()-(i+1));
                glVertex2f(j+1, imagen.getAltoImagen()-(i+1));
                glVertex2f(j+1, imagen.getAltoImagen()-i);
            }

        }
        glEnd();
    }
    glPopMatrix();


}
void Graficador::graficarHistograma()
{
    glClear(GL_COLOR_BUFFER_BIT);

    vector<int> vectorRepeticionesValoresR = estadistica.getRepeticionesValoresR();
    vector<int> vectorRepeticionesValoresG = estadistica.getRepeticionesValoresG();
    vector<int> vectorRepeticionesValoresB = estadistica.getRepeticionesValoresB();

    vector<int> vectorPromedioIntensidades = estadistica.getRepeticionesPromedioIntensidades();

    glScalef((width()*1.0f)/256.0f, (height()*1.0f)/(estadistica.getVecesValorMasRepetido()*1.0f), 0.0f);


    for(unsigned int i=0;i<vectorPromedioIntensidades.size();i++)
    {
       glBegin(GL_QUADS);
       {
           glColor3f(0.5,0.5,0.5);
           glVertex2i(i,0);
           glVertex2i(i, vectorPromedioIntensidades[i]);
           glVertex2i(i+1,vectorPromedioIntensidades[i+1]);
           glVertex2i(i+1,0);
       }
       glEnd();
    }
    if(formatoArchivo == "P3" || formatoArchivo == "P6")
    {
        for(int i = 0; i<vectorRepeticionesValoresR.size();i++)
        {
            glBegin(GL_LINE_STRIP);
            {
                glColor3f(1.0f,0.0f,0.0f);
                glVertex2i(i, vectorRepeticionesValoresR[i]);
                glVertex2i(i+1,vectorRepeticionesValoresR[i+1]);
            }
            glEnd();
        }

        for(int i = 0; i<vectorRepeticionesValoresG.size();i++)
        {
            glBegin(GL_LINE_STRIP);
            {
                glColor3f(0.0f,1.0f,0.0f);
                glVertex2i(i, vectorRepeticionesValoresG[i]);
                glVertex2i(i+1,vectorRepeticionesValoresG[i+1]);
            }
            glEnd();
        }

        for(int i = 0; i<vectorRepeticionesValoresB.size();i++)
        {
            glBegin(GL_LINE_STRIP);
            {
                glColor3f(0.0f,0.0f,1.0f);
                glVertex2i(i, vectorRepeticionesValoresB[i]);
                glVertex2i(i+1,vectorRepeticionesValoresB[i+1]);
            }
            glEnd();
        }
    }

    controlGraficarHistograma = false;

}
void Graficador::graficarRectanguloZoom()
{
    if(clickIzquierdoPresionado == true && controlPresionado == true)
    {
        glPushMatrix();

        glLineWidth(5);

        glTranslatef(desplazamientoX,desplazamientoY, 0.0f);

        glScalef(escala, escala, 1.0f);

        glBegin(GL_LINE_LOOP);

        glColor3f(1.0f,1.0f,0.0f);
        glVertex2i(posicionInicialX, imagen.getAltoImagen() - posicionInicialY);
        glVertex2i(posicionInicialX, imagen.getAltoImagen() - posicionMomentaneaY);
        glVertex2i(posicionMomentaneaX,imagen.getAltoImagen() - posicionMomentaneaX);
        glVertex2i(posicionMomentaneaX,imagen.getAltoImagen() - posicionInicialX);
        glEnd();

        glPopMatrix();
    }
}
void Graficador::paintGL()
{

    anchoImagen = imagen.getAnchoImagen();
    altoImagen = imagen.getAltoImagen();
    escalaAncho = (float)width()/(float)anchoImagen;
    escalaAlto = (float)height()/(float)altoImagen;

    escala = 1.0;
    desplazamientoX = 0.0;
    desplazamientoY = 0.0;

    if(escalaAncho<escalaAlto)
    {
        escala = escalaAncho;
        desplazamientoY = (height() - altoImagen*escala)*0.5f;
    }else
    {
        escala = escalaAlto;
        desplazamientoX = (width() - anchoImagen*escala)*0.5f;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0.0,0.0,width(),height());

    if(controlGraficarZoom)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(posicionVentanaInicialX, posicionVentanaFinalX, height() - posicionVentanaFinalY, height() - posicionVentanaInicialY, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }else
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width(), 0, height(), -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }


    graficarImagen();
    graficarRectanguloZoom();
    if(controlGraficarHistograma)
    {
        graficarHistograma();
    }


}
void Graficador::keyPressEvent(QKeyEvent *pEvent)
{
    if(pEvent->key() == Qt::Key_Control)
    {
        controlPresionado = true;
    }

    if(pEvent->key() == Qt::Key_Left)
    {
        flechaIzquierdaPresionada = true;
    }

    if(pEvent->key() == Qt::Key_Right)
    {
        flechaDerechaPresionada = true;
    }

    if(pEvent->key() == Qt::Key_Up)
    {
        flechaArribaPresionada = true;
    }

    if(pEvent->key() == Qt::Key_Down)
    {
        flechaAbajoPresionada = true;
    }

    if(pEvent->key() == Qt::Key_H)
    {
        hPresionada = true;
    }

    if(pEvent->key() == Qt::Key_G)
    {
        gPresionada = true;
    }

    if(pEvent->key() == Qt::Key_M)
    {
        mPresionada = true;
    }

    if(pEvent->key() == Qt::Key_S)
    {
        sPresionada = true;
    }

    if(pEvent->key() == Qt::Key_A)
    {
        aPresionada = true;
    }

    if(pEvent->key() == Qt::Key_C)
    {
        cPresionada = true;
    }

    if(pEvent->key() == Qt::Key_Plus)
    {
        plusPresionada = true;
    }

    if(pEvent->key() == Qt::Key_Minus)
    {
        minusPresionada = true;
    }

    if(pEvent->key() == Qt::Key_B)
    {
        bPresionada = true;
    }

    if(pEvent->key() == Qt::Key_O)
    {
        oPresionada = true;
    }

    if(pEvent->key() == Qt::Key_N)
    {
        nPresionada = true;
    }

    if(pEvent->key() == Qt::Key_Escape)
    {
        escapePresionado = true;
    }




    if(controlPresionado && flechaIzquierdaPresionada)
    {
//        ANDA
        if(indiceImagen>0)
        {
            indiceImagen--;
            setImagen(listadoDeImagenes[indiceImagen],auxDirectorio);
        }
    }

    if(controlPresionado && flechaDerechaPresionada)
    {
//        ANDA
        if(indiceImagen<listadoDeImagenes.size()-1)
        {
            indiceImagen++;
            setImagen(listadoDeImagenes[indiceImagen],auxDirectorio);
        }
    }

    if(controlPresionado && flechaArribaPresionada)
    {
//        ANDA
        if(indiceLUT < (int)listadoLUT.size()-1)
        {
            indiceLUT++;
        }

        lut.leerArchivoLUT(auxDirectorioLUT+listadoLUT[indiceLUT]);
        getImagenOriginal();
        lut.pseudocolorear(&imagen);
    }

    if(controlPresionado && flechaAbajoPresionada)
    {
//        ANDA PERO TENGO PROBLEMAS CON EL PASE DEL PRIMER FILTRO A LA IMAGEN ORIGINAL
        if(indiceLUT>-1)
        {
            indiceLUT--;
        }
        lut.leerArchivoLUT(auxDirectorioLUT+listadoLUT[indiceLUT]);
        getImagenOriginal();
        lut.pseudocolorear(&imagen);
        if(indiceLUT == -1)
        {
            getImagenOriginal();
        }
    }

    if(controlPresionado && cPresionada)
    {
//        ANDA
        getImagenOriginal();
        imagen.ajustarContrasteImagen();
    }

    if(controlPresionado && plusPresionada)
    {
//        ANDA
        int brillo=0;
        cout<<"Ingrese la cantidad de brillo que desea aumentar: "<<endl;
        cin>>brillo;
        imagen.cambiarBrillo((float)brillo);
    }

    if(controlPresionado && minusPresionada)
    {
//        ANDA
        int brillo=0;
        cout<<"Ingrese ls cantidad de brillo que desea disminuir: "<<endl;
        cin>>brillo;
        brillo = -brillo;
        imagen.cambiarBrillo((float)brillo);
    }

    if(controlPresionado && bPresionada)
    {
//        ANDA
        int intensidad;
        cout<<endl<<"Ingrese la intensidad a utilizar para binarizar: ";
        cin>>intensidad;
        imagen.binarizarImagen((float)intensidad);
    }

    if(controlPresionado && nPresionada)
    {
//        ANDA
        getImagenOriginal();
        imagen.negativizarImagen();
    }

    if(controlPresionado && sPresionada)
    {
//        ANDA PERO SE TRABA
        filtroPasaBajos.procesarImagen(&imagen);
    }

    if(controlPresionado && mPresionada)
    {
//        ANDA PERO SE TRABA
        filtroMediana.procesarImagen(&imagen);
    }

    if(controlPresionado && aPresionada)
    {
//        ANDA PERO SE TRABA
        filtroPasaAltos.procesarImagen(&imagen);
    }

    if(controlPresionado && hPresionada)
    {
//        ANDA
        estadistica.setImagen(&imagen);
        estadistica.informarDatos();
        controlGraficarHistograma = true;
    }

    if(controlPresionado && gPresionada)
    {
//        ANDA
        interfaz.guardarImagen(&imagen);
    }

    if(controlPresionado && oPresionada)
    {
//        ANDA
        getImagenOriginal();
        controlGraficarZoom = false;
        controlGraficarHistograma = false;
    }

    if(escapePresionado)
    {
//        ANDA
        escapePresionado = false;
        close();
    }
    update();
}
void Graficador::keyReleaseEvent(QKeyEvent *pEvent)
{
    if(pEvent->key() == Qt::Key_Control)
    {
        controlPresionado = false;
    }

    if(pEvent->key() == Qt::Key_Left)
    {
        flechaIzquierdaPresionada = false;
    }

    if(pEvent->key() == Qt::Key_Up)
    {
        flechaArribaPresionada = false;
    }

    if(pEvent->key() == Qt::Key_Down)
    {
        flechaAbajoPresionada = false;
    }

    if(pEvent->key() == Qt::Key_Right)
    {
        flechaDerechaPresionada = false;
    }

    if(pEvent->key() == Qt::Key_Plus)
    {
        plusPresionada = false;
    }

    if(pEvent->key() == Qt::Key_Minus)
    {
        minusPresionada = false;
    }

    if(pEvent->key() == Qt::Key_S)
    {
        sPresionada = false;
    }

    if(pEvent->key() == Qt::Key_M)
    {
        mPresionada = false;
    }

    if(pEvent->key() == Qt::Key_A)
    {
        aPresionada = false;
    }

    if(pEvent->key() == Qt::Key_H)
    {
        hPresionada = false;
    }

    if(pEvent->key() == Qt::Key_G)
    {
        gPresionada = false;
    }

    if(pEvent->key() == Qt::Key_B)
    {
        bPresionada = false;
    }

    if(pEvent->key() == Qt::Key_O)
    {
        oPresionada = false;
    }

    if(pEvent->key() == Qt::Key_N)
    {
        nPresionada = false;
    }

    if(pEvent->key() == Qt::Key_Escape)
    {
        escapePresionado = false;
    }

    if(pEvent->key() == Qt::Key_C)
    {
        cPresionada = false;
    }
}
void Graficador::mousePressEvent(QMouseEvent *pEvent)
{
    clickIzquierdoPresionado = pEvent->button() == Qt::LeftButton;

    if(clickIzquierdoPresionado == true && controlPresionado == true)
    {
        posicionInicialY = ((this->mapFromGlobal(QCursor::pos()).y() - desplazamientoY)/(escala));

        posicionVentanaInicialY = this->mapFromGlobal(QCursor::pos()).y();

        posicionInicialX = ((this->mapFromGlobal(QCursor::pos()).x() - desplazamientoX)/(escala));

        posicionVentanaInicialX = this->mapFromGlobal(QCursor::pos()).x();

    }
}

void Graficador::mouseMoveEvent(QMouseEvent *pEvent)
{
    if(pEvent->buttons()& Qt::LeftButton && controlPresionado == true)
    {
        controlMouseMove = true;

        posicionMomentaneaY = ((this->mapFromGlobal(QCursor::pos()).y() - desplazamientoY)/(escala));

        posicionMomentaneaX = ((this->mapFromGlobal(QCursor::pos()).x() - desplazamientoX)/(escala));

        update();
    }
}

void Graficador::mouseReleaseEvent(QMouseEvent *pEvent)
{
    bool clickIzquierdoRelease = pEvent->MouseButtonRelease;

    if(clickIzquierdoRelease == true && controlPresionado == true)
    {
        controlPresionado = false;

        controlMouseMove = false;

        posicionFinalY = ((this->mapFromGlobal(QCursor::pos()).y()- desplazamientoY)/(escala));

        posicionVentanaFinalY = this->mapFromGlobal(QCursor::pos()).y();

        posicionFinalX = ((this->mapFromGlobal(QCursor::pos()).x() - desplazamientoX)/(escala));

        posicionVentanaFinalX = this->mapFromGlobal(QCursor::pos()).x();

        if(posicionInicialX == posicionFinalX and posicionInicialY == posicionFinalY)
        {
            deteccion.procesarImagen(posicionFinalY,posicionFinalX, &imagen);
            cout<<"El area pintada es: "<<deteccion.getAreaPintada()<<endl;
        }else
        {
            resizeGL(anchoVentana,altoVentana);
            controlGraficarZoom = true;
        }
    }

    update();
}
Graficador::~Graficador()
{

}

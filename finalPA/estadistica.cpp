#include "estadistica.h"

Estadistica::Estadistica()
{

}
void Estadistica::setImagen(Imagen *pImagen)
{
    imagen = pImagen;

    vectorRepeticionesValoresR.clear();
    vectorRepeticionesValoresG.clear();
    vectorRepeticionesValoresB.clear();
    vectorRepeticionesPromedioIntensidades.clear();

    auxiliarModa.clear();
    valoresR.clear();
    valoresG.clear();
    valoresB.clear();
    promedioIntensidades.clear();

    procesarImagen();

}
void Estadistica::procesarImagen()
{
    float valorR, valorG, valorB, auxAcumuladorPromedioFirst = 0, auxAcumuladorPromedioSecond = 0, auxAcumuladorDesviacion = 0;

    int rango = imagen->getMaxRangoDinamico();

    vectorRepeticionesValoresR.resize(rango);
    vectorRepeticionesValoresG.resize(rango);
    vectorRepeticionesValoresB.resize(rango);
    vectorRepeticionesPromedioIntensidades.resize(rango);

    auxiliarModa.resize(4);

    for(int i = 0; i < imagen->getAltoImagen(); i++)
    {
        for(int j = 0; j< imagen->getAnchoImagen(); j++)
        {
            valorR = imagen->getValorR(i,j);
            vectorRepeticionesValoresR[(int)valorR]++;
            valoresR[valorR]++;

            valorG = imagen->getValorG(i,j);
            vectorRepeticionesValoresG[(int)valorG]++;
            valoresG[valorG]++;

            valorB = imagen->getValorB(i,j);
            vectorRepeticionesValoresB[(int)valorB]++;
            valoresB[valorB]++;

            promedio = (valorR + valorG + valorB)/3.0f;
            vectorRepeticionesPromedioIntensidades[(int)promedio]++;
            promedioIntensidades[promedio]++;
        }
    }
    valorMin = promedioIntensidades.begin()->first;
    vecesValorMin = promedioIntensidades.begin()->second;


    for(map<float, int>::iterator iter = promedioIntensidades.begin(); iter != promedioIntensidades.end(); ++iter)
    {
        int valor = iter->first;

        auxAcumuladorPromedioFirst  += (iter->first)*(iter->second);
        auxAcumuladorPromedioSecond += iter->second;

        if (valor < valorMin)
        {
            valorMin = valor;
            vecesValorMin = iter->second;
        }
        if (valor > valorMax)
        {
            valorMax = valor;
            vecesValorMax = iter->second;
        }
        if(iter->second>vecesValorMasRepetidoIntensidadPromedio)
        {
            valorMasRepetidoIntensidadPromedio = iter->first;
            vecesValorMasRepetidoIntensidadPromedio = iter->second;
        }
    }

    for(map<float, int>::iterator iter = valoresR.begin(); iter != valoresR.end(); ++iter)
    {
        if(iter->second>vecesValorRojoMasRepetido)
        {
            valorRojoMasRepetido = iter->first;
            vecesValorRojoMasRepetido = iter->second;
        }
    }

    for(map<float, int>::iterator iter = valoresG.begin(); iter != valoresG.end(); ++iter)
    {
        if(iter->second>vecesValorVerdeMasRepetido)
        {
            valorVerdeMasRepetido = iter->first;
            vecesValorVerdeMasRepetido = iter->second;
        }
    }

    for(map<float, int>::iterator iter = valoresB.begin(); iter != valoresB.end(); ++iter)
    {
        if(iter->second>vecesValorAzulMasRepetido)
        {
            valorAzulMasRepetido = iter->first;
            vecesValorAzulMasRepetido = iter->second;
        }
    }

    promedio =  (float)auxAcumuladorPromedioFirst/(float)auxAcumuladorPromedioSecond;

    for(map<float, int>::iterator it = promedioIntensidades.begin(); it != promedioIntensidades.end(); ++it)
        auxAcumuladorDesviacion += (((it->first) - promedio)*((it->first) - promedio))*it->second;

    desviacionEstandar = sqrt((float)auxAcumuladorDesviacion/(float)(auxAcumuladorPromedioSecond-1));
    auxiliarModa[0] = vecesValorRojoMasRepetido;
    auxiliarModa[1] = vecesValorVerdeMasRepetido;
    auxiliarModa[2] = vecesValorAzulMasRepetido;
    auxiliarModa[3] = vecesValorMasRepetidoIntensidadPromedio;

    vecesValorMasRepetido = *max_element(auxiliarModa.begin(),auxiliarModa.end());

    if(vecesValorMasRepetido == vecesValorRojoMasRepetido)
        valorMasRepetido = valorRojoMasRepetido;

    if(vecesValorMasRepetido == vecesValorVerdeMasRepetido)
        valorMasRepetido = valorVerdeMasRepetido;

    if(vecesValorMasRepetido == vecesValorAzulMasRepetido)
        valorMasRepetido = valorAzulMasRepetido;

    if(vecesValorMasRepetido == vecesValorMasRepetidoIntensidadPromedio)
        valorMasRepetido = valorMasRepetidoIntensidadPromedio;


}
float Estadistica::getPromedio()
{
    return promedio;
}
float Estadistica::getDesviacionEstandar()
{
    return desviacionEstandar;
}
float Estadistica::getValorMin()
{
    return valorMin;
}
int Estadistica::getCantidadVecesValorMin()
{
    return vecesValorMin;
}
float Estadistica::getValorMax()
{
    return valorMax;
}
int Estadistica::getCantidadVecesValorMax()
{
    return vecesValorMax;
}
float Estadistica::getModa()
{
    return valorMasRepetido;
}
int Estadistica::getVecesValorMasRepetido()
{
    return vecesValorMasRepetido;
}

float Estadistica::getValorRojoMasRepetido()
{
    return valorRojoMasRepetido;
}
int Estadistica::getVecesValorRojoMasRepetido()
{
    return vecesValorRojoMasRepetido;
}
float Estadistica::getValorAzulMasRepetido()
{
    return valorAzulMasRepetido;
}
int Estadistica::getVecesValorAzulMasRepetido()
{
    return vecesValorAzulMasRepetido;
}
float Estadistica::getValorVerdeMasRepetido()
{
    return valorVerdeMasRepetido;
}
int Estadistica::getVecesValorVerdeMasRepetido()
{
    return vecesValorVerdeMasRepetido;
}
vector<int> Estadistica::getRepeticionesValoresR()
{
    return vectorRepeticionesValoresR;
}
vector<int> Estadistica::getRepeticionesValoresG()
{
    return vectorRepeticionesValoresG;
}
vector<int> Estadistica::getRepeticionesValoresB()
{
    return vectorRepeticionesValoresB;
}
vector<int> Estadistica::getRepeticionesPromedioIntensidades()
{
    return vectorRepeticionesPromedioIntensidades;
}
void Estadistica::informarDatos()
{
    cout<<"Datos estadisticos: "<<endl<<endl;

    cout<<"Valor minimo: "<<getValorMin()<<endl;
    cout<<"Cantidad de veces que se repite el valor minimo: "<<getCantidadVecesValorMin()<<endl;
    cout<<"Valor maximo: "<<getValorMax()<<endl;
    cout<<"Cantidad de veces que se repite el valor maximo: "<<getCantidadVecesValorMax()<<endl;
    cout<<"Valor mas repetito: "<<getModa()<<endl;
    cout<<"Promedio: "<<getPromedio()<<endl;
    cout<<"Desviacion estandar: "<<getDesviacionEstandar()<<endl;

    cout<<"Valor rojo mas repetido: "<<getValorRojoMasRepetido()<<endl;
    cout<<"Cantidad de veces que se repite el valor rojo: "<<getVecesValorRojoMasRepetido()<<endl;
    cout<<"Valor verde mas repetido: "<<getValorVerdeMasRepetido()<<endl;
    cout<<"Cantidad de veces que se repite el valor verde: "<<getVecesValorVerdeMasRepetido()<<endl;
    cout<<"Valor azul mas repetido: "<<getValorAzulMasRepetido()<<endl;
    cout<<"Cantidad de veces que se repite el valor azul: "<<getVecesValorAzulMasRepetido()<<endl;

}

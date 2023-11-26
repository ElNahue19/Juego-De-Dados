#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <vector>
#include "rlutil.h"
using namespace std;

//declaracin de funciones
void tirarDados(int);
void ordenarDados(int);
void escalera(int,int*, int*, int*);
void sumarDados(int, int, int*);
void trio(int, int*);
void sexteto(int, int*);
void seis6(int, int*, int*);
void dibujarDados(int);
void tresLanzamientos(int, int*, int*, int*);
void panelEntreTurnos(char, int, int, int, int);
void pantallaEntreTurnos(int, char, char, char, int, int);
void ganador(char, int, int);

//FUNCION TIRAR DADOS
void tirarDados(int vec[])
{
    for(int i=0; i<=5; i++)
    {
        int numAleatorio = 1 + rand() % (7 - 1);
        vec[i] = numAleatorio;
    }
}


//FUNCION ORDENAR DADOS
void ordenarDados(int vec[])
{
    for(int i = 0; i <=5 ; i++)
    {
        int maxIndex = i;
        for(int j = i + 1; j <= 5; j++)
        {
            if (vec[j] > vec[maxIndex])
            {
                maxIndex = j;
            }
        }
        // Intercambiar el elemento máximo con el elemento actual
        int temp = vec[i];
        vec[i] = vec[maxIndex];
        vec[maxIndex] = temp;
    }
}

//Funciones
void escalera(int vec[], int* puntuacionT, int* lanzamiento, int* vEscalera)
{
    int cont=0;
    int ant;

    for(int i=0; i<=5; i++)
    {

        if(i==0)
        {
            ant=vec[i];
        }
        else if(vec[i] == ant-1)
        {
            cont++;
            ant=vec[i];
        }

    }

    if(cont==5)
    {
        *puntuacionT=500;
        *lanzamiento=3;
        *vEscalera=1;


    }

}


void sumarDados(int vec[], int vEscalera, int* puntuacionT)
{
    //contador
    int cont=0;
    //Comprobacion para que no entre y salga escalera
    if(vEscalera==0)
    {
        for(int i=0; i<=5; i++)
        {

            if(vec[i] == vec[i+1])
            {
                cont++;
                if(vec[i+1]==vec[i+2])
                {
                    cont+=3;
                    i=6;
                }

            }
        }
        if(cont<=3)
        {
            *puntuacionT = vec[0]+vec[1]+vec[2]+vec[3]+vec[4]+vec[5];
        }
    }

}

void trio(int vec[], int* puntuacionT)
{
    //contador
    int cont=0;
    int numIgual=0;
    for(int i=0; i<=5; i++)
    {

        if(vec[i] == vec[i+1])
        {

            cont++;
            if(vec[i+1]==vec[i+2])
            {
                cont+=2;
                if(numIgual==0)
                {
                    numIgual=vec[i];
                    i+=6;
                }
            }

        }
    }
    if(cont>2 && cont<5)
    {

        *puntuacionT = numIgual*10;

    }

}

void sexteto(int vec[], int* puntuacionT)
{
    //contador
    int cont=0;
    int numIgual=0;
    for(int i=0; i<=5; i++)
    {

        if(vec[i] == vec[i+1])
        {

            cont++;
            if(numIgual==0)
            {
                numIgual=vec[i];
            }
        }
    }
    if(cont>4 && numIgual!=6)
    {

        *puntuacionT = numIgual*50;

    }

}

void seis6(int vec[], int* maxP, int* lanzamientos)
{
    //contador
    int cont=0;
    int numIgual=0;
    for(int i=0; i<=5; i++)
    {

        if(vec[i] == vec[i+1])
        {

            cont++;
            if(numIgual==0)
            {
                numIgual=vec[i];
            }
        }
    }
    if(cont==5 && numIgual==6)
    {
        *maxP=0;
        *lanzamientos=4;

    }

}

void dibujarDados(int vec[])
{

    int xPos = 40;
    int yPos = 15;

    for (int i = 0; i <= 5; i++)
    {
        rlutil::locate(xPos, yPos);
        cout << " ------- ";
        rlutil::locate(xPos, yPos + 1);
        cout << "|       |";
        rlutil::locate(xPos, yPos + 2);
        cout << "|   " << vec[i] << "   |";
        rlutil::locate(xPos, yPos + 3);
        cout << "|       |";
        rlutil::locate(xPos, yPos + 4);
        cout << " ------- ";

        xPos += 10;
    }

}

void tresLanzamientos(int lanzamiento, int* puntuacionT, int* maxP, int* antTurno)
{

    if(lanzamiento==1)
    {
        *antTurno = *puntuacionT;
        *maxP = *puntuacionT;
    }
    else if(*puntuacionT>*antTurno)
    {
        *maxP = *puntuacionT;
        *antTurno= *puntuacionT;
    }


}

void panelEntreTurnos(char jug[20], int ronda, int puntosJug, int maxP, int lanzamientos)
{

    rlutil::locate(40,10);
    cout << "TURNO DE " << jug << "  |  RONDA N: " << ronda << "  |  PUNTAJE TOTAL: " << puntosJug << " PUNTOS" << endl;
    rlutil::locate(40,12);
    cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxP << " PUNTOS" << endl;
    rlutil::locate(40,14);
    cout << "LANZAMIENTO N: " << lanzamientos << endl;
    rlutil::locate(40,16);

}

void pantallaEntreTurnos(int ronda, char proxJugador[20], char jugador1[20], char jugador2[20], int puntosJug1, int puntosJug2)
{

    rlutil::locate(40, 15);
    cout<< "RONDA Nro: " << ronda << endl;

    rlutil::locate(40, 15+1);
    cout<< "PROXIMO TURNO DE "<< proxJugador <<endl;

    rlutil::locate(40, 15+3);
    cout<< "PUNTAJE DE " <<jugador1<< ":" << puntosJug1<< " PUNTOS"<<endl;

    rlutil::locate(40, 15+4);
    cout<< "PUNTAJE DE " <<jugador2<< ":" << puntosJug2<< " PUNTOS"<<endl;

    rlutil::anykey();
    rlutil::cls();

}

void ganador(char jugador[20], int puntosJug, int rondas)
{

    rlutil::locate(45,15);
    cout<<"El ganador es " << jugador;
    rlutil::locate(45,16);
    cout<<"Con un puntaje total de: " << puntosJug;
    rlutil::locate(45,17);
    cout <<"Con una cantidad de rondas de: " << rondas;
    cout<< endl;
    system("pause");
    rlutil::cls();

}







#endif // FUNCIONES_H_INCLUDED

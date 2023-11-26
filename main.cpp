#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#include "rlutil.h"
#include "funciones.h"

using namespace std;
using namespace rlutil;


int main()
{
    int seguirJugando=0;
    while(seguirJugando==0)
    {
        //Menu
        int cantidadJugadores;
        char jugador1[20], jugador2[20];

        //Vectores
        int dados[7];
        int dadosOrdenados[7];

        //Control
        int i,c,x,z,numAleatorio;

        //Contador
        int ronda=1, lanzamientos=1;

        //Acumuladores
        int  puntosPorRonda=0, puntosJug1=0, puntosJug2=0, maxPuntuacion=0, puntuacionTurno, antTurno=0;

        // Banderas
        int vEscalera=0;

        srand(time(NULL));
        rlutil::setBackgroundColor(rlutil::MAGENTA);
        rlutil::setColor(rlutil::WHITE);

        int opcion = 1;
        int cursorY = 12;

        rlutil::hidecursor();

        while (true)
        {
            cls();
            locate(40,5);
            cout << "Quinientos o escalera" << endl <<  endl << endl;
            locate(40,6);
            cout << "---------------------" << endl;

            locate(1,10);
            cout << "Seleccione el modo de juego: " << endl;
            locate(40,12);
            cout << "Un jugador" << endl;
            locate(40,13);
            cout << "Dos jugadores" << endl;
            locate(40,14);
            cout << "Prueba un jugador"<< endl;

            locate(38, cursorY);
            cout << (char)254 << endl;

            int tecla = getkey();
            if (tecla == KEY_UP && opcion > 1)
            {
                opcion--; // Mueve hacia arriba si se presiona la flecha arriba
                cursorY--;
            }
            else if (tecla == KEY_DOWN && opcion < 3)
            {
                opcion++; // Mueve hacia abajo si se presiona la flecha abajo
                cursorY++;
            }
            else if (tecla == KEY_ENTER || tecla == '\r')
            {
                break; // Sale del bucle si se presiona Enter
            }
        }
        cantidadJugadores = opcion;
        cls();

        //----------------------------------------------------------1 JUGADOR ------------------
        if(cantidadJugadores==1 || cantidadJugadores==3)
        {
            puntosJug1=0; // cada vez que inicie se resetean los puntos en 0

            rlutil::locate(1,10);
            cout << "Por favor, ingrese el nombre del jugador 1: " << endl;
            rlutil::locate(45,10);
            cin >> jugador1;
            rlutil::cls();


            while(puntosJug1<500)
            {
                lanzamientos = 1;
                maxPuntuacion=0;
                for(x=1; x<=3; x++)
                {
                    panelEntreTurnos(jugador1, ronda, puntosJug1, maxPuntuacion, lanzamientos);


                    if(cantidadJugadores==1)
                    {
                        tirarDados(dados);
                    }
                    else
                    {

                        for(int n=0; n<=5; n++)
                        {
                            rlutil::locate(40,23+n);
                            cin >> dados[n];
                        }

                    }



                    dibujarDados(dados);



                    ordenarDados(dados);
//-------------Combos-----------------------
                    seis6(dados, &maxPuntuacion, &x);
                    escalera(dados, &puntuacionTurno, &x, &vEscalera);
                    sumarDados(dados, vEscalera, &puntuacionTurno);
                    trio(dados, &puntuacionTurno);
                    sexteto(dados, &puntuacionTurno);



                    tresLanzamientos(x, &puntuacionTurno, &maxPuntuacion, &antTurno);

                    lanzamientos++;
                    cout<<endl;
                    system("pause");
                    rlutil::locate(40,10);
                }
                puntosJug1+=maxPuntuacion;
                ronda++;
            }
        }
        else if(cantidadJugadores==2) //----------------------------2 JUGADORES -----------------
        {
            cout << "Por favor, ingrese el nombre del jugador 1: " << endl;
            cin >> jugador1;
            rlutil::cls();

            cout << "Por favor, ingrese el nombre del jugador 2: " << endl;
            cin >> jugador2;
            rlutil::cls();
            rlutil::locate(40,10);

            while(puntosJug1<500 && puntosJug2<500)
            {


                //------------------------primer jugador-----------
                lanzamientos = 1;
                maxPuntuacion=0;
                for(x=1; x<=3; x++)
                {
                    panelEntreTurnos(jugador1, ronda, puntosJug1, maxPuntuacion, lanzamientos);




                    tirarDados(dados);

                    dibujarDados(dados);

                    ordenarDados(dados);
//-----------------COMBOS-----------------------
                    seis6(dados, &maxPuntuacion, &x);
                    escalera(dados, &puntuacionTurno, &x, &vEscalera);
                    sumarDados(dados, vEscalera, &puntuacionTurno);
                    trio(dados, &puntuacionTurno);
                    sexteto(dados, &puntuacionTurno);



                    tresLanzamientos(x, &puntuacionTurno, &maxPuntuacion, &antTurno);

                    lanzamientos++;
                    cout << endl;
                    system("pause");

                    rlutil::locate(40,10);
                }
                puntosJug1+=maxPuntuacion;

                cout << endl;

                rlutil::anykey();
                rlutil::cls();

                // -------------------------------------------------------------PANTALLA ENTRE TURNOS 1-------

                pantallaEntreTurnos(ronda, jugador2, jugador1, jugador2, puntosJug1, puntosJug2);

                //----------------------Segundo Jugador------------

                lanzamientos = 1;
                maxPuntuacion=0;
                for(x=1; x<=3; x++)
                {
                    panelEntreTurnos(jugador2, ronda, puntosJug2, maxPuntuacion, lanzamientos);

                    tirarDados(dados);

                    dibujarDados(dados);

                    ordenarDados(dados);
//----------------COMBOS----------------------
                    seis6(dados, &maxPuntuacion, &x);
                    escalera(dados, &puntuacionTurno, &x, &vEscalera);
                    sumarDados(dados, vEscalera, &puntuacionTurno);
                    trio(dados, &puntuacionTurno);
                    sexteto(dados, &puntuacionTurno);



                    tresLanzamientos(x, &puntuacionTurno, &maxPuntuacion, &antTurno);

                    lanzamientos++;

                    cout<<endl;
                    system("pause");
                    rlutil::locate(40,10);
                    rlutil::cls();

                }
                puntosJug2+=maxPuntuacion;
                ronda++;
                // -------------------------------------------------------------PANTALLA ENTRE TURNOS 2-------

                pantallaEntreTurnos(ronda, jugador1, jugador1, jugador2, puntosJug1, puntosJug2);


            }


        }

        rlutil::cls();

        if(cantidadJugadores==1)
        {

            ganador(jugador1, puntosJug1, ronda);

        }
        else
        {

            if(puntosJug1>500 && puntosJug2>500)
            {

                rlutil::locate(45,15);
                cout<<"Hubo un empate";
                rlutil::locate(45,16);
                cout <<"Con una cantidad de rondas de: " << ronda;
                system("pause");
                rlutil::cls();


            }
            else if(puntosJug2>puntosJug1)
            {
                {

                    ganador(jugador2, puntosJug2, ronda);

                }
            }
            else if(puntosJug1>puntosJug2)
            {

                ganador(jugador1, puntosJug1, ronda);

            }
        }

        cout << "Quiere seguir jugando?" << endl << "0=Si ; 1=No" << endl;
        cin >> seguirJugando;
    }

    return 0;
}



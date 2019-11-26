#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
int main()
{
    LinkedList* listaAerolinea = ll_newLinkedList();
    LinkedList* listaVuelosCortos=ll_newLinkedList();
    int respuesta;
    int opcion;
    do
    {
        getValidInt("1) Cargar archivo.\n2) Mostrar Vuelos.\n3) Filtrar vuelos cortos.\n4) Listar vuelos a Portugal.\n5) Filtrar a Alex Lifeson.\n6) Salir.\nElija una opcion: ","ERROR, Solo Numeros",1,6,&opcion);
        switch(opcion)
        {
        case 1:
            respuesta=controller_loadFromText("Vuelos.csv",listaAerolinea);
            switch(respuesta)
            {
            case 0:
                printf("Cargado exitosamente en Texto\n");
                pausa();
                break;
            case 1:
                borrar();
                printf("pFile no pudo ser abierto o ListaAerolinea es NULL\n");
                pausa();
                break;
            }
            break;
        case 2:
            controller_ListAerolineas(listaAerolinea);
            pausa();
            break;
        case 3:
            listaVuelosCortos=ll_filter(listaAerolinea,filterVuelosCortos);
            controller_saveAsText("VuelosCortos.txt",listaVuelosCortos);
            break;
        case 4:
            controller_vuelosPortugal(listaAerolinea);
            pausa();
            break;
        case 5:
            controller_NOAlexLifeson(listaAerolinea);
            pausa();
            break;
        case 6:
            break;
        }
        borrar();
    }
    while(opcion!=6);



    return 0;
}

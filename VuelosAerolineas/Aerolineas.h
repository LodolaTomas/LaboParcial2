#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[20];
    char destino[20];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

} eAerolinea;


eAerolinea* aerolinea_new(void);
eAerolinea* aerolinea_newParameters(char* idVuelosStr,char* idAvionStr,char* fechaStr,char* destinoStr,char* idPilotoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr);
int aerolineas_getIdVuelos(eAerolinea* this,int* idVuelos);
int aerolineas_setIdVuelos(eAerolinea* this,int idVuelos);
int aerolineas_getIdAvion(eAerolinea* this,int* idAvion);
int aerolineas_setIdAvion(eAerolinea* this,int idAvion);
int aerolineas_getFecha(eAerolinea* this,char* fecha);
int aerolineas_setFecha(eAerolinea* this,char* fecha);
int aerolineas_getDestino(eAerolinea* this,char* destino);
int aerolineas_setDestino(eAerolinea* this,char* destino);
int aerolineas_getIdPiloto(eAerolinea* this,int* idPiloto);
int aerolineas_setIdPiloto(eAerolinea* this,int idPiloto);
int aerolineas_getCantPasajeros(eAerolinea* this,int* cantPasajeros);
int aerolineas_setCantPasajeros(eAerolinea* this,int cantPasajeros);
int aerolineas_getHoraDespegue(eAerolinea* this,int* horaDespegue);
int aerolineas_setHoraDespegue(eAerolinea* this,int horaDespegue);
int aerolineas_getHoraLlegada(eAerolinea* this,int* horaLlegada);
int aerolineas_setHoraLlegada(eAerolinea* this,int horaLlegada);
void aerolineas_MostrarUno(eAerolinea* UnaAerolinea);
int filterVuelosCortos(void* pElement);
int filterNOAlexLifeson(void* pElement);
int filterPortugal(void* pElement);

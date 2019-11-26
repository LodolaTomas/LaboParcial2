#include "Aerolineas.h"


eAerolinea* aerolinea_new(void)
{
    eAerolinea* miAerolinea=NULL;
    miAerolinea=(eAerolinea*)malloc(sizeof(eAerolinea));
    if(miAerolinea!=NULL)
    {
        aerolineas_setIdVuelos(miAerolinea,0);
        aerolineas_setIdAvion(miAerolinea,0);
        aerolineas_setIdPiloto(miAerolinea,0);
        aerolineas_setFecha(miAerolinea,"");
        aerolineas_setDestino(miAerolinea,"");
        aerolineas_setCantPasajeros(miAerolinea,0);
        aerolineas_setHoraDespegue(miAerolinea,0);
        aerolineas_setHoraLlegada(miAerolinea,0);
    }
    return miAerolinea;
}

eAerolinea* aerolinea_newParameters(char* idVuelosStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr)
{
    eAerolinea* miAerolinea=NULL;
    miAerolinea=aerolinea_new();
    if(miAerolinea!=NULL)
    {
        aerolineas_setIdVuelos(miAerolinea,atoi(idVuelosStr));
        aerolineas_setIdAvion(miAerolinea,atoi(idAvionStr));
        aerolineas_setIdPiloto(miAerolinea,atoi(idPilotoStr));
        aerolineas_setFecha(miAerolinea,fechaStr);
        aerolineas_setDestino(miAerolinea,destinoStr);
        aerolineas_setCantPasajeros(miAerolinea,atoi(cantPasajerosStr));
        aerolineas_setHoraDespegue(miAerolinea,atoi(horaDespegueStr));
        aerolineas_setHoraLlegada(miAerolinea,atoi(horaLlegadaStr));
    }
    return miAerolinea;
}
int aerolineas_getIdVuelos(eAerolinea* this,int* idVuelos)
{
    int retorno=0;
    if(this!=NULL && idVuelos!=NULL)
    {
        *idVuelos=this->idVuelo;
        retorno=1;
    }
    return retorno;

}
int aerolineas_setIdVuelos(eAerolinea* this,int idVuelos)
{
    int retorno=0;
    if(this!=NULL && idVuelos>=0)
    {
        this->idVuelo=idVuelos;
        retorno=1;
    }
    return retorno;

}
int aerolineas_getIdAvion(eAerolinea* this,int* idAvion)
{
    int retorno=0;
    if(this!=NULL && idAvion!=NULL)
    {
        *idAvion=this->idAvion;
        retorno=1;
    }
    return retorno;
}
int aerolineas_setIdAvion(eAerolinea* this,int idAvion)
{
    int retorno=0;
    if(this!=NULL && idAvion>=0)
    {
        this->idAvion=idAvion;
        retorno=1;
    }
    return retorno;
}
int aerolineas_getFecha(eAerolinea* this,char* fecha)
{
    int retorno=0;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=1;
    }
    return retorno;
}
int aerolineas_setFecha(eAerolinea* this,char* fecha)
{
    int retorno=0;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=1;
    }
    return retorno;
}
int aerolineas_getDestino(eAerolinea* this,char* destino)
{
    int retorno=0;
    if(this!=NULL && destino!=NULL)
    {
        strcpy(destino,this->destino);
        retorno=1;
    }
    return retorno;

}
int aerolineas_setDestino(eAerolinea* this,char* destino)
{
    int retorno=0;
    if(this!=NULL && destino!=NULL)
    {
        strcpy(this->destino,destino);
        retorno=1;
    }
    return retorno;
}
int aerolineas_getIdPiloto(eAerolinea* this,int* idPiloto)
{
    int retorno=0;
    if(this!=NULL && idPiloto!=NULL)
    {
        *idPiloto=this->idPiloto;
        retorno=1;
    }
    return retorno;
}
int aerolineas_setIdPiloto(eAerolinea* this,int idPiloto)
{
    int retorno=0;
    if(this!=NULL && idPiloto>=0)
    {
        this->idPiloto=idPiloto;
        retorno=1;
    }
    return retorno;
}
int aerolineas_getCantPasajeros(eAerolinea* this,int* cantPasajeros)
{
    int retorno=0;
    if(this!=NULL && cantPasajeros!=NULL)
    {
        *cantPasajeros=this->cantPasajeros;
        retorno=1;
    }
    return retorno;
}
int aerolineas_setCantPasajeros(eAerolinea* this,int cantPasajeros)
{
    int retorno=0;
    if(this!=NULL && cantPasajeros>=0)
    {
        this->cantPasajeros=cantPasajeros;
        retorno=1;
    }
    return retorno;
}
int aerolineas_getHoraDespegue(eAerolinea* this,int* horaDespegue)
{
    int retorno=0;
    if(this!=NULL && horaDespegue!=NULL)
    {
        *horaDespegue=this->horaDespegue;
        retorno=1;
    }
    return retorno;
}
int aerolineas_setHoraDespegue(eAerolinea* this,int horaDespegue)
{
    int retorno=0;
    if(this!=NULL && horaDespegue>=0)
    {
        this->horaDespegue=horaDespegue;
        retorno=1;
    }
    return retorno;
}
int aerolineas_getHoraLlegada(eAerolinea* this,int* horaLlegada)
{
    int retorno=0;
    if(this!=NULL && horaLlegada!=NULL)
    {
        *horaLlegada=this->horaLlegada;
        retorno=1;
    }
    return retorno;
}
int aerolineas_setHoraLlegada(eAerolinea* this,int horaLlegada)
{
    int retorno=0;
    if(this!=NULL && horaLlegada>=0)
    {
        this->horaLlegada=horaLlegada;
        retorno=1;
    }
    return retorno;
}
void aerolineas_MostrarUno(eAerolinea* unaAerolinea)
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char piloto[50];
    char fecha[50];
    char destino[20];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    if(unaAerolinea!=NULL)
    {
        aerolineas_getIdVuelos(unaAerolinea,&idVuelo);
        aerolineas_getIdAvion(unaAerolinea,&idAvion);
        aerolineas_getIdPiloto(unaAerolinea,&idPiloto);
        aerolineas_getFecha(unaAerolinea,fecha);
        aerolineas_getDestino(unaAerolinea,destino);
        aerolineas_getCantPasajeros(unaAerolinea,&cantPasajeros);
        aerolineas_getHoraDespegue(unaAerolinea,&horaDespegue);
        aerolineas_getHoraLlegada(unaAerolinea,&horaLlegada);
        switch(idPiloto)
        {
        case 1:
            strcpy(piloto,"Alex Lifeson");
            break;
        case 2:
            strcpy(piloto,"Richard Bach");
            break;
        case 3:
            strcpy(piloto,"John Kerry");
            break;
        case 4:
            strcpy(piloto,"Erwin Rommel");
            break;
        case 5:
            strcpy(piloto,"Stephen Coonts");
            break;
        }
        printf("%5d %10d %20s %15s %15s %15d %15d %15d\n",idVuelo,idAvion,piloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
    }

}
int filterVuelosCortos(void* pElement)
{
    int retorno=0;
    int horaLlegada;
    int horaDespegue;
    int duracionVuelo;
    eAerolinea* unaAerolinea=(eAerolinea*)pElement;
    aerolineas_getHoraDespegue(unaAerolinea,&horaDespegue);
    aerolineas_getHoraLlegada(unaAerolinea,&horaLlegada);
    duracionVuelo=horaLlegada-horaDespegue;
    if(duracionVuelo<3)
    {
        retorno=1;
    }
    return retorno;
}
int filterPortugal(void* pElement)
{
    int retorno=0;
    char destino[50];
    eAerolinea* unaAerolinea=(eAerolinea*)pElement;
    aerolineas_getDestino(unaAerolinea,destino);
    if(strcmp(destino,"Portugal")==0)
    {
        retorno=1;
    }
    return retorno;
}
int filterNOAlexLifeson(void* pElement)
{
    int retorno=0;
    int piloto;
    eAerolinea* unaAerolinea=(eAerolinea*)pElement;
    aerolineas_getIdPiloto(unaAerolinea,&piloto);
    if(piloto!=1)
    {
        retorno=1;
    }
    return retorno;
}

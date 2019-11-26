#include "Controller.h"


int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int state=1;//1 sino pudo abrir el archivo
    FILE* pArchive=fopen(path,"r");

    if(pArchive!=NULL && pArrayList!=NULL)
    {
        state=parser_AerolineasFromText(pArchive,pArrayList);//=-1 si pArrayList es NULL
        //=0 si fue exitoso
    }
    return state;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayList)
{
    int state=1;//1 si el archivo no pudo ser abierto
    FILE* pArchivo=fopen(path,"rb");

    if(pArchivo!=NULL && pArrayList!=NULL)
    {
        state=parser_AerolineasFromBinary(pArchivo,pArrayList);
    }

    return state;
}

int controller_ListAerolineas(LinkedList* pArrayList)
{
    int state=-1;
    int i;
    int len;
    eAerolinea* this=NULL;

    if(pArrayList!=NULL)
    {
        borrar();
        len=ll_len(pArrayList);
        if(len!=0)
        {
            printf("******************************************************************************************************************************\n");
            printf("%5s %10s %14s %15s %18s %20s %15s %15s\n","ID_VUELO","ID_AVION","PILOTO","FECHA","DESTINO","CANT_PASAJEROS","HORA_DESPEGUE","HORA_LLEGADA");
            printf("******************************************************************************************************************************\n");

            for(i=0; i<len; i++)
            {
                this=(eAerolinea*)ll_get(pArrayList,i);
                aerolineas_MostrarUno(this);
            }
            printf("******************************************************************************************************************************\n");
            state=0;
        }
        else
        {
            printf("LA LISTA ESTA VACIA\n");
        }
    }
    return state;
}


int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int state=-1;
    int i;
    eAerolinea* this=NULL;
    int len;
    FILE* pArchivo=fopen(path,"w");

    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[20];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int counter=0;

    if(pArchivo!=NULL && pArrayList!=NULL)
    {
        fprintf(pArchivo,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
        len=ll_len(pArrayList);
        for(i=0; i<len; i++)
        {
            this=(eAerolinea*)ll_get(pArrayList,i);
            aerolineas_getIdVuelos(this,&idVuelo);
            aerolineas_getIdAvion(this,&idAvion);
            aerolineas_getIdPiloto(this,&idPiloto);
            aerolineas_getFecha(this,fecha);
            aerolineas_getDestino(this,destino);
            aerolineas_getCantPasajeros(this,&cantPasajeros);
            aerolineas_getHoraDespegue(this,&horaDespegue);
            aerolineas_getHoraLlegada(this,&horaLlegada);
            fprintf(pArchivo,"%d,%d,%d,%s,%s,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
            counter++;
        }
        state=0;
        fclose(pArchivo);
        printf("Fueron guardados: %d\n",counter);//idea de passu
    }
    return state;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayList)
{
    int state=-1;
    int i;
    int len;
    eAerolinea* this=NULL;
    int counter=0;
    FILE* pArchivo=fopen(path,"wb");//abro el archivo en modo write binary

    if(pArchivo!=NULL && pArrayList!=NULL)//Verifico que nada sea NULL
    {
        len=ll_len(pArrayList);
        for(i=0; i<len; i++) //Recorro el Array de empleados
        {
            this=(eAerolinea*)ll_get(pArrayList,i);//obtengo el empleado en la posicion i
            fwrite(this,sizeof(eAerolinea),1,pArchivo);//y lo escribo en el archivo
            counter++;
        }
        state=0;
        printf("Fueron Guardados: %d\n",counter);//idea de passu
        fclose(pArchivo);//Cierro el archivo
    }

    return state;
}

void controller_vuelosPortugal(LinkedList* this)
{


    LinkedList* listaVuelosPortugal=ll_newLinkedList();
    if(this!=NULL && listaVuelosPortugal!=NULL)
    {

        listaVuelosPortugal=ll_filter(this,filterPortugal);
        controller_ListAerolineas(listaVuelosPortugal);
    }
    else
    {
        printf("LA LISTA ESTA VACIA\n");
    }

}
void controller_NOAlexLifeson(LinkedList* this)
{


    LinkedList* listaNoAlexLifeson=ll_newLinkedList();
    if(this!=NULL)
    {
        listaNoAlexLifeson=ll_filter(this,filterNOAlexLifeson);
        controller_ListAerolineas(listaNoAlexLifeson);
    }
    else
    {
        printf("LA LISTA ESTA VACIA\n");
    }
}



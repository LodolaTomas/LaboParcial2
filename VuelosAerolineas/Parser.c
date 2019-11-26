#include "Parser.h"

int parser_AerolineasFromText(FILE* pFile, LinkedList* pArrayList)
{
    int state=1;
    int counter=0;
    eAerolinea* this=NULL;
    char idVueloStr[20];
    char idAvionStr[20];
    char idPilotoStr[20];
    char fechaStr[20];
    char destinoStr[50];
    char cantPasajerosStr[20];
    char horaDespegueStr[20];
    char horaLlegadaStr[20];

    if(pFile!=NULL && pArrayList!=NULL)//Verifico que lo ingresado sea
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVueloStr,idAvionStr,idPilotoStr,fechaStr,destinoStr,cantPasajerosStr,horaDespegueStr,horaLlegadaStr);//Falsa lectura
        //leo el primer renglon
        while(!feof(pFile))//leo el archivo hasta el final
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVueloStr,idAvionStr,idPilotoStr,fechaStr,destinoStr,cantPasajerosStr,horaDespegueStr,horaLlegadaStr);//leo datos del archivo
            this=aerolinea_newParameters(idVueloStr,idAvionStr,idPilotoStr,fechaStr,destinoStr,cantPasajerosStr,horaDespegueStr,horaLlegadaStr);//agrego los parametros en mi aux
            ll_add(pArrayList,this);//los agrego al LinkedList
            counter++;
        }
        state=0;//Cambio el estado
        fclose(pFile);
        printf("Fueron cargados : %d\n",counter);//idea de passu
    }
    return state;
}

int parser_AerolineasFromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int state=1;//1 si pArrayListEmployee o pFIle son NULL
    eAerolinea* this;
    int counter=0;
    if(pFile!=NULL && pArrayList!=NULL)//Verifico que no sea NULL
    {
        while(!feof(pFile))//Recorro hasta el final del archivo
        {
            this=aerolinea_new();//creo un empleadoAux
            if(this!=NULL)
            {
                fread(this,sizeof(eAerolinea),1,pFile);//guardo en el aux lo de tipo FILE
                if(feof(pFile))
                {
                    break;
                }
                ll_add(pArrayList,this);//lo agrego la linkedList
                counter++;
            }
        }
        state=0;//cambio el estado
        fclose(pFile);//cierro el archivo
        printf("Fueron cargados : %d\n",counter);//idea de passu
    }
    return state;// -1 si pFile o pArrayLinkedList es NULL
    // 0 si todo salio correctamente
}

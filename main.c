#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>

int main(){
    Rede *rede;
    rede = (Rede*)malloc(sizeof(Rede));
    rede->nClinicas = 0;
    //atribuirValoresTeste(rede);   
    menu(rede);
    free(rede);
}
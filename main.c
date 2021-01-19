#include <stdio.h>
#include "funcoes.h"
#include <string.h>
#include <stdlib.h>

/*
    Corrigir/Por fazer: 
        -> apontador ou outro metodo para acompanhar numero de clinicas criadas
*/

int main(){
    Rede *rede;
    rede = (Rede*)malloc(sizeof(Rede));

    rede->nClinicas = 0;

    atribuirValoresTeste(rede);
    
    menu(rede);

    free(rede);
}
/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>

/**
 * @brief 
 * 
 * @return int 
 */
int main(){
    Rede *rede;
    rede = (Rede*)malloc(sizeof(Rede));
    rede->nClinicas = 0;
    atribuirValoresTeste(rede);   
    menu(rede);
    free(rede);
}
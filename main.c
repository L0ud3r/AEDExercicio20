/**
 * @file main.c
 * @author Pedro Simões / Diogo Espírito Santo (a21140@alunos.ipca.pt / a21146@alunos.ipca.pt)
 * @brief Aplicação em C que gere uma rede de clinicas
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
 * @brief Main que contem declaracao de uma nova variavel *rede, alocacao de memoria nessa variavel
 *        inicializar numero de Clinicas a 0, executa o menu(rede) onde o programa inteiro funciona, por fim
 *        libertacao da memoria anteriormente alocada
 * 
 * @return int 
 */
int main(){
    Rede *rede;
    rede = (Rede*)malloc(sizeof(Rede));
    rede->nClinicas = 0;
    menu(rede);
    free(rede);
}
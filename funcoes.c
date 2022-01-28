/**
 * @file funcoes.c
 * @author Pedro Simões / Diogo Espírito Santo (a21140@alunos.ipca.pt / a21146@alunos.ipca.pt)
 * @brief Documento .c que contem todas as funções utilizadas para fazer o programa
 * @version 0.1
 * @date 2021-01-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include "funcoes.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Funcao que contem o menu principal da aplicacao
 * 
 * @param rede 
 */
void menu(Rede *rede){
    //Declaraçao de variaveis
    int opcao;
    
    //Enquanto o utilizador nao inserir -1, não sairá da aplicacao
    do
    {
        apresentacaoTitulo();

        printf("\n[1] ADICIONAR CLINICA   [2] ENTRAR CLINICA   [3] OPCOES RESOLUCAO DE EXERCICIOS\n\n[4] AJUDA   [5] REMOVER CLINICA   [-1] SAIR");
        printf("\n\nInsira a sua opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            criarFichaClinica(rede);
            break;
        case 2:
            mostrarListaClinicas(rede);
            break;
        case 3:
            mostrarListagens(rede);
            break;
        case 4:
            menuAjuda(rede);
            break;
        case 5:
            apagarClinica(rede);
            break;
        case -1:
            exit(0);
        default:
            break;
        }
    } while (opcao != -1);
}

/**
 * @brief Menu para mostrar as listagens impostas nos enunciados
 * 
 * @param rede 
 */
void mostrarListagens(Rede *rede){
    //Declaracao de variaveis
    int opcao;
    
    //Enquanto o utilizador nao introduzir -1, não sairá deste menu
    do{
        apresentacaoTitulo();

        printf("\n[1] LISTAGEM 1   [2] LISTAGEM 2   [3] LISTAGEM 3   \n[4] LISTAGEM 4   [-1] RETROCEDER");
        printf("\n\nInsira a sua opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            resumoIdadesVencimentos(rede);
            break;
        case 2:
            listarMedicosApenas(rede);
            break;
        case 3:
            contaAgenda(rede, escolhaClinica(rede));
            break;
        case 4:
            apresentaAgenda(rede);
            break;
        default:
            break;
        }
    } while (opcao != -1);
}

/**
 * @brief Funcao que limpa consola e mostra o titulo da aplicacao
 * 
 */
void apresentacaoTitulo(){
    system("cls");
    printf("\t\t/-----------------------------------\\\n\t\t| APP REDE CLINICAS VAMOS FICAR BEM |\n\t\t\\-----------------------------------/\n");
}

/**
 * @brief Janela que mostra informaçao que ajuda o utilizador a interagir com a app
 * 
 * @param rede 
 */
void menuAjuda(Rede *rede){
    printf("\nBem-vindo a APP da Rede Clinica 'VAMOS TODOS FICAR BEM'.\n\n   -> Para marcar uma consulta, va a ENTRAR CLINICA e de seguida clique em AGENDAR CONSULTA, onde ira\nregistar-se inserido o seu nome, sns e data da consulta.\n");
    printf("\n   -> Se quiser criar uma ficha de um profissional de saude, mais uma vez, clique em ENTRAR CLINICA e de\nseguida clique em CRIAR FICHA FUNCIONARO.\n");
    printf("\n   -> Para criar uma clinica, no menu inicial clique em CRIAR CLINICA.\n\nPara mais informacoes, contacte-nos: 253 000 000");

    printf("\n\nPrima Enter para continuar");
    fflush(stdin);
    getchar();
}

/**
 * @brief Funcao que permite criar uma clinica
 * 
 * @param rede 
 */
void criarFichaClinica(Rede *rede){

    //Declaracao das variaveis
    char nomeAux[TAMNOMECLINICA];
    int teste = rede->nClinicas;

    apresentacaoTitulo();
    
    //Se o utilizador introduzir 'cancelar', retrocede
    printf("\n\nInsira 'cancelar' para voltar a pagina anterior");
    printf("\n\nIntroduza o nome na clinica a adicionar na rede: ");
    fgets(nomeAux, TAMNOME, stdin);
    nomeAux[strlen(nomeAux) - 1] = '\0';

    if (strcasecmp(nomeAux, "cancelar") == 0)
    {
        return;
    }
    
    //Armazena nome na clinica de indice nClinicas atual
    strcpy(rede->clinicas[teste].nomeClinica, nomeAux);
    rede->clinicas[rede->nClinicas].id = rede->indiceMaximo + 1;

    rede->clinicas[rede->nClinicas].nFuncionarios = 0;
    rede->clinicas[rede->nClinicas].nMedicos = 0;
    rede->clinicas[rede->nClinicas].nEnfermeiros = 0;
    rede->clinicas[rede->nClinicas].nAuxiliares = 0;
    rede->clinicas[rede->nClinicas].indiceMaximo = 0;
    rede->clinicas[rede->nClinicas].valido = true;

    //Incrementa indice para proxima clinica
    rede->nClinicas++;
    rede->indiceMaximo++;
}

/**
 * @brief Mostra a ficha de um funcionario a escolha do utilizador
 * 
 * @param rede 
 */
void mostrarListaClinicas(Rede *rede){
    //Declaracao de variaveis
    int opcao;

    apresentacaoTitulo();

    //Se nao houver clinicas criadas, avisa utilizador e retrocede
    if (rede->nClinicas <= 0){
        printf("AINDA NAO FOI ADICIONADA NENHUMA CLINICA!\n\n");
        printf("Pressione Enter para continuar");
        fflush(stdin);
        getchar();
        return;
    }

    printf("\nInsira -1 para retroceder\nEscolha uma clinica:\n\n");

    //Mostra lista de clinicas
    for (int i = 0; i < rede->nClinicas; i++)
    {
        if (rede->clinicas[i].valido == true) printf("[%d] - %s\n", rede->clinicas[i].id, rede->clinicas[i].nomeClinica);
    }

    printf("Clinica -> ");
    scanf("%d", &opcao);

    if (opcao == -1)
    {
        return;
    }

    while (opcao < 1 || opcao > rede->nClinicas)
    {
        printf("Insira uma clinica valida-> ");
        scanf("%d", &opcao);
    }

    //Entra na clinica escolhida
    menuClinica(&rede->clinicas[opcao - 1]);    
}

/**
 * @brief Menu que permite gerir clinica e marcar consultas
 * 
 * @param clinica 
 */
void menuClinica(Clinica *clinica){
    //Declaracao de variaveis
    int opcao;
    
    //Enquanto nao introduzir -1, nao sairá deste menu
    do
    {
        apresentacaoTitulo();

        printf("\n[1] ADICIONAR FUNCIONARIO   [2] MARCAR CONSULTA   [3] VER FICHA FUNCIONARIO\n[4] APAGAR FUNCIONARIO  [-1] RETROCEDER");
        printf("\n\nInsira a sua opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
    
        switch (opcao)
        {
        case 1:
            criarFichaFuncionario(clinica);
            break;
        case 2:
            marcarConsulta(clinica);
            break;
        case 3:
            verFichaFuncionario(clinica);
            break;
        case 4:
            apagarFuncionario(clinica);
            break;
        default:
            break;
        }
    } while (opcao != -1);
}

/**
 * @brief Funcao que inativa uma clinica, "removendo-a"
 * 
 * @param rede 
 */
void apagarClinica(Rede *rede){
    int opcao, indice = -1;

    apresentacaoTitulo();

    if (rede->nClinicas <= 0){
        printf("Ainda nao foi adicionada nenhuma clinica!\n\nPressione ENTER para continuar");
        fflush(stdin);
        getchar();
        return;
    }

    printf("\nInsira -1 para retroceder\nEscolha uma clinica:\n");

    for (int i = 0; i < rede->nClinicas; i++)
    {   
        printf("[%d] - %s\n", rede->clinicas[i].id, rede->clinicas[i].nomeClinica);
    }
    printf("Clinica -> ");
    scanf("%d", &opcao);

    if (opcao == -1)
    {
        return;
    }
    

    for (int i = 0; i < rede->nClinicas; i++)
    {
        if (opcao == rede->clinicas[i].id)
        {
            indice = i;
        }
    }

    while (indice == -1)
    {
        printf("Clincia -> ");
        scanf("%d", &opcao);

        for (int i = 0; i < rede->nClinicas; i++)
        {
            if (opcao == rede->clinicas[i].id)
            {
                indice = i;
            }
        }
    }

    rede->clinicas[indice].valido = false;

    rede->nClinicas--;    
    printf("\nClinica %s removida com sucesso!", rede->clinicas[indice].nomeClinica);
    fflush(stdin);
    getchar();
}

/**
 * @brief Adicionar funcionario novo na clinica
 * 
 * @param clinica 
 */
void criarFichaFuncionario(Clinica *clinica){
    //Declaracao de variaveis
    char nomeAux[TAMNOME];

    apresentacaoTitulo();

    //para sair introduza no nome 'sair'
    printf("\nPara sair insira 'sair'\n");
    printf("NOME FUNCIONARIO: ");
    fgets(nomeAux, TAMNOME, stdin);
    nomeAux[strlen(nomeAux) - 1] = '\0';
    
    if (strcasecmp(nomeAux, "sair") == 0)
    {
        return;
    }

    strcpy(clinica->funcionarios[clinica->nFuncionarios].nome, nomeAux);

    printf("IDADE: ");
    scanf("%d", &clinica->funcionarios[clinica->nFuncionarios].idade);

    while (clinica->funcionarios[clinica->nFuncionarios].idade < 0)
    {
        printf("IDADE: ");
        scanf("%d", &clinica->funcionarios[clinica->nFuncionarios].idade);
    }

    fflush(stdin);
    printf("GENERO: ");
    scanf("%c", &clinica->funcionarios[clinica->nFuncionarios].genero);
    fflush(stdin);

    while (clinica->funcionarios[clinica->nFuncionarios].genero != 'm' && clinica->funcionarios[clinica->nFuncionarios].genero != 'M'
            && clinica->funcionarios[clinica->nFuncionarios].genero != 'f' && clinica->funcionarios[clinica->nFuncionarios].genero != 'F')
    {
        printf("GENERO: ");
        scanf("%c", &clinica->funcionarios[clinica->nFuncionarios].genero);
        fflush(stdin);
    }

    printf("\n[1] Medico   [2] Enfermeiro   [3] Auxiliar de saude\n");
    printf("PROFISSAO: ");
    scanf("%d", &clinica->funcionarios[clinica->nFuncionarios].profissao);

    while (clinica->funcionarios[clinica->nFuncionarios].profissao != 1 && clinica->funcionarios[clinica->nFuncionarios].profissao != 2
            && clinica->funcionarios[clinica->nFuncionarios].profissao != 3)
    {
        printf("\n[1] Medico   [2] Enfermeiro   [3] Auxiliar de saude\n");
        printf("PROFISSAO: ");
        scanf("%d", &clinica->funcionarios[clinica->nFuncionarios].profissao);
    }

    if(clinica->funcionarios[clinica->nFuncionarios].profissao == 1) clinica->nMedicos++;
    else if(clinica->funcionarios[clinica->nFuncionarios].profissao == 2) clinica->nEnfermeiros++;
    else if(clinica->funcionarios[clinica->nFuncionarios].profissao == 3) clinica->nAuxiliares++;

    printf("VENCIMENTO: ");
    scanf("%f", &clinica->funcionarios[clinica->nFuncionarios].vencimento);

    while (clinica->funcionarios[clinica->nFuncionarios].vencimento < 0)
    {
        printf("VENCIMENTO: ");
        scanf("%f", &clinica->funcionarios[clinica->nFuncionarios].vencimento);
    }
    fflush(stdin);

    //ID a partir do indice mais alto no array de funcionarios, 0 compromissos e é valido
    clinica->funcionarios[clinica->nFuncionarios].id = clinica->indiceMaximo + 1;
    clinica->funcionarios[clinica->nFuncionarios].nCompromissos = 0;
    clinica->funcionarios[clinica->nFuncionarios].valido = true;
    clinica->nFuncionarios++;
    clinica->indiceMaximo++;
}

/**
 * @brief Funcao para marcar consulta com um medico ou enfermeiro
 * 
 * @param clinica 
 */
void marcarConsulta(Clinica *clinica){
    //Declaracao de variaveis
    int opcao, indice = -1, tempSNS, contador = 0;

    apresentacaoTitulo();

    //Se nao houver medicos ou enfermeiros, avisa e retrocede
    if (clinica->nMedicos <= 0 && clinica->nEnfermeiros <= 0){
        printf("Ainda nao foi adicionado nenhum medico ou enfermeiro a esta clinica!\n\nPressione ENTER para continuar");
        fflush(stdin);
        getchar();
        return;
    }

    printf("\nInsira -1 para retroceder\nEscolha um profissional:\n");

    for (int i = 0; i < clinica->nFuncionarios; i++)
    {   
        if (clinica->funcionarios[i].valido == true)
        {
            if (clinica->funcionarios[i].profissao == 1 || clinica->funcionarios[i].profissao == 2){
                printf("[%d] - %s ", clinica->funcionarios[i].id, clinica->funcionarios[i].nome);
                
                if (clinica->funcionarios[i].profissao == 1) printf("(medico/a)\n");
                else if (clinica->funcionarios[i].profissao == 2) printf("(enfermeiro/a)\n");
            }
        }
    }
    printf("Profissional -> ");
    scanf("%d", &opcao);

    if (opcao == -1)
    {
        return;
    }
    

    for (int i = 0; i < clinica->nFuncionarios; i++)
    {
        if (clinica->funcionarios[i].valido == true){
            if (opcao == clinica->funcionarios[i].id)
            {
                indice = i;
            }
        }
    }

    while (indice == -1)
    {
        printf("Profissional -> ");
        scanf("%d", &opcao);

        for (int i = 0; i < clinica->nFuncionarios; i++)
        {
            if (clinica->funcionarios[i].valido == true){
                if (opcao == clinica->funcionarios[i].id)
                {
                    indice = i;
                }
            }
        }
    }
    
    fflush(stdin);
    printf("\nInsira nome do utente: ");
    fgets(clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].nome, TAMNOME, stdin);
    clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].nome[strlen(clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].nome) - 1] = '\0';

    printf("Insira o numero SNS do utente: ");
    scanf("%d", &tempSNS);

    while ((tempSNS / 100000000) < 1 || (tempSNS / 100000000) > 9)
    {   
        printf("Insira SNS valido: ");
        scanf("%d", &tempSNS);
    }
    
    clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].sns = tempSNS;

    fflush(stdin);
    printf("Insira a data da consulta (dd/mm/aa): ");
    scanf("%d/%d/%d", &clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.dia, &clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.mes, &clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.ano);
    
    while (clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.ano < 2019 || clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.ano > 3000 || clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.mes > 12 || clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.mes < 1 && clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.dia < 1 || clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.dia > 31)
    {   
        fflush(stdin);
        printf("Insira a data da consulta (dd/mm/aa): ");
        scanf("%d/%d/%d", &clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.dia, &clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.mes, &clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].data.ano);
    }
    
    clinica->funcionarios[indice].nCompromissos++;
    return;
}

/**
 * @brief Funcao que torna o funcionario invalido, de forma a "apaga-lo"
 * 
 * @param clinica 
 */
void apagarFuncionario(Clinica *clinica){
    int opcao, indice = -1;

    apresentacaoTitulo();

    if (clinica->nFuncionarios <= 0){
        printf("Ainda nao foi adicionado nenhum funcionario a esta clinica!\n\nPressione ENTER para continuar");
        fflush(stdin);
        getchar();
        return;
    }

    printf("\nInsira -1 para retroceder\nEscolha um profissional:\n");

    for (int i = 0; i < clinica->nFuncionarios; i++)
    {   
        printf("[%d] - %s ", clinica->funcionarios[i].id, clinica->funcionarios[i].nome);
        if (clinica->funcionarios[i].profissao == 1) printf("(medico/a)\n");
        else if (clinica->funcionarios[i].profissao == 2) printf("(enfermeiro/a)\n");
        else if (clinica->funcionarios[i].profissao == 3) printf("(auxiliar)\n");
    }
    printf("Profissional -> ");
    scanf("%d", &opcao);

    if (opcao == -1)
    {
        return;
    }
    

    for (int i = 0; i < clinica->nFuncionarios; i++)
    {
        if (opcao == clinica->funcionarios[i].id)
        {
            indice = i;
        }
    }

    while (indice == -1)
    {
        printf("Profissional -> ");
        scanf("%d", &opcao);

        for (int i = 0; i < clinica->nFuncionarios; i++)
        {
            if (opcao == clinica->funcionarios[i].id)
            {
                indice = i;
            }
        }
    }

    clinica->funcionarios[indice].valido = false;

    if (clinica->funcionarios[indice].profissao == 1) clinica->nMedicos--;
    else if (clinica->funcionarios[indice].profissao == 2) clinica->nEnfermeiros--;
    else if (clinica->funcionarios[indice].profissao == 3) clinica->nAuxiliares--;
    
    printf("\nProfissional de saude %s removido com sucesso!", clinica->funcionarios[indice].nome);
    fflush(stdin);
    getchar();
}

/**
 * @brief Funcao que faz o utilizador escolher um funcionario de saude
 *        e mostra a sua ficha de funcionario
 * 
 * @param clinica 
 */
void verFichaFuncionario(Clinica *clinica){
    int opcao, indice = -1;

    apresentacaoTitulo();

    if (clinica->nFuncionarios == 0)
    {
        printf("\n\nNenhum funcionario adicionado ainda!\nPressione Enter para continuar");
        fflush(stdin);
        getchar();
        return;
    }
    

    printf("\nInsira -1 para retroceder\nEscolha um profissional:\n");

    for (int i = 0; i < clinica->nFuncionarios; i++)
    {   
        if (clinica->funcionarios[i].valido == true){
            printf("[%d] - %s ", clinica->funcionarios[i].id, clinica->funcionarios[i].nome);
            if (clinica->funcionarios[i].profissao == 1) printf("(medico/a)\n");
            else if (clinica->funcionarios[i].profissao == 2) printf("(enfermeiro/a)\n");
            else printf("(auxiliar)\n");
        }
    }
    printf("Profissional -> ");
    scanf("%d", &opcao);
    if(opcao == -1) return;
    do
    {
        indice = -1;

        for (int i = 0; i < clinica->nFuncionarios; i++)
        {
            if (clinica->funcionarios[i].valido == true){
                if (opcao == clinica->funcionarios[i].id) indice = i;
            }
        }

        while (indice == -1)
        {
            printf("Profissional -> ");
            scanf("%d", &opcao);
            if(opcao == -1) return;

            for (int i = 0; i < clinica->nFuncionarios; i++)
            {
                if (clinica->funcionarios[i].valido == true){
                    if (opcao == clinica->funcionarios[i].id) indice = i;
                }
            }
        }

        printf("\n\n---------- Ficha de Profissional de Saude ----------\n");
        printf("NOME: %s\n", clinica->funcionarios[indice].nome);
        printf("IDADE: %d\n", clinica->funcionarios[indice].idade);
        printf("GENERO: ");
        if (clinica->funcionarios[indice].genero == 'm' || clinica->funcionarios[indice].genero == 'M') printf("Masculino\n");
        else printf("Feminino\n");
        printf("PROFISSAO: ");
        if (clinica->funcionarios[indice].profissao == 1) printf("Medico/a\n");
        else if (clinica->funcionarios[indice].profissao == 2) printf("Enfermeiro/a\n");
        else printf("Auxiliar\n");
        printf("VENCIMENTO: %.2f\n", clinica->funcionarios[indice].vencimento);
        printf("NUMERO DE CONSULTAS MARCADAS: %d\n\n", clinica->funcionarios[indice].nCompromissos);

        printf("\n\nPressione ENTER para continuar");
        fflush(stdin);
        getchar();
        apresentacaoTitulo();

        printf("\nInsira -1 para retroceder\nEscolha um profissional:\n");

        for (int i = 0; i < clinica->nFuncionarios; i++)
        {   
            if (clinica->funcionarios[i].valido == true){  
                printf("[%d] - %s ", clinica->funcionarios[i].id, clinica->funcionarios[i].nome);
                if (clinica->funcionarios[i].profissao == 1) printf("(medico/a)\n");
                else if (clinica->funcionarios[i].profissao == 2) printf("(enfermeiro/a)\n");
                else printf("(auxiliar)\n");
            }
        }
        printf("Profissional -> ");
        scanf("%d", &opcao);

        if(opcao == -1) return;

    } while (opcao != -1);

    return;
}

/**
 * @brief Funcao para escolher uma clinica
 * 
 * @param rede 
 * @return int 
 */
int escolhaClinica(Rede *rede){
    int opcao;

    apresentacaoTitulo();

    if (rede->nClinicas <= 0){
        return -1;
    }

    printf("\nInsira -1 para retroceder\nEscolha uma clinica:\n\n");

    for (int i = 0; i < rede->nClinicas; i++)
    {
        if (rede->clinicas[i].valido == true) printf("[%d] - %s\n", rede->clinicas[i].id, rede->clinicas[i].nomeClinica);
    }

    do
    {
        printf("Clinica -> ");
        scanf("%d", &opcao);

        if (opcao == -1) return -1;
    } while (rede->clinicas[opcao - 1].valido != true);
    
    return (opcao - 1);
}

/**
 * @brief Listagem 1: Mostra media de idades, total de profissionais de saude e somatorio de salario
 *        de cada profissao, de cada genero, tudo por clinica
 * 
 * @param rede 
 */
void resumoIdadesVencimentos(Rede *rede){

    apresentacaoTitulo();

    if (rede->nClinicas == 0){
        printf("Aplicacao nao tem nenhuma clinica adicionada ainda!\n\n");
        printf("Pressione ENTER para continuar");
        fflush(stdin);
        getchar();
        return;
    }

    int somaTotalIdades;
    float somaTotalVencimentosEnfMasc, somaTotalVencimentosEnfFem, somaTotalVencimentosMedMasc, somaTotalVencimentosMedFem, somaTotalVencimentosAuxMasc, somaTotalVencimentosAuxFem;

    for (int i = 0; i < rede->nClinicas; i++)
    {
        if (rede->clinicas[i].valido == true){
            somaTotalIdades = 0;
            somaTotalVencimentosEnfFem = 0.0F;
            somaTotalVencimentosEnfMasc = 0.0F;
            somaTotalVencimentosMedMasc = 0.0F;
            somaTotalVencimentosMedFem = 0.0F;
            somaTotalVencimentosAuxMasc = 0.0F;
            somaTotalVencimentosAuxFem = 0.0F;

            for (int j = 0; j < rede->clinicas[i].nFuncionarios; j++)
            {
                if (rede->clinicas[i].funcionarios[j].valido == true){
                    if (rede->clinicas[i].funcionarios[j].profissao == 3)
                    {
                        if (rede->clinicas[i].funcionarios[j].genero == 'm') somaTotalVencimentosAuxMasc = somaTotalVencimentosAuxMasc + rede->clinicas[i].funcionarios[j].vencimento;
                        else somaTotalVencimentosAuxFem = somaTotalVencimentosAuxFem + rede->clinicas[i].funcionarios[j].vencimento;
                    }
                    else if (rede->clinicas[i].funcionarios[j].profissao == 1)
                    {
                        if (rede->clinicas[i].funcionarios[j].genero == 'm') somaTotalVencimentosMedMasc = somaTotalVencimentosMedMasc + rede->clinicas[i].funcionarios[j].vencimento;
                        else somaTotalVencimentosMedFem = somaTotalVencimentosMedFem + rede->clinicas[i].funcionarios[j].vencimento;
                    }
                    else if (rede->clinicas[i].funcionarios[j].profissao == 2)
                    {
                        if (rede->clinicas[i].funcionarios[j].genero == 'm') somaTotalVencimentosEnfMasc = somaTotalVencimentosEnfMasc + rede->clinicas[i].funcionarios[j].vencimento;
                        else somaTotalVencimentosEnfFem = somaTotalVencimentosEnfFem + rede->clinicas[i].funcionarios[j].vencimento;
                    }

                    somaTotalIdades = somaTotalIdades + rede->clinicas[i].funcionarios[j].idade;
                }
            }

            if (rede->clinicas[i].nFuncionarios == 0)
            {
                printf("Clinica %s nao tem funcionarios ainda adicionados!\n\n", rede->clinicas[i].nomeClinica);
            }
            else
            {
                printf("Clinica %s:\n - Quantidade de funcionarios na clinica %s: %d\n - Media de idades de funcionarios na clinica %s: %.1f\n\n", rede->clinicas[i].nomeClinica, rede->clinicas[i].nomeClinica, rede->clinicas[i].nFuncionarios, rede->clinicas[i].nomeClinica, ((float)somaTotalIdades/rede->clinicas[i].nFuncionarios));
                printf("           \n - Medicos:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n", "", somaTotalVencimentosMedMasc, "", somaTotalVencimentosMedFem);
                printf("           \n - Enfermeiros:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n", "", somaTotalVencimentosEnfMasc, "", somaTotalVencimentosEnfFem);
                printf("           \n - Auxiliar:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n\n", "", somaTotalVencimentosAuxMasc, "", somaTotalVencimentosAuxFem);
            }
        }
    }

    printf("\nPressione ENTER para continuar");
    fflush(stdin);
    getchar();
    return;
}

/**
 * @brief Mostrar ficha de todos os medicos, por clinica e somatorio de todos os vencimentos deles
 * 
 * @param rede 
 */
void listarMedicosApenas(Rede *rede){

    apresentacaoTitulo();

    if (rede->nClinicas == 0){
        printf("Aplicacao nao tem nenhuma clinica adicionada ainda!\n\n");
        printf("Pressione ENTER para continuar");
        fflush(stdin);
        getchar();
        return;
    }

    float somatorio = 0.0F;
    
    printf("\nVENCIMENTO DE TODOS OS MEDICOS DA REDE:\n");
    for (int i = 0; i < rede->nClinicas; i++)
    {
        if (rede->clinicas[i].valido == true)
        {
            if (rede->clinicas[i].nMedicos > 0)
            {
                printf("\nCLINICA %s:\n\n", rede->clinicas[i].nomeClinica);
                for (int j = 0; j < rede->clinicas[i].nFuncionarios; j++)
                {
                    if (rede->clinicas[i].funcionarios[j].valido == true){
                        if (rede->clinicas[i].funcionarios[j].profissao == 1)
                        {
                            printf("\n\n---------- Ficha de Profissional de Saude ----------\n");
                            printf("NOME: %s\n", rede->clinicas[i].funcionarios[j].nome);
                            printf("IDADE: %d\n", rede->clinicas[i].funcionarios[j].idade);
                            printf("GENERO: ");
                            if (rede->clinicas[i].funcionarios[j].genero == 'm' || rede->clinicas[i].funcionarios[j].genero == 'M') printf("Masculino\n");
                            else printf("Feminino\n");
                            printf("PROFISSAO: ");
                            if (rede->clinicas[i].funcionarios[j].profissao == 1) printf("Medico/a\n");
                            else if (rede->clinicas[i].funcionarios[j].profissao == 2) printf("Enfermeiro/a\n");
                            else printf("Auxiliar\n");
                            printf("VENCIMENTO: %.2f\n", rede->clinicas[i].funcionarios[j].vencimento);
                            printf("NUMERO DE CONSULTAS MARCADAS: %d\n\n", rede->clinicas[i].funcionarios[j].nCompromissos);
                            somatorio += rede->clinicas[i].funcionarios[j].vencimento;
                        }
                    }
                }
            }
            else if (rede->clinicas[i].nMedicos <= 0) printf("\nCLINCIA %s nao tem medicos ainda!\n", rede->clinicas[i].nomeClinica);
        }
    }

    if (rede->clinicas->nFuncionarios != 0) printf("\nTOTAL DE TODOS OS VENCIMENTOS: %.2f", somatorio);

    printf("\nPressione ENTER para continuar");
    fflush(stdin);
    getchar();
    return;
}

/**
 * @brief Conta numero de consultas de um enfermeiro
 * 
 * @param rede 
 * @param indice 
 */
void contaAgenda(Rede *rede, int indice){

    int contador;

    apresentacaoTitulo();

    if (rede->nClinicas <= 0){
        printf("APLICACAO NAO TEM NENHUMA CLINICA ADICIONADA AINDA\n\n");
        printf("Pressione ENTER para continuar");
        fflush(stdin);
        getchar();
        return;
    }
    
    if (rede->clinicas[indice].nEnfermeiros <= 0)
    {
        printf("\n\nNENHUM FUNCIONARIO ADICIONADO AINDA!\nPressione Enter para continuar");
        fflush(stdin);
        getchar();
        indice = escolhaClinica(rede);
        apresentacaoTitulo();
    }

    if (indice == -1) return;

    for (int i = 0; i < rede->clinicas[indice].nFuncionarios; i++)
    {   
        if (rede->clinicas[indice].valido)
            {
            contador = 0;
            
            if (rede->clinicas[indice].funcionarios[i].valido == true){
                if (rede->clinicas[indice].funcionarios[i].profissao == 2)
                {
                    contador += rede->clinicas[indice].funcionarios[i].nCompromissos;
                    printf("Enfermeiro/a %s tem %d compromisso/s\n", rede->clinicas[indice].funcionarios[i].nome, contador);
                }
            }
        }
    }

    printf("\nPrima ENTER para continuar");
    fflush(stdin);
    getchar();
    return;
}

/**
 * @brief Mostra a agenda de um medico ou enfermeiro
 * 
 * @param rede 
 */
void apresentaAgenda(Rede *rede){

    if (rede->nClinicas == 0){
        apresentacaoTitulo();
        printf("APLICACAO NAO TEM NENHUMA CLINICA ADICIONADA AINDA\n\n");
        printf("Pressione ENTER para continuar");
        fflush(stdin);
        getchar();
        return;
    }

    int indiceClinica = escolhaClinica(rede) , indiceFuncionario, opcao, indiceLimite = -1;
    
    while (rede->clinicas[indiceClinica].nFuncionarios <= 0)
    {
        apresentacaoTitulo();
        printf("\n\nNENHUM FUNCIONARIO ADICIONADO AINDA!\nPressione ENTER para continuar");
        fflush(stdin);
        getchar();
        indiceClinica = escolhaClinica(rede);
    }

    if (rede->clinicas[indiceClinica].nMedicos <= 0 && rede->clinicas[indiceClinica].nEnfermeiros <= 0){
        apresentacaoTitulo();
        printf("\nAINDA NAO FOI INTRODUZIDO NENHUM MEDICO OU ENFERMEIRO NESTA CLINICA!");
        fflush(stdin);
        getchar();
        return;
    }

    for (int i = 0; i < rede->clinicas[indiceClinica].nFuncionarios; i++)
    {
        if (rede->clinicas[indiceClinica].valido == true)
        {
            if (rede->clinicas[indiceClinica].funcionarios[i].valido == true){
                if (rede->clinicas[indiceClinica].funcionarios[i].profissao == 1 || rede->clinicas[indiceClinica].funcionarios[i].profissao == 2)
                {
                    if (indiceLimite < i) indiceLimite = i;
                }
            }
        }
    }

    apresentacaoTitulo();
    printf("\nInsira -1 para retroceder\nEscolha um profissional:\n\n");

    for (int i = 0; i < rede->clinicas[indiceClinica].nFuncionarios; i++)
    {   
        if (rede->clinicas[indiceClinica].valido == true)
        {
            if (rede->clinicas[indiceClinica].funcionarios[i].valido == true){
                if (rede->clinicas[indiceClinica].funcionarios[i].profissao != 3)
                {
                    printf("[%d] - %s ", rede->clinicas[indiceClinica].funcionarios[i].id, rede->clinicas[indiceClinica].funcionarios[i].nome);
                    if (rede->clinicas[indiceClinica].funcionarios[i].profissao == 1) printf("(medico/a)\n");
                    else if (rede->clinicas[indiceClinica].funcionarios[i].profissao == 2) printf("(enfermeiro/a)\n");
                }
            }
        }
    }

    printf("\nProfissional -> ");
    scanf("%d", &opcao);

    if (opcao == -1) return;
    while (opcao < 1 || opcao > indiceLimite + 1)
    {
        printf("Profissional -> ");
        scanf("%d", &opcao);
    }
    

    for (int i = 0; i < rede->clinicas[indiceClinica].nFuncionarios; i++)
    {
        if (rede->clinicas[indiceClinica].funcionarios->valido == true){
            if (opcao == rede->clinicas[indiceClinica].funcionarios[i].id) indiceFuncionario = i;
        }
    }

    printf("\nAgenda do profissional de saude %s:\n", rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].nome);
    if (rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].nCompromissos <= 0)
    {
        printf("Este profissional de saude ainda nao tem qualquer consulta marcada!\n");
        printf("\nPressione ENTER para continuar");
        fflush(stdin);
        getchar();
        return;
    }
    for (int i = 0; i < rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].nCompromissos; i++)
    {
        printf("  -DIA %d/%d/%d\n", rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].calendario[i].data.dia, rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].calendario[i].data.mes, rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].calendario[i].data.ano);
        printf("     -> NOME PACIENTE: %s\n", rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].calendario[i].nome);
        printf("     -> SNS DO PACIENTE: %d\n\n", rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].calendario[i].sns);
    }

    printf("\nPressione ENTER para continuar");
    fflush(stdin);
    getchar();
    return;
}
#include <stdio.h>
#include "funcoes.h"
#include <string.h>
#include <stdlib.h>

#pragma region VALORES TESTE

void atribuirValoresTeste(Rede *rede){
    //Numero clinicas
    rede->nClinicas = 4;

    //Nome e numero funcionarios em cada clinica 
    strcpy(rede->clinicas[0].nomeClinica, "S.Joao");
    strcpy(rede->clinicas[1].nomeClinica, "S.Jorge");
    strcpy(rede->clinicas[2].nomeClinica, "S.Maria");
    //Clinica DUMMY
    strcpy(rede->clinicas[3].nomeClinica, "S.DUMMY");

    rede->clinicas[0].nFuncionarios = 3;
    rede->clinicas[1].nFuncionarios = 3;
    rede->clinicas[2].nFuncionarios = 2;
    //Clinica DUMMY
    rede->clinicas[3].nFuncionarios = 1;
    rede->clinicas[0].id = 1;
    rede->clinicas[1].id = 2;
    rede->clinicas[2].id = 3;
    //Clinica DUMMY
    rede->clinicas[3].id = 4;

    rede->clinicas[0].nMedicos = 2;
    rede->clinicas[0].nEnfermeiros = 1;
    rede->clinicas[0].nAuxiliares = 0;
    rede->clinicas[1].nMedicos = 0;
    rede->clinicas[1].nEnfermeiros = 1;
    rede->clinicas[1].nAuxiliares = 2;
    rede->clinicas[2].nMedicos = 0;
    rede->clinicas[2].nEnfermeiros = 1;
    rede->clinicas[2].nAuxiliares = 2;
    //Clinica DUMMY
    rede->clinicas[3].nMedicos = 0;
    rede->clinicas[3].nEnfermeiros = 0;
    rede->clinicas[3].nAuxiliares = 0;


    #pragma region Clinica1

        #pragma region Funcionario1

        strcpy(rede->clinicas[0].funcionarios[0].nome, "Pedro");
        rede->clinicas[0].funcionarios[0].id = 1;
        rede->clinicas[0].funcionarios[0].idade = 25;
        rede->clinicas[0].funcionarios[0].vencimento = 1550.50;
        rede->clinicas[0].funcionarios[0].profissao = 1;
        rede->clinicas[0].funcionarios[0].genero = 'm';
        rede->clinicas[0].funcionarios[0].nCompromissos = 2;
        strcpy(rede->clinicas[0].funcionarios[0].calendario[0].nome, "S.Antonio");
        rede->clinicas[0].funcionarios[0].calendario[0].sns = 845761354;
        strcpy(rede->clinicas[0].funcionarios[0].calendario[0].dataTeste, "17/12/2021");
        strcpy(rede->clinicas[0].funcionarios[0].calendario[1].nome, "S.Maria");
        rede->clinicas[0].funcionarios[0].calendario[1].sns = 778546213;
        strcpy(rede->clinicas[0].funcionarios[0].calendario[1].dataTeste, "15/12/2021");
        rede->clinicas[0].funcionarios[0].valido = true;
        
        #pragma endregion
        
        #pragma region Funcionario2
        strcpy(rede->clinicas[0].funcionarios[1].nome, "Joao");
        rede->clinicas[0].funcionarios[1].id = 2;
        rede->clinicas[0].funcionarios[1].idade = 20;
        rede->clinicas[0].funcionarios[1].vencimento = 2000.50;
        rede->clinicas[0].funcionarios[1].profissao = 1;
        rede->clinicas[0].funcionarios[1].nCompromissos = 1;
        rede->clinicas[0].funcionarios[1].genero = 'm';
        strcpy(rede->clinicas[0].funcionarios[1].calendario[0].nome, "S.Jose");
        rede->clinicas[0].funcionarios[1].calendario[0].sns = 789456132;
        strcpy(rede->clinicas[0].funcionarios[1].calendario[0].dataTeste, "16/03/2021");
        rede->clinicas[0].funcionarios[1].valido = true;

        #pragma endregion

        #pragma region Funcionario3
        strcpy(rede->clinicas[0].funcionarios[2].nome, "Maria");
        rede->clinicas[0].funcionarios[2].id = 3;
        rede->clinicas[0].funcionarios[2].idade = 35;
        rede->clinicas[0].funcionarios[2].vencimento = 3500.50;
        rede->clinicas[0].funcionarios[2].profissao = 2;
        rede->clinicas[0].funcionarios[2].nCompromissos = 1;
        rede->clinicas[0].funcionarios[2].genero = 'f';
        strcpy(rede->clinicas[0].funcionarios[2].calendario[0].nome, "S.Manel");
        rede->clinicas[0].funcionarios[2].calendario[0].sns = 784568722;
        strcpy(rede->clinicas[0].funcionarios[2].calendario[0].dataTeste, "16/03/2021");
        rede->clinicas[0].funcionarios[2].valido = false;
        #pragma endregion
    #pragma endregion

    #pragma region Clinica2

        #pragma region Funcionario1

        strcpy(rede->clinicas[1].funcionarios[0].nome, "Diogo");
        rede->clinicas[1].funcionarios[0].id = 1;
        rede->clinicas[1].funcionarios[0].idade = 25;
        rede->clinicas[1].funcionarios[0].vencimento = 2562.50;
        rede->clinicas[1].funcionarios[0].profissao = 2;
        rede->clinicas[1].funcionarios[0].genero = 'm';
        rede->clinicas[1].funcionarios[0].nCompromissos = 2;
        strcpy(rede->clinicas[1].funcionarios[0].calendario[0].nome, "S.Olivia");
        rede->clinicas[1].funcionarios[0].calendario[0].sns = 458721365;
        strcpy(rede->clinicas[1].funcionarios[0].calendario[0].dataTeste, "17/12/2021");
        strcpy(rede->clinicas[1].funcionarios[0].calendario[1].nome, "S.Ruca");
        rede->clinicas[1].funcionarios[0].calendario[1].sns = 485462153;
        strcpy(rede->clinicas[1].funcionarios[0].calendario[1].dataTeste, "18/12/2021");
        rede->clinicas[1].funcionarios[0].valido = false;

        #pragma endregion

        #pragma region Funcionario2
        strcpy(rede->clinicas[1].funcionarios[1].nome, "Pedro");
        rede->clinicas[1].funcionarios[1].id = 2;
        rede->clinicas[1].funcionarios[1].idade = 25;
        rede->clinicas[1].funcionarios[1].vencimento = 1550.50;
        rede->clinicas[1].funcionarios[1].profissao = 3;
        rede->clinicas[1].funcionarios[1].genero = 'm';
        rede->clinicas[1].funcionarios[1].valido = true;
        #pragma endregion

        #pragma region Funcionario3
        strcpy(rede->clinicas[1].funcionarios[2].nome, "Jacare");
        rede->clinicas[1].funcionarios[2].id = 3;
        rede->clinicas[1].funcionarios[2].idade = 25;
        rede->clinicas[1].funcionarios[2].vencimento = 1550.50;
        rede->clinicas[1].funcionarios[2].profissao = 3;
        rede->clinicas[1].funcionarios[2].genero = 'm';
        rede->clinicas[1].funcionarios[2].valido = true;
        #pragma endregion

    #pragma endregion

    #pragma region Clinica3
        #pragma region Funcionario1

        strcpy(rede->clinicas[2].funcionarios[0].nome, "Diogo");
        rede->clinicas[2].funcionarios[0].id = 1;
        rede->clinicas[2].funcionarios[0].idade = 25;
        rede->clinicas[2].funcionarios[0].vencimento = 44000.50;
        rede->clinicas[2].funcionarios[0].profissao = 2;
        rede->clinicas[2].funcionarios[0].genero = 'm';
        rede->clinicas[2].funcionarios[0].nCompromissos = 2;
        strcpy(rede->clinicas[2].funcionarios[0].calendario[0].nome, "S.Olivia");
        rede->clinicas[2].funcionarios[0].calendario[0].sns = 458721365;
        strcpy(rede->clinicas[2].funcionarios[0].calendario[0].dataTeste, "17/12/2021");
        strcpy(rede->clinicas[2].funcionarios[0].calendario[1].nome, "S.Ruca");
        rede->clinicas[2].funcionarios[0].calendario[1].sns = 485462153;
        strcpy(rede->clinicas[2].funcionarios[0].calendario[1].dataTeste, "18/12/2021");
        rede->clinicas[2].funcionarios[0].valido = true;

        #pragma endregion

        #pragma region Funcionario2
        strcpy(rede->clinicas[2].funcionarios[1].nome, "ZEzocas");
        rede->clinicas[2].funcionarios[1].id = 2;
        rede->clinicas[2].funcionarios[1].idade = 40;
        rede->clinicas[2].funcionarios[1].vencimento = 468.50;
        rede->clinicas[2].funcionarios[1].profissao = 3;
        rede->clinicas[2].funcionarios[1].genero = 'm';
        rede->clinicas[2].funcionarios[1].valido = false;

        #pragma endregion

        #pragma region Funcionario3
        strcpy(rede->clinicas[2].funcionarios[2].nome, "Rikzinho");
        rede->clinicas[2].funcionarios[2].id = 3;
        rede->clinicas[2].funcionarios[2].idade = 32;
        rede->clinicas[2].funcionarios[2].vencimento = 999.50;
        rede->clinicas[2].funcionarios[2].profissao = 3;
        rede->clinicas[2].funcionarios[2].genero = 'm';
        rede->clinicas[2].funcionarios[2].valido = true;
        #pragma endregion

    #pragma endregion

    strcpy(rede->clinicas[3].funcionarios[0].nome, "Rikzinho");
    rede->clinicas[3].funcionarios[0].id = 3;
    rede->clinicas[3].funcionarios[0].idade = 32;
    rede->clinicas[3].funcionarios[0].vencimento = 999.50;
    rede->clinicas[3].funcionarios[0].profissao = 3;
    rede->clinicas[3].funcionarios[0].genero = 'm';
    rede->clinicas[2].funcionarios[2].valido = false;

}

#pragma endregion

//CONCLUIDO FIX FALTA APAGAR CLINICAS
void menu(Rede *rede){
    int opcao;
    
    do
    {
        apresentacaoTitulo();

        printf("\n[1] ADICIONAR CLINICA   [2] ENTRAR CLINICA   [3] OPCOES RESOLUCAO DE EXERCICIOS   [4] AJUDA   [-1] SAIR");
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
            mostrarExercicios(rede);
            break;
        case 4:
            menuAjuda(rede);
            break;
        case -1:
            exit(0);
        default:
            break;
        }
    } while (opcao != -1);
}

//CONCLUIDO FIX
void mostrarExercicios(Rede *rede){
    int opcao;
    
    do{
        apresentacaoTitulo();

        printf("\n[1] PONTO 1   [2] PONTO 2   [3] PONTO 3   \n[4] PONTO 4   [-1] RETROCEDER");
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

//CONCLUIDO FIX
void apresentacaoTitulo(){
    system("cls");
    printf("\t\t/-----------------------------------\\\n\t\t| APP REDE CLINICAS VAMOS FICAR BEM |\n\t\t\\-----------------------------------/\n");
}

//CONCLUIDO FIX
void menuAjuda(Rede *rede){
    printf("\nBem-vindo a APP da Rede Clinica 'VAMOS TODOS FICAR BEM'.\n\n   -> Para marcar uma consulta, va a ENTRAR CLINICA e de seguida clique em AGENDAR CONSULTA, onde ira\nregistar-se inserido o seu nome, sns e data da consulta.\n");
    printf("\n   -> Se quiser criar uma ficha de um profissional de saude, mais uma vez, clique em ENTRAR CLINICA e de\nseguida clique em CRIAR FICHA FUNCIONARO.\n");
    printf("\n   -> Para criar uma clinica, no menu inicial clique em CRIAR CLINICA.\n\nPara mais informacoes, contacte-nos: 253 000 000");

    printf("\n\nPrima Enter para continuar");
    fflush(stdin);
    getchar();
}

//CONCLUIDO FIX
void criarFichaClinica(Rede *rede){

    char nomeAux[TAMNOMECLINICA];
    int teste = rede->nClinicas;

    apresentacaoTitulo();
    
    printf("\n\nInsira 'cancelar' para voltar a pagina anterior");
    printf("\n\nIntroduza o nome na clinica a adicionar na rede: ");
    fgets(nomeAux, TAMNOME, stdin);
    nomeAux[strlen(nomeAux) - 1] = '\0';

    if (strcasecmp(nomeAux, "cancelar") == 0)
    {
        return;
    }
    
    strcpy(rede->clinicas[teste].nomeClinica, nomeAux);
    rede->clinicas[rede->nClinicas].id = rede->nClinicas + 1;

    rede->clinicas[rede->nClinicas].nFuncionarios = 0;
    rede->clinicas[rede->nClinicas].nMedicos = 0;
    rede->clinicas[rede->nClinicas].nEnfermeiros = 0;
    rede->clinicas[rede->nClinicas].nAuxiliares = 0;
    rede->clinicas[rede->nClinicas].indiceMaximo = 0;

    rede->nClinicas++;
}

//CONCLUIDO FIX
void mostrarListaClinicas(Rede *rede){
    int opcao;

    apresentacaoTitulo();

    if (rede->nClinicas == 0){
        printf("AINDA NAO FOI ADICIONADA NENHUMA CLINICA!\n\n");
        printf("Pressione Enter para continuar");
        fflush(stdin);
        getchar();
        return;
    }

    printf("\nInsira -1 para retroceder\nEscolha uma clinica:\n\n");

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

    while (opcao < 1 || opcao > rede->nClinicas)
    {
        printf("Insira uma clinica valida-> ");
        scanf("%d", &opcao);
    }

    menuClinica(&rede->clinicas[opcao - 1], rede);    
}

//CONCLUIDO FIX APAGAR FUNIONARIOS
void menuClinica(Clinica *clinica, Rede *rede){
    int opcao;
    
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
            criarFichaFuncionario(clinica, rede);
            break;
        case 2:
            marcarConsulta(clinica, rede);
            break;
        case 3:
            verFichaFuncionario(clinica, rede);
            break;
        case 4:
            apagarFuncionario(clinica);
            break;
        default:
            break;
        }
    } while (opcao != -1);
}

//CONCLUIDO FIX
void criarFichaFuncionario(Clinica *clinica, Rede *rede){
    char nomeAux[TAMNOME];

    apresentacaoTitulo();

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

    clinica->funcionarios[clinica->nFuncionarios].id = clinica->indiceMaximo + 1;
    clinica->funcionarios[clinica->nFuncionarios].nCompromissos = 0;
    clinica->funcionarios[clinica->nFuncionarios].valido = true;
    clinica->nFuncionarios++;
    clinica->indiceMaximo++;
}

//CONCLUIDO FIX
void marcarConsulta(Clinica *clinica, Rede *rede){
    int opcao, indice = -1, tempSNS;

    apresentacaoTitulo();

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

    while ((tempSNS / 100000000) < 1 && (tempSNS / 100000000) > 9)
    {   
        printf("Insira SNS valido: ");
        scanf("%d", &tempSNS);
    }
    
    clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].sns = tempSNS;

    fflush(stdin);
    printf("Insira a data da consulta (dd/mm/aa): ");
    fgets(clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].dataTeste, 15, stdin);
    clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].nome[strlen(clinica->funcionarios[indice].calendario[clinica->funcionarios[indice].nCompromissos].nome) - 1] = '\0';
    
    clinica->funcionarios[indice].nCompromissos++;
    return;
}

//CONCLUIDO FIX
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

//CONCLUIDO FIX
void verFichaFuncionario(Clinica *clinica, Rede *rede){
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

    do
    {

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

    } while (opcao != -1);

    return;
}

//CONCLUIDO FIX POR FAZER
int escolhaClinica(Rede *rede){
    int opcao;

    apresentacaoTitulo();

    if (rede->nClinicas <= 0){
        return -1;
    }

    printf("\nInsira -1 para retroceder\nEscolha uma clinica:\n\n");

    for (int i = 0; i < rede->nClinicas; i++)
    {
        printf("[%d] - %s\n", rede->clinicas[i].id, rede->clinicas[i].nomeClinica);
    }

    printf("Clinica -> ");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > rede->nClinicas + 1)
    {
        printf("Insira uma clinica valida-> ");
        scanf("%d", &opcao);
    }
    
    if (opcao == -1)
    {
        menu(rede);
    }
    
    return (opcao - 1);
}

//Exercicio1 CONCLUIDO FIX
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
            printf("Clinica %s nao tem funcionarios ainda adicionados!\n\n");
        }
        else
        {
            printf("Clinica %s:\n - Quantidade de funcionarios na clinica %s: %d\n - Media de idades de funcionarios na clinica %s: %.1f\n\n", rede->clinicas[i].nomeClinica, rede->clinicas[i].nomeClinica, rede->clinicas[i].nFuncionarios, rede->clinicas[i].nomeClinica, ((float)somaTotalIdades/rede->clinicas[i].nFuncionarios));
            printf("           \n - Medicos:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n", "", somaTotalVencimentosMedMasc, "", somaTotalVencimentosMedFem);
            printf("           \n - Enfermeiros:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n", "", somaTotalVencimentosEnfMasc, "", somaTotalVencimentosEnfFem);
            printf("           \n - Auxiliar:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n\n", "", somaTotalVencimentosAuxMasc, "", somaTotalVencimentosAuxFem);
        }
    }

    printf("\nPressione ENTER para continuar");
    fflush(stdin);
    getchar();
    return;
}

//Exercicio2 CONCLUIDO FIX
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
        if (rede->clinicas[i].nMedicos > 0)
        {
            printf("\nCLINICA %s:\n\n", rede->clinicas[i].nomeClinica);
            for (int j = 0; j < rede->clinicas[i].nFuncionarios; j++)
            {
                if (rede->clinicas[i].funcionarios[j].valido == true){
                    if (rede->clinicas[i].funcionarios[j].profissao == 1)
                    {
                        printf("    -> NOME: %s\n", rede->clinicas[i].funcionarios[j].nome);
                        printf("    -> VENCIMENTO: %.2f\n\n", rede->clinicas[i].funcionarios[j].vencimento);
                        somatorio += rede->clinicas[i].funcionarios[j].vencimento;
                    }
                }
            }
        }
        else if (rede->clinicas[i].nMedicos <= 0) printf("\nCLINCIA %s nao tem medicos ainda!\n", rede->clinicas[i].nomeClinica);
    }

    printf("\nTOTAL DE TODOS OS VENCIMENTOS: %.2f", somatorio);

    printf("\nPressione ENTER para continuar");
    fflush(stdin);
    getchar();
    return;
}

//Exercicio3 CONCLUIDO FIX
void contaAgenda(Rede *rede, int indice){

    int contador;

    apresentacaoTitulo();

    if (rede->nClinicas <= 0){
        printf("Aplicacao nao tem nenhuma clinica adicionada ainda!\n\n");
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
        contador = 0;
        
        if (rede->clinicas[indice].funcionarios[i].valido == true){
            if (rede->clinicas[indice].funcionarios[i].profissao == 2)
            {
                contador += rede->clinicas[indice].funcionarios[i].nCompromissos;
                printf("Enfermeiro/a %s tem %d compromisso/s\n", rede->clinicas[indice].funcionarios[i].nome, contador);
            }
        }
    }

    printf("\nPrima ENTER para continuar");
    fflush(stdin);
    getchar();
    return;
}

//Exercicio4 CONCLUIDO FIX
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
        if (rede->clinicas[indiceClinica].funcionarios[i].valido == true){
            if (rede->clinicas[indiceClinica].funcionarios[i].profissao == 1 || rede->clinicas[indiceClinica].funcionarios[i].profissao == 2)
            {
                if (indiceLimite < i) indiceLimite = i;
            }
        }
    }

    apresentacaoTitulo();
    printf("\nInsira -1 para retroceder\nEscolha um profissional:\n\n");

    for (int i = 0; i < rede->clinicas[indiceClinica].nFuncionarios; i++)
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
        printf("  -DIA %s\n", rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].calendario[i].dataTeste);
        printf("     -> NOME PACIENTE: %s\n", rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].calendario[i].nome);
        printf("     -> SNS DO PACIENTE: %d\n\n", rede->clinicas[indiceClinica].funcionarios[indiceFuncionario].calendario[i].sns);
    }

    printf("\nPressione ENTER para continuar");
    fflush(stdin);
    getchar();
    return;
}
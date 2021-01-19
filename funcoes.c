#include <stdio.h>
#include "funcoes.h"
#include <string.h>
#include <stdlib.h>

/*
    Ideias para menu():
        -> apagar ficha medico (secundário)
        -> apagar clinica (secundário)
*/
void menu(Rede *rede){
    int opcao;
    
    apresentacaoTitulo();

    printf("\n[1] ADICIONAR CLINICA   [2] ENTRAR CLINICA   [3] OPCOES RESOLUCAO DE EXERCICIOS  \n\n[4] APAGAR CLINICA(por fazer)  [5] AJUDA");
    printf("\n\nInsira a sua opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);

    while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5)
    {
        printf("Insira a sua opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
    }

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
        
        break;
    case 5:
        menuAjuda();
        break;
    default:
        break;
    }
    
}

//Por fazer
void mostrarExercicios(Rede *rede){
    int opcao;
    
    apresentacaoTitulo();

    printf("\n[1] PONTO 1   [2] PONTO 2   [3] PONTO 3   [4] PONTO 4");
    printf("\n\nInsira a sua opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);

    while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4)
    {
        printf("Insira a sua opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
    }

    switch (opcao)
    {
    case 1:
        resumoIdadesVencimentos(rede);
        break;
    case 2:
        listarMedicosApenas(rede);
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    default:
        break;
    }
}

//CONCLUIDO
void apresentacaoTitulo(){
    system("cls");
    printf("\t\t/-----------------------------------\\\n\t\t| APP REDE CLINICAS VAMOS FICAR BEM |\n\t\t\\-----------------------------------/\n");
}

//CONCLUIDO
void menuAjuda(){
    printf("\nBem-vindo a APP da Rede Clinica 'VAMOS TODOS FICAR BEM'.\n\n   -> Para marcar uma consulta, va a ENTRAR CLINICA e de seguida clique em AGENDAR CONSULTA, onde ira\nregistar-se inserido o seu nome, sns e data da consulta.\n");
    printf("\n   -> Se quiser criar uma ficha de um profissional de saude, mais uma vez, clique em ENTRAR CLINICA e de\nseguida clique em CRIAR FICHA FUNCIONARO.\n");
    printf("\n   -> Para criar uma clinica, no menu inicial clique em CRIAR CLINICA.\n\nPara mais informacoes, contacte-nos: 253 000 000");
}

//CONCLUIDO
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
    //rede->clinicas[teste].nomeClinica;
    strcpy(rede->clinicas[teste].nomeClinica, nomeAux);
    rede->clinicas[rede->nClinicas].id = rede->nClinicas + 1;
    rede->clinicas[rede->nClinicas].nFuncionarios = 0;

    rede->nClinicas++;
    menu(rede);
}

//CONCLUIDO
void mostrarListaClinicas(Rede *rede){
    int opcao;

    apresentacaoTitulo();

    printf("\nInsira -1 para retroceder\nEscolha uma clinica:\n\n");

    for (int i = 0; i < rede->nClinicas; i++)
    {
        printf("[%d] - %s\n", rede->clinicas[i].id, rede->clinicas[i].nomeClinica);
    }

    printf("Clinica -> ");
    scanf("%d", &opcao);

    while (opcao < -1 && opcao > rede->nClinicas + 1)
    {
        printf("Insira uma clinica valida-> ");
        scanf("%d", &opcao);
    }
    
    if (opcao == -1)
    {
        return;
    }
    

    menuClinica(rede->clinicas[opcao - 1], rede);    
}

//Por fazer
void menuClinica(Clinica clinica, Rede *rede){
    int opcao;
    
    apresentacaoTitulo();

    printf("\n[1] ADICIONAR FUNCIONARIO   [2] MARCAR CONSULTA   [3] VER FICHA FUNCIONARIO   \n[4] APAGAR CLINICA(por fazer)   [-1] RETROCEDER");
    printf("\n\nInsira a sua opcao: ");
    scanf("%d", &opcao);
    fflush(stdin);

    while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != -1)
    {
        printf("Insira a sua opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
    }

    switch (opcao)
    {
    case 1:
        criarFichaFuncionario(clinica, rede);
        break;
    case 2:
        marcarConsulta(clinica, rede);
        break;
    case 3:
        verFichaFuncionario(clinica);
        break;
    case 4:
        
        break;
    case -1:
        menu(rede);
        break;
    default:
        break;
    }
}

//CONCLUIDO
void criarFichaFuncionario(Clinica clinica, Rede *rede){
    char nomeAux[TAMNOME];

    apresentacaoTitulo();

    printf("\nPara sair insira 'sair'\n");
    printf("NOME FUNCIONARIO: ");
    fgets(nomeAux, TAMNOME, stdin);
    nomeAux[strlen(nomeAux) - 1] = '\0';
    
    if (strcasecmp(nomeAux, "sair") == 0)
    {
        menuClinica(clinica, rede);
    }

    strcpy(clinica.funcionarios[clinica.nFuncionarios].nome, nomeAux);

    printf("IDADE: ");
    scanf("%d", &clinica.funcionarios[clinica.nFuncionarios].idade);

    while (clinica.funcionarios[clinica.nFuncionarios].idade < 0)
    {
        printf("IDADE: ");
        scanf("%d", &clinica.funcionarios[clinica.nFuncionarios].idade);
    }

    fflush(stdin);
    printf("GENERO: ");
    scanf("%c", &clinica.funcionarios[clinica.nFuncionarios].genero);
    fflush(stdin);

    while (clinica.funcionarios[clinica.nFuncionarios].genero != 'm' && clinica.funcionarios[clinica.nFuncionarios].genero != 'M'
            && clinica.funcionarios[clinica.nFuncionarios].genero != 'f' && clinica.funcionarios[clinica.nFuncionarios].genero != 'F')
    {
        printf("GENERO: ");
        scanf("%c", &clinica.funcionarios[clinica.nFuncionarios].genero);
        fflush(stdin);
    }

    printf("\n[1] Medico   [2] Enfermeiro   [3] Auxiliar de saude\n");
    printf("PROFISSAO: ");
    scanf("%d", &clinica.funcionarios[clinica.nFuncionarios].profissao);

    while (clinica.funcionarios[clinica.nFuncionarios].profissao != 1 && clinica.funcionarios[clinica.nFuncionarios].profissao != 2
            && clinica.funcionarios[clinica.nFuncionarios].profissao != 3)
    {
        printf("\n[1] Medico   [2] Enfermeiro   [3] Auxiliar de saude\n");
        printf("PROFISSAO: ");
        scanf("%d", &clinica.funcionarios[clinica.nFuncionarios].profissao);
    }

    printf("VENCIMENTO: ");
    scanf("%f", &clinica.funcionarios[clinica.nFuncionarios].vencimento);

    while (clinica.funcionarios[clinica.nFuncionarios].vencimento < 0)
    {
        printf("VENCIMENTO: ");
        scanf("%f", &clinica.funcionarios[clinica.nFuncionarios].vencimento);
    }
    

    clinica.funcionarios[clinica.nFuncionarios].id = clinica.nFuncionarios + 1;
    clinica.funcionarios[clinica.nFuncionarios].nCompromissos = 0;
    clinica.nFuncionarios++;

    menuClinica(clinica, rede);
}

//CONCLUIDO
void marcarConsulta(Clinica clinica, Rede *rede){
    int opcao, indice = -1, tempSNS;

    apresentacaoTitulo();

    printf("\nInsira -1 para retroceder\nEscolha um profissional:\n");

    for (int i = 0; i < clinica.nFuncionarios; i++)
    {   
        if (clinica.funcionarios[i].profissao == 1 || clinica.funcionarios[i].profissao == 2){
            printf("[%d] - %s ", clinica.funcionarios[i].id, clinica.funcionarios[i].nome);
            
            if (clinica.funcionarios[i].profissao == 1) printf("(medico/a)\n");
            else if (clinica.funcionarios[i].profissao == 2) printf("(enfermeiro/a)\n");
        }
    }
    printf("Profissional -> ");
    scanf("%d", &opcao);

    if (opcao == -1)
    {
        menuClinica(clinica, rede);
    }
    

    for (int i = 0; i < clinica.nFuncionarios; i++)
    {
        if (opcao == clinica.funcionarios[i].id)
        {
            indice = i;
        }
    }

    while (indice == -1)
    {
        printf("Profissional -> ");
        scanf("%d", &opcao);

        for (int i = 0; i < clinica.nFuncionarios; i++)
        {
            if (opcao == clinica.funcionarios[i].id)
            {
                indice = i;
            }
        }
    }
    
    fflush(stdin);
    printf("\nInsira nome do utente: ");
    fgets(clinica.funcionarios[indice].calendario[clinica.funcionarios[indice].nCompromissos].nome, TAMNOME, stdin);
    clinica.funcionarios[indice].calendario[clinica.funcionarios[indice].nCompromissos].nome[strlen(clinica.funcionarios[indice].calendario[clinica.funcionarios[indice].nCompromissos].nome) - 1] = '\0';

    printf("Insira o numero SNS do utente: ");
    scanf("%d", &tempSNS);

    while ((tempSNS / 100000000) < 1 && (tempSNS / 100000000) > 9)
    {   
        printf("Insira SNS valido: ");
        scanf("%d", &tempSNS);
    }
    
    clinica.funcionarios[indice].calendario[clinica.funcionarios[indice].nCompromissos].sns = tempSNS;

    fflush(stdin);
    printf("Insira a data da consulta (dia/mes/ano): ");
    fgets(clinica.funcionarios[indice].calendario[clinica.funcionarios[indice].nCompromissos].dataTeste, 15, stdin);
    clinica.funcionarios[indice].calendario[clinica.funcionarios[indice].nCompromissos].nome[strlen(clinica.funcionarios[indice].calendario[clinica.funcionarios[indice].nCompromissos].nome) - 1] = '\0';
    
    clinica.funcionarios[indice].nCompromissos++;
}

//CONCLUIDO
void verFichaFuncionario(Clinica clinica){
    int opcao, indice = -1;

    apresentacaoTitulo();

    printf("\nInsira -1 para retroceder\nEscolha um profissional:\n");

    for (int i = 0; i < clinica.nFuncionarios; i++)
    {   
        printf("[%d] - %s ", clinica.funcionarios[i].id, clinica.funcionarios[i].nome);
        if (clinica.funcionarios[i].profissao == 1) printf("(medico/a)\n");
        else if (clinica.funcionarios[i].profissao == 2) printf("(enfermeiro/a)\n");
        else printf("(auxiliar)\n");
    }
    printf("Profissional -> ");
    scanf("%d", &opcao);

    do
    {

        for (int i = 0; i < clinica.nFuncionarios; i++)
        {
            if (opcao == clinica.funcionarios[i].id) indice = i;
        }

        while (indice == -1)
        {
            printf("Profissional -> ");
            scanf("%d", &opcao);

            for (int i = 0; i < clinica.nFuncionarios; i++)
            {
                if (opcao == clinica.funcionarios[i].id) indice = i;
            }
        }

        printf("\n\n---------- Ficha de Profissional de Saude ----------\n");
        printf("NOME: %s\n", clinica.funcionarios[indice].nome);
        printf("IDADE: %d\n", clinica.funcionarios[indice].idade);
        printf("GENERO: ");
        if (clinica.funcionarios[indice].genero == 'm' || clinica.funcionarios[indice].genero == 'M') printf("Masculino\n");
        else printf("Feminino\n");
        printf("PROFISSAO: ");
        if (clinica.funcionarios[indice].profissao == 1) printf("Medico/a\n");
        else if (clinica.funcionarios[indice].profissao == 2) printf("Enfermeiro/a\n");
        else printf("Auxiliar\n");
        printf("VENCIMENTO: %.2f\n\n", clinica.funcionarios[indice].vencimento);

        printf("\nInsira -1 para retroceder\nEscolha um profissional:\n");

        for (int i = 0; i < clinica.nFuncionarios; i++)
        {   
            printf("[%d] - %s ", clinica.funcionarios[i].id, clinica.funcionarios[i].nome);
            if (clinica.funcionarios[i].profissao == 1) printf("(medico/a)\n");
            else if (clinica.funcionarios[i].profissao == 2) printf("(enfermeiro/a)\n");
            else printf("(auxiliar)\n");
        }
        printf("Profissional -> ");
        scanf("%d", &opcao);

    } while (opcao != -1);
}


/************************FAZER FUNCOES DE SELECAO DE MEDICOS/CLINICAS PARA OS EXERCICIOS*******************************/


//Exercicio1 CONCLUIDO
void resumoIdadesVencimentos(Rede *rede){

    apresentacaoTitulo();

    int somaTotalProfissionais, somaTotalIdades;
    float somaTotalVencimentosEnfMasc, somaTotalVencimentosEnfFem, somaTotalVencimentosMedMasc, somaTotalVencimentosMedFem, somaTotalVencimentosAuxMasc, somaTotalVencimentosAuxFem;

    for (int i = 0; i < rede->nClinicas; i++)
    {
        somaTotalIdades = 0;
        somaTotalProfissionais = 0;

        for (int j = 0; j < rede->clinicas[i].nFuncionarios; j++)
        {
            somaTotalProfissionais++;
            somaTotalIdades = somaTotalIdades + rede->clinicas[i].funcionarios[j].idade;
        }
        
        printf(" - Quantidade de funcionarios na clinica %s: %d\n - Media de idades de funcionarios na clinica %s: %.1f\n\n", rede->clinicas[i].nomeClinica, somaTotalProfissionais, rede->clinicas[i].nomeClinica, ((float)somaTotalIdades/somaTotalProfissionais));
    }
    
    for (int i = 0; i < rede->nClinicas; i++)
    {
        somaTotalVencimentosEnfFem = 0.0F;
        somaTotalVencimentosEnfMasc = 0.0F;
        somaTotalVencimentosMedMasc = 0.0F;
        somaTotalVencimentosMedFem = 0.0F;
        somaTotalVencimentosAuxMasc = 0.0F;
        somaTotalVencimentosAuxFem = 0.0F;

        for (int j = 0; j < rede->clinicas[i].nFuncionarios; j++)
        {
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
        }

        printf("Clinica %s:\n - Medicos:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n", rede->clinicas[i].nomeClinica, "", somaTotalVencimentosMedMasc, "", somaTotalVencimentosMedFem);
        printf("           \n - Enfermeiros:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n", "", somaTotalVencimentosEnfMasc, "", somaTotalVencimentosEnfFem);
        printf("           \n - Auxiliar:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n\n", "", somaTotalVencimentosAuxMasc, "", somaTotalVencimentosAuxFem);
    }
}

//Exercicio2 CONCLUIDO
void listarMedicosApenas(Rede *rede){

    float somatorio = 0.0F;
    
    printf("\nVENCIMENTO DE TODOS OS MEDICOS DA REDE:\n");
    for (int i = 0; i < rede->nClinicas; i++)
    {
        printf("\nCLINICA %s:\n", rede->clinicas[i].nomeClinica);
        for (int j = 0; j < rede->clinicas[i].nFuncionarios; j++)
        {
            if (rede->clinicas[i].funcionarios[j].profissao == 1)
            {
                printf("NOME: %s\n", rede->clinicas[i].funcionarios[j].nome);
                printf("VENCIMENTO: %.2f\n", rede->clinicas[i].funcionarios[j].vencimento);
                somatorio += rede->clinicas[i].funcionarios[j].vencimento;
            }
        }
    }
    printf("\nTOTAL DE TODOS OS VENCIMENTOS: %.2f", somatorio);
}

//Exercicio3 CONCLUIDO
void contaAgenda(Rede *rede, int opcao){
    int contador;

    for (int i = 0; i < rede->clinicas[opcao].nFuncionarios; i++)
    {
        contador = 0;
        if (rede->clinicas[opcao].funcionarios[i].profissao == 2)
        {
            contador += rede->clinicas[opcao].funcionarios[i].nCompromissos;
            printf("Enfermeiro/a %s tem %d compromisso/s\n", rede->clinicas[opcao].funcionarios[i].nome, contador);
        }
    }
}

//Exercicio4 CONCLUIDO
void apresentaAgenda(Funcionario funcionario){

    printf("Agenda do profissional de saude %s:\n", funcionario.nome);
    for (int i = 0; i < funcionario.nCompromissos; i++)
    {
        printf("  -DIA %s\n", funcionario.calendario[i].dataTeste);
        printf("     -> NOME PACIENTE: %s\n", funcionario.calendario[i].nome);
        printf("     -> SNS DO PACIENTE: %d\n\n", funcionario.calendario[i].sns);
    }
}
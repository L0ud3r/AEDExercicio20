#include <stdio.h>
#include "funcoes.h"
#include <string.h>
#include <stdlib.h>

/*
    Ideias para menu():
        -> criar clinica
        -> ficha medico
        -> apagar ficha medico (secundário)
        -> apagar clinica (secundário)
        -> meter opcoes dos exercícios
        -> agendar compromissos
*/
void menu(Rede rede){
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
        
        break;
    case 3:
        
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
void criarFichaClinica(Rede rede){
    char nomeAux[TAMNOMECLINICA];

    apresentacaoTitulo();
    
    printf("\n\nInsira 'cancelar' para voltar a pagina anterior");
    printf("\n\nIntroduza o nome na clinica a adicionar na rede: ");
    fgets(nomeAux, TAMNOME, stdin);
    nomeAux[strlen(nomeAux) - 1] = '\0';

    if (strcasecmp(nomeAux, "cancelar") == 0)
    {
        menu(rede);
    }
    
    strcpy(rede.clinicas[rede.nClinicas].nomeClinica, nomeAux);
    rede.nClinicas++;
}

//Funcao testa valores hardcode
/*
void testarValores(Clinica *clinica, int n){

    int id = 0;

//--------PARTE CLINICA---------
    clinica[0].nFuncionarios = 2;
    strcpy(clinica[0].nomeClinica, "Clinica de Enfias");

//--------PARTE FUNCIONARIOS---------
    strcpy(clinica[0].funcionarios[0].nome, "Pedro");
    clinica[0].funcionarios[0].idade = 20;
    clinica[0].funcionarios[0].profissao = 1;
    clinica[0].funcionarios[0].genero = 'm';
    clinica[0].funcionarios[0].vencimento = 1750.00;
    clinica[0].funcionarios[0].nCompromissos = 1;
    strcpy(clinica[0].funcionarios[0].calendario[0].nome, "Sr.Antonio");
    clinica[0].funcionarios[0].calendario[0].sns = 542136485;
    strcpy(clinica[0].funcionarios[0].calendario[0].dataTeste, "16/03/2021");
    

    strcpy(clinica[0].funcionarios[1].nome, "Josefina");
    clinica[0].funcionarios[1].idade = 23;
    clinica[0].funcionarios[1].profissao = 2;
    clinica[0].funcionarios[1].genero = 'f';
    clinica[0].funcionarios[1].vencimento = 2400.00;
    clinica[0].funcionarios[1].nCompromissos = 2;
    strcpy(clinica[0].funcionarios[1].calendario[0].nome, "Sr.Josue");
    clinica[0].funcionarios[1].calendario[0].sns = 54821236;
    strcpy(clinica[0].funcionarios[1].calendario[0].dataTeste, "15/05/2022");
    strcpy(clinica[0].funcionarios[1].calendario[1].nome, "Sra.Delfina");
    clinica[0].funcionarios[1].calendario[1].sns = 542136485;
    strcpy(clinica[0].funcionarios[1].calendario[1].dataTeste, "14/02/2021");

//--------PARTE CLINICA---------
    clinica[1].nFuncionarios = 3;
    strcpy(clinica[1].nomeClinica, "Clinica Privada de Braga");

//--------PARTE FUNCIONARIOS---------
    strcpy(clinica[1].funcionarios[0].nome, "Augusto");
    clinica[1].funcionarios[0].idade = 20;
    clinica[1].funcionarios[0].profissao = 1;
    clinica[1].funcionarios[0].genero = 'm';
    clinica[1].funcionarios[0].vencimento = 1750.00;
    clinica[1].funcionarios[0].nCompromissos = 3;
    strcpy(clinica[1].funcionarios[0].calendario[0].nome, "Sr.Josue");
    clinica[1].funcionarios[0].calendario[0].sns = 54821236;
    strcpy(clinica[1].funcionarios[0].calendario[0].dataTeste, "15/05/2022");
    strcpy(clinica[1].funcionarios[0].calendario[1].nome, "Sra.Delfina");
    clinica[1].funcionarios[0].calendario[1].sns = 54213648;
    strcpy(clinica[1].funcionarios[0].calendario[1].dataTeste, "14/02/2021");
    strcpy(clinica[1].funcionarios[0].calendario[2].nome, "Sr.Marco");
    clinica[1].funcionarios[0].calendario[2].sns = 46854263;
    strcpy(clinica[1].funcionarios[0].calendario[2].dataTeste, "15/05/2022");

    strcpy(clinica[1].funcionarios[1].nome, "Rita");
    clinica[1].funcionarios[1].idade = 23;
    clinica[1].funcionarios[1].profissao = 2;
    clinica[1].funcionarios[1].genero = 'f';
    clinica[1].funcionarios[1].vencimento = 2400.00;
    clinica[1].funcionarios[1].nCompromissos = 1;
    strcpy(clinica[1].funcionarios[1].calendario[0].nome, "Sra.Celeste");
    clinica[1].funcionarios[1].calendario[0].sns = 45657841;
    strcpy(clinica[1].funcionarios[1].calendario[0].dataTeste, "03/03/2022");


    strcpy(clinica[1].funcionarios[2].nome, "Jorge");
    clinica[1].funcionarios[2].idade = 45;
    clinica[1].funcionarios[2].profissao = 1;
    clinica[1].funcionarios[2].genero = 'm';
    clinica[1].funcionarios[2].vencimento = 4800.00;
    clinica[1].funcionarios[2].nCompromissos = 1;
    strcpy(clinica[1].funcionarios[2].calendario[0].nome, "Sr.Jorge");
    clinica[1].funcionarios[2].calendario[0].sns = 87564215;
    strcpy(clinica[1].funcionarios[2].calendario[0].dataTeste, "12/03/2022");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < clinica[i].nFuncionarios; j++)
        {
            clinica[i].funcionarios[j].id = id + 1;
        }
        
    }
    
}*/

//Exercicio1 CONCLUIDO
void resumoIdadesVencimentos(Rede rede){

    int somaTotalProfissionais, somaTotalIdades;
    float somaTotalVencimentosEnfMasc, somaTotalVencimentosEnfFem, somaTotalVencimentosMedMasc, somaTotalVencimentosMedFem, somaTotalVencimentosAuxMasc, somaTotalVencimentosAuxFem;

    for (int i = 0; i < rede.nClinicas; i++)
    {
        somaTotalIdades = 0;
        somaTotalProfissionais = 0;

        for (int j = 0; j < rede.clinicas[i].nFuncionarios; j++)
        {
            somaTotalProfissionais++;
            somaTotalIdades = somaTotalIdades + rede.clinicas[i].funcionarios[j].idade;
        }
        
        printf(" - Quantidade de funcionarios na clinica %s: %d\n - Media de idades de funcionarios na clinica %s: %.1f\n\n", rede.clinicas[i].nomeClinica, somaTotalProfissionais, rede.clinicas[i].nomeClinica, ((float)somaTotalIdades/somaTotalProfissionais));
    }
    
    for (int i = 0; i < rede.nClinicas; i++)
    {
        somaTotalVencimentosEnfFem = 0.0F;
        somaTotalVencimentosEnfMasc = 0.0F;
        somaTotalVencimentosMedMasc = 0.0F;
        somaTotalVencimentosMedFem = 0.0F;
        somaTotalVencimentosAuxMasc = 0.0F;
        somaTotalVencimentosAuxFem = 0.0F;

        for (int j = 0; j < rede.clinicas[i].nFuncionarios; j++)
        {
            if (rede.clinicas[i].funcionarios[j].profissao == 3)
            {
                if (rede.clinicas[i].funcionarios[j].genero == 'm') somaTotalVencimentosAuxMasc = somaTotalVencimentosAuxMasc + rede.clinicas[i].funcionarios[j].vencimento;
                else somaTotalVencimentosAuxFem = somaTotalVencimentosAuxFem + rede.clinicas[i].funcionarios[j].vencimento;
            }
            else if (rede.clinicas[i].funcionarios[j].profissao == 1)
            {
                if (rede.clinicas[i].funcionarios[j].genero == 'm') somaTotalVencimentosMedMasc = somaTotalVencimentosMedMasc + rede.clinicas[i].funcionarios[j].vencimento;
                else somaTotalVencimentosMedFem = somaTotalVencimentosMedFem + rede.clinicas[i].funcionarios[j].vencimento;
            }
            else if (rede.clinicas[i].funcionarios[j].profissao == 2)
            {
                if (rede.clinicas[i].funcionarios[j].genero == 'm') somaTotalVencimentosEnfMasc = somaTotalVencimentosEnfMasc + rede.clinicas[i].funcionarios[j].vencimento;
                else somaTotalVencimentosEnfFem = somaTotalVencimentosEnfFem + rede.clinicas[i].funcionarios[j].vencimento;
            }
        }

        printf("Clinica %s:\n - Medicos:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n", rede.clinicas[i].nomeClinica, "", somaTotalVencimentosMedMasc, "", somaTotalVencimentosMedFem);
        printf("           \n - Enfermeiros:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n", "", somaTotalVencimentosEnfMasc, "", somaTotalVencimentosEnfFem);
        printf("           \n - Auxiliar:\n%5s- Homens: %.2f\n%5s- Mulheres: %.2f\n\n", "", somaTotalVencimentosAuxMasc, "", somaTotalVencimentosAuxFem);
    }
}

//Exercicio2 CONCLUIDO
void listarMedicos(Rede rede){

    float somatorio = 0.0F;
    
    printf("\nVENCIMENTO DE TODOS OS MEDICOS DA REDE:\n");
    for (int i = 0; i < rede.nClinicas; i++)
    {
        printf("\nCLINICA %s:\n", rede.clinicas[i].nomeClinica);
        for (int j = 0; j < rede.clinicas[i].nFuncionarios; j++)
        {
            if (rede.clinicas[i].funcionarios[j].profissao == 1)
            {
                printf("NOME: %s\n", rede.clinicas[i].funcionarios[j].nome);
                printf("VENCIMENTO: %.2f\n", rede.clinicas[i].funcionarios[j].vencimento);
                somatorio += rede.clinicas[i].funcionarios[j].vencimento;
            }
        }
    }
    printf("\nTOTAL DE TODOS OS VENCIMENTOS: %.2f", somatorio);
}

//Exercicio3 CONCLUIDO
void contaAgenda(Rede rede, int opcao){
    int contador;

    for (int i = 0; i < rede.clinicas[opcao].nFuncionarios; i++)
    {
        contador = 0;
        if (rede.clinicas[opcao].funcionarios[i].profissao == 2)
        {
            contador += rede.clinicas[opcao].funcionarios[i].nCompromissos;
            printf("Enfermeiro/a %s tem %d compromisso/s\n", rede.clinicas[opcao].funcionarios[i].nome, contador);
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
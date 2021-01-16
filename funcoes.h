#define TAMNOME 20
#define TAMAGENDA 25
#define TAMFUNCIONARIOS 20
#define TAMNOMECLINICA 20
#define NUMCLINICAS 10

typedef struct{
    char nome[TAMNOME];
    int sns;
    char dataTeste[15];
} Utente;

typedef struct{
    char nome[TAMNOME], genero;
    int idade, profissao;
    float vencimento;
    Utente calendario[TAMAGENDA];
    int nCompromissos;
    int id;
} Funcionario;

typedef struct{
    char nomeClinica[TAMNOMECLINICA];
    Funcionario funcionarios[TAMFUNCIONARIOS];
    int nFuncionarios;
} Clinica;

typedef struct{
    Clinica clinicas[NUMCLINICAS];
    int nClinicas;
} Rede;

void resumoIdadesVencimentos(Rede rede);
void listarMedicos(Rede rede);
void contaAgenda(Rede rede, int opcao);
void apresentaAgenda(Funcionario funcionario);
void menu(Rede rede);
void menuAjuda();
void criarFichaClinica(Rede rede);
void apresentacaoTitulo();
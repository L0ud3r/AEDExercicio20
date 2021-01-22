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
    int idade, profissao, nCompromissos, id;
    float vencimento;
    Utente calendario[TAMAGENDA];
} Funcionario;

typedef struct{
    char nomeClinica[TAMNOMECLINICA];
    Funcionario funcionarios[TAMFUNCIONARIOS];
    int nFuncionarios, id, nMedicos, nEnfermeiros, nAuxiliares;
} Clinica;

typedef struct{
    Clinica clinicas[NUMCLINICAS];
    int nClinicas;
} Rede;

void resumoIdadesVencimentos(Rede *rede);
void listarMedicosApenas(Rede *rede);
void mostrarExercicios(Rede *rede);
void mostrarListaClinicas(Rede *rede);
void contaAgenda(Rede *rede, int indice);
void apresentaAgenda(Rede *rede);
void menu(Rede *rede);
void menuAjuda(Rede *rede);
void criarFichaClinica(Rede *rede);
void apresentacaoTitulo();
void menuClinica(Clinica clinica, Rede *rede);
void criarFichaFuncionario(Clinica *clinica, Rede *rede);
void marcarConsulta(Clinica *clinica, Rede *rede);
void verFichaFuncionario(Clinica *clinica, Rede *rede);
int escolhaClinica(Rede *rede);

void atribuirValoresTeste(Rede *rede);
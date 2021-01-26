/**
 * @brief Ficheiro .h com structs e assinaturas
 * 
 */
#define TAMNOME 20
#define TAMAGENDA 25
#define TAMFUNCIONARIOS 20
#define TAMNOMECLINICA 20
#define NUMCLINICAS 10

//Criacao de bool
typedef enum{false, true} bool;

//Criacao de struct para o formato da data
typedef struct{
    int dia, mes, ano;
} Data;

//Criacao de struct para cada paciente
typedef struct{
    char nome[TAMNOME];
    int sns;
    Data data;
} Utente;

//Criacao de struct para cada funcionario
typedef struct{
    char nome[TAMNOME], genero;
    int idade, profissao, nCompromissos, id;
    float vencimento;
    Utente calendario[TAMAGENDA];
    bool valido;
} Funcionario;

//Criacao de struct para cada clinica
typedef struct{
    char nomeClinica[TAMNOMECLINICA];
    Funcionario funcionarios[TAMFUNCIONARIOS];
    int nFuncionarios, id, nMedicos, nEnfermeiros, nAuxiliares, indiceMaximo;
    bool valido;
} Clinica;

//Criacao de struct para acompanhar valores de restantes structs e numero de clinicas
typedef struct{
    Clinica clinicas[NUMCLINICAS];
    int nClinicas, indiceMaximo;
} Rede;

//Assinatura de funcoes
void resumoIdadesVencimentos(Rede *rede);
void listarMedicosApenas(Rede *rede);
void mostrarListagens(Rede *rede);
void mostrarListaClinicas(Rede *rede);
void contaAgenda(Rede *rede, int indice);
void apresentaAgenda(Rede *rede);
void menu(Rede *rede);
void menuAjuda(Rede *rede);
void criarFichaClinica(Rede *rede);
void apresentacaoTitulo();
void menuClinica(Clinica *clinica);
void criarFichaFuncionario(Clinica *clinica);
void marcarConsulta(Clinica *clinica);
void verFichaFuncionario(Clinica *clinica);
int escolhaClinica(Rede *rede);
void apagarFuncionario(Clinica *clinica);
void apagarClinica(Rede *rede);
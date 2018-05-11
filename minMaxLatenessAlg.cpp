#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#ifdef WIN32
    #define LIMPA_TELA system("cls")
#else
    #define LIMPA_TELA system("clear")
#endif

//Caracterização de um JOB
typedef struct Jobs{
  char descricaoJob[25];
  int duracao;
  int deadline;
  int atraso;
  struct Jobs *proximo;
}Jobs;

//Declaração de funções
int menu();
void cabecalhoInsercao();
Jobs* insereJobs(Jobs *, char *, int, int);
void calculaAtraso(Jobs *);
void imprimeJobs(Jobs *);

int main(){
  int lateness, opcao, duracao, deadline;
  Jobs *jobs = NULL;
  char descricaoJob[25];

  do{
    opcao = menu();
    switch (opcao) {
      case 1:
        LIMPA_TELA;
        cabecalhoInsercao();
        printf("Digite a descricao do Evento que deseja inserir: ");
        scanf("%s", descricaoJob);

        LIMPA_TELA;
        cabecalhoInsercao();
        printf("Digite a duracao do Evento que deseja inserir: ");
        scanf("%d", &duracao);

        LIMPA_TELA;
        cabecalhoInsercao();
        printf("Digite o deadline do Evento que deseja inserir: ");
        scanf("%d", &deadline);

        jobs = insereJobs(jobs, descricaoJob, duracao, deadline);

        calculaAtraso(jobs);
        imprimeJobs(jobs);
      break;
      case 2:
        LIMPA_TELA;
        calculaAtraso(jobs);
        printf("\n ------------- Lista de Eventos -------------\n\n");
        imprimeJobs(jobs);
      break;
      case 0:
        LIMPA_TELA;
        printf("Programa finalizado!\n");
        break;
      default:
        LIMPA_TELA;
        printf("\nOpcao nao encontrada!!!!\n");
        break;
    }
  }while(opcao != 0);
  return 0;
}

//=============== SUBPROGRAMAS ==============

int menu(){
  int op;
  printf("\n\n----------- MINIMIZE MAXIMUM LATENESS -----------\n\n");
  printf("1 - Inserir Evento\n");
  printf("2 - Imprimir Lista de Eventos\n");
  printf("0 - SAIR\n\n");
  printf("Digite a opcao desejada: ");
  scanf("%d",&op);
  return op;
}


void cabecalhoInsercao(){
  printf("---------------------------------------------\n");
  printf("|              INSERINDO EVENTO             |\n");
  printf("---------------------------------------------\n");
}


Jobs* insereJobs(Jobs *jobs , char *descricaoJob, int duracao, int deadline){
  Jobs* aux = jobs;
  Jobs* novo;
  Jobs* anterior = NULL;
  int valor;

  novo = (Jobs*)malloc(sizeof(Jobs));
  if(novo == NULL){
    printf("\nAlocacao falhou\n");
    exit(1);
  }
  strcpy(novo->descricaoJob, descricaoJob);
  novo->duracao = duracao;
  novo->deadline = deadline;

  if(jobs == NULL){
    novo->proximo = NULL;
    jobs = novo;
  }else {
    while(aux != NULL && aux->deadline < deadline){
      anterior = aux;
      aux = aux->proximo;
    }
    novo->proximo = aux;

    if (anterior == NULL) {
      jobs = novo;
    }else {
      anterior->proximo = novo;
    }
  }
  printf("\nElemento inserido");
  return jobs;
}

void calculaAtraso(Jobs *jobs){
  int horarioTermino = 0;
  int atraso = 0;
  Jobs *aux = jobs;
  while(aux != NULL){
    horarioTermino += aux->duracao;
    atraso = horarioTermino - aux->deadline;
    if(atraso < 0){
      aux->atraso = 0;
    }else{
      aux->atraso = atraso;
    }
    aux = aux->proximo;
  }
}

void imprimeJobs(Jobs *jobs){
    int contadorEvento = 1;
    while(jobs != NULL)
    {
      printf("\n------------ Evento %d -------------\n", contadorEvento);
      printf("Descricao do evento: %s\n", jobs->descricaoJob);
      printf("Duracao do evento: %d\n",jobs->duracao);
      printf("Deadline do evento: %d\n",jobs->deadline);
      printf("Atraso do evento: %d\n",jobs->atraso);
      printf("-----------------------------------\n");
      jobs = jobs->proximo;
      contadorEvento++;
    }
}

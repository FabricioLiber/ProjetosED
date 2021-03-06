#include "fila.h"
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void criarFila (tfila *F) {
  F->inicio = F->fim = NULL;
}

int vaziaFila (tfila F) {
  return (F.inicio == NULL && F.fim == NULL);
}

int primeiroFila (tfila F, scliente *C) {
  if (vaziaFila(F)) return 0; /* erro: fila vazia */
  *C = (F.inicio)->cliente;
  return 1;
}

int inserirFila (tfila *F, scliente C) {
  tno *novo;
  novo = (tno*) malloc(sizeof(tno));
  if (novo == NULL) return 0; /* Erro: mem¢ria insuficiente */
  novo->cliente = C;
  novo->prox = NULL;
  if (vaziaFila(*F))
    F->inicio = novo;
    else
      (F->fim)->prox = novo;
      F->fim = novo;
  return 1;
}

int removerFila (tfila *F, scliente *C) {
  tno *aux;
  if (vaziaFila(*F)) return 0; /* Erro: fila vazia */
  primeiroFila(*F,C);
  if (F->inicio == F->fim)
    F->fim = NULL;
  aux = F->inicio;
  F->inicio = (F->inicio)->prox;
  free(aux);
  return 1;
}

int tamanhoFila (tfila F) {
  int tam=1;

  if (vaziaFila(F)) return 0; //se vazia nao tem nenhum elemento
  while ((F.inicio)->prox != NULL) {
    F.inicio = (F.inicio)->prox;
    tam++;
  }
  return tam;
}

void imprimirFila (tfila F) {

  printf("FILA =>");
  if (!vaziaFila(F)) {
    while ((F.inicio)->prox != NULL) {
      printf("Cliente:%d(TC:%d,PA:%d) - ",(F.inicio)->cliente.id,(F.inicio)->cliente.entrada,(F.inicio)->cliente.atendimento);
      F.inicio = (F.inicio)->prox;
    }
    printf("Cliente:%d(TC:%d,PA:%d)\n",(F.inicio)->cliente.id,(F.inicio)->cliente.entrada,(F.inicio)->cliente.atendimento);
  }
}

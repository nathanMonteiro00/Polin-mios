#include <stdio.h>


typedef struct no No;
typedef struct lista Lista;
No *criaNo(int coef, int expo);
Lista *criaLista();
void insereOrd(Lista *lista, int coef, int expo);
void printa(Lista *lista);
Lista *fazOperacao(Lista *Polinomio1, Lista *Polinomio2);
Lista *subtraiPolinomio(Lista *poli1, Lista *poli2);
Lista *novoPolinomio(Lista *lista);
void montaPolinomio(Lista *poli, int qtdPMono);
Lista *multiplicaLista(Lista *poli, Lista *poli2);
void limpaMemoria(Lista **lista_ref);

#include <stdio.h>
#include <stdlib.h>
#include "polinomios.h"


typedef struct no{
    
    int coeficiente;
    int expoente;
    struct no *prox;
    
}No;

typedef struct lista{
    // sempre aponta para o primeiro elemeneto
    No *inicio;
    
}Lista;

No *criaNo(int coef, int expo){
    No *novo = (No*)calloc(1, sizeof(No));
    novo -> coeficiente = coef;
    novo -> expoente = expo;
    novo -> prox  = NULL;
    
    return novo;
}

Lista *criaLista(){
    
    Lista *lista = (Lista*)calloc(1, sizeof(Lista));
    lista -> inicio = NULL;
    
    return lista;
}

void insereOrd(Lista *lista, int coef, int expo){

    No *aux = lista -> inicio;
    No *novo = criaNo(coef,expo);
    No *pred = NULL;
    
    if(lista -> inicio == NULL){
        lista -> inicio = novo;

    }else{
        
        while(aux != NULL && expo < aux -> expoente){
            pred = aux;
            aux = aux -> prox;
        }

        if(aux != NULL && aux -> expoente == expo){
                aux -> coeficiente = aux -> coeficiente + novo -> coeficiente;

                if(aux -> coeficiente == 0){
                    if(pred == NULL){
                        lista -> inicio = aux -> prox;
                    }else{
                        pred -> prox = aux -> prox;
                    }
                    aux -> prox = NULL;
                    free(aux);
                }

                free(novo);
        }
        else if(pred == NULL){ 
        //elemento tem o maior expoente do que os da lista, ou seja, será o primeiro.

            novo -> prox = lista -> inicio;
            lista -> inicio = novo; 
            
        }else{ // inserir no meio ou final
            
            pred -> prox = novo;
            novo -> prox = aux;
        }
    } 
}

void printa(Lista *lista){
    
    No *aux = lista -> inicio;

    while(aux != NULL){
        if(aux -> coeficiente == 0){
            printf("");
        }else if(aux -> expoente == 0){
            printf(" %d ", aux -> coeficiente);
        }else if(aux -> expoente == 1){
            printf(" %dx ", aux -> coeficiente);
        }else{
            printf(" %dx^%d ", aux -> coeficiente, aux -> expoente);
        }

        if(aux -> coeficiente != 0 && aux -> prox != NULL){
            if(aux -> prox -> coeficiente > 0){
            printf("+");
            }
        }
        aux = aux -> prox;
    }
    printf("\n");
}
    
void montaPolinomio(Lista *poli, int qtdPMono){

    int i = 1, coef, exp;
    while(i <= qtdPMono){
        printf("Informe o coeficiente %d: ", i);
        scanf("%d", &coef);

        printf("Informe o expoente de x: ");
        scanf("%d", &exp);

        insereOrd(poli, coef, exp);
        i++;
        printf("\n");
    }
    printf("\n");
}


Lista *novoPolinomio(Lista *lista){
    Lista *novo = criaLista();
    No *aux = (No*)calloc(1, sizeof(No));
    aux = lista -> inicio;

    while(aux != NULL){
        insereOrd(novo, aux -> coeficiente, aux -> expoente); // vai organizar a lista em ordem decrescente e somar os semelhantes
        aux = aux -> prox;
    }

    return novo;
}

Lista *subtraiPolinomio(Lista *poli1, Lista *poli2){
    Lista *subtraido;
    No *aux = poli2 -> inicio; 
    No *pred = NULL;

    while(aux != NULL){
        // para subtrair, primeiro temos que trocar os sinais do segundo polinomio
        aux -> coeficiente = aux -> coeficiente*(-1);
        aux = aux -> prox;
    }

    subtraido = fazOperacao(poli1, poli2);

    return subtraido;
}

Lista *somaPolinomio(Lista *poli1, Lista *poli2){
    Lista *soma;
    soma = fazOperacao(poli1, poli2);

    return soma;
}

Lista *fazOperacao(Lista *Polinomio1, Lista *Polinomio2){

    Lista *resultado = criaLista();
    No *aux = Polinomio1 -> inicio; 
    No *pred = NULL;

    if(Polinomio1 -> inicio == NULL && Polinomio2 -> inicio == NULL){
        return NULL;

    }else if(Polinomio1 -> inicio == NULL){
        
        return Polinomio2;

    }else if(Polinomio2 -> inicio == NULL){

        return Polinomio1;

    }else{ 

        while(aux != NULL){
            pred = aux;
            aux = aux -> prox;
        }
    
        pred -> prox = Polinomio2 -> inicio;
        resultado = novoPolinomio(Polinomio1); // cria uma lista inserindo ordenado e fazendo a soma dos termos semelhantes
        pred -> prox = NULL; 
        return resultado;
    }
}

Lista *multiplicaLista(Lista *poli, Lista *poli2){

    No *aux = poli -> inicio;
    No *aux2;
    Lista *multi = criaLista();
    int coef, expo;

    while(aux != NULL){
        aux2 = poli2 -> inicio;
        while(aux2 != NULL){
            coef = (aux -> coeficiente)*(aux2 -> coeficiente);
            expo = (aux -> expoente) + (aux2 -> expoente);
            insereOrd(multi, coef,expo);
            aux2 = aux2 -> prox;
        }
        aux = aux -> prox;
    }

    return multi;
}

void limpaMemoria(Lista **lista_ref){

    Lista *lista = *lista_ref;
    No *no = lista -> inicio;
    No *aux = NULL;

    while(no != NULL){
        aux = no;
        no = no -> prox;
        free(aux);
    }

    free(lista);
    *lista_ref = NULL;

}

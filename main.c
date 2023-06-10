#include <stdio.h>
#include "polinomios.h"
#include "polinomios.c"
    
void main(){
    
    Lista *poli1, *poli2, *poli3;
    int qtdMonomios, qtdMonomios2;
    int escolha;
do{
    poli1 = criaLista();
    poli2 = criaLista();
    poli3 = criaLista();

    printf("\n------------- MENU -------------\n");
    printf("1 - Subtrair polinomios\n");
    printf("2 - Somar polinomios\n");
    printf("3 - Multiplicar polinomios\n");
    printf("4 - Sair\n");
    printf("----------------------------------");

    do{
        printf("\n\nEscolha a operacao que deseja realizar (1, 2 ou 3) ou encerrar (4): ");
        scanf(" %d", &escolha);

        if((escolha != 1) && (escolha != 2) && (escolha != 3) && (escolha != 4)){
            printf("Escolha uma opcao valida.\n");
        }

    }while((escolha != 1) && (escolha != 2) && (escolha != 3) && (escolha != 4));

    if(escolha != 4){
        printf("Defina a quantidade de monomios para o Polinomio 1: ");
        scanf("%d", &qtdMonomios);
        printf("Defina a quantidade de monomios para o Polinomio 2: ");
        scanf("%d", &qtdMonomios2);

        montaPolinomio(poli1, qtdMonomios);
        montaPolinomio(poli2, qtdMonomios2);

        printf("\nPolinomio 1: ");
        printa(poli1);
        printf("Polinomio 2: ");
        printa(poli2);
       }
    
    switch (escolha)
    {
    case 1:

        poli3 = subtraiPolinomio(poli1, poli2);
        printf("Polinomio apos subtracao: ");
        printa(poli3);
        break;
    
    case 2:

        poli3 = somaPolinomio(poli1, poli2);
        printf("Polinomio apos soma: ");
        printa(poli3);
        break;
    
    case 3:

        poli3 = multiplicaLista(poli1, poli2);
        printf("Polinomio apos multiplicacao: ");
        printa(poli3);
        break;
    
    default:
        break;
    }
    printf("\n");

    limpaMemoria(&poli1);
    limpaMemoria(&poli2);
    limpaMemoria(&poli3);
}while(escolha != 4);

}

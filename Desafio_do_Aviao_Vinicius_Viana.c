#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 3
struct voos{
    int numero_do_voo;
    char origem [50];
    char destino [50];
    int lugares;
    }voo[12];

void dados (){
    int i;
    for (i=0;i<MAX;i++){
    printf ("\n\t---Informe os dados dos vôos---\n");
    printf ("\nNúmero do voo %d: ",i+1);
    scanf ("%d",&voo[i].numero_do_voo);
    printf ("\nOrigem: ");
    scanf ("%s",&voo[i].origem);
    printf ("\nDestino: ");
    scanf ("%s",&voo[i].destino);
    printf ("\nLugares Disponíveis: ");
    scanf ("%d",&voo[i].lugares);
    system ("cls");
    fflush (stdin);
    }
}
main (){
    setlocale (LC_ALL,"Portuguese");
    int option=0, i, j,consult, voltar, num, numero_do_voo, ncompara,k,num2;
    char orig [50], dest [50];
    dados();
    while (option!=3){
        printf ("\n\t----------------MENU----------------\n");
        printf ("\nDigite uma das opções abaixo\n");
        printf ("\t1 - Consultar\n\t2 - Efetuar Reserva\n\t3 - Sair\n");
        scanf("%d",&option);
        system ("cls");
        fflush (stdin);

        switch(option){

            case 1:

            printf("\nVocê escolheu a opção 1 - Consultar\nAgora escola um modo de busca: ");
            printf ("\n\t1 - Por número de Vôo\n\t2 - Por Origem\n\t3 - Por Destino\n");
            scanf ("%d",&consult);
            fflush (stdin);

            if (consult==1){
                printf ("\nDigite o número do vôo: \n");
                scanf ("%d",&num);
                fflush (stdin);
                for (i=0;i<MAX;i++){
                    if(num==voo[i].numero_do_voo){
                        printf ("\n\tVôo escolhido: %d",i);
                        printf ("\n\tOrigem: %s\n\tDestino: %s\n\tLugares Disponíveis: %d\n",voo[i].origem, voo[i].destino, voo[i].lugares);
                        system ("pause");
                        system ("cls");
                    }
                }
            }
           if (consult==2){
                printf ("\nDigite a Origem do vôo: \n");
                scanf ("%s",&orig);
                fflush (stdin);
                for (i=0;i<MAX;i++){
                    if (!strcmp(orig,voo[i].origem)){
                        printf ("\nVôo escolhido: %d",i);
                        printf ("\n\tNúmero do vôo: %d\n\tDestino: %s\n\tLugares Disponíveis: %d\n",voo[i].numero_do_voo, voo[i].destino, voo[i].lugares);
                        system ("pause");
                        system ("cls");
                    }
                }
           }
                if (consult==3){
                    printf ("\nDigite o destino do vôo: \n");
                    scanf ("%s",&dest);
                    for (i=0;i<MAX;i++){
                        if (!strcmp(dest,voo[i].destino)){
                            printf ("\nVôo escolhido: %d",i);
                            printf ("\n\tNúmero do vôo: %d\n\tOrigem: %s\n\tLugares Disponíveis: %d\n",voo[i].numero_do_voo, voo[i].origem, voo[i].lugares);
                            system ("pause");
                            system ("cls");
                        }
                    }
                }
            break;

            case 2:

            printf ("\n\tVocê escolheu a opção 2\nDigite o número do vôo para fazer sua reserva: \n");
            scanf ("%d",&num2);
            fflush (stdin);
            for (i=0;i<MAX;i++){
                if (num2 == voo[i].numero_do_voo && voo[i].lugares>0){
                    printf ("\nVaga reservada com sucesso\n");
                    voo[i].lugares--;
                    system ("pause");
                    system ("cls");
                    break;
                }
                if (num2 == voo[i].numero_do_voo && voo[i].lugares==0){
                    printf ("\nVôo lotado, tente novamente mais tarde\n");
                    system ("pause");
                    system ("cls");
                    break;
                }
            }
            if (i==MAX){
                printf ("\nVôo inexistente\n");
                system ("pause");
                system ("cls");
            }
            break;

        case 3:

        printf ("\n\n\n\n\t---Obrigado pela participação---\n\n\n\n");
        break;
        }
    }
}



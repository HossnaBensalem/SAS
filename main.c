#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct{
    int jour;
    int mois;
    int annee;
}Date_echeance;
 typedef struct{
     char titre[50];
     char description[100];
     char priorite[10];
     Date_echeance date;
 }Tache;
     Tache ts[100];
     int Taille =0;
    
void ajouter(){
    printf("entre un titre:");
    scanf(" %[^\n]%*c",ts[Taille].titre);
    printf("donner une description:");
    scanf(" %[^\n]%*c",ts[Taille].description);
    int choix;
    do
    {
        printf("entre la priorite(1-high 2-low):");
        scanf("%d",&choix);
        switch (choix)
        {
            case 1:
            strcpy(ts[Taille].priorite,"high");
            break;
            case 2:
            strcpy(ts[Taille].priorite,"low");
            break;
           default:printf("choix invalide");
        }
    }while(choix!=1 && choix!=2);
  do{
     printf("Entrer le jour (1 a 31):");
    scanf("%d",&ts[Taille].date.jour); 
        if(ts[Taille].date.jour>=1 && ts[Taille].date.jour<=31 ){ 
        }
        else{
            printf("le jour est invalide, \n");
        }
        }while (ts[Taille].date.jour<1 || ts[Taille].date.jour>31);
do{
    printf("donner le mois:");
    scanf("%d",&ts[Taille].date.mois);
    if(ts[Taille].date.mois>=1 && ts[Taille].date.mois<=12){
    }
    else{
        printf("le mois est invalide  \n");
    }
}while (ts[Taille].date.mois<1 || ts[Taille].date.mois>12);

do{
    printf("donner l'annee:");
    scanf("%d",&ts[Taille].date.annee);
    if(ts[Taille].date.annee<=2050){
        
    }
    else{
        printf("annee est invalide \n");
    }
}while (ts[Taille].date.annee>2050);
    Taille++;   
    printf("la tache a ete ajouter avec succes");
}
void menu(){
        printf("==============================\n");
        printf("::::::::::: MENU :::::::::::::\n");
        printf("==============================\n");
        printf("Entrer :\n");
        printf("1. pour ajouter une tache\n");
        printf("2. quitter \n");
        
}
int main()
{
    int p;
  do {
    menu();
    printf("choisissez une option :");
    scanf("%d",&p);
        switch (p) {      
        case 1:
        ajouter();
        break;
        case 2 : printf("au revoir!\n");
        exit(0);
        default:
        printf("option invalide\n"); 
        }
 
   } while(p != 6);
    return 0;
}
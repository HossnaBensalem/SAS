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
  do{
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
void afficher()
{
    if(Taille==0){
        printf("aucun taches disponibles!!");
        return;
    }
    int i;
    for(i=0;i<Taille;i++){
    printf("le titre est :%s\n",ts[i].titre);
    printf("la description est :%s\n",ts[i].description);
    printf("la priorite est :%s\n",ts[i].priorite);
    printf("le jour est :%d\n",ts[i].date.jour);
    printf("le mois est :%d\n",ts[i].date.mois);  
    printf("l'annee est :%d\n",ts[i].date.annee);
    }
}
void modifier()
{
    if(Taille==0){
        printf("aucun taches disponibles!!");
    }
    int indice;
    printf("Entre l'indice de la tache qui veux modifier (0 a %d): ", Taille - 1);
    scanf("%d", &indice);
    if (indice < 0 || indice >= Taille)
    {
        printf("invalide!\n");
    }
    else {
    printf("Entre le nouveau titre est :");
    scanf("%s",ts[indice].titre);
    printf("Entre le nouveau description est :");
    scanf("%s",ts[indice].description);
    }
    int choix;
    do
    {
        printf("entre la priorite(1-high 2-low):");
        scanf("%d",&choix);
        switch (choix)
        {
            case 1:
            strcpy(ts[indice].priorite,"high");
            break;
            case 2:
            strcpy(ts[indice].priorite,"low");
            break;
           default:printf("choix invalide");
        }
    }while(choix!=1 && choix!=2);
    printf("Entre le nouveau jour est :");
    scanf("%d",&ts[indice].date.jour);
    printf("Entre le nouveau mois est :");
    scanf("%d",&ts[indice].date.mois);
    printf("Entre le nouveau annee est :");
    scanf("%d",&ts[indice].date.annee);
}
void supprimer()
{
    if(Taille==0){
        printf("aucun taches disponibles!!");
    }
    int indice,i;
    printf("Entre l'indice qui veux supprimer:");
    scanf("%d",&indice);
        if(indice<0 || indice> Taille){
            printf("invalide !");
        }
        else{
            for(i=indice;i<Taille;i++){
            ts[i]=ts[i+1];
            }
         }
Taille--;
}
void menu(){
        printf("==============================\n");
        printf("::::::::::: MENU :::::::::::::\n");
        printf("==============================\n");
        printf("Entrer :\n");
        printf("1. pour ajouter une tache\n");
        printf("2. pour afficher la liste des taches\n");
        printf("3. pour modifier une tache\n");
        printf("4. pour supprimer une tache\n");
        printf("5. quitter \n");
        
}
int main()
{
    int p;
  do {
    menu();
    printf("choisissez une option :\n");
    scanf("%d",&p);
        switch (p) {      
        case 1:
        ajouter();
        break;
        case 2: 
        afficher();
        break;
        case 3:
        modifier();
        break;
        case 4:
        supprimer();
        break;
        case 5 : printf("au revoir!\n");
        exit(0);
        default:
        printf("option invalide\n"); 
        }
 
   } while(p != 6);
    return 0;
}
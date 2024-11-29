/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//la structure Date_echeance pour stocker la date d'échéance d'une tâche
typedef struct{
    int jour;
    int mois;
    int annee;
}Date_echeance;
//la structure Tache pour stocker les informations d'une tâche
 typedef struct{
     char titre[50];
     char description[100];
     char priorite[10];
     Date_echeance date;
}Tache;
// Tableau de tâches avec une capacité maximale de 100 tâches
     Tache ts[100];
     int Taille =0;
// Fonction pour ajouter une nouvelle tâche
void ajouter(){
    
   printf("entre un titre :");
   scanf(" %[^\n]",ts[Taille].titre);
   printf("donner une description :");
   scanf(" %[^\n]",ts[Taille].description);
   printf("entre la priorite high/low :");
   scanf(" %[^\n]",ts[Taille].priorite);
   printf("entre le jour :");
   scanf("%d",&ts[Taille].date.jour);
   printf("entre le mois :");
   scanf("%d",&ts[Taille].date.mois);
   printf("entre le annee :");
   scanf("%d",&ts[Taille].date.annee);
   Taille++;
      
   printf("Tache ajoutee avec succees\n");
   }
 // Fonction pour afficher la liste des tâches
void afficher()
{
    if(Taille==0){
        printf("aucun taches disponibles!!");
        return;
// Affiche toutes les tâches enregistrées
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
// Fonction pour modifier une tâche existante
void modifier()
{
    int indice;
    printf("Entre l'indice de la tache qui veux modifier : ");
     scanf("%d", &indice);// Demande à l'utilisateur de saisir l'indice de tâche
     if (indice > 0 && indice <= Taille) {
    printf("Entrez un nouveau titre : ");
    scanf(" %[^\n]",ts[indice].titre);
    printf("Entrez un nouveau description :");
    scanf("%s",ts[indice].description);
    printf(" Modiffier date d'echeance  : ");
    printf("Entre le nouveau jour est :");
    scanf("%d",&ts[indice].date.jour);
    printf("Entre le nouveau mois est :");
    scanf("%d",&ts[indice].date.mois);
    printf("Entre le nouveau annee est :");
    scanf("%d",&ts[indice].date.annee);
    
    printf("Priorité actuelle : %s\n", ts[indice].priorite);
    printf("Entrez une nouvelle priorité (high/low) : ");
    scanf(" %s",ts[indice].priorite); 
         indice--;
    printf("Tache a modifier avec succees\n");
     }
     else{
         printf("invalide index");
         }
     }
// Fonction pour supprimer une tâche
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
// Fonction pour filtrer les tâches par priorité
void filtre()
{
    if (Taille == 0){
        printf("Aucune tache disponible.\n");
        return;
    }
    char filtre[20];
    printf("Entrez la priorité pour filtrer (high/low) : ");
    scanf("%s", filtre);
    int T= 0;
    int i; 
    printf("\nTaches avec la priorite '%s' :\n", filtre);
    for (i = 0; i < Taille; i++) {
        if (strcmp(ts[i].priorite, filtre) == 0) {
            printf("Tache %d :\n", i + 1);
            printf("  Titre       : %s\n", ts[i].titre);
            printf("  Description : %s\n", ts[i].description);
            printf("  Date        : %02d/%02d/%04d\n", ts[i].date.jour, ts[i].date.mois, ts[i].date.annee);
            printf("  priorite    : %s\n", ts[i].priorite);
            T = 1;
        }
    }
    if (!T) {
        printf("Aucune tâche trouvée avec la priorite '%s'.\n", filtre);
    }
}// Affiche le menu
void menu(){
        printf("==============================\n");
        printf("::::::::::: MENU :::::::::::::\n");
        printf("==============================\n");
        printf("Entrer :\n");
        printf("1. pour ajouter une tache\n");
        printf("2. pour afficher la liste des taches\n");
        printf("3. pour modifier une tache\n");
        printf("4. pour supprimer une tache\n");
        printf("5. pour Filtrer les Taches \n");
        printf("6. quitter \n");   
   // Fonction principale     
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
        case 5:
        filtre();
        break;
        case 6 : printf("au revoir!\n");
        exit(0);
        default:
        printf("option invalide\n"); 
        }
 
   } while(p != 6);
    return 0;
}
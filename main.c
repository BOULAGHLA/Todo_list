#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    Basse = 1,
    Moyenne,
    Haute
} Priorite;

typedef struct
{
    char titre[3];
    Priorite priorite;
    struct DueDate
    {int day; int month; int year;
    } dueDate;
    int status;
} Tache;

Tache taches[3];
int tache_num = 0;

void ajouter()
{
      if(tache_num >= 3)
    {
        printf("Impossible d'ajouter d'autres tâches, la liste est pleine !\n");
        return;
    }
    printf("Enter la titre: ");
     scanf(" %[^\n]", taches[tache_num].titre);

    printf("Entrer la priorite (1. Basse, 2. Moyenne, 3. Haute): ");
    scanf("%d", (int *)&taches[tache_num].priorite);

    printf("Entrer la date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &taches[tache_num].dueDate.day, &taches[tache_num].dueDate.month, &taches[tache_num].dueDate.year);

    taches[tache_num].status = 0;

    tache_num++;

    printf("Success \n");
}

void afficher()
{
       if (tache_num == 0)
    {
        printf("Aucune tâche à afficher pour l'instant !\n");
        return;
    }
    for (int i = 0; i < tache_num; i++)
        printf("id: %d, description: %s, Priorite: %d, Date: %d/%d/%d, Status: %d\n",
               i, taches[i].titre, taches[i].priorite, taches[i].dueDate.day, taches[i].dueDate.month,
               taches[i].dueDate.year, taches[i].status);
}

void modifier(){
  if (tache_num == 0)
    {
        printf("Aucune tache a modifier pour l'instant .\n");
        return;
    }
    afficher();

    int choix;
    printf("Enter la tache pour modifier: ");
    scanf("%d", &choix);
    if (choix < 0 || choix >= tache_num)
    {
        printf("Erreur! Il n'y a aucune tâche avec le numéro que vous avez entré. \n");
        return;
    }
    printf("Entrer le nouveau titre: ");
    scanf(" %[^\n]", taches[choix].titre);

    printf("Entrer la priorite (1. Basse, 2. Moyenne, 3. Haute): ");
    scanf("%d", (int *)&taches[choix].priorite);

    printf("Entrer la date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &taches[choix].dueDate.day, &taches[choix].dueDate.month, &taches[choix].dueDate.year);

    printf("Modifier avec success!\n");
}

void supprimer(){
      if(tache_num <= 0)
    {
        printf("Il n'y a aucune tache a supprimer .\n");
        return;
    }
    afficher();
    int choix;
    printf("Enter la tache pour supp: ");
    scanf("%d", &choix);
      if (choix < 0 || choix >= tache_num)
    {
        printf("Erreur! il n'y a aucune tâche avec le numéro que vous avez entré \n");
        return;
    }

    for (int i = choix; i < tache_num; i++)
        taches[i] = taches[i + 1];

    tache_num--;

    printf("Suppression réussie .\n");
}

void marque(){
   if(tache_num <= 0)
    {
        printf("Il n'y a pas encore de tâches.\n");
        return;
    }
    printf("Enter la tache pour marque terminer: ");
    int choix;
      if (scanf("%d", &choix) != 1 || choix < 0 || choix >= tache_num) {
        printf("Invalid task ID.\n");
        return;
    }

    taches[choix].status = 1;
     printf("tach Done\n");
}

int main()
{
    int choix;
    do {
        printf("******************** TO DO list **********************\n");

        printf("\n1. Ajouter\n2. Modifier\n3. Supprimer\n4. Marquer termine\n5. Afficher \n6. Quitter\n");
        printf("Choose an action: ");
        if (scanf("%d", &choix) != 1) {
            printf("Invalid input.\n");
          while (getchar() != '\n');
        continue;
        }

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                modifier();
                break;
            case 3:
                supprimer();
                break;
            case 4:
                marque();
                break;
            case 5:
                afficher();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choix != 6);



     return 0;
}

























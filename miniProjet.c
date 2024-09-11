#include <stdio.h>
#include <string.h>
int main(){

    int option, i, etudiantUpmoyenne;
    char prenom[100], nom[100], maxNom[100], maxPrenom[100];
    char minNom[100], minPrenom[100]; 
    float note, moyenne, sommeNote, compteur, max, min;
    int addEtudiant;
    max = 0;
    min = 20;
    sommeNote = 0;
    compteur = 0;
    addEtudiant = 1;
    etudiantUpmoyenne = 0;

    do {
    printf("========== Menu : \n");
    printf("[1]. informations generales : \n");
    printf("[2]. le calcul et l'affichage  de moyenne.\n");
    printf("[3]. affiche l'etudiant avec la meilleure et la pire note.\n");
    printf("[4]. combien d'etudiants ont une note superieure e la moyenne.\n");
    printf("[5]. Quitter le programme.\n");
    printf("Entrer le nombre d'opperation souhaiter : ");
    scanf("%d", &option);

   

    
        switch(option){
            case 1 :
                    printf("Entrer les informations suivantes : \n");
                    printf("prenom : ");
                    scanf("%s", &prenom);
                    printf("nom : ");
                    scanf("%s", &nom);
                    printf("note : ");
                    scanf("%f", &note);
                    if (note>max){
                        max = note;
                        strcpy(maxNom, nom);
                        strcpy(maxPrenom, prenom);
                    }
                    if (note < min){
                        min = note;
                        strcpy(minNom, nom);
                        strcpy(minPrenom, prenom);     
                    }
                    
                    compteur = compteur + 1; 
                    sommeNote = sommeNote + note;
                    moyenne = sommeNote / compteur;
                    /*
                    moyenne = sommeNote / compteur;
                    if (note > moyenne){
                        etudiantUpmoyenne++;
                    }
                    */
                    break;
            case 2:
                if (compteur == 0){
                    printf("pas de moyenne.");
                } 
                else {
                    moyenne = sommeNote / compteur;
                    printf("La moyenne est %.2f\n\n", moyenne);
                }
                break;
            case 3 :
                if (compteur == 0) {
                    printf("Pas d'etudiant !\n");
                } else {
                    printf("note maximale : %.2f de %s %s \n", max, maxNom, maxPrenom);
                    printf("pire note : %.2f de %s %s \n", min, minNom, minPrenom );
                }
                break;
            case 4: 
                for (i=1; i<=compteur; i++){
                    printf("Reentrer vos points : ");
                    scanf("%f", &note);
                    if (note > moyenne){
                        etudiantUpmoyenne = etudiantUpmoyenne + 1;
                    }
                }
                printf("Le nombre d'etudiants ont une note superieure a la moyenne est %d", etudiantUpmoyenne);
                break;        
        }
        printf("\n");

    }while(option != 5);
    return 0;
}



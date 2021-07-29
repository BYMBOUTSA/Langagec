/*
    Ici nous allons utiliser les ternaires 
    à la place des if
*/

#include <stdio.h>


int main(void) {
    
    //Déclaration de nos variables
    int min = 0, max = 0, somme = 0;

    //Demande à l'utilisateur d'entré un nombre min
    printf("Entrez un nombre MIN (entre 1 et 1000) : ");
    scanf("%d", &min);

    //Prévoir le cas où min < 1
    (min < 1) ? printf("MIN trop petit !\n") : printf("Bonne valeur de MIN !\n");  // équivalent à cond = (min < 1) ? 1 : 0; printf("MIN trop petit !\n");

    //Demande à l'utilisateur d'entré un nombre max
    printf("Entrez un nombre MAX (entre 1 et 1000) : ");
    scanf("%d", &max);

    //Prévoir le cas où max > 1000
    (max > 1000) ? printf("MAX trop grand !\n") : printf("Bonne valeur de MAX !\n"); // équivalent à cond = (max > 1000) ? 1 : 0; printf("MAX trop grand !\n");

    //prévoir le cas où min > max
    (min > max) ? printf("Saisies incorrectes !\n") : printf("Saisies correctes !\n"); // équivalent à cond = (min > max) ? 1 : 0; printf("Saisies incorrectes !\n");

    //Calcul de la somme des entiers d'un nombre à l'autre
    if(max != min) {
        for(int i = min; i < max + 1; i++)
            somme += i; // équivalent à somme = somme + i;
     }

     else
        somme = min; // qui est égal à max aussi car max = min dans ce cas là
    
    printf("Somme finale : %d\n", somme);
    
    return 0;
}
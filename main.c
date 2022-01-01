/********************************************************************
 *              PROJET C : Grands Entiers Naturels                  *
 * *****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX
typedef char BigNat[MAX];

typedef enum  {false = 0, true = 1}bool;



// Fonction d'initialisation à 0
int init(int BigNat) {
    BigNat = 0;
    return BigNat;
}

// Fonction d'initialisation à partir d'une chaîne de caractère
char init_chaine(char *s) {
    char s1[] = "123456789";
    return s1;
}


// Fonction de lecture
int read(int BigNat) {
    scanf("%d", &BigNat);
}


// Fonction d'écriture sur la sortie standard
int write(int BigNat) {
    printf("valeur en octal : %o\n", BigNat); // en octal
    printf("valeur en hexadecimal : %x\n", BigNat); // en hexadécimal
    printf("valeur en decimal : %d", BigNat); // en décimal
    printf("Valeur cadrer à gauche : %-6hd\n", BigNat); // cadrage à gauche
    printf("valeur cadrer à droite : %6hd\n", BigNat); // cadrage à droite
}


// Fonction addition
int addition(int nb1, int nb2) {
    return nb1 + nb2;
}

// Fonction soustraire
int soustraction(int nb1, int nb2) {
    return nb1 - nb2;
}

// Fonction multiplication
int multiplication(int nb1, int nb2) {
    return nb1 * nb2;
}


// Fonction division
int division(int nb1, int nb2) {
    if(nb2 > 0)
        return nb1 / nb2;
    else if(nb2 < 0) {
        printf("Erreur de saisie\n");
        return -2;
    }  
    else {
        printf("Math ERROR\n");
        return -1;
    }
 
}


// Fonction modulo
int modulo(int nb1, int nb2){
    if(nb2 > 0)
        return nb1 % nb2;
    else if(nb2 < 0) {
        printf("Erreur de saisie\n");
        return -2;
    }  
    else {
        printf("Math ERROR\n");
        return -1;
    }
}


// Fonction inférieur
int inf(int nb1, int nb2) {
    if(nb1 < nb2)
        return true;
    return false;
}

// fonction supérieur
int sup(int nb1, int nb2) {
    if(nb1 > nb2)
        return true;
    return false;
}

// fonction inférieur ou égal
int infEgal(int nb1, int nb2) {
    if(nb1 <= nb2)
        return true;
    return false;
}


// fonction supérieur ou égal
int supEgal(int nb1, int nb2) {
    if(nb1 >= nb2)
        return true;
    return false;
}

// fonction égal
int egal(int nb1, int nb2) {
    if(nb1 == nb2)
        return true;
    return false;
}


// fonction différente 
int diff(int nb1, int nb2) {
    if(nb1 != nb2)
        return true;
    return false;
}



// Fonction factorielle
double factorielle(unsigned short x) {
    if(x == 0)
        return 1;
    else
        return (x * factorielle(x - 1));
}



int main(void) {

    int BigNat; 
    char s[] = "12345678";
    int nb1 = 22, nb2 = 22;

   
    BigNat = init(BigNat);
    printf("Initialement : %d\n", BigNat);
    printf("chaîne : %d\n", init_chaine(s));
    printf("La division de %d et %d est : %d\n", nb1, nb2, division(nb1, nb2));
    printf("Le reste de la division de %d et %d est : %d\n", nb1, nb2, modulo(nb1, nb2));
    printf("%d < %d : %d\n", nb1, nb2, inf(nb1, nb2));
    printf("%d > %d : %d\n", nb1, nb2, sup(nb1, nb2));
    printf("%d <= %d : %d\n", nb1, nb2, infEgal(nb1, nb2));
    printf("%d >= %d : %d\n", nb1, nb2, supEgal(nb1, nb2));
    printf("%d == %d : %d\n", nb1, nb2, egal(nb1, nb2));
    printf("%d != %d : %d\n", nb1, nb2, diff(nb1, nb2));

    // Test de la fonction factorielle
    int value = 100;
    printf("Le factorielle de %d : %lf\n", value, factorielle(value));

    return EXIT_SUCCESS;
}
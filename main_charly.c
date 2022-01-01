/********************************************************************
 *              PROJET C : Grands Entiers Naturels                  *
 * *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200
typedef char* BigNat;

// Fonction d'initialisation à 0
BigNat init_int(int a) {
    BigNat b = malloc((MAX+1)*sizeof(char)); // on alloue une chaîne de taille MAX + 1
    b[MAX] = '\0';
    for(int x = 0; x < MAX; x++) b[x]='0';
    int x = MAX-1;
    while(a != 0) {
        b[x--] = a % 10 + '0'; // on pars de l'avant dernier caractère et on met le dernier chiffre du nombre grâce au modulo 10
        a /= 10; // on divise par 10 pour passer à la case précédente ainsi de suite
    }

    return b;
    free(b);
}

BigNat init_str(char* a) {
    BigNat b = init_int(0);
    int l = MAX-1;
    for(int x = strlen(a)-1; x >= 0; x--)
        b[l--] = a[x];

    return b;
    free(b);
}

// Fonction d'écriture sur la sortie standard
void ecrire(BigNat a) {
    int n = MAX-1;
    for(int x = 0; x < MAX; x++) {
        if(a[x] != '0'){ // ici on recherche le premier caractère différent de 0
            n = x; // on indique le carctère
            break;
        }
    }
    for(int x = n; x < MAX; x++)
        printf("%c",a[x]); // on affiche tous les autres caractères les uns à la suite des autres.
}

// Fonction d'initialisation à partir d'une chaîne de caractère
/*char init_chaine(char *s) {
    char s1[] = "123456789";
    return s1;
}*/


// Fonction de lecture
/*int read(int BigNat) {
    scanf("%d", &BigNat);
}*/


// Fonction d'écriture sur la sortie standard
/*int write(int BigNat) {
    printf("valeur en octal : %o\n", BigNat); // en octal
    printf("valeur en hexadecimal : %x\n", BigNat); // en hexadécimal
    printf("valeur en decimal : %d", BigNat); // en décimal
    printf("Valeur cadrer à gauche : %-6hd\n", BigNat); // cadrage à gauche
    printf("valeur cadrer à droite : %6hd\n", BigNat); // cadrage à droite
}*/


// Fonction addition
/*int addition(int nb1, int nb2) {
    return nb1 + nb2;
}*/

BigNat addition(BigNat a, BigNat b) {
    BigNat r = init_int(0);
    int n;
    for(int x = MAX-1; x > 0; x--) {
        n = r[x] + a[x] + b[x] - 3 * '0';
        r[x] = n % 10 + '0';
        if(n > 9)
            r[x-1]++;
    }
    return r;
    free(r);
}

// Fonction soustraire
/*int soustraction(int nb1, int nb2) {
    return nb1 - nb2;
}*/

BigNat soustraction(BigNat a, BigNat b) {
    BigNat p = init_int(0);
    int n;
    for(int x = MAX-1; x > 0; x--) {
        n = p[x] + a[x] - b[x] + 3 * '0';
        p[x] = n % 10 + '0';
        if(n > 9)
            p[x-1]++;
    }
    return p;
    free(p);
}



// Fonction multiplication
/*int multiplication(int nb1, int nb2) {
    return nb1 * nb2;
}*/
BigNat multiplication(BigNat a, BigNat b) {
    BigNat m = init_int(0);
    int n;
    for(int x = MAX-1; x > 0; x--) {
        n = m[x] + a[x] * b[x] - 3 * '0';
        m[x] = n % 10 + '0';
        if(n > 9)
            m[x-1]++;
    }
    return m;
    free(m);
}

// Fonction division
/*int division(int nb1, int nb2) {
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

}*/


// Fonction modulo
/*int modulo(int nb1, int nb2){
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
}*/


// Fonction inférieur
/*int inf(int nb1, int nb2) {
    if(nb1 < nb2)
        return true;
    return false;
}*/

// fonction supérieur
/*int sup(int nb1, int nb2) {
    if(nb1 > nb2)
        return true;
    return false;
}*/

// fonction inférieur ou égal
/*int infEgal(int nb1, int nb2) {
    if(nb1 <= nb2)
        return true;
    return false;
}*/


// fonction supérieur ou égal
/*int supEgal(int nb1, int nb2) {
    if(nb1 >= nb2)
        return true;
    return false;
}*/

// fonction égal
/*int egal(int nb1, int nb2) {
    if(nb1 == nb2)
        return true;
    return false;
}*/


// fonction différente
/*int diff(int nb1, int nb2) {
    if(nb1 != nb2)
        return true;
    return false;
}*/



// Fonction factorielle
/*double factorielle(unsigned short x) {
    if(x == 0)
        return 1;
    else
        return (x * factorielle(x - 1));
}*/



int main(void) {

    /*int BigNat;
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
    printf("Le factorielle de %d : %lf\n", value, factorielle(value));*/

    BigNat a = init_int(1234000),b = init_int(3764);
    BigNat x = init_str("123456789123456789"),y = init_str("645978312");

    printf("a = ");
    ecrire(a);
    printf("\nb = ");
    ecrire(b);
    printf("\na + b = ");
    ecrire(addition(a,b));
    printf("\na - b = ");
    ecrire(soustraction(a,b));
    printf("\na * b = ");
    ecrire(multiplication(a,b));
    printf("\n\n");

    printf("x = ");
    ecrire(x);
    printf("\ny = ");
    ecrire(y);
    printf("\nx + y = ");
    ecrire(addition(x,y));
    printf("\n\n");

    return EXIT_SUCCESS;
}

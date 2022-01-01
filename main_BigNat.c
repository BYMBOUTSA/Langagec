/********************************************************************
 *              PROJET C : Grands Entiers Naturels                  *
 * *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 200

typedef char* BigNat;

/*
conséquent x = MAX - 1 et return b
invariant de boucle : x < MAX

Rôle: Initialise un BigNat à partir d'un entier naturel
*/

// Fonction d'initialisation à partir d'un entier naturel
BigNat init_int(int a) {
    BigNat b = malloc((MAX + 1)*sizeof(char));
    b[MAX] = '\0';
    for(int x = 0; x < MAX; x++) b[x] = '0';
    int x = MAX - 1;
    while(a != 0){
        b[x--] = a % 10 + '0';
        a /= 10;
    }

    return b;
}


/*
conséquent : return strlen(s)-n+1

Rôle : Renvoyer la longueur réel du nombre.

*/

// Fonction permettant de renvoyer la longueur réel du nombre
int real_len(char *s) {
    int n = 0;
    while(s[n++] == '0');
    return strlen(s) - n + 1;
}


/*
antécédent real_len(s)<=MAX
conséquent b=init_int(0), l=MAX-1 et return b
invariant de boucle : x >= 0

Rôle: Initialise un BigNat à partir d'une chaîne de caractère
*/

// Fonction d'initialisation à partir d'une chaîne de caractère
BigNat init_str(char* s) {
    assert(real_len(s) <= MAX);
    BigNat b = init_int(0);
    int l = MAX-1;
    for(int x = strlen(s) - 1; x >= 0; x--)
        b[l--] = s[x];

    return b;
}


/*
conséquent b=init_int(0) et return b
invariant de boucle : x < MAX

Rôle: Initialise un BigNat à partir d'un autre BigNat
*/
// Fonction d'initialisation à partir d'un autre BigNat
BigNat init_BigNat(BigNat a) {
    BigNat b = init_int(0);
    for(int x = 0; x < MAX; x++)
        b[x] = a[x];

    return b;
}

// Fonction d'écriture sur la sortie standard
/*int write(int BigNat) {
    printf("valeur en octal : %o\n", BigNat); // en octal
    printf("valeur en hexadecimal : %x\n", BigNat); // en hexadécimal
    printf("valeur en decimal : %d", BigNat); // en décimal
    printf("Valeur cadrer à gauche : %-6hd\n", BigNat); // cadrage à gauche
    printf("valeur cadrer à droite : %6hd\n", BigNat); // cadrage à droite
}*/


/*
conséquent n = MAX-1
invariant de boucle : x < MAX

Rôle : Ecrire sur la sortie standard

*/
void ecrire(BigNat a){
    int n = MAX - 1;
    for(int x = 0; x < MAX; x++){
        if(a[x] != '0'){
            n = x;
            break;
        }
    }
    for(int x = n; x < MAX; x++)
        printf("%c",a[x]);
}


/*
conséquent return false, return true
invariant de boucle : x < MAX

Rôle : Vérifier la valeur supérieur de deux BigNat

*/
// fonction supérieur
bool sup(BigNat a, BigNat b){
    for(int x = 0; x < MAX; x++){
        if(a[x] > b[x])
            return true;

        else if(a[x] < b[x])
            return false;
    }

    return false;
}


/*
conséquent return false, return true
invariant de boucle : x < MAX

Rôle : Vérifier l'égalité de deux BigNat

*/
// fonction égal
bool eq(BigNat a, BigNat b){
    for(int x = 0; x < MAX; x++)
        if(a[x] != b[x])
            return false;

    return true;
}


/*
conséquent return false, return true
invariant de boucle : x < MAX

Rôle : Vérifier la différence de deux BigNat

*/
// fonction différente
bool dif(BigNat a, BigNat b) {
    for(int x = 0;x < MAX; x++)
        if(a[x] != b[x])
            return true;

    return false;
}

/*
conséquent : Si le BigNat a est égal au BigNat b alors on renvoi false sinon on renvoi !sup(a,b)

Rôle : Vérifier si le BigNat 1 est inférieur au BigNat 2

*/
// Fonction inférieur
bool inf(BigNat a, BigNat b){
    if(eq(a,b))
        return false;
    else return !sup(a,b);
}

/*
conséquent : Si le BigNat a est bien inférieur ou égal à au BigNat b la fonction renvoi !sup(a,b)

Rôle : Vérifier si le BigNat 1 est inférieur ou égal au BigNat 2

*/
// fonction inférieur ou égal
bool infeq(BigNat a, BigNat b){
    return !sup(a,b);
}


/*
conséquent : Si le BigNat a est bien supérieur ou égal à au BigNat b la fonction renvoi !inf(a,b)

Rôle : Vérifier si le BigNat 1 est supérieur ou égal au BigNat 2

*/
// fonction supérieur ou égal
bool supeq(BigNat a, BigNat b){
    return !inf(a,b);
}


/*
antécédent real_len(a) < MAX && real_len(b) < MAX
conséquent r=init_int(0), n, return r
invariant de boucle : x > 0

Rôle: Additionner deux BigNat
*/

// Fonction addition
BigNat addi(BigNat a, BigNat b){
    assert(real_len(a) < MAX && real_len(b) < MAX);
    BigNat r = init_int(0);
    int n;
    for(int x = MAX - 1; x > 0; x--){
        n = r[x] + a[x] + b[x] - 3 * '0';
        r[x] = n % 10 +'0';
        if(n > 9)
            r[x-1]++;
    }
    return r;
}


/*
antécédent real_len(a) < MAX && real_len(b) < MAX && infeq(b,a)
conséquent r = init_int(0), c = init_BigNat(b), n, return r
invariant de boucle : x > 0

Rôle: Soustraire deux BigNat
*/
// Fonction soustraire
BigNat sous(BigNat a, BigNat b){
    assert(real_len(a) < MAX && real_len(b) < MAX && infeq(b,a));
    BigNat r = init_int(0),c = init_BigNat(b);
    int n;
    for(int x = MAX - 1; x > 0; x--){
        n = a[x] - c[x];
        r[x] = n >= 0 ? n + '0' : 10 + n + '0';
        if(n < 0)
            c[x-1]++;
    }
    free(c);
    return r;
}


/*
antécédent real_len(a) + real_len(b) <= MAX
conséquent m = init_int(0), r = init_int(0), c = init_BigNat(b), n, return m
invariant de boucle : x >= MAX - real_len(b) et y >= MAX - real_len(a) - 1

Rôle: Multiplier deux BigNat
*/
// Fonction multiplication
BigNat mult(BigNat a, BigNat b){
    assert(real_len(a) + real_len(b) <= MAX);
    BigNat m = init_int(0), r = init_int(0), c = init_int(0);
    int n;
    for(int x = MAX - 1;x >= MAX - real_len(b); x--){
        for(int i = 0; i < MAX; i++)
            r[i] = '0';
        for(int y = MAX - 1; y >= MAX - real_len(a) - 1; y--){
            n = (b[x] - '0') * (a[y] - '0') + c[y] - '0';
            r[x+y+1-MAX] = n % 10 + '0';
            c[y-1] = n / 10 + '0';
        }
        m=addi(m,r);
    }
    free(r); free(c);
    return m;
}

// Fonction division










// Fonction modulo







/*
conséquent : t = init_int(0),r = init_int(1), return r, s = sous(a,r), m = mult(a, factorielle(s)) et return m 

Rôle : Teste si un ensemble est vide.

*/
// Fonction factorielle
BigNat factorielle(BigNat a) {
    BigNat t = init_int(0), r = init_int(1);
    if(eq(a,t)){
        free(t);
        return r;
    }
    else {
        BigNat s = sous(a,r) , m = mult(a, factorielle(s));
        free(t); free(r); free(s);
        return m;
    }
}




int main(void) {

    BigNat a = init_int(1234000), b = init_int(3764), ab = addi(a,b), ba = sous(a,b);
    BigNat x = init_str("123456789123456789"), y = init_str("645978312"), xy = addi(x,y), yx = sous(x,y);

    printf("a = ");
    ecrire(a);
    printf("\nb = ");
    ecrire(b);
    printf("\na + b = ");
    ecrire(ab);
    printf("\na - b = ");
    ecrire(ba);
    printf("\n\n");

    printf("x = ");
    ecrire(x);
    printf("\ny = ");
    ecrire(y);
    printf("\nx + y = ");
    ecrire(xy);
    printf("\nx - y = ");
    ecrire(yx);
    printf("\n\n");

    printf("Superieur : %d\nSuperieur ou egal: %d\nInferieur : %d\nInferieur ou egal : %d\nEgal : %d\nDifferent : %d\n\n\n",sup(x,y),supeq(x,y),inf(x,y),infeq(x,y),eq(x,y),dif(x,y));

    free(a); free(b); free(ab); free(ba); free(x); free(y); free(xy); free(yx);


    for(int x = 100; x <= 100; x++){
        BigNat a = init_int(x), b = factorielle(a);
        ecrire(a);
        printf("! = ");
        ecrire(b);
        printf(" (%d chiffres)\n",real_len(b));
        free(a); free(b);
    }

    return EXIT_SUCCESS;
}

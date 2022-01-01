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


// Fonction d'initialisation à partir d'un entier naturel
BigNat init_int(int a) {
    BigNat b=malloc((MAX+1)*sizeof(char));
    b[MAX]='\0';
    for(int x=0;x<MAX;x++) b[x]='0';
    int x=MAX-1;
    while(a!=0){
        b[x--]=a%10+'0';
        a/=10;
    }

    return b;
}


// Fonction permettant de renvoyer la longueur réel du nombre
int real_len(char *s) {
    int n=0;
    while(s[n++]=='0');
    return strlen(s)-n+1;
}


// Fonction d'initialisation à partir d'une chaîne de caractère
BigNat init_str(char* s) {
    assert(real_len(s)<=MAX);
    BigNat b=init_int(0);
    int l=MAX-1;
    for(int x=strlen(s)-1;x>=0;x--)
        b[l--]=s[x];

    return b;
}

// Fonction d'initialisation à partir d'un autre BigNat
BigNat init_BigNat(BigNat a) {
    BigNat b=init_int(0);
    for(int x=0;x<MAX;x++)
        b[x]=a[x];

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


void ecrire(BigNat a){
    int n=MAX-1;
    for(int x=0;x<MAX;x++){
        if(a[x]!='0'){
            n=x;
            break;
        }
    }
    for(int x=n;x<MAX;x++)
        printf("%c",a[x]);
}


// fonction supérieur
bool sup(BigNat a, BigNat b){
    for(int x=0;x<MAX;x++){
        if(a[x]>b[x])
            return true;

        else if(a[x]<b[x])
            return false;
    }

    return false;
}

// fonction égal
bool eq(BigNat a, BigNat b){
    for(int x=0;x<MAX;x++)
        if(a[x]!=b[x])
            return false;

    return true;
}

// fonction différente
bool dif(BigNat a, BigNat b) {
    for(int x = 0;x < MAX; x++)
        if(a[x] != b[x])
            return true;

    return false;
}

// Fonction inférieur
bool inf(BigNat a, BigNat b){
    if(eq(a,b))
        return false;
    else return !sup(a,b);
}

// fonction inférieur ou égal
bool infeq(BigNat a, BigNat b){
    return !sup(a,b);
}

// fonction supérieur ou égal
bool supeq(BigNat a, BigNat b){
    return !inf(a,b);
}

// Fonction addition
BigNat addi(BigNat a, BigNat b){
    assert(real_len(a)<MAX && real_len(b)<MAX);
    BigNat r=init_int(0);
    int n;
    for(int x=MAX-1;x>0;x--){
        n=r[x]+a[x]+b[x]-3*'0';
        r[x]=n%10+'0';
        if(n>9)
            r[x-1]++;
    }
    return r;
}

// Fonction soustraire
BigNat sous(BigNat a, BigNat b){
    assert(real_len(a)<MAX && real_len(b)<MAX && infeq(b,a));
    BigNat r=init_int(0),c=init_BigNat(b);
    int n;
    for(int x=MAX-1;x>0;x--){
        n=a[x]-c[x];
        r[x] = n>=0 ? n+'0' : 10+n+'0';
        if(n<0)
            c[x-1]++;
    }
    free(c);
    return r;
}

// Fonction multiplication
BigNat mult(BigNat a, BigNat b){
    assert(real_len(a)+real_len(b)<=MAX);
    BigNat m=init_int(0),r=init_int(0),c=init_int(0);
    int n;
    for(int x=MAX-1;x>=MAX-real_len(b);x--){
        for(int i=0;i<MAX;i++)
            r[i]='0';
        for(int y=MAX-1;y>=MAX-real_len(a)-1;y--){
            n=(b[x]-'0')*(a[y]-'0')+c[y]-'0';
            r[x+y+1-MAX]=n%10+'0';
            c[y-1]=n/10+'0';
        }
        m=addi(m,r);
    }
    free(r); free(c);
    return m;
}

// Fonction division










// Fonction modulo








// Fonction factorielle
BigNat factorielle(BigNat a) {
    BigNat t=init_int(0),r=init_int(1);
    if(eq(a,t)){
        free(t);
        return r;
    }
    else {
        BigNat s=sous(a,r),m=mult(a, factorielle(s));
        free(t); free(r); free(s);
        return m;
    }
}




int main(void) {

    BigNat a=init_int(1234000),b=init_int(3764),ab=addi(a,b),ba=sous(a,b);
    BigNat x=init_str("123456789123456789"),y=init_str("645978312"),xy=addi(x,y),yx=sous(x,y);

    printf("a=");
    ecrire(a);
    printf("\nb=");
    ecrire(b);
    printf("\na+b=");
    ecrire(ab);
    printf("\na-b=");
    ecrire(ba);
    printf("\n\n");

    printf("x=");
    ecrire(x);
    printf("\ny=");
    ecrire(y);
    printf("\nx+y=");
    ecrire(xy);
    printf("\nx-y=");
    ecrire(yx);
    printf("\n\n");

    printf("Superieur : %d\nSuperieur ou egal: %d\nInferieur : %d\nInferieur ou egal : %d\nEgal : %d\nDifferent : %d\n\n\n",sup(x,y),supeq(x,y),inf(x,y),infeq(x,y),eq(x,y),dif(x,y));

    free(a); free(b); free(ab); free(ba); free(x); free(y); free(xy); free(yx);


    for(int x=100;x<=100;x++){
        BigNat a=init_int(x),b=factorielle(a);
        ecrire(a);
        printf("! = ");
        ecrire(b);
        printf(" (%d chiffres)\n",real_len(b));
        free(a); free(b);
    }

    return EXIT_SUCCESS;
}

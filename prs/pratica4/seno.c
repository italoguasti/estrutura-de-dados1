#include "seno.h"

#include <stdio.h>

long int fatorial(int);

long int pot(int, int);

double taylor(int, int, int);

double seno(int x, int n) {
    /* Preencha aqui */
    if(n == 1){
        return x;
    }
    if(n%2 == 0){
        return seno(x, n-1) - taylor(x, n, 3);
    }else{
        return seno(x, n-1) + taylor(x, n, 3);
    }
}

long int fatorial(int n) {
    /* Preencha aqui */
    if(n == 1){
        return 1;
    }
    return fatorial(n-1)*n;
}

long int pot(int b, int n) {
    /* Preencha aqui */
    if(n == 1){
        return b;
    }
    return pot(b, n-1)*b;
}

double taylor(int x, int n, int i) {
    /* Preencha aqui */
    if(n>2){
        for(int j = 0; j+2 < n; j++){
            i = i + 2;
        }
    }
    double aux;
    double pote = pot(x,i);
    double fat = fatorial(i);
    aux = pote/fat;
    return aux;
}
#include "Pilha.hpp"
#include <stdio.h>


int main(int argc, char **argv){
    Pilha<int> p = Pilha<int>(20);
    int x;
    try{
        for(x = 0; x < 30;x++) p.empilha(x);
        for(x = 0; x < 30;x++) printf("Elemento: %d\n",p.desempilha());
    }
    catch(const char *c) {
        printf(c);
    }
}

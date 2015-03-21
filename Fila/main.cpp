#include "Fila.hpp"
#include <stdio.h>

int main(int argc, char **argv){
    Fila<int> p = Fila<int>(20);
    int x;
    try{
        for(x = 0; x < 20;x++) p.inclui(x);
        for(x = 0; x < 20;x++) printf("Elemento: %d\n",p.retira());
    }
    catch(const char *c) {
        printf(c);
    }
}

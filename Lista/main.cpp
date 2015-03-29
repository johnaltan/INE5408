#include "Lista.hpp"
#include <stdio.h>

int main(int argc, char **argv){
    Lista<int> l = Lista<int>(20);
    int x;
    int val[] = {1,6,2,9,8,3,7,4,0,5};
    try{
        for(x = 0; x < 10;x++) l.adiciona(x);
        for(x = 0; x < 10;x++) printf("Elemento: %d\n",l.retiraPrimeiro());
    }
    catch(const char *c) {
        printf(c);
    }
}

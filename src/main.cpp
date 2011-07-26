#include <stdio.h>
#include <stdlib.h>

#include "../include/List.hpp"

List<int> numeros;
main()
{
    numeros.insertBegin(12);
    numeros.push(20);
    printf("%i\n",numeros[1]->dataNode());

    
}
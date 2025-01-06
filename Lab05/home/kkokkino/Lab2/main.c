// main.c
#include <stdio.h>
#include "functions.h"

int main() {
    greet();  // Call the greet function from functions.c

    int result = add(5, 3);  // Call the add function from functions.c
    printf("The result of adding 5 and 3 is: %d\n", result);
    return 0;
}

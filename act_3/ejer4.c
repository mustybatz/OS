#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char command[10];

    printf("Programa a ejecutar: ");
    scanf("%s", command);

    int ret = system(command);

    return 0;
}

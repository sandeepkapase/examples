#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n;
    union {
        int d;
        char string[1];
    }u;
}fam_t;

int main( void )
{

    char test_string[] = "Toto je testovaci string.";


    size_t size = 0;
    size = sizeof( fam_t ) + (strlen(test_string)-1)*sizeof(char);

    fam_t* fam = NULL;
    fam = (fam_t*)malloc(size);
    strcpy( fam->u.string, test_string );
    fam->n = size;
    printf("%i\t%s\n", fam->n, fam->u.string);

    free(fam);

    return 0;
}

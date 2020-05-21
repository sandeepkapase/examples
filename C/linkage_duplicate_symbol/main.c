#include <stdio.h>
#ifdef RENAME_SUM
int sum(int, int);
int sumu2(int, int);
#else
int sum(int, int);
#endif

int main() {
    printf("\nmain");
    printf("\nsum unit one: %d", sum(1,2));
#ifdef RENAME_SUM
    printf("\nsum unit two: %d", sumu2(2,3));
#endif
}

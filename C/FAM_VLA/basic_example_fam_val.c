#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int age;
    float salary;
    char name[];
}employee;

void allocarr(int n) {
    int myarr[n];
    printf("\nSize of vla:%ld", sizeof(myarr));
}

int main(void) {
    // VAL
    allocarr(1);
    allocarr(11);
    allocarr(111);
    allocarr(1111);
    // FAM
    printf("\nsize of employee:%ld", sizeof(employee));
    char *name = "empname";
    int len = strlen(name);
    employee *e = malloc(sizeof(employee)+len);
    e->age = 30;
    e->salary = 3000000;
    strncpy(e->name, name, len);
    printf("\nAge:%d Salary:%f Name:%s", e->age, e->salary, e->name);
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

void display(int *tab) {
    printf("%d %d %d %d\n", tab[0], tab[1], tab[2], tab[3]);
}

int * change_tab(int *tab){
    // display(tab);
    tab[1] = 80;
    tab[3] = 140;
    // display(tab);
    return *tab;
}

int main(void) {
    int tab[] = {25, 50, 75, 100};
    // printf("tab[0] = %d\n", &tab[0]);
    // printf("tab[0] = %d\n", *tab);
    display(tab);
    *tab = change_tab(tab);
    display(tab);
    // printf("tab[0] = %d\n", tab);
    return 0;
}
// tab[0] = *tab 
// tab = &tab[0]
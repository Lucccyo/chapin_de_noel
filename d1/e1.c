#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

void display(int *tab) {
    printf("%d %d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]); // c'était de taille 3 pourtant :/
}

int * update_top(int l, int sum, int *top) {
    // display(top);
    if (sum > top[0]) {
        top[2] = top[1];
        top[1] = top[0];
        top[0] = sum;
    } 
    else if (sum > top[1]) {
        top[2] = top[1];
        top[1] = sum;
    } else if (sum > top[2]) {
        top[2] = sum;
    }
    // display(top);
    return *top;
}

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int top[3] = {0};
    int sum = 0; 
    int l = 1;
    fp = fopen("./data.txt", "r");
    if (fp == NULL) exit(1);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (read == 1) { *top = update_top(l, sum, top); sum = 0; l++; }
        else sum = sum + atoi(line);
    }
    *top = update_top(l, sum, top);
    display(top);
    printf("sum of top3 = %d\n", (top[0] + top[1] + top[2]));
    if (ferror(fp)) { perror("read() error"); exit(1); }
    free(line);
    fclose(fp);
    return 0;
}
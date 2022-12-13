#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int update_max(int l, int sum, int max) {
    printf("lutin %d : %d\n", l, sum);
    if (max < sum) max = sum;
    sum = 0;
    return max;
}

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int max = 0;
    int sum = 0; 
    int l = 1;
    fp = fopen("./data.txt", "r");
    if (fp == NULL) exit(1);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (read == 1) { max = update_max(l, sum, max); sum = 0; l++; }
        else sum = sum + atoi(line);
    }
    max = update_max(l, sum, max);
    printf("max = %d\n", max);
    if (ferror(fp)) { perror("read() error"); exit(1); }
    free(line);
    fclose(fp);
    return 0;
}
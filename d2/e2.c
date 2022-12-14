#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

int score = 0;

void work_on_line (char *line) {
    int diff = (int)line[2] - (int)line[0];
    if (diff < 23) diff = diff +3;
    switch (diff) {
        case 25: // lose
            score = score + 0;
            break;
        case 24: // win
            score = score + 6;
            break;
        case 23: // draw
            score = score + 3;
            break;
        default:
            printf("error %d\n", diff);
            break;
    }
    score = score + (int)line[2] - 87;
}

int main(void){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("./data.txt", "r");
    if (fp == NULL) exit(1);
    while ((read = getline(&line, &len, fp)) != -1) {
        work_on_line(line);
    }
    printf("final score : %d\n", score);
    if (ferror(fp)) { perror("read() error"); exit(1); }
    free(line);
    fclose(fp);
    return 0;
}
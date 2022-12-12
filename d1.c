# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void display (char line[]) {
  for (int i = 0; i < 10; i++) printf("%c ", line[i]);
  printf("\n");
}

int main (int argc, char **argv) {
  int fd, nbOct;
  char buffer[256] = {0};
  char line[10];
  int count = 0;
  char path[] = "./data.txt"; 
  fd = open(path, O_RDONLY);
  if (fd == -1) { perror("open() error"); exit(1); }
  while (1) {
    nbOct = read(fd, buffer, 1);
    if (nbOct == -1) { perror("read() error"); exit(1); }
    if (nbOct == 0) break; // end of file
    count++;
    if (buffer[0] == '\n') {
      if (line[0] == '*') printf(">> ");
      write(1, line, count-1);
      write(1, buffer, 1);
      fflush(stdout);
      for(int i = 0; i < sizeof(line); i++) line[i] = '*';
      count = 0;
    }
    else {line[count-1] = buffer[0];}
  }
  close(fd);
  return 0; 
}

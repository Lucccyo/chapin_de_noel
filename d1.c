# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int main (int argc, char **argv) {
  int fdesc, nbOct;
  char tampon[256] = {0};
  char mot_buffer[10];
  int count = 0;
  char path[] = "./data.txt"; 
  fdesc = open(path, O_RDONLY); // ouverture
  if (fdesc == -1) { perror("open() error"); exit(1); }
  while (1) {
    nbOct = read(fdesc, tampon, 1); // lecture
    if (nbOct == -1) { perror("read() error"); exit(1); }
    if (nbOct == 0) break; // fin du fichier
    count++;

    if (tampon[0] == '\n') {
      // printf("."); // le premier passage de ligne, car c prends les fichiers qui commencent a la ligne 0?
      write(1, mot_buffer, count-1); // écriture
      write(1, tampon, 1);
      fflush(stdout);
      for(int i = 0; i < sizeof(mot_buffer); i++) mot_buffer[i] = '*';
      count = 0;
    }
    else {mot_buffer[count-1] = tampon[0];}
  }
  close(fdesc); // fermeture
  return 0; 
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int isStripe(int i) {
  if (i<38||(i>76&&i<115)||(i>153&&i<192)||(i>230&&i<269)||(i>307&&i<346)||(i>384&&i<422)||i>461) return 1;
  return 0;
}

// I'm making an American flag without the stars because that's too much work.
int main() {
  int i, j, r, g, b;
  char line[30] = "P3 950 500 255\n";
  char line2[30];
  int fd = open("work00.ppm", O_WRONLY);
  write(fd, line, strlen(line));
  for (i=0; i<500; i++) {
    for (j=0; j<950; j++) {
      r=g=b=255; // background is by default white (white stripes)
      if (isStripe(i)) { // red stripes
        g=0;
        b=0;
      }
      if (i<269&&j<380) { // the blue section
        r=60;
        g=59;
        b=110;
      }
      sprintf(line2, "%d %d %d ", r, g, b);
      write(fd, line2, strlen(line2));
    }
    write(fd, "\n", 1);
  }

  close(fd);
  return 0;

}
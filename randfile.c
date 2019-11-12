#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include "randfile.h"

int randNum(){
  int file = open( "/dev/random", O_RDONLY); //opening random file
  if (file < 0){ //checking for errors
    printf ("Error opening file: %s\n",strerror(errno));
  }
  int n;
  int r = read(file, &n, sizeof(n)); //reading from random file
  if (r < 0){ //checking for errors
    printf("Error reading from file: %s\n", strerror(errno));
  }
  close(file); //closing file
  return n;
}

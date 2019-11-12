#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include "randfile.h"

int main(){
  printf("Generating random numbers:\n");
  int arr[10];
  int i;
  for(i=0; i<10; i++){
    int r = randNum();
    printf("\trandom %d: %d\n", i, r);
    arr[i] = r;
  }

  printf("\nWriting numbers to file...\n");
  int file = open( "randarr", O_WRONLY | O_CREAT, 0640); //creating file
  if (file < 0){ //checking for errors
    printf ("Error opening file: %s\n",strerror(errno));
  }
  int wr = write(file, &arr, sizeof(arr));
  if (wr < 0){ //checking for errors
    printf ("Error writing to file: %s\n",strerror(errno));
  }
  close(file);

  printf("\nReading numbers from file...\n");
  int arr2[10]; //second array
  int file2 = open( "randarr", O_RDONLY); //opening created file
  if (file2 < 0){ //checking for errors
    printf ("Error opening file: %s\n",strerror(errno));
  }
  int rd = read(file2, &arr2, sizeof(arr2));
  if (rd < 0){ //checking for errors
    printf ("Error reading from file: %s\n",strerror(errno));
  }
  close(file2);

  printf("\nVerification that written values were the same:\n");
  for(i=0; i<10; i++){
    printf("\trandom %d: %d\n", i, arr2[i]);
  }
}

#include "pdfparser.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/stat.h>

#define _FILE_OFFSET_BITS 64

int
main(int argc, char **argv) {
  int ret = 0;
  EncData *e;
  if(argc != 2) {
    fprintf(stderr,"Usage: %s filename\n", argv[0]);
    exit(1);
  }

  FILE *file;
  if((file = fopen(argv[1], "r")) == 0) {
    fprintf(stderr,"Error: file %s not found\n", argv[1]);
    exit(2); 
  }
  //  int ch;
  e = calloc(1,sizeof(EncData));

  if(!openPDF(file,e)) {
    fprintf(stderr, "Error: Not a valid PDF\n");
    ret = 3;
    goto out;
  }

  ret = getEncryptedInfo(file, e);
  if(ret != 0) {
    if(ret == EENCNF) 
      fprintf(stderr, "Error: Could not extract encryption information\n");
    else if(ret == ETRANF)
      fprintf(stderr, "Error: First trailer not found\n");
    else if(ret == ETRENF)
      fprintf(stderr, "Error: Encryption object not found in trailer\n");
    else if(ret == ETRINF)
      fprintf(stderr, "Error: ID object not found in trailer\n");
    ret = 4;
    goto out;
  }
  printEncData(e);

  freeEncData(e);

  if(fclose(file) != 0) {
    fprintf(stderr, "Error: closing file %s\n", argv[1]);
  }

  return 0;

 out:
  freeEncData(e);
  if(fclose(file) != 0) {
    fprintf(stderr, "Error: closing file %s\n", argv[1]);
  }
  exit(ret);
}

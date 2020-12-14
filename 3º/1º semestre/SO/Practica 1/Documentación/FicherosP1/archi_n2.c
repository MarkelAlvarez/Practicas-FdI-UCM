#include <stdio.h>
#include <stdlib.h>
#include "archi.h"

int main(int argc,char* argv[])
{
  int i;

  printf("Hello ...%d\n", VAR);

  if( argc >= 1 )
    for( i=0; i < argc; i++)
        printf("Argument #%d: %s\n",i,argv[i]);	

  exit(0);
}


#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  int i;

  if(argc < 2){
    printf(2, "usage: kill pid...\n");
    exit();
  }
  for(i=1; i<argc; i++){
    if(atoi(argv[i]) == 1){
        printf(1, "No vas a matar a init!\n");
        continue;
    }
    kill(atoi(argv[i]));
  }
  exit();
}

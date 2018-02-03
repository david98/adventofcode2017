#include <stdio.h>
#define MAXLENGTH 200

typedef struct string{
  char content[MAXLENGTH];
  int length;
} t_string;

typedef struct program{
  t_string name;
  t_program *heldBy;
} t_program;

int main(){
  
  return 0;
}

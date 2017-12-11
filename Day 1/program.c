#include <stdio.h>
int main(){
  FILE *fp;
  char c, cNext;
  int sum=0;
  fp = fopen("input.txt", "r");
  c = getc(fp);
  while( ((cNext=getc(fp)) != EOF) ){
    (c==cNext) ? sum+=(c - '0'):0;
    c=cNext;
  }
  printf("%d", sum+9);
}

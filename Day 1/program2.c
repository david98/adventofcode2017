#include <stdio.h>
#include <stdlib.h>
#define J (i+sz/2)
#define C cn[i]
int main(){
  FILE *fp;
  char *cn, c;
  int sum=0,sz,i=0,j;
  fp=fopen("input.txt", "r");
  fseek(fp, 0L, SEEK_END);
  sz=ftell(fp) - 2;
  rewind(fp);
  cn=malloc(sz+1);
  for(;(c=getc(fp))!=EOF;i++)
    C=c;
  C='\0';
  for(i=0;i<sz;i++){
    j= J > sz ? (J-sz) : J;
    if( C == cn[j] )
      sum+= (C - '0');
  }
  printf("%d", sum);
}

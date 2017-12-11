#include <stdio.h>
#include <stdlib.h>
#define C cn[i]
#define SZ 2134
#define J (i+SZ/2)
int main(){
  FILE *fp;
  char cn[2135], c;
  int sum=0,i=0,j;
  fp=fopen("input.txt", "r");
  for(;(c=getc(fp))!=EOF;i++)
    C=c;
  C='\0';
  for(i=0;i<SZ;i++){
    j= J > SZ ? (J-SZ) : J;
    C == cn[j] ? sum+= (C-'0'):0;
  }
  printf("%d", sum);
}

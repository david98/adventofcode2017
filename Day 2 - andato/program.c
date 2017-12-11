#include <stdio.h>
#include <limits.h>
int i,j,sum,max=INT_MIN,min=INT_MAX,num;
int main() {
  FILE *fp;
  char temp[10], c;
  fp = fopen("input.txt", "r");
  while((c=getc(fp))!=EOF){
    if((c!='\0')&&(c!='\n')){
      temp[i]=c;
      i++;
    }
    else{
      num=j=0;
      while(i>=0){
        num+= (temp[--i]-'0')*(++j);
      }
      i=0;
      printf("%d", num);
    }


  }
  return 0;
}

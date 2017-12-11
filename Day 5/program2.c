#include <stdio.h>
#define MAXDIM 2000

void printArray(int *array, int n){
  int i;

  for( i = 0; i < n; i++ )
    printf("%d\n", array[i]);

}

int parseInt(char *string, int size){
  int num = 0,
      i,
      power = 1;

  for( i = size - 1; i > 0; i--, power *= 10 )
    num += (string[i]-'0') * power;

  if( string[0] == '-' )
    num = -num;
  else
    num += (string[0]-'0') * power;

  return num;
  /*int num;

  string[size] = '\0';

  sscanf(string, "%d", &num);
  return num;*/
}

int stepsToExit(int *numbers, int size){
  int i = 0,
      j,
      steps = 0;

  while( i >= 0 && i < size){
    j = i;
    i += numbers[j];
    steps++;
    if( numbers[j] >= 3 )
      numbers[j]--;
    else
      numbers[j]++;
  }

  return steps;
}

int main(){
  char c, temp[MAXDIM];
  FILE *fp;
  int numbers[MAXDIM],
      i = 0,
      j = 0;

  fp = fopen("input.txt", "r");

  while( (c = getc(fp)) != EOF ){
    if( c == '\n' ){
      numbers[i] = parseInt(temp, j);
      i++;
      j = 0;
    } else {
      temp[j] = c;
      j++;
    }
  }

  fclose(fp);

  printf("%d", stepsToExit(numbers, i));
  return 0;
}

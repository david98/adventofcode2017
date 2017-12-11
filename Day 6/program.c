#include <stdio.h>
#define MAXDIM 30
#define MAXDIM2 1000

int parseInt(char *string, int size){
  int num;

  string[size] = '\0';

  sscanf(string, "%d", &num);
  return num;
}

void printArray(int *array, int n){
  int i;

  for( i = 0; i < n; i++ )
    printf("%d\n", array[i]);

}

int arrayEquals(int *array1, int *array2, int n){
  int equals = 1,
      i = 0;

  for( i = 0; i < n && equals; i++ )
    if( array1[i] != array2[i] )
      equals = 0;

  return equals;
}

void arrayCopy(int *dest, int *source, int size){
  int i;

  for( i = size - 1; i >= 0; i-- )
    dest[i] = source[i];
}

void balanceBlocks(int *banks, int size){
  int spareBlocks,
      maxNumberIndex = 0,
      maxNumber = banks[0],
      i;

  for( i = 0; i < size; i++ ){
    if( banks[i] > maxNumber ){
      maxNumber = banks[i];
      maxNumberIndex = i;
    }
  }

  spareBlocks = maxNumber;
  banks[maxNumberIndex] = 0;
  i = maxNumberIndex + 1;
  if( i > size )
    i = 0;
  while( spareBlocks > 0 ){

    banks[i]++;

    i++;
    if( i > size )
      i = 0;
    spareBlocks--;
  }

}

int stepsToDetectLoop(int *banks, int size){
  int steps = 0,
      loop = 0,
      i = 0,
      history[MAXDIM2][MAXDIM];

  while( !loop && steps < MAXDIM2 - 1 ){

    steps++;

    balanceBlocks(banks, size);

    for( i = 1; i < steps; i++ ){
      if( arrayEquals(history[i], banks, size) )
        loop = 1;
    }

    arrayCopy(history[steps], banks, size);
    /*printArray(history[steps], size);
    printf("\n");*/

  }

  return steps;
}

int main(){
  FILE *fp;
  char c, temp[MAXDIM];
  int i = 0,
      j = 0,
      banks[MAXDIM];

  fp = fopen("input.txt", "r");

  while( (c = getc(fp)) != EOF ){
    if( c == '\t' || c == ' ' || c == '\n' ){
      banks[i] = parseInt(temp, j);
      i++;
      j = 0;
    } else {
      temp[j] = c;
      j++;
    }
  }

  printf("%d", stepsToDetectLoop(banks, i));

}

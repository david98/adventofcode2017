#include <stdio.h>
#include <string.h>
#define MAXDIM 100

void printArray(int *array, int n){
  int i;

  for( i = 0; i < n; i++ )
    printf("%d ", array[i]);

  printf("\n");
}

void zero(char passphrase[MAXDIM][MAXDIM]){
  int i, j;

  for(i = 0; i < MAXDIM; i++ )
    for(j = 0; j < MAXDIM; j++ )
      passphrase[i][j] = '\0';
}

/*
* Arrays must be of the same size
*/
int arrayEquals(int *array1, int *array2, int n){
  int equals = 1,
      i = 0;

  for( i = 0; i < n && equals; i++ )
    if( array1[i] != array2[i] )
      equals = 0;

  return equals;
}

int areStringsAnagrams(char *string1, char *string2){
  int characterCount1[255] = {0}, characterCount2[255] = {0},
      i,
      anagrams = 0,
      n = strlen(string1);

  if( strlen(string2) == n ){
    for( i = 0; i < n; i++ ){
      characterCount1[(int)string1[i]]++;
      characterCount2[(int)string2[i]]++;
    }

    anagrams = arrayEquals(characterCount1, characterCount2, 255);
  }

  return anagrams;

}

int checkIfValidPassphrase(char passphrase[MAXDIM][MAXDIM], int numberOfWords){
  char currentWord[MAXDIM];
  int i, j, valid = 1;

  for(i = 0; (i < numberOfWords) && valid; i++){
    strcpy(currentWord, passphrase[i]);
    for( j = i + 1; (j < numberOfWords) && valid; j++)
      valid = !areStringsAnagrams(currentWord, passphrase[j]);
  }

  return valid;
}

int main(){
  char currentPassphrase[MAXDIM][MAXDIM], c;
  FILE *fp;
  int wordIndex = 0,
      charIndex = 0,
      validCounter = 0;

  fp = fopen("input.txt", "r");
  zero(currentPassphrase);
  while( (c = getc(fp)) != EOF ){
    if( (c == ' ') || (c == '\0') || (c == '\t') ){
      //nuova parola
      charIndex = 0;
      wordIndex++;
    } else if( c == '\n' ){
      //controlla passphrase attuale
      if( checkIfValidPassphrase(currentPassphrase, wordIndex+1) )
        validCounter++;
      //nuova passphrase
      zero(currentPassphrase);
      wordIndex = 0;
      charIndex = 0;
    } else{
      //salva carattere
      currentPassphrase[wordIndex][charIndex] = c;
      charIndex++;
    }
  }

  printf("%d", validCounter);

  return 0;
}

#include <stdio.h>
#include <string.h>
#define MAXDIM 100

void zero(char passphrase[MAXDIM][MAXDIM]){
  int i, j;

  for(i = 0; i < MAXDIM; i++ )
    for(j = 0; j < MAXDIM; j++ )
      passphrase[i][j] = '\0';
}

int checkIfValidPassphrase(char passphrase[MAXDIM][MAXDIM], int numberOfWords){
  char currentWord[MAXDIM];
  int i, j, valid = 1;

  for(i = 0; (i < numberOfWords) && valid; i++){
    strcpy(currentWord, passphrase[i]);
    for( j = i + 1; (j < numberOfWords) && valid; j++){
      if( strcmp(currentWord, passphrase[j]) == 0 )
        valid = 0;
    }
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

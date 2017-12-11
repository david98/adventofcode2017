#include <stdio.h>
#include <math.h>

typedef struct point{
  int x;
  int y;
} t_point;

t_point findCoordinates(int n){
  t_point nCoordinates;
  nCoordinates.x = 0;
  nCoordinates.y = 0;

  int k = ceil( (sqrt(n) - 1)/2 ),
      t = 2 * k + 1,
      m = t * t;
      t--;

  if( n >= (m-t) ){
    nCoordinates.x = k - (m-n);
    nCoordinates.y = -k;
  } else
    m -= t;
  if( n >= (m-t) ){
    nCoordinates.x = -k;
    nCoordinates.y = -k + (m-n);
  } else
    m -= t;
  if( n >= (m-t) ){
    nCoordinates.x = -k + (m-n);
    nCoordinates.y = k;
  } else {
    nCoordinates.x = k;
    nCoordinates.y = k - (m-n-t);
  }

  return nCoordinates;
}

int distanceFromZero(t_point point){
  return abs(point.x) + abs(point.y);
}

int main(){
  int number;
  t_point numberCoordinates;
  printf("Insert number: ");
  scanf("%d", &number);
  numberCoordinates = findCoordinates(number);
  printf("Coordinates: %d\t%d\n", numberCoordinates.x, numberCoordinates.y);
  printf("Number of steps: %d", distanceFromZero(numberCoordinates));
  getchar();

  return 0;
}

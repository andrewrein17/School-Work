#include <stdio.h>

int i, j;
int a[20][11];
int f;
int b[20][11];

int main()
{
  printf("input a factor (2-10):\n");
  scanf("%d", &f);
  i = 0;
  while (i < 20) {
    j = 0;
    while (j < 11) {
      a[i][j] = i*11+j;
      printf("%5d", a[i][j]);
      j = j+1;
    }
    printf("\n");
    i = i+1;
  }
  
  printf("*\n");
  printf("%d\n", f);
  printf("=\n");

  i=0;
  while (i < 20) {
    j = 0;
    while (j < 11) {
      b[i][j] = a[i][j]*f;
      printf("%5d", b[i][j]);
      j = j+1;
    }
    printf("\n");
    i = i+1;
  }
  printf("\n");
}

#include <stdio.h>

int i, j, k;
int a[20][15];
int b[15][5];
int c[20][5];
int cur, s;

int main()
{
  printf("pick a prime seed (7, 11, 13, 17): ");
  scanf("%d", &cur);
  i = 0;
  while (i < 20) {
    j = 0;
    while (j < 15) {
      cur = cur * 7 - (cur * 7)/1811*1811;
      a[i][j] = cur;
      printf("%7d", a[i][j]);
      j = j+1;
    }
    printf("\n");
    i = i+1;
  }
   
  printf("*\n");
  i=0;
  while (i < 15) {
    j = 0;
    while (j < 5) {
      cur = cur * 7 - (cur * 7)/1811*1811;
      b[i][j] = cur;
      printf("%7d", b[i][j]);
      j = j+1;
    }
    printf("\n");
    i = i+1;
  }
  i = 0;
  
  printf("=\n");
  
   i = 0;
   while (i < 20) {
     j = 0;
     while (j < 5) {
       s = 0;
       k = 0;
       while (k < 15) {
	 s = s + a[i][k]*b[k][j];
	 k = k+1;
       }	 
       c[i][j] = s;
       printf("%10d", c[i][j]);
       j = j+1;
     }
     printf("\n");
     i = i+1;
   }  
}

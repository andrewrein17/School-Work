#include <stdio.h>

int i, j;
int a[20][8];
int b[8];
int c[20];
int k, s;

int main()
{
   i = 0;
   while (i < 20) {
     j = 0;
     while (j < 8) {
       a[i][j] = i*8+j;
       printf("%5d", a[i][j]);
       j = j+1;
     }
     printf("\n");
     i = i+1;
   }
   
   printf("*\n");

   i = 0;
   while (i < 8) {
     b[i] = i*i;
     printf("%5d\n", b[i]);
     i = i+1;
   }

   printf("=\n");

   i = 0;
   while (i < 20) {
     j = 0;
     s = 0;
     while (j < 8) {
       s = s + a[i][j] * b[j];
       j = j+1;
     }
     c[i] = s;
     i = i+1;
   }
   
   k = 0;
   while (k < 20) {
     printf("c[%2d] = ", k);
     printf("%5d\n", c[k]);
     k = k+1;
   }
  
}

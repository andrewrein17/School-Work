#include <stdio.h>

int i, j;
int a[10][20];
int s;

int main()
{
   i = 0;
   while (i < 10) {
     j = 0;
     while (j < 20) {
       a[i][j] = i*20+j;
       printf("%5d", a[i][j]);
       j = j+1;
     }
     printf("\n");
     i = i+1;
   }

   printf("column sum:\n");
   j = 0;
   while (j < 20) {
     i= 0;
     s = 0;
     while (i < 10) {
       s = s + a[i][j];
       i = i+1; 
     }
     printf("%5d", s);
     j = j+1;
   }
   printf("\n");
}

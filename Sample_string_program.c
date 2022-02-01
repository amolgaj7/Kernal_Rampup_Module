#include <stdio.h>
#include "My_string.h"

int main() {
   char str1[100] = "This is ", str2[] = "Amol Gajbhiye";

   // concatenates str1 and str2
   // the resultant string is stored in str1.
   strcat(str1, str2);

   puts(str1);
   

   return 0;
}
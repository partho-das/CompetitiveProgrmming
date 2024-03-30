/**

#if #else #elif #endif
#ifdef #ifndef #undef
*/

#include<stdio.h>
#define add(a,b) a##b
#define PI 3.1416
int main()
{
  #ifdef PI
  printf("yes\n");
  #undef PI
  #endif // PI
  #ifndef PI
  #define PI 3.59
  #endif // PI

  printf("%f",PI);



 return 0;
}

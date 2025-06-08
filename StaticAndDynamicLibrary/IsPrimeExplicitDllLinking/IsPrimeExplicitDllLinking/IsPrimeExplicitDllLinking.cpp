#include "pch.h"
#include "IsPrimeExplicitDllLinking.h"

extern "C" bool IsPrime(long long int n)
{
   if (n <= 1) return false;
   for (long long int i = 2; i * i <= n; i++) {
      if (n % i == 0) 
         return false;
   }
   return true;
}
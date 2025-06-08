#include "pch.h"
#include "CountFactorsDLL.h"

int CountFactorsDll(const long long int n) {
   int count = 0;
   for (long long int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
         if (i == n / i) {
            count += 1;
         }
         else {
            count += 2;
         }
      }
   }
   return count;
}
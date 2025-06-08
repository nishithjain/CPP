#include "CountFactors.h"

int CountFactors(const long long int n) {
   int count = 0;
   for (long long int i = 1; i <= n; i++) {
      if (n % i == 0) {
         count++;
      }
   }
   return count;
}

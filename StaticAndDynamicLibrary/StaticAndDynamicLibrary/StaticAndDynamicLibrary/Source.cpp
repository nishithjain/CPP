#include "CountFactors.h"
#include "CountFactorsDLL.h"
#include <iostream>
#include <windows.h>

int main()
{
   {
      constexpr long long int i = 1'000'000'000;
      const auto number_of_factors = CountFactors(i);
      std::cout << "Number of Factors for " << i << " is :"
         << number_of_factors << "\n";
   }
   {  // Implicit Linking 
      constexpr long long int i = 1'000'000'000;
      const auto number_of_factors = CountFactorsDll(i);
      std::cout << "Number of Factors for " << i << " is :"
         << number_of_factors << "\n";
   }
   {  // Explicit Linking
      // Use this when you don't have a .lib file or want plugin-style loading.
      const HMODULE h_dll = LoadLibrary(TEXT("IsPrimeExplicitDllLinking.dll"));
      if (!h_dll) {
         std::cerr << "Failed to load DLL\n";
         return 1;
      }

      typedef bool (*IsPrimeFunction)(long long int);
      auto is_prime = (IsPrimeFunction)GetProcAddress(h_dll, "IsPrime");
      if (!is_prime) {
         std::cerr << "Function not found\n";
         return 1;
      }

      constexpr long long int i = 999'983;
      const auto is_the_number_prime = is_prime(i);
      const auto ans = is_the_number_prime ? "Prime number!" : "Not a Prime number.";
      std::cout << "The given number " << i << " is " << ans << "\n";

      FreeLibrary(h_dll);
   }
}
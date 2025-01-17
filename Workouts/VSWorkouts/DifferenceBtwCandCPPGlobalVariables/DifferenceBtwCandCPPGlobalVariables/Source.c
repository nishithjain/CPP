#include <stdio.h>
#include "Car.h"
#include "Helicopter.h"

/************************************************************************
Number of Helicopter = 10, but we didn't set any Helicopter count. 
Why is this?

In C, a global variable is just a declaration unless it is initialized.
In C++, a global variable is definition. If we try compiling the code
by invoking C++ compiler, we will get error"Multiple defined symbols found".

One way to solve this issues is to initialize the global variable when it 
is declared. If we initialize, we will get "redefinition; multiple initialization"
error.
************************************************************************/

int main(void)
{
    setCarCount(10);
    printf("Number of Cars = %d\n", getCarCount());
    printf("Number of Helicopter = %d\n", getHelicopterCount());

    return 0;
}
/*  OUTPUT
Number of Cars = 10
Number of Helicopter = 10
*/
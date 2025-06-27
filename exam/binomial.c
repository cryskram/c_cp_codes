#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int binomialCoefficient(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()
{
    int n = 6, k = 4;
    binomialCoefficient(n, k);
    return 0;
}

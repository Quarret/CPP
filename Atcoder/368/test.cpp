#include <stdio.h>
#include <math.h>
int factorial(int x)
{
    int i, sum = 1;
    for (i = 1; i <= x; i++)
    {
        sum *= i;
    }
    return sum;
}
int main()
{
    double x;
    scanf("%lf", &x);
    int n = 0;
    double sum = 0;
    int a = 1, index = 1;
    do
    {
        sum += a * (pow(x, (2 * n + 1))) / factorial(2 * n + 1);
        a = a * (-1);
        n += 1;
        index += 1;

    } while (pow(x, (2 * n + 1)) / factorial(2 * n + 1) >= 0.00001);
    printf("sin %lf = %lf\n", x, sum);
    printf("index=%d", index);
}
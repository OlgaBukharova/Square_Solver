#include <stdio.h>
#include <math.h>

void solve_zero_deg(double c, int * num)
{
    if (c != 0)
    {
        * num = 0;
    }
}

void solve_linear(double b, double c, double * x, int * num)
{
    * num = 1;
    * x = -c / b;
}

void solve_quadratic(double a, double b, double c, double * x1, double * x2, int * num)
{
    double discr = b * b - 4 * a * c;

    if (discr < 0)
    {
        * num = 0;
    }
    else
    {
        if (discr == 0)
        {
            * num = 1;

            * x1 = -b / (2 * a);
        }
        else 
        {
            * num = 2;

            double sqrt_discr = sqrt(discr);

            * x1 = (-b - sqrt_discr) / (2 * a);
            * x2 = (-b + sqrt_discr) / (2 * a);
        }
    }
}

void input_coef(double * a, double * b, double * c)
{
    scanf("%lf%lf%lf", a, b, c);
}

void solve_equation(double a, double b, double c, double * x1, double * x2, int * num)
{
    if (a == 0) 
    {
        if (b == 0) 
        {
            solve_zero_deg(c, num);
        }
        else 
        {
            solve_linear(b, c, x1, num);
        }
    }
    else
    {
        solve_quadratic(a, b, c, x1, x2, num);
    }
}

void output_solution(int num, double x1, double x2)
{
    switch (num)
    {
        case 0:
            printf("No solutions\n");
            break;
        case 1:
            printf("X = %lg\n", x1);
            break;
        case 2:
            printf("X1 = %lg\nX2 = %lg\n", x1, x2);
            break;
        default:
            printf("All numbers\n"); 
    }
}

int main()
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;
    int num = -1;

    input_coef(&a, &b, &c);

    solve_equation(a, b, c, &x1, &x2, &num);

    output_solution(num, x1, x2);

    return 0;
} 
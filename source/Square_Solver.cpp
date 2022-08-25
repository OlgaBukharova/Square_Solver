#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c)
{
    double discr = b * b - 4 * a * c;

    printf("Quadratic equation\nDiscriminant = %lg\n", discr);

    double x1 = NAN;
    double x2 = NAN;

    if (discr < 0)
    {
        printf("No solutions\n");
    }
    else
    {
        if (discr == 0)
        {
            x1 = -b / (2 * a);

            if (x1 == -0)
            { 
                x1 = 0;
            }

            printf("x1 = x2 = %lg\n", x1);
        }
        else
        {
            double sqrt_discr = sqrt(discr);

            x1 = (-b - sqrt_discr) / (2 * a);
            x2 = (-b + sqrt_discr) / (2 * a);

            if (x1 == -0) 
            {
                x1 = 0;
            }

            if (x2 == -0) 
            {
                x2 = 0;
            }

            printf("x1 = %lg\nx2 = %lg\n", x1, x2);
        }
    }

    return 0;
}

int solves_linear(double b, double c)
{
    double x = -c / b;

    if (x == -0) 
    {
        x = 0;
    }

    printf ("Linear equation\nx = %lg\n", x);

    return 0;
}

int solve_zero_deg(double c)
{
    printf("Zero degree equation\n");

    if (c == 0) 
    {
        printf("All numbers\n");
    }
    else 
    {    
        printf("No solutions\n");
    }

    return 0;
}

int main()
{
    double a = NAN; 
    double b = NAN;
    double c = NAN;

    scanf("%lf%lf%lf", &a, &b, &c);
 
    if (a == 0) 
    {
        if (b == 0)
        {
            solve_zero_deg(c);
        }
        else 
        {
            solves_linear(b, c);
        }
    }
    else
    {
        solve_quadratic(a, b, c);
    }

    return 0;
}
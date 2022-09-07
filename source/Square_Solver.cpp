#include <stdio.h>
#include <math.h>

struct equation
{
    double a;
    double b;
    double c;
    int number;
    double x1;
    double x2;
};

void solve_zero_deg(struct equation * ex)
{
    if (ex -> c != 0)
    {
        ex -> number = 0;
    }
}

void solve_linear(struct equation * ex)
{
    ex -> number = 1;
    ex -> x1 = -(ex -> c) / (ex -> b);
}

void solve_quadratic(struct equation * ex)
{
    double discr = (ex -> b) * (ex -> b) - 4 * (ex -> a) * (ex -> c);

    if (discr < 0)
    {
        ex -> number = 0;
    }
    else
    {
        if (discr == 0)
        {
            ex -> number = 1;

            ex -> x1 = -(ex -> b) / (2 * (ex -> a));
        }
        else 
        {
            ex -> number = 2;

            double sqrt_discr = sqrt(discr);

            ex -> x1 = (-(ex -> b) - sqrt_discr) / (2 * (ex -> a));
            ex -> x2 = (-(ex -> b) + sqrt_discr) / (2 * (ex -> a));
        }
    }
}

void input_coef(struct equation * ex)
{
    scanf("%lf%lf%lf", & (ex -> a), & (ex -> b), & (ex -> c));
}

void solve_equation(struct equation * ex)
{
    if (ex -> a == 0) 
    {
        if (ex -> b == 0) 
        {
            solve_zero_deg(ex);
        }
        else 
        {
            solve_linear(ex);
        }
    }
    else
    {
        solve_quadratic(ex);
    }
}

void output_solution(struct equation * ex)
{
    switch (ex -> number)
    {
        case 0:
            printf("No solutions\n");
            break;
        case 1:
            printf("X = %lg\n", ex -> x1);
            break;
        case 2:
            printf("X1 = %lg\nX2 = %lg\n", ex -> x1, ex -> x2);
            break;
        default:
            printf("All numbers\n"); 
    }
}

int main()
{
    struct equation user_eq;
    user_eq.a = NAN;
    user_eq.b = NAN;
    user_eq.c = NAN;
    user_eq.x1 = NAN;
    user_eq.x2 = NAN;
    user_eq.number = -1;

    input_coef(&user_eq);

    solve_equation(&user_eq);

    output_solution(&user_eq);

    return 0;
}
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

#include "../headers/solver.h"

#define EPS 1e-10 

bool is_zero(double a)
{
    assert(isfinite(a));

    return fabs(a) < EPS;
}

double if_minus_o(double a)  
{
    assert(isfinite(a));

    if (is_zero(a))
        return 0;
    else 
        return a;
}

void solve_zero_deg(struct equation *ex)
{
    assert(ex);
    assert(isfinite(ex->c));

    if (!is_zero(ex->c))
    {
        ex->number = 0;
    } 
}

void solve_linear(struct equation *ex)
{
    assert(ex);
    assert(isfinite(ex->b));
    assert(isfinite(ex->c));

    ex->number = 1;
    ex->x1 = if_minus_o(-(ex->c) / (ex->b));
}

void solve_quadratic(struct equation *ex)
{
    assert(ex);
    assert(isfinite(ex->a));
    assert(isfinite(ex->b));
    assert(isfinite(ex->c));

    double discr = (ex->b) * (ex->b) - 4 * (ex->a) * (ex->c);

    if (discr < 0)
    {
        ex->number = 0;
    }
    else
    {
        if (is_zero(discr))
        {
            ex->number = 1;

            ex->x1 = if_minus_o(-(ex->b) / (2 * (ex->a)));
        }
        else 
        {
            ex->number = 2;

            double sqrt_discr = sqrt(discr);

            ex->x1 = (-(ex->b) - sqrt_discr) / (2 * (ex->a));
            ex->x2 = (-(ex->b) + sqrt_discr) / (2 * (ex->a));


        }
    }
}

void clean_buffer()
{
    char c = 0;

    while (((c = getchar()) != EOF) && (c != '\n'));
}

int check_buffer()
{
    char c = 0;
    while (((c = getchar()) != EOF) && (c != '\n'))
    {
        if (!isspace(c))
            return 1; //incorrect
    }
    return 0; //correct
}

void input_coef(struct equation * ex)
{
    assert(ex);

    int s = 0;

    while (s != 3)
    {
        s = scanf("%lf%lf%lf", &(ex->a), &(ex->b), &(ex->c));

        if ((s != 3) || (check_buffer()))
        {
            clean_buffer();
            
            printf("Input error. Try again...\n");

            s = 0;
        }
    }
   
}

void solve_equation(struct equation *ex)
{
    assert(ex);
    assert(isfinite(ex->a));
    assert(isfinite(ex->b));
    assert(isfinite(ex->c));

    if (is_zero(ex->a)) 
    {
        if (is_zero(ex->b)) 
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

void output_solution(struct equation *ex)
{
    assert(ex);
    
    switch (ex->number)
    {
        case 0:
            printf("No solutions\n");
            break;
        case 1:
            printf("X = %lg\n", ex->x1);
            break;
        case 2:
            printf("X1 = %lg\nX2 = %lg\n", ex->x1, ex->x2);
            break;
       
        default:
            printf("All numbers\n");  
    }
}
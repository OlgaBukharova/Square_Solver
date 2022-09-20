#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EPS 0.000000001

struct equation
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
    int number = -1;
    double x1 = NAN;
    double x2 = NAN;
};

/**
 * @brief Comparation of floating point numbers to 0
 * 
 * @param a Floationg point number
 * @return true if a is 0
 * @return false if a is not 0
 */
bool is_zero(double a)
{
    assert(isfinite(a));

    return fabs(a) < EPS;
}

/**
 * @brief Change of -0 to 0
 * 
 * @param a Floating point number
 * @return double 0 if a is -0, a if not -0
 */
double if_minus_o(double a)  
{
    assert(isfinite(a));

    if (is_zero(a))
        return 0;
    else 
        return a;
}

/**
 * @brief Solvation of zero degree equations (coefficients at x^2 and x are 0)
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
void solve_zero_deg(struct equation *ex)
{
    assert(ex);
    assert(isfinite(ex->c));

    if (!is_zero(ex->c))
    {
        ex->number = 0;
    } 
}

/**
 * @brief Solvation of linear equations (coefficient at x^2 is 0, coefficient at x is not 0)
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
void solve_linear(struct equation *ex)
{
    assert(ex);
    assert(isfinite(ex->b));
    assert(isfinite(ex->c));

    ex->number = 1;
    ex->x1 = if_minus_o(-(ex->c) / (ex->b));
}

/**
 * @brief Solvation of quadratic equation (coefficient at x^2 is not 0)
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
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

/**
 * @brief Scaning user coefficients 
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
void input_coef(struct equation * ex)
{
    assert(ex);

    int s = 0;
    s = scanf("%lf%lf%lf", &(ex->a), &(ex->b), &(ex->c));

}

/**
 * @brief Solvation of any equation
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
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

/**
 * @brief Printing solutions depending on the number of colutions 
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
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

int main()
{
    struct equation user_eq = {};

    input_coef(&user_eq);

    solve_equation(&user_eq);

    output_solution(&user_eq);

    return 0;
}
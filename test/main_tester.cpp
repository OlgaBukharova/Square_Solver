#include <stdio.h>
#include "../headers/solver.h"
#include <assert.h>

/**
 * @brief Printing error message
 * 
 * @param ex Structure of coefficients, number of solutions and solutions
 * @param n_exp Integer number
 * @param x1_exp Floating piont number
 * @param x2_exp Floating piont number
 */
void print_error(struct equation * ex, int n_exp, double x1_exp, double x2_exp)
{
    printf("_________________\n");
    printf("Test failed.\nCoef: %lf, %lf, %lf.\n", ex->a, ex->b, ex->c);
    printf("Expected number of solutions: %d.\nExpected solutions x1, x2: %lf, %lf.\n", n_exp, x1_exp, x2_exp);
    printf("Recieved number of solutions: %d.\nRecieved solutions x1, x2: %lf, %lf.\n", ex->number, ex->x1, ex->x2);
    printf("_________________\n\n");
}

/**
 * @brief Checking if recieved informarion is equal to expected information
 * 
 * @param ex Structure of coefficients, number of solutions and solutions
 * @param x1_exp Floating piont number
 * @param x2_exp Floating piont number
 * @return true if equal
 * @return false if not equal
 */
bool equal_solutions(struct equation * ex, double x1_exp, double x2_exp)
{
    if (ex->number == 2)
        return ((is_equal(x1_exp, ex->x1) && is_equal(x2_exp, ex->x2)) || (is_equal(x1_exp, ex->x2) && is_equal(x2_exp, ex->x1)));
    else if (ex->number == 1)
        return (is_equal(x1_exp, ex->x1) && isnan(ex->x2));
    else
        return (isnan(ex->x1) && isnan(ex->x2));
    
}

/**
 * @brief Scanning test information: coefficients and expected number of solutions and solutions
 * 
 * @param ex Structure of coefficients, number of solutions and solutions
 * @param n_exp Integer number
 * @param x1_exp Floating piont number
 * @param x2_exp Floating piont number
 * @return int 1 if test is incorrect, 0 otherwise
 */
int test_input_coef(struct equation* ex, int* n_exp, double* x1_exp, double* x2_exp)
{
    assert(ex);

    int s = 0;

    s = scanf("%lf%lf%lf", &(ex->a), &(ex->b), &(ex->c));

    if (s != 3) 
    {
        printf("Incorrect test. Lack of coef.\n");    
        return 1;
    }

    scanf("%d", n_exp);

    if (*n_exp == 2)
        scanf("%lf%lf", x1_exp, x2_exp);
    else if (*n_exp == 1)
        scanf("%lf", x1_exp);
    else if (!((*n_exp == 0) || (*n_exp == -1)))
    {
        printf("Incorrect test. Invalid expected number of solutions.\n");
        return 1;
    }
    
   return 0;
}

/**
 * @brief Outputing results of tests
 * 
 * @param ex Structure of coefficients, number of solutions and solutions
 * @param n_exp Integer number
 * @param x1_exp Floating point number
 * @param x2_exp Floating point nimber
 * @return int 1 if test is passed, 0 otherwise
 */
int test_output(struct equation * ex, int n_exp, double x1_exp, double x2_exp)
{
    assert(ex);

    if ((ex->number != n_exp))
    {
        print_error(ex, n_exp, x1_exp, x2_exp);
        return 0;
    }
    else if (!equal_solutions(ex, x1_exp, x2_exp))
    {    
        print_error(ex, n_exp, x1_exp, x2_exp);
        return 0;
    }
    else 
        printf("Test passed.\n");
    
    return 1;
}

int main()
{
    int n_exp = 0;
    double x1_exp = NAN;
    double x2_exp = NAN;
    int n_tests = 0;
    int count_passed = 0;

    struct equation test_eq = {};

    scanf("%d", &n_tests);

    for (int i = 1; i <= n_tests; i++)
    {
        printf("____________________\nTest %d\n", i);
        if (!test_input_coef(&test_eq, &n_exp, &x1_exp, &x2_exp))
        {
            solve_equation(&test_eq);
            count_passed += test_output(&test_eq, n_exp, x1_exp, x2_exp);
        }

        n_exp = 0;
        x1_exp = NAN;
        x2_exp = NAN;
        test_eq.x1 = NAN;
        test_eq.x2 = NAN;
        test_eq.number = -1;
    }

    printf("____________________\n++++++++++++++++++++\nPASSED %d/%d TESTS\n++++++++++++++++++++\n", count_passed, n_tests);

    return 0;
}
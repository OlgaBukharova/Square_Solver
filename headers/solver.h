#pragma once

#include <math.h>

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
 * @param a Floating point number
 * @return true if a is 0
 * @return false if a is not 0
 */
bool is_zero(double a);

/**
 * @brief Change of -0 to 0
 * 
 * @param a Floating point number
 * @return double 0 if a is -0, a if not -0
 */
double if_minus_o(double a);  

/**
 * @brief Comparation of two floating point numbers
 * 
 * @param a Floating point number
 * @param b Floating piont number
 * @return true if equal
 * @return false if not equal
 */
bool is_equal(double a, double b)

/**
 * @brief Solvation of zero degree equations (coefficients at x^2 and x are 0)
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
void solve_zero_deg(struct equation *ex);

/**
 * @brief Solvation of linear equations (coefficient at x^2 is 0, coefficient at x is not 0)
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
void solve_linear(struct equation *ex);

/**
 * @brief Solvation of quadratic equation (coefficient at x^2 is not 0)
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
void solve_quadratic(struct equation *ex);

/**
 * @brief Cleaning buffer stdin
 * 
 */
void clean_buffer();

/**
 * @brief Checking if the buffer stdin is clean
 * 
 * @return int 0 if clean, 1 otherwise
 */
int check_buffer();

/**
 * @brief Scaning user coefficients 
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
void input_coef(struct equation * ex);

/**
 * @brief Solvation of any equation
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
void solve_equation(struct equation *ex);

/**
 * @brief Printing solutions depending on the number of colutions 
 * 
 * @param ex Structure of coefficient, number of solutions and solutions
 */
void output_solution(struct equation *ex);
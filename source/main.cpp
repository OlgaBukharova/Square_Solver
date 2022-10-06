#include <stdio.h>
#include "../headers/solver.h"

int main()
{
    struct equation user_eq = {};

    printf("This programm will solve any quadratic equation\n");
    printf("Input coefficients A, B, C of quadratic equation Ax^2 + Bx + C = 0\n");

    input_coef(&user_eq);

    solve_equation(&user_eq);

    printf("\nSolutions:\n");

    output_solution(&user_eq);

    return 0;
}
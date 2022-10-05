#include <stdio.h>
#include "../headers/solver.h"

int main()
{
    struct equation user_eq = {};

    input_coef(&user_eq);

    solve_equation(&user_eq);

    output_solution(&user_eq);

    return 0;
}
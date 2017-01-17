#include <stdio.h>

/* -------------------------- f_val ------------------------- */
/*  Given a double, x, this routine returns the value 
    f(x) = x^3 - 6.1 x^2 + 10.8 x - 5.8.                      */

double f_val (double x) {
    return x*x*x - 6.1 * x * x + 10.8 * x - 5.8;
}
/* ------------------------ END f_val ----------------------- */


/* ------------------------ midpoint ------------------------ */
/*  Given an interval [a, b], a tolerance, and a maximum
    number of steps, this routine executes the midpoint 
    method to compute an approximation, p', to a root, p, of 
    the function f in the interval [a,b] such that 
    |p' - p| <= TOL.                                          */

double midpoint (double a, double b, double TOL, 
                 double f(double x), int Numstep) {
    int i;
    double FA, FP, p;

    FA = f(a);

    for(i = 1; i <= Numstep; i++) {
        p = a + (b - a)/2;
        FP = f(p);

        if(FP == 0 || (b - a)/2 <= TOL) {
            break;
        }
        else if(FA*FP > 0) {
            a = p;
            FA = FP;
        }
        else {
            b = p;
        }
    }

    return p;
}
/* ---------------------- END midpoint ---------------------- */


/* -------------------------- main -------------------------- */
/*  Main program which computes all real roots of f_val.      */
void main() {
    /*---- Computing first root using midpoint ----*/
    printf("Root in [0.5, 1.5]: %lg\n", 
            midpoint(0.5, 1.5, 10e-5, f_val, 100));

    /*---- Computing second root using midpoint ----*/
    printf("Root in [1.5, 2.5]: %lg\n", 
            midpoint(1.5, 2.5, 10e-5, f_val, 100));

    /*---- Computing third root using midpoint ----*/
    printf("Root in [3, 4]: %lg\n", 
            midpoint(3, 4, 10e-5, f_val, 100));
}
/* ------------------------ END main ------------------------ */

#include "msr.h"

void report(const char *name, int task, double r1, double r2, double r3, double r4, double t1, double t2,int it, double eps, int k, int nx, int ny, int p)
{
    printf (
        "%s : Task = %d R1 = %e R2 = %e R3 = %e R4 = %e T1 = %.2f T2 = %.2f\
        It = %d E = %e K = %d Nx = %d Ny = %d P = %d\n",
        name, task, r1, r2, r3, r4, t1, t2, it, eps, k, nx, ny, p);
}

void get_my_rows(int n, int p, int thr, int &i1, int &i2)
{
    i1 = n * thr; i1 /= p;
    i2 = n * (thr + 1); i2 /= p;   
}

int get_len_msr(int nx, int ny)
{
    return (nx - 1) * (ny - 1) * 6 + (nx - 1) * 4 * 2 + (ny - 1) * 4 * 2 + 3 * 2 + 2 * 2;
}

void* msr_sovle(void* ptr)
{
    args *arg = (args*) ptr;

    double a = arg->a;
    double b = arg->b;
    double c = arg->c;
    double d = arg->d;
    int nx = arg->nx;
    int ny = arg->ny;
    int k = arg->k;
    double eps = arg->eps;
    int mi = arg->mi;
    int p = arg->p;
    int thr = arg->thr;
    double *A = arg->A;
    int *I = arg->I;


    return nullptr;
}
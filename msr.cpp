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
void ij2l(int nx, int ny, int i, int j, int &l)
{
    ny = ny;
    l = i + j * (nx + 1);
}
void l2ij(int nx, int ny, int l, int &i, int &j)
{
    ny = ny;
    j = l / (nx + 1);
    i = l - j * (nx + 1);
}

int IA_ij(int nx, int ny, double hx, double hy, int i, int j, int is, int js, int s, int *I, double *A)
{
    double S = 0.5 * hx * hy;
    int l, ls;

    ij2l(nx, ny, i, j, l);
    ij2l(nx, ny, is, js, ls);

    // if (l != ls)
    // I[s] = ls;

    if(!A && !I)
    {
        printf("A and I are nullptrs in IA_ij for i = %d , j = %d , is = %d , js = %d , s = %d\n",i,j,is,js,s);
        return -1;
    }

    if(i > 0 && i < nx && j > 0 && j < ny)
    {
        if (l  == ls) A[s] = 6 * S / 6;
        else A[s] = 2 * S / 12;
    }

    if(i > 0 && i < nx && j == 0)
    {
        if (l == ls) A[s] = 3 * S / 6;
        else if (s == 0 || s == 1) A[s] = 1 * S / 12;
        else if (s == 2 || s == 3) A[s] = 2 * S / 12;
        else return -1;
    }

    if(i > 0 && i < nx && j == ny)
    {
        if (l == ls) A[s] = 3 * S / 6;
        else if (s == 0 || s == 3) A[s] = 1 * S / 12;
        else if (s == 1 || s == 2) A[s] = 2 * S / 12;
        else return -1;
    }

    if(i == 0 && j > 0 && j < ny)
    {
        if (l == ls) A[s] = 3 * S / 6;
        else if (s == 0 || s == 3) A[s] = 2 * S / 12;
        else if (s == 1 || s == 2) A[s] = 1 * S / 12;
        else return -1;
    }

    if(i == nx && j > 0 && j < ny)
    {
        if (l == ls) A[s] = 3 * S / 6;
        else if (s == 0 || s == 3) A[s] = 1 * S / 12;
        else if (s == 1 || s == 2) A[s] = 2 * S / 12;
        else return -1;
    }

    if(i == 0 && j == 0)
    {
        if (l == ls) A[s] = 2 * S / 6;
        else if (s == 0 || s == 1) A[s] = 1 * S / 12;
        else if (s == 2) A[s] = 2 * S / 12;
        else return -1;
    }

    if(i == nx && j == ny)
    {
        if (l == ls) A[s] = 2 * S / 6;
        else if (s == 0 || s == 2) A[s] = 1 * S / 12;
        else if (s == 1) A[s] = 2 * S / 12;
        else return -1;
    }

    if(i == 0 && j == ny)
    {
        if (l == ls) A[s] = 1 * S / 6;
        else if (s == 0 || s == 1) A[s] = 1 * S / 12;
        else return -1;
    }

    if(i == nx && j == 0)
    {
        if (l == ls) A[s] = 1 * S / 6;
        else if (s == 0 || s == 1) A[s] = 1 * S / 12;
        else return -1;
    }

    return 0;
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

    a = a; b = b; c = c; d = d; nx = nx; ny = ny; k = k; eps = eps; mi = mi; p = p; thr = thr; A = A; I = I;




    return nullptr;
}
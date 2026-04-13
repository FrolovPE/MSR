#ifndef MSR_H
#define MSR_H
#include <stdio.h>
#include <pthread.h>
#include "args.h"
#include "extpll.h"

void *parallelMSR(void *arg);
void get_my_rows(int n, int p, int thr, int &i1, int &i2);
void report(const char *name, int task, double r1, double r2, double r3, double r4, double t1, double t2,int it, double eps, int k, int nx, int ny, int p);
int get_len_msr(int nx, int ny);
void* msr_sovle(void* ptr);

#endif
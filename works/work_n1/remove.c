#include <stdio.h>
#include <stdlib.h>
#include "remove.h"

int func_val(int x, int b){
    float a0=186.752, a1=-148.235, a2=34.5049, a3=-3.5091, a4=0.183166, a5=-0.00513554, a6=0.0000735464, a7=-4.22038;
    for(int i=0;i<7;i++){
        a7*=(1/10);
    }
    return a0 + (a1+b)*x + a2*(x*x) + a3*(x*x*x) + a4*(x*x*x*x) + a5*(x*x*x*x*x) + a6*(x*x*x*x*x*x) + a7*(x*x*x*x*x*x*x);
}
/**
 * @file main.c
 */

#include "ulp_riscv/ulp_riscv.h"
#include "ulp_riscv/ulp_riscv_utils.h"

extern int add(int x, int y);

volatile int result_s;
volatile int result_c;

int main(void)
{
    result_s = add(1, 2);
    result_c = 1 + 2;
}

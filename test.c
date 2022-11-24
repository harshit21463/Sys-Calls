#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define SYS_kernel_2D_memcpy 451

int main() {
    float M1[3][3] = {{5.5,3.4,32.3},{2.5,4.9,21.4},{24.32,6.9,7.4}};
    float M2[3][3] = {{14.1,11.5,24.1},{14.3,15.1,14.1},{9.1,1.3,4.1}};

    printf("INITIAL MATRIX 1 : \n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", M1[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    printf("INITIAL MATRIX 2 : \n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", M2[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    int check = syscall(SYS_kernel_2D_memcpy, M2, M1);

    if(check < 0){
        printf("ERROR: SysCall Failure");
        exit(1);
    }
    printf("FINAL MATRIX 1 : \n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", M1[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    printf("FINAL MATRIX 2 : \n");

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%lf ", M2[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

extern void saxpy_asm(float A, float *X, float *Y, float *Z, int n);

void saxpy_c(float A, float *X, float *Y, float *Z, int n) {
    for (int i = 0; i < n; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}

int main() {
    int n;
    float A;
    float *X, *Y, *Z;

    printf("Enter vector size (n): ");
    scanf("%d", &n);

    X = (float *)malloc(n * sizeof(float));
    Y = (float *)malloc(n * sizeof(float));
    Z = (float *)malloc(n * sizeof(float));

    printf("Enter scalar A: ");
    scanf("%f", &A);

    printf("Enter elements of vector X:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &X[i]);
    }

    printf("Enter elements of vector Y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &Y[i]);
    }

    // SAXPY thru C
    saxpy_c(A, X, Y, Z, n);
    printf("\nSAXPY Results from C:\n");
    for (int i = 0; i < n && i < 10; i++) {
        printf("Z[%d] = %.2f\n", i, Z[i]);
    }

    // SAXPY thru Assembly
    saxpy_asm(A, X, Y, Z, n);
    printf("\nSAXPY Results from Assembly:\n");
    for (int i = 0; i < n && i < 10; i++) {
        printf("Z[%d] = %.2f\n", i, Z[i]);
    }

    free(X);
    free(Y);
    free(Z);

    return 0;
}

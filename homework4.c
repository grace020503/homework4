#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int cols);
int **allocate_matrix(int rows, int cols);
void free_matrix(int **matrix, int rows, int cols);
void addition_matrix(int **matrix_a, int **matrix_b, int rows, int cols);
void subtraction_matrix(int **matrix_a, int **matrix_b, int rows, int cols);
void transpose_matrix(int **matrix_a, int rows, int cols);
void multiply_matrix(int **matrix_a, int **matrix_b, int rows_a, int cols_a, int cols_b);

int main() {
    int rows_a, cols_a, rows_b, cols_b;

    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &rows_a);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &cols_a);

    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &rows_b);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &cols_b);

    // Check if matrix A and matrix B can be added, subtracted, or multiplied.
    if (rows_a != rows_b || cols_a != cols_b) {
        printf("Error: Matrix A and Matrix B must have the same dimensions.\n");
        exit(1);
    }
    if (cols_a != rows_b) {
        printf("Error: The number of columns of Matrix A must be equal to the number of rows of Matrix B.\n");
        exit(1);
    }

    // Allocate memory for matrix A and matrix B.
    int **matrix_a = allocate_matrix(rows_a, cols_a);
    int **matrix_b = allocate_matrix(rows_b, cols_b);

    // Fill matrix A and matrix B with user input.
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_a; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < rows_b; i++) {
        for (int j = 0; j < cols_b; j++) {
            scanf("%d", &matrix_b[i][j]);
        }
    }

    // Perform matrix operations.
    printf("Matrix A:\n");
    print_matrix(matrix_a, rows_a, cols_a);

    printf("Matrix B:\n");
    print_matrix(matrix_b, rows_b, cols_b);

    printf("Addition of matrix A and matrix B:\n");
    addition_matrix(matrix_a, matrix_b, rows_a, cols_a);
    printf("\n");

    printf("Subtraction of matrix A and matrix B:\n");
    subtraction_matrix(matrix_a, matrix_b, rows_a, cols_a);
    printf("\n");

    printf("Transpose of matrix A:\n");
    transpose_matrix(matrix_a, rows_a, cols_a);
    printf("\n");

    printf("Multiplication of matrix A and matrix B:\n");
    multiply_matrix(matrix_a, matrix_b, rows_a, cols_a, cols_b);
    printf("\n");

    // Free memory used by matrix A and matrix B.
    free_matrix(matrix_a, rows_a, cols_a);
    free_matrix(matrix_b, rows_b, cols_b);

    return 0;
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **allocate_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void free_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void addition_matrix(int **matrix_a, int **matrix_b, int rows, int cols) {
    int **matrix_c = allocate_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_c[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    print_matrix(matrix_c, rows, cols);
    free_matrix(matrix_c, rows, cols);
}

void subtraction_matrix(int **matrix_a, int **matrix_b, int rows, int cols) {
    int **matrix_c = allocate_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_c[i][j] = matrix_a[i][j] - matrix_b[i][j];
        }
    }

    print_matrix(matrix_c, rows, cols);
    free_matrix(matrix_c, rows, cols);
}

void transpose_matrix(int **matrix_a, int rows, int cols) {
    int **matrix_c = allocate_matrix(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_c[j][i] = matrix_a[i][j];
        }
    }

    print_matrix(matrix_c, cols, rows);
    free_matrix(matrix_c, cols, rows);
}

void multiply_matrix(int **matrix_a, int **matrix_b, int rows_a, int cols_a, int cols_b) {
    int **matrix_c = allocate_matrix(rows_a, cols_b);

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            matrix_c[i][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    print_matrix(matrix_c, rows_a, cols_b);
    free_matrix(matrix_c, rows_a, cols_b);
}
#include <stdio.h>
#include <stdlib.h>

void ptintid(){
    char *name = "Kim sieun";
	char *id = "2021053007";

    printf("-----[%s] [%s]-----\n\n", name, id); //name,  id 출력
}

// 행렬 출력 함수
void printMatrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n"); // 입력 받은 행의 크기 출력
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]); // 각 행렬의 크기만큼 요소 출력
        }
        printf("\n");
    }
}

// 행렬 동적 메모리 할당 함수
int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *)); //row 크기의 int 포인터를 동적할당
    for(int i=0; i<rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int)); //i번째 행에 대해, 열 크기의 int 변수를 동적할당
    }
    return matrix;
}

// 할당된 행렬 동적 메모리 해제 함수
void freeMatrix(int **matrix, int rows) {
    for(int i=0; i<rows; i++) {
        free(matrix[i]); // 동적할당 해제
    }
    free(matrix); // 포인터 동적할당 해제
}

// 행렬 입력 함수
void inputMatrix(int **matrix, int rows, int cols) {
    printf("Enter matrix elements:\n"); //행렬 요소를 입력
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// 행렬 덧셈 함수
void addMatrix(int **a, int **b, int **c, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// 행렬 뺄셈 함수
void subtractMatrix(int **a, int **b, int **c, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// 행렬 전치 함수
void transposeMatrix(int **a, int **t, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            t[j][i] = a[i][j];
        }
    }
}

// 행렬 곱셈 함수
void multiplyMatrix(int **a, int **b, int **c, int rows1, int cols1, int cols2) {
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols2; j++) {
            c[i][j] = 0;
            for(int k=0; k<cols1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows of matrix A: "); //행렬 A의 행 개수를 입력
    scanf("%d", &rows1);
    printf("Enter the number of columns of matrix A: "); // 행렬 A의 열 개수 입력
    scanf("%d", &cols1);

    // 행렬 A 할당
        int **a = allocateMatrix(rows1, cols1);

    inputMatrix(a, rows1, cols1);
    printMatrix(a, rows1, cols1);

    printf("\nEnter the number of rows of matrix B: "); //행렬 B의 행 개수를 입력
    scanf("%d", &rows2);
    printf("Enter the number of columns of matrix B: "); // 행렬 B의 열 개수 입력
    scanf("%d", &cols2);

    // 행렬 B 할당
    int **b = allocateMatrix(rows2, cols2);

    inputMatrix(b, rows2, cols2);
    printMatrix(b, rows2, cols2);

    // A와 B의 크기가 다른 경우 프로그램 종료
    if(rows1 != rows2 || cols1 != cols2) {
        printf("Error: Matrix sizes do not match\n");
        freeMatrix(a, rows1);
        freeMatrix(b, rows2);
        return 0;
    }

    // 덧셈 행렬 C 할당
    int **c = allocateMatrix(rows1, cols1);

    // 덧셈 행렬 계산
    addMatrix(a, b, c, rows1, cols1);
    printMatrix(c, rows1, cols1);

    // 뺄셈 행렬 C 할당
    int **d = allocateMatrix(rows1, cols1);

    // 뺄셈 행렬 계산
    subtractMatrix(a, b, d, rows1, cols1);
    printMatrix(d, rows1, cols1);

    // 전치 행렬 T 할당
    int **t = allocateMatrix(cols1, rows1);

    // 전치 행렬 계산
    transposeMatrix(a, t, rows1, cols1);
    printMatrix(t, cols1, rows1);

    // 곱셈 행렬 E 할당
    int **e = allocateMatrix(rows1, cols2);

    // 곱셈 행렬 계산
    multiplyMatrix(a, b, e, rows1, cols1, cols2);
    printMatrix(e, rows1, cols2);

    // 메모리 해제
    freeMatrix(a, rows1);
    freeMatrix(b, rows2);
    freeMatrix(c, rows1);
    freeMatrix(d, rows1);
    freeMatrix(t, cols1);
    freeMatrix(e, rows1);

    return 0;
}
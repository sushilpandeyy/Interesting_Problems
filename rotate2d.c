#include <stdio.h>

void rotateMatrixClockwise(int mat[][100], int rows, int cols, int steps) {
    steps = steps % 4; // To handle multiples of 4 rotations

    for (int s = 0; s < steps; s++) {
        int rotated[100][100];

        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                rotated[i][j] = mat[rows - j - 1][i];
            }
        }

        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                mat[i][j] = rotated[i][j];
            }
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);

    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    int matrix[100][100];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int steps;
    printf("Enter the number of clockwise rotations: ");
    scanf("%d", &steps);

    rotateMatrixClockwise(matrix, rows, cols, steps);

    printf("Rotated matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

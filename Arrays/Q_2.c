#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int row;
    int col;
    int value;
};

struct SparseMatrix
{
    int rows;
    int cols;
    int num_elements;
    struct Element *elements;
};

struct SparseMatrix *createSparseMatrix(int rows, int cols, int num_elements)
{
    struct SparseMatrix *matrix = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->num_elements = num_elements;
    matrix->elements = (struct Element *)malloc(num_elements * sizeof(struct Element));
    return matrix;
}

void displaySparseMatrix(struct SparseMatrix *matrix)
{
    int i, j, k = 0;
    for (i = 1; i <= matrix->rows; i++)
    {
        for (j = 1; j <= matrix->cols; j++)
        {
            if (k < matrix->num_elements && matrix->elements[k].row == i && matrix->elements[k].col == j)
            {
                printf("%d ", matrix->elements[k].value);
                k++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct SparseMatrix *transpose(struct SparseMatrix *matrix)
{
    struct SparseMatrix *transposed_matrix = createSparseMatrix(matrix->cols, matrix->rows, matrix->num_elements);
    int i;
    for (i = 0; i < matrix->num_elements; i++)
    {
        transposed_matrix->elements[i].row = matrix->elements[i].col;
        transposed_matrix->elements[i].col = matrix->elements[i].row;
        transposed_matrix->elements[i].value = matrix->elements[i].value;
    }
    return transposed_matrix;
}

void add(struct SparseMatrix *matrix1, struct SparseMatrix *matrix2)
{
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols)
    {
        printf("Matrices must have the same dimensions for addition.\n");
        return;
    }

    int i, j, k1 = 0, k2 = 0;
    for (i = 1; i <= matrix1->rows; i++)
    {
        for (j = 1; j <= matrix1->cols; j++)
        {
            int value1 = 0, value2 = 0;
            if (k1 < matrix1->num_elements && matrix1->elements[k1].row == i && matrix1->elements[k1].col == j)
            {
                value1 = matrix1->elements[k1].value;
                k1++;
            }
            if (k2 < matrix2->num_elements && matrix2->elements[k2].row == i && matrix2->elements[k2].col == j)
            {
                value2 = matrix2->elements[k2].value;
                k2++;
            }
            if (value1 + value2 != 0)
            {
                printf("%d ", value1 + value2);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct SparseMatrix *multiply(struct SparseMatrix *matrix1, struct SparseMatrix *matrix2)
{
    if (matrix1->cols != matrix2->rows)
    {
        printf("Number of columns in first matrix must be equal to number of rows in second matrix for multiplication.\n");
        return NULL;
    }

    int i, j, k;
    for (i = 1; i <= matrix1->rows; i++)
    {
        for (j = 1; j <= matrix2->cols; j++)
        {
            int sum = 0;
            for (k = 1; k <= matrix1->cols; k++)
            {
                int value1 = 0, value2 = 0;
                for (int l = 0; l < matrix1->num_elements; l++)
                {
                    if (matrix1->elements[l].row == i && matrix1->elements[l].col == k)
                    {
                        value1 = matrix1->elements[l].value;
                        break;
                    }
                }
                for (int l = 0; l < matrix2->num_elements; l++)
                {
                    if (matrix2->elements[l].row == k && matrix2->elements[l].col == j)
                    {
                        value2 = matrix2->elements[l].value;
                        break;
                    }
                }
                sum += value1 * value2;
            }
            if (sum != 0)
            {
                printf("%d ", sum);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    struct SparseMatrix *matrix1, *matrix2, *result_matrix;

    printf("Enter the dimensions of the first matrix (rows columns): ");
    int rows1, cols1;
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of non-zero elements in the first matrix: ");
    int num_elements1;
    scanf("%d", &num_elements1);
    matrix1 = createSparseMatrix(rows1, cols1, num_elements1);

    printf("Enter the non-zero elements of the first matrix (row column value):\n");
    for (int i = 0; i < num_elements1; i++)
    {
        scanf("%d %d %d", &matrix1->elements[i].row, &matrix1->elements[i].col, &matrix1->elements[i].value);
    }

    printf("Enter the dimensions of the second matrix (rows columns): ");
    int rows2, cols2;
    scanf("%d %d", &rows2, &cols2);
    printf("Enter the number of non-zero elements in the second matrix: ");
    int num_elements2;
    scanf("%d", &num_elements2);
    matrix2 = createSparseMatrix(rows2, cols2, num_elements2);

    printf("Enter the non-zero elements of the second matrix (row column value):\n");
    for (int i = 0; i < num_elements2; i++)
    {
        scanf("%d %d %d", &matrix2->elements[i].row, &matrix2->elements[i].col, &matrix2->elements[i].value);
    }
    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Transpose\n");
        printf("2. Addition\n");
        printf("3. Multiplication\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            result_matrix = transpose(matrix1);
            printf("\nTranspose of the first matrix:\n");
            displaySparseMatrix(result_matrix);
            break;
        case 2:
            printf("\nAddition of the two matrices:\n");
            add(matrix1, matrix2);
            break;
        case 3:
            printf("\nMultiplication of the two matrices:\n");
            multiply(matrix1, matrix2);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}
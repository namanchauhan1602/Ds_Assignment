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

struct SparseMatrix *add(struct SparseMatrix *matrix1, struct SparseMatrix *matrix2)
{
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols)
    {
        printf("Matrices must have the same dimensions for addition.\n");
        return NULL;
    }

    struct SparseMatrix *result_matrix = createSparseMatrix(matrix1->rows, matrix1->cols, matrix1->num_elements + matrix2->num_elements);
    int i, j, k = 0;
    for (i = 0; i < matrix1->rows; i++)
    {
        for (j = 0; j < matrix1->cols; j++)
        {
            int value1 = 0, value2 = 0;
            if (k < matrix1->num_elements && matrix1->elements[k].row == i && matrix1->elements[k].col == j)
            {
                value1 = matrix1->elements[k].value;
                k++;
            }
            if (k < matrix2->num_elements && matrix2->elements[k].row == i && matrix2->elements[k].col == j)
            {
                value2 = matrix2->elements[k].value;
                k++;
            }
            if (value1 + value2 != 0)
            {
                result_matrix->elements[result_matrix->num_elements].row = i;
                result_matrix->elements[result_matrix->num_elements].col = j;
                result_matrix->elements[result_matrix->num_elements].value = value1 + value2;
                result_matrix->num_elements++;
            }
        }
    }
    return result_matrix;
}

struct SparseMatrix *multiply(struct SparseMatrix *matrix1, struct SparseMatrix *matrix2)
{
    if (matrix1->cols != matrix2->rows)
    {
        printf("Number of columns in first matrix must be equal to number of rows in second matrix for multiplication.\n");
        return NULL;
    }

    struct SparseMatrix *result_matrix = createSparseMatrix(matrix1->rows, matrix2->cols, 0);
    int i, j, k;
    for (i = 0; i < matrix1->rows; i++)
    {
        for (j = 0; j < matrix2->cols; j++)
        {
            int sum = 0;
            for (k = 0; k < matrix1->cols; k++)
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
                result_matrix->elements[result_matrix->num_elements].row = i;
                result_matrix->elements[result_matrix->num_elements].col = j;
                result_matrix->elements[result_matrix->num_elements].value = sum;
                result_matrix->num_elements++;
            }
        }
    }
    return result_matrix;
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
            result_matrix = add(matrix1, matrix2);
            if (result_matrix != NULL)
            {
                printf("\nAddition of the two matrices:\n");
                displaySparseMatrix(result_matrix);
            }
            break;
        case 3:
            result_matrix = multiply(matrix1, matrix2);
            if (result_matrix != NULL)
            {
                printf("\nMultiplication of the two matrices:\n");
                displaySparseMatrix(result_matrix);
            }
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
            ;
            break;
        }
    }
}
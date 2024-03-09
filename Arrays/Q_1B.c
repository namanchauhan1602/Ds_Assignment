#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findDuplicate(int arr1[], int arr1_len, int arr2[], int arr2_len)
{
    sortArray(arr1, arr1_len);
    sortArray(arr2, arr2_len);
    int Element = 0;
    for (int i = 0; i < arr1_len; i++)
    {
        if (arr1[i] != Element)
        {
            Element = arr1[i];
            for (int j = 0; j < arr2_len; j++)
            {
                if (arr2[j] == arr1[i])
                {
                    printf("%d ", arr2[j]);
                    break;
                }
            }
        }
    }
}

void mergeArrays(int arr1[], int arr1_len, int arr2[], int arr2_len)
{
    int mergedSize = arr1_len + arr2_len;
    int mergedArray[mergedSize];
    int i = 0, j = 0, k = 0;

    while (i < arr1_len && j < arr2_len)
    {
        if (arr1[i] <= arr2[j])
            mergedArray[k++] = arr1[i++];
        else
            mergedArray[k++] = arr2[j++];
    }

    while (i < arr1_len)
    {
        mergedArray[k++] = arr1[i++];
    }

    while (j < arr2_len)
    {
        mergedArray[k++] = arr2[j++];
    }

    sortArray(mergedArray, mergedSize);

    for (int i = 0; i < mergedSize; i++)
    {
        printf("%d ", mergedArray[i]);
    }
}

int main()
{
    int arr1[] = {1, 3, 2, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};

    int arr1_len = sizeof(arr1) / sizeof(arr1[0]);
    int arr2_len = sizeof(arr2) / sizeof(arr2[0]);

    printf("Common elements in both the arrays are: -\n");
    findDuplicate(arr1, arr1_len, arr2, arr2_len);
    printf("\n");
    printf("Merged array: \n");
    mergeArrays(arr1, arr1_len, arr2, arr2_len);
    return 0;
}
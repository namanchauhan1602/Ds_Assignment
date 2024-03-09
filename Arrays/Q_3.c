#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1])
        {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int n;
    printf("\nEnter the size of array:- \n");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements in array:- \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nSorted array is: -\n");
    sortArray(arr, n);
}
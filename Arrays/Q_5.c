#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            
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
    printf("\nEnter thhe size of array:- \n");
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
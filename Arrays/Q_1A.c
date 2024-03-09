#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

void countFrequency(int arr[], int n)
{
    printf("Element Frequency\n");
    printf("--------------------\n");
    int count = 1;
    int Element = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != Element)
        {
            Element = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                if (Element == arr[j])
                {
                    count++;
                }
            }
            printf("%d %d \n", Element, count);
            count = 1;
        }
    }
}

int main()
{
    int arr[] = {2, 4, 5, 5, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    printf("Enter the element you want to find in the array:- \n");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element not present in array\n");
    else
        printf("Element %d found at index: %d\n", x, result);

    countFrequency(arr, n);

    return 0;
}

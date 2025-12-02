#include<stdio.h>

void main()
{
    int array[20], n, i, j, temp;

    printf("Enter the limit of array:");
    scanf("%d", &n);

    printf("Enter the array elements:");
    for(i = 0; i < n; i++)
        scanf("%d", &array[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("Sorted Array = ");
    for(i = 0; i < n; i++)
        printf("%d ", array[i]);
}

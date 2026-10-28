
#include <stdio.h>

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int linearSearch(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int marks[100], n, i, choice, key, result;

    printf("DSA ALGORITHM SIMULATOR\n");
    printf("Enter number of students (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of students!\n");
        return 0;
    }

    printf("Enter student marks (0-100):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &marks[i]);

        if (marks[i] < 0 || marks[i] > 100)
        {
            printf("Invalid marks!\n");
            return 0;
        }
    }

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("6. Display Marks\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                bubbleSort(marks, n);
                printf("Marks sorted using Bubble Sort:\n");
                display(marks, n);
                break;

            case 2:
                selectionSort(marks, n);
                printf("Marks sorted using Selection Sort:\n");
                display(marks, n);
                break;

            case 3:
                insertionSort(marks, n);
                printf("Marks sorted using Insertion Sort:\n");
                display(marks, n);
                break;

            case 4:
                printf("Enter mark to search: ");
                scanf("%d", &key);
                result = linearSearch(marks, n, key);

                if (result != -1)
                    printf("Mark found at position %d\n", result + 1);
                else
                    printf("Mark not found\n");
                break;

            case 5:
                bubbleSort(marks, n);
                printf("Marks sorted for Binary Search:\n");
                display(marks, n);

                printf("Enter mark to search: ");
                scanf("%d", &key);
                result = binarySearch(marks, n, key);

                if (result != -1)
                    printf("Mark found at position %d in sorted list\n",result + 1);
                else
                    printf("Mark not found\n");
                break;

            case 6:
                printf("Student marks:\n");
                display(marks, n);
                break;

            case 0:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
*/

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int t = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = t;

    return (i + 1);
}

void quicksort(int arr[], int s, int e)
{

    if (s >= e)
        return;
    int c = partition(arr, s, e);
    quicksort(arr, s, c - 1);
    quicksort(arr, c + 1, e);
}

void quickSort(int input[], int size)
{

    int s = 0, e = size - 1;
    quicksort(input, s, e);
}

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void maxHeapfy(vector<int> &arr, int n, int i)
{

    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr, i, largest);

        maxHeapfy(arr, n, largest);
    }
}

void buildMaxHeap(vector<int> &arr)
{
    int n = arr.size();
    // int i = (n / 2) - 1 will be the heigth
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeapfy(arr, n, i);
    }
}

void printArray(const vector<int> array)
{
    for (int num : array)
    {
        cout << num << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> heap_arr = {23, 17, 14, 6, 13, 10, 1, 5, 7, 12};

    cout << "Original array: ";
    printArray(heap_arr);

    // Constrói um heap máximo a partir do vetor
    buildMaxHeap(heap_arr);

    cout << "Next array: ";
    printArray(heap_arr);

    return 0;
}
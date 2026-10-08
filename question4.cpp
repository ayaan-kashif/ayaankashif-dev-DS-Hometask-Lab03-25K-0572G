#include <iostream>
#include <string>
using namespace std;

void swapItems(int &left, int &right)
{
    int temporary = left;
    left = right;
    right = temporary;
}

void copyArray(const int source[], int destination[], int size)
{
    for (int i = 0; i < size; ++i)
        destination[i] = source[i];
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i];
        if (i < size - 1)
            cout << " ";
    }
    cout << '\n';
}

void diminishingDistanceScanner(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        long long comparisons = 0, swaps = 0;
        for (int i = gap; i < size; ++i)
        {
            int j = i;
            while (j >= gap)
            {
                ++comparisons;
                if (arr[j - gap] <= arr[j])
                    break;
                swapItems(arr[j - gap], arr[j]);
                ++swaps;
                j -= gap;
            }
        }
        cout << "Gap: " << gap << '\n';
        cout << "Gap percentage: " << 100.0 * gap / size << "%\n";
        cout << "Phase comparisons: " << comparisons << '\n';
        cout << "Phase swaps: " << swaps << '\n';
        cout << "Current array: ";
        printArray(arr, size);
    }
    cout << "Sorted array: ";
    printArray(arr, size);
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    int size;
    cout << "Enter number of items: ";
    if (!(cin >> size) || size <= 0)
    {
        cout << "Invalid number of items.\n";
        return 1;
    }

    int *arr = new int[size];
    cout << "Enter tracking IDs: ";
    for (int i = 0; i < size; ++i)
    {
        if (!(cin >> arr[i]))
        {
            cout << "Invalid tracking ID.\n";
            delete[] arr;
            return 1;
        }
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] == arr[i])
            {
                cout << "Tracking IDs must be unique.\n";
                delete[] arr;
                return 1;
            }
        }
    }

    diminishingDistanceScanner(arr, size);
    delete[] arr;
    return 0;
}

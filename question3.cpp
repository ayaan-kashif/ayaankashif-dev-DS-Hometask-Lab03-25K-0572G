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

void minimalSwapCrane(int arr[], int size)
{
    long long swaps = 0, skipped = 0, comparisons = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        int minimum = i;
        for (int j = i + 1; j < size; ++j)
        {
            ++comparisons;
            if (arr[j] < arr[minimum])
                minimum = j;
        }
        if (minimum == i)
            ++skipped;
        else
        {
            swapItems(arr[i], arr[minimum]);
            ++swaps;
        }
    }
    cout << "Sorted array: ";
    printArray(arr, size);
    cout << "Total actual swaps: " << swaps << '\n';
    cout << "Skipped swaps: " << skipped << '\n';
    cout << "Total comparisons (N(N-1)/2): " << comparisons << '\n';
    cout << "Swap-to-Comparison Ratio: "
         << (comparisons == 0 ? 0.0 : 100.0 * swaps / comparisons) << "%\n";
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

    minimalSwapCrane(arr, size);
    delete[] arr;
    return 0;
}

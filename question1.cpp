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

void adjacentSwapper(int arr[], int size)
{
    long long swaps = 0, comparisons = 0;
    int passes = 0;
    for (int pass = 0; pass < size - 1; ++pass)
    {
        bool swapped = false;
        ++passes;
        for (int j = 0; j < size - 1 - pass; ++j)
        {
            ++comparisons;
            if (arr[j] > arr[j + 1])
            {
                swapItems(arr[j], arr[j + 1]);
                ++swaps;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    cout << "Sorted array: ";
    printArray(arr, size);
    cout << "Total swaps: " << swaps << '\n';
    cout << "Actual comparisons: " << comparisons
         << " | Theoretical worst-case comparisons N(N-1)/2: "
         << 1LL * size * (size - 1) / 2 << '\n';
    cout << "Passes saved: " << (size > 0 ? size - 1 : 0) - passes << '\n';
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

    adjacentSwapper(arr, size);
    delete[] arr;
    return 0;
}

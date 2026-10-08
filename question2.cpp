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

void insertionArmSorter(int arr[], int size)
{
    long long totalShiftDistance = 0;
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i], j = i - 1, shifts = 0;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
            ++shifts;
        }
        arr[j + 1] = key;
        totalShiftDistance += shifts;
        cout << "Key " << key << ": ";
        if (shifts == 0)
            cout << "No shift required\n";
        else
            cout << "Inserted into its correct position\n";
        cout << "Positions shifted: " << shifts << '\n';
        cout << "Current array: ";
        printArray(arr, size);
    }
    cout << "Sorted array: ";
    printArray(arr, size);
    cout << "Total shift distance: " << totalShiftDistance << '\n';
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

    insertionArmSorter(arr, size);
    delete[] arr;
    return 0;
}

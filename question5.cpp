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

int midpointSplitSearch(int arr[], int size, int targetID)
{
    for (int i = 1; i < size; ++i)
    {
        if (arr[i - 1] > arr[i])
        {
            cout << "Error: Conveyor is unsorted. Search aborted.\n";
            return -1;
        }
    }
    int maxSteps = 0;
    for (int n = size; n > 0; n /= 2)
        ++maxSteps;
    int low = 0, high = size - 1, steps = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        ++steps;
        cout << "Low: " << low << ", Mid: " << mid << ", High: " << high << '\n';
        cout << "Remaining search space: " << 100.0 * (high - low + 1) / size << "%\n";
        cout << "Steps taken: " << steps << " / Theoretical max steps: " << maxSteps << '\n';
        if (arr[mid] == targetID)
            return mid;
        if (targetID < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
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

    int targetID;
    cout << "Enter tracking ID to search: ";
    if (!(cin >> targetID))
    {
        cout << "Invalid tracking ID.\n";
        delete[] arr;
        return 1;
    }
    int index = midpointSplitSearch(arr, size, targetID);
    cout << "Returned index: " << index << '\n';
    delete[] arr;
    return 0;
}

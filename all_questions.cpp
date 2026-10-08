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
        cout << "Invalid number of items. Enter a positive integer.\n";
        return 1;
    }
    int *original = new int[size];
    cout << "Enter tracking IDs: ";
    for (int i = 0; i < size; ++i)
    {
        if (!(cin >> original[i]))
        {
            cout << "Invalid tracking ID.\n";
            delete[] original;
            return 1;
        }
        for (int j = 0; j < i; ++j)
        {
            if (original[j] == original[i])
            {
                cout << "Tracking IDs must be unique.\n";
                delete[] original;
                return 1;
            }
        }
    }
    int *items = new int[size];
    copyArray(original, items, size);
    cout << "\nTask 1:\n";
    adjacentSwapper(items, size);
    copyArray(original, items, size);
    cout << "\nTask 2:\n";
    insertionArmSorter(items, size);
    copyArray(original, items, size);
    cout << "\nTask 3:\n";
    minimalSwapCrane(items, size);
    copyArray(original, items, size);
    cout << "\nTask 4:\n";
    diminishingDistanceScanner(items, size);
    cout << "\nTask 5:\nEnter tracking ID to search: ";
    int targetID;
    if (!(cin >> targetID))
    {
        cout << "Invalid tracking ID.\n";
        delete[] items;
        delete[] original;
        return 1;
    }
    int index = midpointSplitSearch(items, size, targetID);
    if (index == -1)
        cout << "Tracking ID not found.\n";
    else
        cout << "Tracking ID found at index " << index << " (zero-based).\n";
    delete[] items;
    delete[] original;
    return 0;
}

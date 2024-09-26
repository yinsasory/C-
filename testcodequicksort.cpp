#include <iostream>

using namespace std;

class QuickSort {
public:
    void sort(int* arr, int size) {
        quickSort(arr, 0, size - 1);
    }

private:
    void quickSort(int* arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    int partition(int* arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};
int main() {
    int arr[] = {12, 34, 11, 9, 3, 2, 56, 67, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    QuickSort qs;
    qs.sort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
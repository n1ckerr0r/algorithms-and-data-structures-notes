#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void insertSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * largest + 1;
    int right = 2 * largest + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] < arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int left, int right) {
    int n = right - left + 1;

    for (int i = left + n/2 - 1; i >= left; i--)
        heapify(arr + left, n, i - left);

    for (int i = right; i > left; i--) {
        swap(arr[left], arr[i]);
        heapify(arr + left, n, i);
    }

    for (int i = right; i > left; i--) {
        swap(arr[i], arr[left]);
        heapify(arr + left, i - left, 0);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left + (right - left) / 2];
    int i = left - 1, j = right + 1;

    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);

        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

void introSortUtil(int arr[], int left, int right, int depthLimit) {
    int size = right - left + 1;

    if (size < 16) {
        insertSort(arr, left, right);
        return;
    }

    if (depthLimit == 0) {
        heapSort(arr, left, right);
        return;
    }

    int part = partition(arr, left, right);
    introSortUtil(arr, left, part, depthLimit);
    introSortUtil(arr, part, right, depthLimit);
}

void introSort(int arr[], int n) {
    if (n <= 1) return;

    int depthLimit = 2 * log2(n);

    introSortUtil(arr, 0, n-1, depthLimit);
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));

    int n = 10;
    int* array = new int[n];
    for (int i = 0; i < n; i++) array[i] = rand() % 100;

    introSort(array, n);

    for (int i = 0; i < n; i++)
        cout << array[i] << ' ';
}
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(vector<int>& array, int left, int mid, int right){
    vector<int> temp(right - left + 1);

    int i = left, j = mid + 1, t = 0;

    while (i <= mid && j <= right){
        if (array[i] <= array[j]) temp[t++] = array[i++];
        else temp[t++] = array[j++];
    }

    while (i <= mid){
        temp[t++] = array[i++];
    }

    while (j <= right){
        temp[t++] = array[j++];
    }

    for (int index = 0; index < temp.size(); index++) {
        array[index + left] = temp[index];
    }
}

void mergeSort(vector<int>& array, int left, int right){
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;

    mergeSort(array, left, mid);
    mergeSort(array, mid+1, right);
    merge(array, left, mid, right);
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    
    vector<int> array(10, 0);
    
    for (int i = 0; i < array.size(); i++) array[i] = rand() % 100;

    mergeSort(array, 0, array.size()-1);

    for (int i = 0; i < array.size(); i++) cout << array[i] << ' ';
}
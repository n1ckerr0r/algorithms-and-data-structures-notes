#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& array, int left, int right){
    int pivot_index = left + rand() % (right - left);
    int pivot = array[pivot_index];
    swap(array[pivot_index], array[left + (right - left)/2]);

    int i = left, j = right;

    while (true){
        while (array[i] < pivot){
            i++;
        }
        while (array[j] > pivot){
            j--;
        }

        if (i >= j) return j;

        swap(array[i], array[j]);
    };
}

void quickSortHoare(vector<int>& array, int left, int right){
    if (left >= right) return;
    int part_index = partition(array, left, right);

    quickSortHoare(array, left, part_index);
    quickSortHoare(array, part_index+1, right);
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    
    vector<int> array(10, 0);
    
    for (int i = 0; i < array.size(); i++) array[i] = rand() % 100;

    quickSortHoare(array, 0, array.size()-1);

    for (int i = 0; i < array.size(); i++) cout << array[i] << ' ';
}
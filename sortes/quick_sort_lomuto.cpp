#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& array, int left, int right){
    int pivot_index = left + rand() % (right - left);
    int pivot = array[pivot_index];
    swap(array[pivot_index], array[right]);

    int i = left;

    for (int j = left; j < right; j++){
        if (array[j] <= pivot){
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[i], array[right]);

    return i;
}

void quickSortLomuto(vector<int>& array, int left, int right){
    if (left >= right) return;
    int part_index = partition(array, left, right);

    quickSortLomuto(array, left, part_index - 1);
    quickSortLomuto(array, part_index + 1, right);
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    
    vector<int> array(10, 0);
    
    for (int i = 0; i < array.size(); i++) array[i] = rand() % 100;

    quickSortLomuto(array, 0, array.size()-1);

    for (int i = 0; i < array.size(); i++) cout << array[i] << ' ';
}
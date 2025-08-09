#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& array){
    int min = *min_element(array.begin(), array.end());
    int max = *max_element(array.begin(), array.end());

    vector<int> count(max - min + 1, 0);
    vector<int> output(array.size());

    for (int i = 0; i < array.size(); i++){
        count[array[i] - min]++;
    }

    for (int i = 0; i < count.size() - 1; i++){
        count[i + 1] += count[i];
    }

    for (int i = array.size() - 1; i >= 0; i--){
        int arr_i = array[i];
        output[count[arr_i - min] - 1] = arr_i;
        count[arr_i - min]--;
    }

    array = output;
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    
    vector<int> array(10, 0);
    
    for (int i = 0; i < array.size(); i++) array[i] = rand() % 100;

    countingSort(array);

    for (int i = 0; i < array.size(); i++) cout << array[i] << ' ';
}
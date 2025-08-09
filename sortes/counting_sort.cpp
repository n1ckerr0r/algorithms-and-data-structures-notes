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

    for (int i = 0; i < array.size(); i++){
        count[array[i] - min]++;
    }

    int k = 0;

    for (int i = 0; i < max - min + 1; i++){
        for (int j = 0; j < count[i]; j++){
            array[k++] = i + min;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    
    vector<int> array(10, 0);
    
    for (int i = 0; i < array.size(); i++) array[i] = rand() % 100;

    countingSort(array);

    for (int i = 0; i < array.size(); i++) cout << array[i] << ' ';
}
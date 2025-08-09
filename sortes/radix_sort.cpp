#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int getDigit(int num, int exp){
    return (num / exp) % 10;
}

void countingSort(vector<int>& array, int exp){
    vector<int> output(array.size());
    vector<int> count(10, 0);

    for (int i : array){
        count[getDigit(i, exp)]++;
    }

    for (int i = 0; i < 9; i++){
        count[i + 1] += count[i];
    }

    for (int i = array.size() - 1; i >= 0; i--){
        output[count[getDigit(array[i], exp)] - 1] = array[i];
        count[getDigit(array[i], exp)]--;
    }

    for(int i = 0; i < array.size(); i++){
        array[i] = output[i];
    }
}

void radixSort(vector<int>& array){
    int max_element = *std::max_element(array.begin(), array.end());

    for (int exp = 1; max_element / exp > 0; exp *= 10){
        countingSort(array, exp);
    }
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    
    vector<int> array(10, 0);
    
    for (int i = 0; i < array.size(); i++) array[i] = rand() % 10000;

    radixSort(array);

    for (int i = 0; i < array.size(); i++) cout << array[i] << ' ';
}
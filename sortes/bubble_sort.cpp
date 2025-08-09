#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(vector<int>& array){
    bool flag = 1;

    while (flag){
        flag = 0;

        for (int i = 0; i < array.size(); i++){
            if (array[i] > array[i+1]){
                swap(array[i], array[i+1]);
                flag = 1;
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    
    vector<int> array(10, 0);
    
    for (int i = 0; i < array.size(); i++) array[i] = rand() % 100;

    bubbleSort(array);

    for (int i = 0; i < array.size(); i++) cout << array[i] << ' ';
}
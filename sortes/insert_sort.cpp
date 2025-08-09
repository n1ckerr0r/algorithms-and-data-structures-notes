#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertSort(vector<int>& array){
    for (int i = 1; i < array.size(); i++){
        int temp = array[i];
        
        int j = i-1;        

        while (j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = temp;
    }
}

int main() {
    srand(static_cast<unsigned int>(std::time(0)));
    
    vector<int> array(10, 0);
    
    for (int i = 0; i < array.size(); i++) array[i] = rand() % 100;

    insertSort(array);

    for (int i = 0; i < array.size(); i++) cout << array[i] << ' ';
}
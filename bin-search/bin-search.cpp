#include <iostream>
#include <vector>

using namespace std;

int binSearch(int n, vector<int>& array){
    int left = 0;
    int right = array.size() - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (array[mid] == n){
            return mid;
        }
        else if (array[mid] < n){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return -1;
}

int main(){
    std::vector<int> nums{1, 3, 5, 7, 9, 10, 13, 25};

    std::cout << binSearch(3, nums) << '\n';
    std::cout << binSearch(10, nums) << '\n';
    std::cout << binSearch(4, nums) << '\n';
}
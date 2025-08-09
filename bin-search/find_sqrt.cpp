#include <iostream>
#include <math.h>
#include <stdexcept>
#include <format>

double sqrtNumber(double n, unsigned int accuracy){
    if (n < 0){
        throw std::runtime_error("Error, sqrt from negative number");
    }
    else if (n == 0){
        return 0;
    }

    double diff = pow(0.1, accuracy);

    double left = 0;
    double right = n;

    while (abs(right - left) > diff){
        double mid = left + (right - left) / 2;

        if (mid * mid < n){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return left;
}

int main(){
    std::cout << std::format("number: {}, sqrt: {}", 3, sqrtNumber(static_cast<double>(3), 3));
}
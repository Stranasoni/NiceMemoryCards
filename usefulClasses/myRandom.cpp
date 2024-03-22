#include "myRandom.h"



MyRandom::MyRandom(int m, int count_output) {
	random_numbers.resize(count_output);

    int c = m - 1;//зависит от m
    int x = time(NULL) % m; //зависит от времени
    int a = ((time(NULL) % m) * primeFactors(m)) + 1; //зависит от m

    while (primeFactors(c) != c) --c;
    random_numbers[0] = x;
    for (int i = 1;
        i < count_output; 
        ++i) {
        random_numbers[i] = (a * (random_numbers[i - 1]) + c) % m;
    }
}

int MyRandom::primeFactors(int m) {
    int composition = 1;

    for (int i = 2; i < (int)(std::sqrt(m) + 1); ++i) {
        while (m % i == 0) {
            composition *= i;
            m = m / i;
        }
    }
    if (m != 1) composition *= m;
    return composition;
}

std::vector<int> MyRandom::GetRNums() {
    return random_numbers;
}

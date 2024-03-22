#ifndef RANDOM_H
#define RANDOM_H

#include <cmath>
#include <ctime>
#include <vector>
class MyRandom 
{
    std::vector<int> random_numbers; 
    int primeFactors(int m); //возвращает произведение простых множителей числа m
    
public:
    MyRandom(int m, int count_output);//linear congruential method
        //если будешь дорабатывать, нужно сделать лучше:
        //либо добавить конструкторов на разные рандомы,
        //либо больше классов 
        //либо дефольный + методы
    std::vector<int> GetRNums();
    

   
};
#endif
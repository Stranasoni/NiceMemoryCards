#ifndef RANDOM_H
#define RANDOM_H

#include <cmath>
#include <ctime>
#include <vector>
class MyRandom 
{
    int x0;
    int primeFactors(int m); //���������� ������������ ������� ���������� ����� m
    int random(int m, int x = time(NULL));
public:
    MyRandom() = default;
   
    std::vector<int> GetRNums(int m);
    //��������� ����� ��������� ������������������ �������������� m
    //���������� �������� ��������������� ����� ����� m
    

   
};
#endif
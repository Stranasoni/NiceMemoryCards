#ifndef RANDOM_H
#define RANDOM_H

#include <cmath>
#include <ctime>
#include <vector>
class MyRandom 
{
    std::vector<int> random_numbers; 
    int primeFactors(int m); //���������� ������������ ������� ���������� ����� m
    
public:
    MyRandom(int m, int count_output);//linear congruential method
        //���� ������ ������������, ����� ������� �����:
        //���� �������� ������������� �� ������ �������,
        //���� ������ ������� 
        //���� ��������� + ������
    std::vector<int> GetRNums();
    

   
};
#endif
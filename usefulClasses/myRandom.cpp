#include "myRandom.h"



int MyRandom::random(int m, int x) {
    //���������� ��������� ����� � ��������� �� 0 �� m
    //������� �� �������� ����������� ������
    //(�� ������ ��������� ��������������� ������������������ ����� �� 0 �� m 
    //��� ������������������ ��� ����� ��� m ��������� �������� �����������)
    //�������:
    //(1)� � m ������� �������(��� ����� ���������)
    //(2)�-1 ������ ������� �������� �������� m � 4,���� m ������ 4
    int c = m;//���������� 0<=c<m
    
    //x %= m //��������� �������� 0<=x<=m
    std::vector<int> prime_factors_m = primeFactors(m);//����� �������? ����������!)
   

    //������: ���������� ����� ����� ����� c � ���������� �� 0 �� m-1,
    //����� � �� �������� �� �� ���� ������� ��������� m
    //�������: ������� ������� ��� ���������� ���������, 
    //�������� ����������� �� ��� ������ � ���������� ������ ��������� 
    //�������� m � n ����� ����������(��� �����) ���������� 
    //����� ��� ����������� ����� ����� �����������,�� ������� � �������� 
    //������������� � ��������������� � �������,
    //���� ������ ��� ������
    int composition_for_a = 1;
    int current_simple_factor = 1;
    bool c_found = false;
    std::vector<int> prime_factors_c;
    for (int i = 0; i < prime_factors_m.size(); ++i) {
        composition_for_a *= prime_factors_m[i];
        if (!c_found)
        {
            int inner_i = i;
            prime_factors_c = primeFactors(--c);
            for (int j = 0; ; ++j, ++inner_i) {
                if (current_simple_factor != prime_factors_c[j] && current_simple_factor != prime_factors_m[j])
                {
                    if (prime_factors_c[j] == prime_factors_m[inner_i]) { current_simple_factor = 1; break; }
                    else {
                        if ((++j < prime_factors_c.size() | ++inner_i < prime_factors_m.size())) { c_found = true; break; }
                        --j; --inner_i;
                        current_simple_factor = prime_factors_m[inner_i];
                        continue;
                    }
                }

            }

        }
    }
    int a = (x % m) * composition_for_a + 1; //��������� 0<=a<m,//!!!!��� �� �� ��� � a!!!!
    //^ ����������� ��������� ���������� ��� ������� �������� m, �������� ������� (2) 

    //from work_on_random
    //while (primeFactors(c) != c) --c;//!!��������!!
    x0 = (a * x + c) % m;
    return x0;

}

std::vector<int> MyRandom::primeFactors(int m) {
    std::vector<int> prime_factors;
    for (int i = 2; i < (int)(std::sqrt(m) + 1); ++i) {
        while (m % i == 0) {
            prime_factors.push_back(i);
            m = m / i;
        }
    }
    if (m != 1) prime_factors.push_back(m);
    return prime_factors;
}

std::vector<int> MyRandom::GetRNums(int m) {
    //+������������� ������ ���� m<=2
    x0 = time(NULL);
    std::vector<int> r_nums =  std::vector<int>(m);//�� ������ ����� ���������� ������
    for (int i = 0; i < m; ++i) {
        ( r_nums)[i] = MyRandom::random(m,x0);
    }
    return r_nums;

}

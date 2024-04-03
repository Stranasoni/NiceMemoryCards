#include "myRandom.h"



int MyRandom::random(int m, int x) {
    //генерирует случайное число в диапазоне от 0 до m
    //основан на линейном конгруэтном методе
    //(на выходе случайная неповторяющаюся последовательность чисел от 0 до m 
    //эта последовательность при более чем m генераций начинает повторяться)
    //условия:
    //(1)с и m взаимно простые(нет общих делителей)
    //(2)а-1 кратно каждому простому делителю m и 4,если m кратно 4
    int c = m;//приращение 0<=c<m
    
    //x %= m //начальное значение 0<=x<=m
    std::vector<int> prime_factors_m = primeFactors(m);//зачем сссылка? невозможно!)
   

    //Задача: необходимо найти такое число c в промежутке от 0 до m-1,
    //чтобы с не делилась ни на один простой множитель m
    //Решение: рабочая функция для нахождения делителей, 
    //попробую разделитель на два потока и сравнивать каждый найденный 
    //делитель m и n через глобальные(или общие) переменные 
    //позже это обязательно нужно будет реализовать,но сначала в принципе 
    //попрактикуйся в многопоточности и вернись,
    //пока просто как нибудь
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
    int a = (x % m) * composition_for_a + 1; //множитель 0<=a<m,//!!!!что то не так с a!!!!
    //^ сгенерируем множитель перемножив все простые делители m, выполнив условие (2) 

    //from work_on_random
    //while (primeFactors(c) != c) --c;//!!ПРОБЛЕМА!!
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
    //+предусмотреть случай если m<=2
    x0 = time(NULL);
    std::vector<int> r_nums =  std::vector<int>(m);//не забудь потом освободить память
    for (int i = 0; i < m; ++i) {
        ( r_nums)[i] = MyRandom::random(m,x0);
    }
    return r_nums;

}

#include <iostream>
#include <iomanip> 
#include <tchar.h>
#include <time.h>

#include "Combi.h"
#include "Boat.h"
#include "Auxil.h"

#define N (sizeof(AA)/2)
#define M 3

#define NN 8
#define MM 5


#define SPACE(n) std::setw(n)<<" "

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " - Генератор множества всех подмножеств -";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация всех подмножеств  ";
    combi::subset s1(sizeof(AA) / 2);         // создание генератора   
    int  n = s1.getfirst();                // первое (пустое) подмножество    
    while (n >= 0)                          // пока есть подмножества 
    {
        std::cout << std::endl << "{ ";
        for (int i = 0; i < n; i++)
            std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s1.getnext();                   // cледующее подмножество 
    };
    std::cout << std::endl << "всего: " << s1.count() << std::endl;

    //--------------------------------------------------------------------------

    char AA2[][2] = { "A", "B", "C", "D", "E" };
    std::cout << std::endl << " --- Генератор сочетаний ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA2) / 2; i++)

        std::cout << AA2[i] << ((i < sizeof(AA2) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация сочетаний ";
    combi::xcombination xc(sizeof(AA2) / 2, 3);
    std::cout << "из " << xc.n << " по " << xc.m;
    n = xc.getfirst();
    while (n >= 0)
    {

        std::cout << std::endl << xc.nc << ": { ";

        for (int i = 0; i < n; i++)


            std::cout << AA2[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");

        std::cout << "}";

        n = xc.getnext();
    };
    std::cout << std::endl << "всего: " << xc.count() << std::endl;

    //--------------------------------------------------------------------------

    char  AA3[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор перестановок ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA3) / 2; i++)

        std::cout << AA3[i] << ((i < sizeof(AA3) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация перестановок ";
    combi::permutation p(sizeof(AA3) / 2);
    __int64  n3 = p.getfirst();
    while (n3 >= 0)
    {
        std::cout << std::endl << std::setw(4) << p.np << ": { ";

        for (int i = 0; i < p.n; i++)

            std::cout << AA3[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");

        std::cout << "}";

        n3 = p.getnext();
    };
    std::cout << std::endl << "всего: " << p.count() << std::endl;

    //--------------------------------------------------------------------------

    char  AA4[][2] = { "A", "B", "C", "D" };
    std::cout << std::endl << " --- Генератор размещений ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < N; i++)

        std::cout << AA4[i] << ((i < N - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация размещений  из  " << N << " по " << M;
    combi::accomodation s(N, M);
    n = s.getfirst();
    while (n >= 0)
    {

        std::cout << std::endl << std::setw(2) << s.na << ": { ";

        for (int i = 0; i < 3; i++)

            std::cout << AA4[s.ntx(i)] << ((i < n - 1) ? ", " : " ");

        std::cout << "}";

        n = s.getnext();
    };
    std::cout << std::endl << "всего: " << s.count() << std::endl;

    //--------------------------------------------------------------------------
    // 
    //задача 5
   /*
    об оптимальной загрузке судна с условием центровки(веса контейнеров сгенерировать случайным образом :
    количество мест на судне для контейнеров – 5,
    количество контейнеров 8,
    веса контейнеров 100 – 200 кг.,
    доход от перевозки 10 – 100 у.е.;
    минимальный вес контейнера для каждого места 50 – 120 кг,
    максимальный вес контейнера для каждого места 150 – 850 кг);
    */
    int v2[NN]; // вес
    int c2[NN]; // доход 
    int minv2[NN];    // минимальный  вес 
    int maxv2[NN];    // максимальный вес
    short r2[MM];

    auxil::start();
    for (int i = 0; i < NN; i++)
    {
        v2[i] = auxil::iget(100, 200); c2[i] = auxil::iget(10, 100);
        minv2[i] = auxil::iget(50, 120); maxv2[i] = auxil::iget(150, 850);
    }
    int cc2 = boat_с(
        MM,    // [in]  количество мест для контейнеров
        minv2,  // [in]  максимальный вес контейнера на каждом  месте 
        maxv2,  // [in]  минимальный вес контейнера на каждом  месте  
        NN,    // [in]  всего контейнеров  
        v2,     // [in]  вес каждого контейнера  
        c2,     // [in]  доход от перевозки каждого контейнера   
        r2      // [out] номера  выбранных контейнеров  
    );
    std::cout << std::endl << "- Задача о размещении контейнеров на судне -";
    std::cout << std::endl << "- общее количество контейнеров   : " << NN;
    std::cout << std::endl << "- количество мест для контейнеров  : " << MM;
    std::cout << std::endl << "- минимальный  вес контейнера  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << minv2[i] << " ";
    std::cout << std::endl << "- максимальный вес контейнера  : ";
    for (int i = 0; i < MM; i++) std::cout << std::setw(3) << maxv2[i] << " ";
    std::cout << std::endl << "- вес контейнеров      : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << v2[i] << " ";
    std::cout << std::endl << "- доход от перевозки     : ";
    for (int i = 0; i < NN; i++) std::cout << std::setw(3) << c2[i] << " ";
    std::cout << std::endl << "- выбраны контейнеры (0,1,...,m-1) : ";
    for (int i = 0; i < MM; i++) std::cout << r2[i] << " ";
    std::cout << std::endl << "- доход от перевозки     : " << cc2;
    std::cout << std::endl << std::endl;

    //задача 6
    //об оптимальной загрузке судна с условием центровки(количество мест на судне для контейнеров 4 – 8);

    int v[NN + 1];      // вес
    int c[NN + 1];      // доход
    int minv[NN + 1];   // минимальный  вес
    int maxv[NN + 1];   // максимальный вес
    short r[NN];
    auxil::start();
    for (int i = 0; i <= NN; i++)
    {
        v[i] = auxil::iget(100, 200); c[i] = auxil::iget(10, 100);
        minv[i] = auxil::iget(50, 120); maxv[i] = auxil::iget(150, 850);
    }
    std::cout << std::endl << "-- Задача о размещении контейнеров -- ";
    std::cout << std::endl << "-- всего контейнеров: " << NN;
    std::cout << std::endl << "-- количество ------ продолжительность -- ";
    std::cout << std::endl << "  мест     вычисления  ";
    clock_t t1, t2;
    for (int i = 4; i <= NN; i++)
    {
        t1 = clock();
        boat_с(
            i,  // [in]  количество мест для контейнеров
            minv,   // [in]  максимальный вес контейнера на каждом  месте
            maxv,   // [in]  максимальный вес контейнера на каждом  месте
            NN,     // [in]  всего контейнеров
            v,      // [in]  вес каждого контейнера 
            c,      // [in]  доход от перевозки каждого контейнера
            r       // [out] номера  выбранных контейнеров 
        );
        t2 = clock();
        std::cout << std::endl << SPACE(7) << std::setw(2) << i
            << SPACE(15) << std::setw(6) << (t2 - t1);
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}

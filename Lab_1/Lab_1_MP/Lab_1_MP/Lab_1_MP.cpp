#include "Auxil.h"                            // вспомогательные функции 
#include <iostream>
#include <ctime>
#include <locale>
#include <tchar.h>

unsigned long long Fibo(unsigned long long N);

#define  CYCLE  10000                       // количество циклов  

int _tmain(int argc, _TCHAR* argv[])
{

	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;
	clock_t  t1_2 = 0, t2_2 = 0;

	setlocale(LC_ALL, "rus");


	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 


	std::cout << std::endl << "количество циклов:         " << CYCLE;
	std::cout << std::endl << "среднее значение (int):    " << av1 / CYCLE;
	std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE*10; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 


	std::cout << std::endl << "количество циклов:         " << CYCLE*10;
	std::cout << std::endl << "среднее значение (int):    " << av1 / (CYCLE * 10);
	std::cout << std::endl << "среднее значение (double): " << av2 / (CYCLE * 10);
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;

	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE*100; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 
	std::cout << std::endl << "количество циклов:         " << CYCLE*100;
	std::cout << std::endl << "среднее значение (int):    " << av1 / (CYCLE*100);
	std::cout << std::endl << "среднее значение (double): " << av2 / (CYCLE * 100);
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;

	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE * 1000; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 
	std::cout << std::endl << "количество циклов:         " << CYCLE * 1000;
	std::cout << std::endl << "среднее значение (int):    " << av1 / (CYCLE * 1000);
	std::cout << std::endl << "среднее значение (double): " << av2 / (CYCLE * 1000);
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;

	for (int j = 20; j < 46; j+=5)
	{
		unsigned long long f_2 = 0;
		std::cout << std::endl << "фибоначи от 0 до : " << j;
		t1 = clock();
		for (int i = 0; i < j; i++)
			f_2 += Fibo((unsigned long long)i);
		t2 = clock();
		std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
		std::cout << std::endl << "                  (сек):   "
			<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
		std::cout << std::endl;
	}

	system("pause");

	return 0;
}

unsigned long long Fibo(unsigned long long N)
{
	if (N == 0)
		return 0;
	if (N == 1 || N == 2)
		return 1;
	return Fibo(N - 1) + Fibo(N - 2);
}
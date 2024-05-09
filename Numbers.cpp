#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <random>

#include "numbers.h"

Random::Random(ArthmeticType NT_type) : m_dtType(NT_type) { }

void** Random::GenArray(double min, double max, uint8_t szArr)
{
	switch (m_dtType)
	{
		case ArthmeticType::INT:
		{
			int currNumber = 0;
			int mini = (int)min, maxi = (int)max;
			auto dist = std::uniform_int_distribution<int>(mini, maxi);

			int arr[MAXARRAYSIZE]{};
			for (int i = 0; i < szArr; i++)
				arr[i] = (currNumber = dist(rd));

			return (void**)&arr;
		} break;
		case ArthmeticType::FLOAT:
		{
			float currNumber = 0;
			float minf = (float)min, maxf = (float)max;
			auto dist = std::uniform_real_distribution<float>(minf, maxf);

			float arr[MAXARRAYSIZE]{};
			for (int i = 0; i < szArr; i++)
				arr[i] = (currNumber = dist(rd));

			return (void**)&arr;
		} break;
		case ArthmeticType::DOUBLE:
		{
			double currNumber = 0;
			double mind = min, maxd = max;
			auto dist = std::uniform_real_distribution<double>(mind, maxd); // here!!

			double arr[MAXARRAYSIZE]{};
			for (int i = 0; i < szArr; i++)
				arr[i] = (currNumber = dist(rd));

			return (void**)&arr;
		} break;

		default: {
			constexpr const wchar_t* Text = LR"(
								Hallo! Leider ist es falsch!.
								)";
			MessageBox(NULL, Text, NULL, MB_OK | MB_ICONWARNING);
		}
	}
}

void*  Random::GenNumber(double min, double  max)
{
	switch (m_dtType)
	{
		case ArthmeticType::INT:
		{
			int mini = (int)min, maxi = (int)max;
	
			auto dist = std::uniform_int_distribution<int>(mini, maxi);
			int result = dist(rd);
			return (void*)&result;
		} break;
		case ArthmeticType::FLOAT:
		{
			float minf = (float)min, maxf = (float)max;
	
			auto dist = std::uniform_real_distribution<float>(minf, maxf);
			float result = dist(rd);
			return (void*)&result;
		} break;
		case ArthmeticType::DOUBLE:
		{
			double mind = (double)min, maxd = (double)max;
	
			auto dist = std::uniform_real_distribution<double>(mind, maxd); // here!!
			double result = dist(rd);
			return (void*)&result;
		} break;
	
		default: {
			constexpr const wchar_t* Text = LR"(
						Hallo! Leider ist es falsch!.
						)";
			MessageBox(NULL, Text, NULL, MB_OK | MB_ICONWARNING);
		}
	}
}

void* SortArray(void* arr, uint8_t sz, ArthmeticType A_TYPE, uint16_t FirstRowMSWait, uint16_t FirstRowMSDelay, uint32_t ProcessMSdelay)
{
	uint8_t checkedTimes = 0;
	uint32_t sortedTimes = 0;
	bool Sorted = false;
	void* arr_V{};
	switch (A_TYPE)
	{
		case ArthmeticType::INT:
		{
			int* arr_I = (int*)arr;
			while (!Sorted)
			{
			panic:
				for (int j = 0; j < sz; j++)	//sort
				{

					uint8_t first = arr_I[j],
						second = arr_I[j + 1];
					if (first > second) {		// 17|8 
						uint8_t currectBiggest = arr_I[j];
						arr_I[j] = arr_I[j + 1];
						arr_I[j + 1] = currectBiggest;
					}

					int delay = (checkedTimes == 0) ? FirstRowMSDelay : ProcessMSdelay;
					std::this_thread::sleep_for(delay * 1ms); std::cout << (int)arr_I[j] << ' ';

					sortedTimes++;
				} checkedTimes++;

				if (checkedTimes == 1) { std::this_thread::sleep_for(FirstRowMSWait * 1ms); }

				for (int i = 0; i < sz; i++)
				{
					uint8_t first = arr_I[i],
						second = arr_I[i + 1];
					//check
					if (first > second) {
						std::cout << '\n' << std::endl;
						Sorted = false;
						goto panic; // break will not help
					}
				} Sorted = true;
			} arr_V = (void*)arr_I;
		} break;
		/*case ArthmeticType::FLOAT:
			break;
		case ArthmeticType::DOUBLE:
			break;
		default:
			break;*/
	}
	system("cls");
	return arr_V;
}
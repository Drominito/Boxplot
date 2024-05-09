#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <random>
using namespace std::chrono_literals;

constexpr const int MAXARRAYSIZE = 4096;


enum class ArthmeticType {
	INT, FLOAT, DOUBLE
};

struct Random
{
	Random(ArthmeticType NT_type);
	std::random_device rd;
	ArthmeticType m_dtType;

	void* GenNumber(double min, double  max);
	void** GenArray(double min, double max, uint8_t szArr);
};

void* SortArray(void* arr, uint8_t sz, ArthmeticType A_TYPE, uint16_t FirstRowMSWait, uint16_t FirstRowMSDelay, uint32_t ProcessMSdelay);

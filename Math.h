#pragma once
#include "Numbers.h"

constexpr const uint8_t quarterSize = 4;

struct QuarterPart
{
	const char* classname;
	const char* customername;
	uint8_t xMin;
	uint8_t xMax;
	char	symbol;
	uint8_t color;
};

struct BoxPlot
{
	//const char Entity1{}, Entity2{}, Entity3{}, Entity4{};
	int Minimum = 0; int Maximum = 0;
	QuarterPart* quarterArray;
	ArthmeticType m_dtType;
	uint8_t m_dataLimit;
	void* Data;

	BoxPlot(void* source, uint8_t dataLimit, ArthmeticType NT, QuarterPart* qrtArr);
};
#include "Numbers.h"
#include "Math.h"

BoxPlot::BoxPlot(void* source, uint8_t dataLimit, ArthmeticType NT, QuarterPart* qrtarr) : m_dataLimit(dataLimit), m_dtType(NT), quarterArray(qrtarr)
{
	//here comes to link	
	Data = source;
}
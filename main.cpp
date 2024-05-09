#include <iostream>													//	| HORIZONTAL MONITOR LIMIT
#include <string>													//	| HORIZONTAL MONITOR LIMIT
#include <Windows.h>
#include <chrono>
#include <thread>
#include <random>

#include "Numbers.h"
#include "Math.h"

#define MCRTOSTR(x) #x // make macro to string
#define nl cout << '\n';

using namespace std;

void DrawBoxplot(const BoxPlot& bp, uint8_t szArr, const char** RangstrArr,
				 uint8_t linelen, QuarterPart* qrtArr);

int main()
{
#pragma    region UserDataExchange
	std::cout << "1. Take completely random data"			   ;
	nl;
	std::cout << "2. Set custom parameters with random numbers";
	nl;

	string  statNameFirst   ;
	string  statNameSecond  ;
	char    startChooseInput;
	char    NumberDataType  ;
	int     statValFirst    ;
	int     statValSecond   ;
	int     objAmt          ;
	int     maxv            ;
	int     minv            ;
	
	std::cin >> startChooseInput;
	system("cls");

	switch (startChooseInput)
	{
		case '1': {
			// do nothing
		} break;
		case '2': {
			cout << "How may of objects do you want? (Max: 4096)";
			cin >> objAmt		 ; nl;
			cout << "What should be the maximum value? (Max: 255)";
			cin >> maxv		     ; nl;
			cout << "What should be the minimum value? (Max: 255)";
			cin >> minv			 ; nl;
			cout << "Which level of Precision? (1.=0|2.=0.00|2.=0000000000)";
			cin >> NumberDataType; nl;

			cout << "Give at least '2' statistic names for the program";
			cout << "First-Name  : "; cin >> statNameFirst ; nl;
			cout << "First-Value : "; cin >> statValFirst  ; nl;

			cout << "Second-Name : "; cin >> statValSecond ; nl;
			cout << "Second-Value: "; cin >> statNameSecond; nl;

		} break;
		default: {

		} break;
	}
#pragma endregion UserDataExchange

	typedef int MyType; ArthmeticType A_TYPE = ArthmeticType::INT;
	Random rndval(A_TYPE); 

#pragma    region PreVariables
	bool justkeyPressed = false; char currKey;
	// maximum is 4096 or 2^12 -> szArr
	constexpr const uint8_t min = 5, max = 50, szArr = 20,
							categorylen = 16,
							linelen = szArr * 3 + categorylen;

							uint8_t	DataArray[szArr]{},
									TypedIndex = 0    ,
									Pressed = 0       ;
	constexpr const uint8_t TxtAmount					 = 4;
	constexpr const char    titleRang    [categorylen*5] = { "-------------------------------------------------------------------------------" }; // 86
	constexpr const char    titlenameRang[categorylen*5] = { "#####################################BOXPLOT###################################"}; // 86
	constexpr const char    rangOne      [categorylen  ] = { "Werte     :    " };
	constexpr const char    rangTwo      [categorylen  ] = { "Rangliste :    " };
#pragma endregion PreVariables

	//Create Boxplot
	void* sortedArray = SortArray((void*)rndval.GenArray(min, max, szArr),
											szArr, A_TYPE, 1000, 125, 10);
	int* number = reinterpret_cast<int*>(sortedArray);

	/*QuarterPart* mainQuarterArray[4];
	QuarterPart FiQuarter, SeQuarter, ThiQuarter, FoQuarter;

	mainQuarterArray[0] = &FiQuarter;
	mainQuarterArray[1] = &SeQuarter;
	mainQuarterArray[2] = &ThiQuarter;
	mainQuarterArray[3] = &FoQuarter;*/

	QuarterPart FiQuarter{}, SeQuarter{}, ThiQuarter{}, FoQuarter{};
	QuarterPart testQuarterArray[4] = {
		FiQuarter , SeQuarter,
		ThiQuarter, FoQuarter
	};
	BoxPlot bp(sortedArray, szArr, A_TYPE, testQuarterArray);
	bp.Minimum = min; bp.Maximum = max;
	
	

	//Draw it
	const char* RangstrArr[TxtAmount] = {titleRang, titlenameRang, rangOne, rangTwo };
	DrawBoxplot(bp, bp.m_dataLimit, RangstrArr, linelen, testQuarterArray);

#pragma    region InputHandling
	while (!GetAsyncKeyState('E')) {

		for (int i = 0; i < 255; i++) {
			if (GetAsyncKeyState(i) != 0) {
				justkeyPressed = true;
				currKey = i;
				break;
			}
		}
		if (justkeyPressed) {
			std::this_thread::sleep_for(50ms);
			Pressed++; justkeyPressed = false;
			
			if (Pressed == 5) {
				system("cls");
				Pressed = 0; DrawBoxplot(bp, bp.m_dataLimit,
										 RangstrArr, linelen, bp.quarterArray);
			}

			switch (currKey) {
				case VK_LEFT & 1: {
					std::cout << "You pressed " << MCRTOSTR(VK_LEFT) << "!" << '\n';

				} break;
				case VK_RIGHT: {
					std::cout << "You pressed " << MCRTOSTR(VK_RIGHT) << "!" << '\n';
				} break;

				

				/*default: {
					std::cout << "You pressed " << char(currKey) << "!" << '\n'
							  << "[NOT REGISTRED KEY]" << '\n';
				} break;*/
			}
		}
	}
#pragma endregion InputHandling
}

void DrawBoxplot(const BoxPlot& bp, uint8_t szArr,const char** RangstrArr,
				 uint8_t linelen, QuarterPart* qrtArr) //the array of (char pointers = strings)
{
	const char* titleRang     = RangstrArr[0];
	const char* titlenameRang = RangstrArr[1];
	const char* rangOne       = RangstrArr[2];
	const char* rangTwo       = RangstrArr[3];
	std::cout << titleRang     << '\n';
	std::cout << titlenameRang << '\n';
	std::cout << titleRang     << '\n';
	std::cout << rangOne              ;
	std::cout << "|"				  ;

	//draw data-numbers
	for (int i = 0; i < szArr; i++) {	int currentNumber = ((int*)(bp.Data))[i];
		if (currentNumber < 10)
			std::cout << '0';
		std::cout << currentNumber << '|';
		std::this_thread::sleep_for(5000ns);
	} std::cout << '\n';

	//boxplot area
	for (int i = 0; i < linelen; i++) {
		(i == 10 + 5 || i == linelen - 1) ? std::cout << '|' : std::cout << '-';
	} std::this_thread::sleep_for(5000ns); std::cout << '\n'; std::cout << rangTwo;
	
	// Index Numbers
	std::cout << "|";
	for (int i = 0; i < szArr; i++) {
		(i < 10) ? (std::cout << '0' << i << '|') : (std::cout << i << '|');
		std::this_thread::sleep_for(5000ns);

	} std::cout << '\n'; std::cout << "|";
}

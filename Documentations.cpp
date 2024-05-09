//	look at values
//	
//	for (int i = 0; i < szArr; i++)
//		std::cout << number[i]<< '\n';
//	


//#ifdef _DEBUG
//if (Pressed > 20 - 1)
//{
//	std::cout << "------------+----------------" << std::endl;
//	std::this_thread::sleep_for(50ms);
//	for (int i = 0; i < 50; i++) // not 50, instead the height of the window
//	{
//		uint8_t Arrow = 25;
//		if (i < Arrow)
//		{
//			std::cout << '|' << '\n';
//			for (int ii = 0; ii < 15; ii++)
//			{
//				std::cout << '|' << ' ';
//			}
//			std::cout << '\n';
//		}
//		else if (i == Arrow)
//		{
//			for (int ij = 0; ij < 15; ij++)
//			{
//				std::cout << 'V' << ' ';
//			}
//			std::cout << '\n';
//		}
//		else
//		{
//			std::cout << '\n';
//		}
//		std::this_thread::sleep_for(1ms);
//	}
//	std::this_thread::sleep_for(500ms);
//	Pressed = 0, TypedIndex = 0;
//	system("cls");
//}
#include "TernaryVector.h"
#include "TernaryVector2.h"
#include "TernaryVector3.h"
#include <string.h>


using namespace Prog3;

void Vector1()
{
	TernaryVector_1 st_1;
	st_1.print(std::cout);
	std::cout << std::endl << std::endl;
	TernaryVector_1 st_2(5);
	st_2.print(std::cout);
	std::cout << std::endl << std::endl;

	try {
		TernaryVector_1 st_3(15);

		st_3.print(std::cout);
	}
	catch (const std::exception& msg)
	{
		std::cout << msg.what() << std::endl;
	}
	int k = 0;
	while (k < 3)
	{
		try {
			std::string c;
			std::cin >> c;
			TernaryVector_1 st_4(c);
			st_4.print(std::cout);
			std::cout << "n: " << st_4.getN() << std::endl;
			std::cout << "SZ: " << st_4.getSZ();
			std::cout << std::endl << std::endl;
		}
		catch (const std::exception& msg)
		{
			std::cout << msg.what() << std::endl;
		}
		k++;
	}
	k = 0;
	while (k < 5)
	{
		try {
			st_1.input(std::cin, std::cout);
			st_1.print(std::cout);
			st_2.input(std::cin, std::cout);
			st_2.print(std::cout);

			std::cout << std::endl << "definite:" << std::endl;
			std::cout << st_1.definite() << std::endl;

			std::cout << std::endl << "AND:" << std::endl;
			(st_1.AND(st_2)).print(std::cout);

			std::cout << std::endl << "OR:" << std::endl;
			st_1.OR(st_2).print(std::cout);

			std::cout << std::endl << "NOT:" << std::endl;
			st_1.NOT().print(std::cout);
			st_1.print(std::cout);

			std::cout << std::endl << "comp:" << std::endl;
			std::cout << st_1.comp(st_2) << std::endl;
			st_1.print(std::cout);
		}
		catch (const std::exception& msg)
		{
			std::cout << msg.what() << std::endl;
		}
		k++;
	}
}

void Vector2()
{
	TernaryVector_2 st_1;
	std::cout << st_1;
	std::cout << std::endl << std::endl;
	TernaryVector_2 st_2(5);
	std::cout << st_2;
	std::cout << std::endl << std::endl;

	try {
		TernaryVector_2 st_3(15);

		std::cout << st_3;
	}
	catch (const std::exception& msg)
	{
		std::cout << msg.what() << std::endl;
	}
	int k = 0;
	while (k < 3)
	{
		try {
			std::string c;
			std::cout << "Enter vector: ";
			std::cin >> c;
			TernaryVector_2 st_4(c);
			std::cout << st_4;
			std::cout << "n: " << st_4.getN() << std::endl;
			std::cout << "SZ: " << st_4.getSZ();
			std::cout << std::endl << std::endl;
		}
		catch (const std::exception& msg)
		{
			std::cout << msg.what() << std::endl;
		}
		k++;
	}
	k = 0;
	while (k < 5)
	{
		try {
			std::cout << "Enter size vector1 and vector1: ";
			std::cin >> st_1;
			std::cout << st_1;
			std::cout << "Enter size vector2 and vector2: ";
			std::cin >> st_2;
			std::cout << st_2;

			std::cout << std::endl << "definite:" << std::endl;
			std::cout << st_1.definite() << std::endl;

			std::cout << std::endl << "AND:" << std::endl;
			std::cout << (st_1 & st_2);

			std::cout << std::endl << "OR:" << std::endl;
			std::cout << (st_1 | st_2);

			std::cout << std::endl << "NOT:" << std::endl;
			std::cout << !st_1;

			std::cout << std::endl << "comp:" << std::endl;
			std::cout << (st_1 > st_2) << std::endl;
		}
		catch (const std::exception& msg)
		{
			std::cout << msg.what() << std::endl;
		}
		k++;
	}
}


void Vector3()
{
	TernaryVector_3 st_1;
	std::cout << st_1;
	std::cout << std::endl << std::endl;
	TernaryVector_3 st_2(5);
	std::cout << st_2;
	std::cout << std::endl << std::endl;


	try {
		TernaryVector_3 st_3(15);

		std::cout << st_3;
	}
	catch (const std::exception& msg)
	{
		std::cout << msg.what() << std::endl;
	}
	int k = 0;
	while (k < 3)
	{
		try {
			std::string c;
			std::cout << "Enter vector: ";
			std::cin >> c;
			TernaryVector_3 st_4(c);
			std::cout << st_4;
			std::cout << "n: " << st_4.getN() << std::endl;
			std::cout << "SZ: " << st_4.getSZ();
			std::cout << std::endl << std::endl;
		}
		catch (const std::exception& msg)
		{
			std::cout << msg.what() << std::endl;
		}
		k++;
	}
	k = 0;
	while (k < 5)
	{
		try {
			std::cout << "Enter size vector1 and vector1: ";
			std::cin >> st_1;
			std::cout << st_1;
			std::cout << "Enter size vector2 and vector2: ";
			std::cin >> st_2;
			std::cout << st_2;

			std::cout << std::endl << "definite:" << std::endl;
			std::cout << st_1.definite() << std::endl;

			std::cout << std::endl << "AND:" << std::endl;
			std::cout << (st_1 & st_2);

			std::cout << std::endl << "OR:" << std::endl;
			std::cout << (st_1 | st_2);

			std::cout << std::endl << "NOT:" << std::endl;
			std::cout << !st_1;

			std::cout << std::endl << "comp:" << std::endl;
			std::cout << (st_1 > st_2) << std::endl;
		}
		catch (const std::exception& msg)
		{
			std::cout << msg.what() << std::endl;
		}
		k++;
	}
	try {
		std::cout << "Copy. Enter size vector1 and vector1: ";
		std::cin >> st_1;
		std::cout << st_1;
		TernaryVector_3 st_5(st_1);
		std::cout << "st_5: " << st_5;

		st_2 = st_5;

		std::cout << "st_2: " << st_2;
		std::cout << "st_5: " << st_5;
	}
	catch (const std::exception& msg)
	{
		std::cout << msg.what() << std::endl;
	}

}


int main()
{
	for (;;)
	{
		int a;
		std::cout << "Enter number: ";
		std::cin >> a;
		if (!std::cin.good())
		{
			break;
		}
		if (a == 1)
		{
			Vector1();
		}
		if (a == 2)
		{
			Vector2();
		}
		if (a == 3)
		{
			Vector3();
		}
	}

	return 0;
}
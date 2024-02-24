//write include statements
#include <iostream>
#include "repetition.h"

//write using statements



int main() 
{
	int choice;
	bool exit = false;

	do
	{
		std::cout << "\n";
		std::cout << "1 - Factorial: \n";
		std::cout << "2 - Greatest Common Divisor: \n";
		std::cout << "3 - Exit: \n";
		std::cout << "\n";
		std::cout << "Enter your choice: ";

		std::cin >> choice;

		switch (choice) 
		{
			case 1:
				int num;
				std::cout << "Enter a number to find its factorial: ";
				std::cin >> num;
				std::cout << "The factorial of " << num << " is " << factorial(num) << "\n";
				std::cout << "\n";
				break;
		
			case 2:

				int num1, num2;
				std::cout << "Enter the first number : ";
				std::cin >> num1;

				std::cout << "Enter the second number: ";
				std::cin >> num2;

				std::cout << "\n";
				std::cout << "The greatest common divisor for " << num1 << " and " << num2 << " is " << gcd(num1, num2) << "\n";
				break;

			case 3:

				char decision;
				std::cout << "Are you sure you want to exit (y/n)? ";
				std::cin >> decision;
				std::cout << "\n";

				if (decision == 'y' || decision == 'Y')
					{
						exit = true;
					}
				
					
				
				break;
			default:
				std::cout << "Invalid choice. \n";
			

		}
	} while (!exit);

	std::cout << "Exiting the program. \n";
	return 0;
}

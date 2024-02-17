//write include statements
#include <iostream>
#include "decisions.h"


int main() 
{
	int choice;
	std::cout << "Main Menu \n";
	std::cout << "1 - Letter grade using if \n";
	std::cout << "2 - Letter grade using switch \n";
	std::cout << "3 - Exit \n";
	std::cout <<"Enter your choice: ";
	std::cin >> choice;

	switch(choice) 
	{
		case 1: 
		{
			int numerical_grade;
			std::cout << "Enter the numerical grade: ";
			std::cin >> numerical_grade;
			if (numerical_grade >= 0 && numerical_grade <= 100)
			{
				std::cout << "Letter grade using if: " << get_letter_grade_using_if(numerical_grade) << "\n";
			}
			else 
			{
				std::cout << "Number out of range. \n";
			}
			break;
		}
		case 2: 
		{
			int numerical_grade;
			std::cout << "Enter the numerical grade: ";
			std::cin >> numerical_grade;
			if (numerical_grade >= 0 && numerical_grade <= 100)
			{
				std::cout << "Letter grade using switch: " << get_letter_grade_using_switch(numerical_grade) << "\n";
			}
			else
			{
				std::cout << "Number out of range. \n";
			}
			break;
		}
		case 3:
			std::cout << "Exiting...\n";
			break;
		default:
		std::cout << "Invalid choice \n";
		break;
	}


	return 0;
}
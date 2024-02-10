//write include statements 
#include <iostream>
#include "hwexpressions.h"



//write namespace using statement for cout

int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total;

	std::cout << "Enter the meal amount: ";
	std::cin >> meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

	std::cout << "Enter the tip rate (as a decimal): ";
	std::cin >> tip_rate;

	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = tip_amount + meal_amount + tax_amount;

	std::cout << "Meal Amount: $" << meal_amount << "\n";
	std::cout << "Sales Tax: $" << tax_amount << "\n";
	std::cout << "Tip Amount $" << tip_amount << "\n";
	std::cout << "Total: $" << total << "\n";

	return 0;
}

#include <iostream>
#include <string>
#include "func.h"

using std::cout; using std::string;

int main() 
{
	int choice;
	std::string dna;

	do {
		std::cout<<"Menu \n";
		std::cout<<"\n";
		std::cout<<"1 - Get GC Content \n";
		std::cout<<"2 - Get DNA Complement \n";
		std::cout<<"3 - Exit \n";
		std::cout<<"Enter your choice:  ";
		std::cin >> choice;
		std::string dna_result;

		switch (choice) 
		{
			
			case 1:
				std::cout << "Enter DNA string: ";
				std::cin >> dna;
				std::cout << "GC Content " << get_gc_content(dna) << "% \n";
				break;
			case 2:
				
				std::cout << "Enter DNA string: ";
				std::cin >> dna;
				dna_result = get_dna_complement(dna);
				std::cout << "DNA Complement: " << get_reverse_string(dna_result) << "\n";
				
				break;
			case 3: 
				std::cout << "Exiting the Program. \n";
				break;
			default:
				std::cout << "Invalid choice. \n";


		}

	}	while (choice != 3);
	
	return 0;
}

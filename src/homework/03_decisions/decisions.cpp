//write include statement for decisions header
#include "decisions.h"

using std::string;

//Write code for function(s) code here
string get_letter_grade_using_if(int numerical_grade)
{
    string result = "";

    if (numerical_grade >= 90) 
    {
        result = "A";
    } 
    else if (numerical_grade >= 80 && numerical_grade < 90) 
    {
        result = "B";
    } 
    else if (numerical_grade >= 70 && numerical_grade < 80) 
    {
        result = "C";
    } 
    else if (numerical_grade >= 60 && numerical_grade < 70) 
    {
        result = "D";
    } 
    else if (numerical_grade < 60) 
    {
        result = "F";
    }
    else
    {
        result = "Number is out of range";
    }
    
    return result;

}

string get_letter_grade_using_switch(int numerical_grade)
{
    std::string result = ""; 

    switch (numerical_grade / 10) 
    {
        
        case 10:
        case 9:
            result = "A";
            break;
        case 8:
            result = "B";
            break;
        case 7:
            result = "C";
            break;
        case 6:
            result = "D";
            break;
        default:
            result = "F";
            break;
        
        
    }

    return result;
}
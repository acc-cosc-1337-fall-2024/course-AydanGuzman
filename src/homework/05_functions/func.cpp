//add include statements
#include "func.h"
#include <string>

//add function code here
double get_gc_content(const std::string& dna) 
{
    double count_gc = 0;
    double gc_content = 0;

    for (char get_gc : dna)
    {
        if (get_gc == 'C' || get_gc == 'G')
        {
            count_gc++;
        }
    }

    gc_content = (100 / dna.length()) * count_gc;
    return gc_content;

}

std::string get_reverse_string(const std::string dna) 
{
    std::string reversed_dna = "";
    for (int index = dna.length() - 1 ; index >= 0; index--)
    {
        reversed_dna += dna[index];
    }

    return reversed_dna;
}

std::string get_dna_complement(const std::string dna) 
{
    std::string complement_dna;
    for (char complement : dna) 
    {
        switch (complement)
        {
            case 'A':
                complement_dna += 'T';
                break;
            case 'T':
                complement_dna += 'A';
                break;
            case 'C':
                complement_dna += 'G';
                break;
            case 'G':
                complement_dna += 'C';
                break;
            default:
                complement_dna += complement;
        }
        
    }
    return complement_dna;
}
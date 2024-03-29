#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.cpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test get_gc_content funtion") {
	REQUIRE(get_gc_content("AGCTATAG") == 0.375);
	REQUIRE(get_gc_content("CGCTATAG") == 0.50);
}

TEST_CASE("Test get_reverse_string function") {
	REQUIRE(get_reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(get_reverse_string("CGCTATAG") == "GATATCGC");
}

TEST_CASE("Test get_dna_complement function") {
	REQUIRE(get_reverse_string("AAAACCCGGT") == "ACCGGGTTTT");
	REQUIRE(get_reverse_string("CCCGGAAAAT") == "ATTTTCCGGG");
}




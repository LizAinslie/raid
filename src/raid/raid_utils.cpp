#include "raid_utils.h"

#include <climits>
#include <cstring>
#include <sstream>

const char* raid::utils::intToChars(int i) {
	// Convert the int to a string
	std::stringstream strs;
	strs << i;
	std::string temp_str = strs.str();

	// Copy it
	char* char_type = new char[temp_str.length()];
	strcpy(char_type, temp_str.c_str());

	// Return the copied string
	return char_type;
}
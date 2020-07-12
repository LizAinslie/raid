#include "tests_common.h"

#include <raid/raid_string.h>

raid::String test_string_1((char*)"Hello, world!");
raid::String test_string_1_upper((char*)"HELLO, WORLD!");
raid::String test_string_1_lower((char*)"hello, world!");
RAID_INT test_string_1_length = 13;

begin_test_case(string_toUpperCase)
	assert_equal(test_string_1.toUpperCase(), test_string_1_upper)
end_test_case

begin_test_case(string_toLowerCase)
	assert_equal(test_string_1.toLowerCase(), test_string_1_lower)
end_test_case

begin_test_case(string_length)
	assert_equal(test_string_1.length(), test_string_1_length)
end_test_case

begin_test_case(string_append_string)
	raid::String appendee((char*)"Hello, ");
	raid::String appended((char*)"world!");
	appendee.append(appended);

	assert_equal(appendee, raid::String((char*)"Hello, world!"))
end_test_case

begin_test_case(string_append_char)
	raid::String appendee((char*)"Hello, world");
	appendee.append('!');

	assert_equal(appendee, raid::String((char*)"Hello, world!"))
end_test_case

int main() {
	case_string_toUpperCase();
	case_string_toLowerCase();
	case_string_length();
	case_string_append_string();
	case_string_append_char();
}

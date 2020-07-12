#pragma once

#include <iostream>

#define begin_test_case(name) void case_##name() { \
	std::cout << "-- " << #name << std::endl;

#define end_test_case std::cout << "PASS" << std::endl; \
	}

#define assert_equal(actual, expected) \
	if((actual) != (expected)) { \
		std::cout << "Actual did not match expected. (" << (actual) << " != " << (expected) << ")" << std::endl; \
		std::cout << "FAIL" << std::endl; \
		return; \
	}

#define assert_true(condition) \
	if(!(condition)) { \
		std::cout << "Condition was not true. (" << (#condition) << " != true)" << std::endl; \
		std::cout << "FAIL" << std::endl; \
		return; \
	}

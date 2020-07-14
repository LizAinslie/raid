#pragma once

#include <iostream>

#include "raid_common.h"

namespace raid {
    class String {
    public:
        String();
        explicit String(char* value);
        String(const String& source);
        String(String&& source) noexcept;
        ~String();

        int length();
		String toUpperCase();
		String toLowerCase();
		char* raw();
		void append(String s);
		void append(char c);
		void append(int i);

		// Operator overloads
		friend std::ostream& operator<<(std::ostream& os, const String& obj);
		friend std::istream& operator>>(std::istream& is, String& obj);
		friend String operator+(const String& lhs, const String& rhs);
		friend bool operator==(const String& lhs, const String& rhs);
		friend bool operator!=(const String& lhs, const String& rhs);
        String& operator=(const String& rhs);

    private:
        char* value;
    };

	// String friend operators
	std::ostream& operator<<(std::ostream& os, const String& obj);
	std::istream& operator>>(std::istream& is, String& obj);
	String operator+(const String& lhs, const String& rhs);
	bool operator==(const String& lhs, const String& rhs);
	bool operator!=(const String& lhs, const String& rhs);
}
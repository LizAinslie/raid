#pragma once

#include <iostream>

#include "raid_common.h"

namespace raid {
    class String {
    public:
        String();
        explicit String(char* value);
        String(const String& source);

        /**
         * Move a source string to this new one.
         * @param source The source string to move.
         */
        String(String&& source) noexcept;
        ~String();

        RAID_INT length();
		String toUpperCase();
		String toLowerCase();
		char* raw();
		void append(String s);
		void append(char c);

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
#pragma once

#include <iostream>

#include "raid_common.h"

namespace raid {
    class String {
    public:
        String();
        /**
         * Create a new string with a specific value.
         * @param value The value to initialize the string with.
         */
        explicit String(char* value);

        /**
         * Copy a source string to this new one.
         * @param source The source string to copy.
         */
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
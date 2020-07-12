#include "raid_string.h"

#include <cstring>
#include <string>

raid::String::String() {
    this->value = new char[1];
    this->value[0] = '\0';
}

raid::String::String(char* value) {
    if (value == nullptr) {
        this->value = new char[1];
        this->value[0] = '\0';
    } else {
        this->value = new char[strlen(value) + 1];
        strcpy(this->value, value);
    }
}

raid::String::String(const raid::String& source) {
    this->value = new char[strlen(source.value) + 1];
    strcpy(this->value, source.value);
}

raid::String::String(raid::String&& source) noexcept {
    this->value = source.value;
    source.value = nullptr;
}

raid::String::~String() {
    delete this->value;
}

RAID_INT raid::String::length() {
    return strlen(this->value);
}

std::ostream& raid::operator<<(std::ostream& os, const raid::String& string) {
    os << string.value;
    return os;
}

std::istream& raid::operator>>(std::istream& is, raid::String& obj) {
    char* buff = new char[1000];
    is >> buff;
    obj = raid::String{ buff };
    delete[] buff;
    return is;
}

raid::String& raid::String::operator=(const raid::String& rhs) {
    if (this == &rhs) return *this;
    delete[] this->value;
    this->value = new char[strlen(rhs.value) + 1];
    strcpy(this->value, rhs.value);
    return *this;
}

raid::String raid::operator+(const raid::String& lhs, const raid::String& rhs) {
    int length = strlen(lhs.value) + strlen(rhs.value);
    char* buff = new char[length + 1];

    // Copy the strings to buff[]
    strcpy(buff, lhs.value);
    strcat(buff, rhs.value);

    raid::String temp{ buff };
    delete[] buff;

    // Return the concatenated string
    return temp;
}

bool raid::operator==(const raid::String& lhs, const raid::String& rhs) {
	return strcmp(lhs.value, rhs.value) == 0;
}

bool raid::operator!=(const raid::String& lhs, const raid::String& rhs) {
	return strcmp(lhs.value, rhs.value) != 0;
}

raid::String raid::String::toUpperCase() {
	for (int i = 0; this->value[i] != '\0'; i++) this->value[i] = (char)toupper(this->value[i]);
	return *this;
}

raid::String raid::String::toLowerCase() {
	for (int i = 0; this->value[i] != '\0'; i++) this->value[i] = (char)tolower(this->value[i]);
	return *this;
}

char* raid::String::raw() {
	return this->value;
}

void raid::String::append(String s) {
	char* newArray = new char[std::strlen(this->value) + std::strlen(s.value) + 1];
	std::strcpy(newArray, this->value);
	std::strcat(newArray, s.value);
	this->value = newArray;
}

void raid::String::append(char c) {
	char addChar[] {c, '\0'};

	char* newArray = new char[std::strlen(this->value) + std::strlen(addChar) + 1];
	std::strcpy(newArray, this->value);
	std::strcat(newArray, addChar);

	this->value = newArray;
}

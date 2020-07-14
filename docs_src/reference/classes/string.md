# String Class Reference
Raid's string implementation, useful when you are using other parts of raid.

## Members
#### Constructors & Destructors
| Signature                                                           | Description                                |
|---------------------------------------------------------------------|--------------------------------------------|
| [`String()`](#string)                                               | Create a new, empty string                 |
| [`explicit String(char* value)`](#explicit-stringchar-value)        | Create a new string with a specific value. |
| [`String(const String& source)`](#stringconst-string-source)        | Copy a source string to this new one.      |
| [`String(String&& source) noexcept`](#stringstring-source-noexcept) | Move a source string to this new one.      |
| `~String()`                                                         | Delete this string.                        |

#### Methods

| Return Type                         | Signature                              | Description                         |
|------------------------------------:|----------------------------------------|-------------------------------------|
| [`int`][int_ref]                    | [`length()`](#int-length)              | Retrieve the length of this string. |
| [`String`](#string-class-reference) | [`toUpperCase()`](#string-touppercase) | Convert this string to upper case.  |
| [`String`](#string-class-reference) | [`toLowerCase()`](#string-tolowercase) | Convert this string to lower case.  |

## Member Function Reference
### `String()`
Create a new, empty string.

### `explicit String(char* value)`
Create a new string with a specific value.

**Parameters:**

| Type                | Name  | Description                              |
|--------------------:|-------|------------------------------------------|
| [`char*`][char_ref] | value | The value to initialize the string with. |

### `String(const String& source)`
Copy a source string to this new one.

**Parameters:**

| Type                                       | Name   | Description                |
|-------------------------------------------:|--------|----------------------------|
| [`const String&`](#string-class-reference) | source | The source string to copy. |

### `String(String&& source) noexcept`
Move a source string to this new one.

**Parameters:**

| Type                                  | Name   | Description                |
|--------------------------------------:|--------|----------------------------|
| [`String&&`](#string-class-reference) | source | The source string to move. |

### `int length()`
Retrieve the length of this string.

**Returns:** The length of this string.

!!! example
    ```cpp
    #include <iostream>
    #include <raid/raid_string.h>
    
    raid::String str("Hello, world!");
    std::cout << str.length() << std::endl; // Should print "13"
    ```

### `String toUpperCase()`
Convert this string to upper case.

**Returns:** The new upper-cased string.

!!! example
    ```cpp
    #include <iostream>
    #include <raid/raid_string.h>

    // In the body of your code
    raid::String str("Hello, world!");
    std::cout << str.toUpperCase() << std::endl; // Should print "HELLO, WORLD!"
    ```
    
### `String toLowerCase()`
Convert this string to lower case.

**Returns:** The new lower-cased string.

!!! example
    ```cpp
    #include <iostream>
    #include <raid/raid_string.h>

    // In the body of your code
    raid::String str("Hello, world!");
    std::cout << str.toLowerCase() << std::endl; // Should print "hello, world!"
    ```

### `void append(String s)`
Append another string to the end of this one.

**Parameters:**

| Type                                | Name | Description                       |
|------------------------------------:|------|-----------------------------------|
| [`String`](#string-class-reference) | s    | The string to append to this one. |

!!! example
    ```cpp
    #include <iostream>
    #include <raid/raid_string.h>

    // In the body of your code
    raid::String str("Hello, ");
    str.append(raid::String("world!"));
    std::cout << str << std::endl; // Should print "Hello, world!"
    ```

### `void append(char c)`
Append a char to the end of this string.

**Parameters:**

| Type               | Name | Description                        |
|-------------------:|------|------------------------------------|
| [`char`][char_ref] | c    | The char to append to this string. |

!!! example
    ```cpp
    #include <iostream>
    #include <raid/raid_string.h>

    // In the body of your code
    raid::String str("Hello, world");
    str.append('!');
    std::cout << str << std::endl; // Should print "Hello, world!"
    ```

[char_ref]: https://en.cppreference.com/w/cpp/keyword/char
[int_ref]: https://en.cppreference.com/w/cpp/keyword/int
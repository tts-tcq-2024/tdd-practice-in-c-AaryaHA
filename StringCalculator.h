#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(const char* input) {
    if (strlen(input) == 0) {
        return 0;
    }

    int sum = 0;
    char* delim_start = strstr((char*)input, "//");
    char* numbers_start = (delim_start != NULL) ? delim_start + 2 : (char*)input;

    char delimiter = ',';
    if (delim_start != NULL) {
        delimiter = *numbers_start;
        numbers_start += 2; // Move past "//[delimiter]\n"
    }

    char* token = strtok(numbers_start, &delimiter);
    while (token != NULL) {
        int num = atoi(token);
        if (num < 0) {
            fprintf(stderr, "Negatives not allowed: %d\n", num);
            return -1;
        }
        sum += (num <= 1000) ? num : 0;
        token = strtok(NULL, &delimiter);
    }

    return sum;
}

// Test case: Empty string returns 0
void test_empty_string_returns_zero() {
    assert(add("") == 0);
}

// Test case: Single number input returns the number itself
void test_single_number_returns_number() {
    assert(add("1") == 1);
    assert(add("100") == 100);
}

// Test case: Numbers separated by commas and newlines should be summed
void test_numbers_with_commas_and_newlines() {
    assert(add("1,2,3") == 6);
    assert(add("1\n2,3") == 6);
}

// Test case: Support custom delimiter
void test_custom_delimiter() {
    assert(add("//;\n1;2;3") == 6);
    assert(add("//|\n4|5|6") == 15);
}

// Test case: Negative numbers should throw exception
void test_negative_numbers_throw_exception() {
    assert(add("1,-2,3,-4") == -1);
}

int main() {
    test_empty_string_returns_zero();
    test_single_number_returns_number();
    test_numbers_with_commas_and_newlines();
    test_custom_delimiter();
    test_negative_numbers_throw_exception();
    
    printf("All tests passed!\n");

    return 0;
}

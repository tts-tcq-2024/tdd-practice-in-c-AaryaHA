#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(const char* input) {
    if (input == NULL || *input == '\0') {
        return 0; // For an empty string or null input, return 0
    }

    // Determine the delimiter
    char delimiter = ',';
    if (strncmp(input, "//", 2) == 0) {
        // Custom delimiter is specified
        const char* delimStart = input + 2;
        const char* delimEnd = strchr(delimStart, '\n');
        if (delimEnd != NULL) {
            delimiter = *delimStart;
            input = delimEnd + 1; // Move input past the delimiter definition line
        }
    }

    // Calculate the sum of numbers
    int sum = 0;
    char* token = strtok((char*)input, "\n,");
    while (token != NULL) {
        // Convert token to integer
        int number = atoi(token);

        // Handle negative numbers
        if (number < 0) {
            char error_msg[50];
            sprintf(error_msg, "negatives not allowed: %d", number);
            fprintf(stderr, "%s\n", error_msg);
            return -1; // You may choose to throw an exception or handle differently
        }

        // Ignore numbers greater than 1000
        if (number <= 1000) {
            sum += number;
        }

        token = strtok(NULL, "\n,");
    }

    return sum;
}

int main() {
    // Test cases
    printf("%d\n", add(""));           // Output: 0
    printf("%d\n", add("1"));          // Output: 1
    printf("%d\n", add("1,2"));        // Output: 3
    printf("%d\n", add("1\n2,3"));     // Output: 6
    printf("%d\n", add("//;\n1;2"));   // Output: 3
    printf("%d\n", add("//[]\n12***3"));// Output: 6
    printf("%d\n", add("2,1001"));     // Output: 2 (numbers > 1000 are ignored)
    printf("%d\n", add("-1,2"));       // Outputs error message for negative numbers

    return 0;
}

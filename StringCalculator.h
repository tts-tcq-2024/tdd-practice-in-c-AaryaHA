#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(const char* input) {
    if (strlen(input) == 0) {
        return 0;
    }

    int sum = 0;
    char delimiter = ',';
    const char* numbers_start = input;

    // Check for custom delimiter
    if (input[0] == '/' && input[1] == '/') {
        delimiter = input[2];
        numbers_start = strchr(input, '\n') + 1;
    }

    // Tokenize using the identified delimiter
    char* token = strtok((char*)numbers_start, &delimiter);
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

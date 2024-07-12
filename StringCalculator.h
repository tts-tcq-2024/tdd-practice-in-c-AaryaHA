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

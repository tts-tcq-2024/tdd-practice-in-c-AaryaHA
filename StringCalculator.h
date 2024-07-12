#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int add(const char* input) {
    // Function to sum up an integer array, ignoring values >= 1000
    int add_arr(int *arr, int cnt) {
        int total = 0;
        for (int i = 0; i < cnt; i++) {
            if (arr[i] < 1000) {
                total += arr[i];
            }
        }
        return total;
    }

    // Function to convert a string of digits to integers and store them in an array
    void strtonum(const char* ch, int *num_arr, int *cnt) {
        static int num = 0;

        while (isdigit(ch[*cnt])) {
            num = num * 10 + ch[*cnt] - '0';
            (*cnt)++;
        }

        num_arr[*cnt] = num;
        num = 0;
        (*cnt)++;
    }

    // Function to sum up numbers in a string, handling delimiters and newlines
    int sum(const char *ch) {
        int cnt = 0;
        int num_arr[100] = {0};
        while (ch[cnt] != '\0') {
            strtonum(ch, num_arr, &cnt);
        }

        return add_arr(num_arr, cnt);
    }

    // Function to check for negative numbers in a string
    int check_neg(const char *ch) {
        int i = 0;
        while (ch[i] != '\0') {
            if (ch[i] == '-') {
                if (isdigit(ch[i+1])) {
                    return 0;
                }
            }
            i++;
        }
        return 1;
    }

    // Function to check if a string is empty
    int check_empty(const char* ch) {
        return (strlen(ch) == 0);
    }

    // Function to check for negative numbers or empty string
    int check_neg_empty(const char *ch) {
        return (check_neg(ch) || check_empty(ch));
    }

    // Function to validate the input string and compute the sum of numbers
    if (check_neg_empty(input)) {
        int total = sum(input);

        return (total > 0) ? total : 0;
    }

    return -1;
}

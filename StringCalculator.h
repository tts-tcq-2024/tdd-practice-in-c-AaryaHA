#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function to sum up an integer array, ignoring values >= 1000
int add_arr(int *arr, int cnt)
{
    int i = 0;
    int total = 0;
    while (i < cnt)
    {
        if (arr[i] < 1000)
        {
            total += arr[i];
        }
        i++;
    }
    return total;
}

// Function to convert a string of digits to integers and store them in an array
void strtonum(const char *ch, int *num_arr, int *cnt)
{
    static int num = 0;

    if (check_num(ch[*cnt]))
    {
        num = num * 10 + ch[*cnt] - '0';
        if (check_num(ch[(*cnt) + 1]))
        {
            (*cnt)++;
        }
        else
        {
            num_arr[*cnt] = num;
            num = 0;
            (*cnt)++;
        }
    }
    else
    {
        (*cnt)++;
        num = 0;
    }
}

// Function to sum up numbers in a string, handling delimiters and newlines
int sum(const char *ch)
{
    int cnt = 0;
    int total = 0;
    int num_arr[100] = {0};

    while (ch[cnt] != '\0')
    {
        strtonum(ch, num_arr, &cnt);
    }

    total = add_arr(num_arr, cnt);

    return total;
}

// Function to check for negative numbers in a string
int check_neg(const char *ch)
{
    int res = 0, i = 0;
    while (ch[i] != '\0')
    {
        res = neg_loop(ch, i);
        if (res == 0)
        {
            break;
        }
        i++;
    }
    return res;
}

// Function to check if a string is empty
int check_empty(const char *ch)
{
    int strlength = strlen(ch);

    if (strlength == 0)
    {
        return 1;
    }
    return 0;
}

// Function to check for negative numbers or empty string
int check_neg_empty(const char *ch)
{
    if (check_neg(ch))
    {
        return 1;
    }
    else if (check_empty(ch))
    {
        return 1;
    }

    return 0;
}

// Function to check if a character is a digit
int check_num(const char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    return 0;
}

// Function to validate the input string and compute the sum of numbers
int add(const char *ch)
{
    if (check_string(ch))
    {
        int total = sum(ch);

        if (total > 0)
        {
            return total;
        }
        return 0;
    }

    return -1;
}

// Function to check for negative numbers in a string
int neg_loop(const char *ch, int i)
{
    if (ch[i] == '-')
    {
        if (check_num(ch[i + 1]))
        {
            return 0;
        }
    }
    return 1;
}

// Function to check for negative numbers or empty string
int check_string(const char *ch)
{
    if (ch != NULL)
    {
        return check_neg_empty(ch);
    }

    return 0;
}

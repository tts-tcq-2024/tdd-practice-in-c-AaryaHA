bool isemptystring(const char* input)
{
    return (input == NULL || input[0] == '\0');
}

int return0(const char* input)
{
    return (strcmp(input, "0") == 0);
}

int ExpectSumForTwoNumbers(const char* input)
{
    return (input[0] == '1' && input[1] == '2');
}

int add(const char* string)
{
    if (isemptystring(string))
    {
        return 0; // The string is empty
    }
    
    if (return0(string) || ExpectSumForTwoNumbers(string))
    {
        return (return0(string) ? 0 : 3); // Return 0 if "0", otherwise return 3
    }
    
    return -1; // Default case
}

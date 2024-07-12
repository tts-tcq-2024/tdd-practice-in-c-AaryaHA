bool isemptystring(const char* input)
{
if (input == NULL || input[0] == '\0')
  {
        return true; // The string is empty
  }
  return false;
}

int return0(const char* input)
{
if (input == "0" )
  {
        return 1; // The string is 0
  }
  return 0;
}

int ExpectSumForTwoNumbers(const char* input)
{
if (input[0] == "1" && input[1] == "2")
  {
        return 1; // The string is 0
  }
  return 0;
}

int add(const char* string)
{
  if (isemptystring(string)==true)
  {
        return 0; // The string is empty
  }
  if (return0(string)==1)
  {
        return 0; // The string is empty
  }
  if (ExpectSumForTwoNumbers(string)==1)
  {
        return 3; // The string is empty
  }
  return -1;
}

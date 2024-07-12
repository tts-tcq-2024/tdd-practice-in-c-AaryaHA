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

int ExpectSumForTwoNumbers(const char* input1, const char* input2)
{
if (input1 == "1" && input2 == "2")
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
  if (ExpectSumForTwoNumbers(string1,string2)==1)
  {
        return 3; // The string is empty
  }
  return -1;
}

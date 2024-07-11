bool isemptystring(const char* input)
{
if (input == NULL || input[0] == '\0')
  {
        return true; // The string is empty
  }
  return false;
}


int add(const char* string)
{
  if (isemptystring(string)==true)
  {
        return 0; // The string is empty
  }
  return -1;
}

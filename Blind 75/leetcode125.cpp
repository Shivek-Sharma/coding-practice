// Valid Palindrome

// Approach 1 -> Time: O(N), Space: O(N)
bool isPalindrome(string s)
{
  string str;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
    {
      s[i] = (s[i] - 'A') + 'a';
      str.push_back(s[i]);
    }

    else if (s[i] >= 'a' && s[i] <= 'z')
      str.push_back(s[i]);

    else if (s[i] >= '0' && s[i] <= '9')
      str.push_back(s[i]);
  }

  int i = 0, j = str.length() - 1;
  while (i <= j)
  {
    if (str[i] != str[j])
      return false;
    i++;
    j--;
  }
  return true;
}

// Approach 2 -> Time: O(N), Space: O(1)
bool isPalindrome(string s)
{
  int i = 0, j = s.length() - 1;

  while (i < j)
  {
    while (!isalnum(s[i]) && i < j)
      i++;

    while (!isalnum(s[j]) && i < j)
      j--;

    if (tolower(s[i]) != tolower(s[j]))
      return false;

    i++;
    j--;
  }

  return true;
}
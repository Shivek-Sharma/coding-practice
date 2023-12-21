// Valid Parentheses

bool isValid(string s)
{
  // while there is brackets in given string
  //->if open bracket, push to stack
  //->if close bracket and type same as stack top, then pop from stack
  // if stack is still not empty, return false, else return true

  stack<char> st;

  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];

    if (ch == '(' || ch == '[' || ch == '{')
    {
      st.push(ch);
      continue;
    }

    if (!st.empty())
    {
      char top = st.top();

      if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{'))
        st.pop();
      else
        return false;
    }
    else
    {
      return false;
    }
  }

  if (!st.empty())
    return false;
  else
    return true;
}
// Time: O(N), Space: O(N)
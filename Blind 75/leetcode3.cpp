// Longest Substring Without Repeating Characters

// Approach 1 -> Time: O(N) + O(N), Space: O(N)
int lengthOfLongestSubstring(string s)
{
  // apply 2 pointer with i=0 and j=0
  // if s[j] is not present in set, calculate len = j-i+1 and calcualte max, store s[j] in set, and j++
  // else remove s[i] from set and i++, because we want non-repeating characters
  // Note: Each character will be visited by both i and j in the worst case (abcdefghzz)

  unordered_set<char> st;
  int maxi = 0;
  int i = 0, j = 0;

  while (j < s.length())
  {
    if (!st.count(s[j]))
    {
      int len = j - i + 1;
      maxi = max(maxi, len);
      st.insert(s[j]);
      j++;
    }
    else
    {
      st.erase(s[i]);
      i++;
    }
  }

  return maxi;
}

// Approach 2 -> Time: O(N), Space: O(N)
int lengthOfLongestSubstring(string s)
{
  // apply 2 pointer with i=0 and j=0
  // if s[j] is present in map, move i to (map[s[j]] + 1)th position if that value > i
  // store the character s[j] and it's index j in map
  // calculate len = j-i+1 and calculate max

  unordered_map<char, int> m; // character->index
  int maxi = 0;
  int i = 0, j = 0;

  while (j < s.length())
  {
    if (m.count(s[j]))
    {
      i = max(m[s[j]] + 1, i);
    }

    m[s[j]] = j;
    int len = j - i + 1;
    maxi = max(maxi, len);
    j++;
  }

  return maxi;
}
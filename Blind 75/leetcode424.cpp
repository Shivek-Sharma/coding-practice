// Longest Repeating Character Replacement

// Approach 1 -> Time: O(26*N), Space: O(26)
int findMaxFreq(unordered_map<char, int> &m)
{
  int maxi = INT_MIN;
  for (auto it : m)
  {
    if (it.second > maxi)
      maxi = it.second;
  }

  return maxi;
}

int characterReplacement(string s, int k)
{
  // apply 2 pointer with i=0 and j=0
  // maintain a map for storing frequency of characters in current window
  // if length of current window (j-i+1) - count of max occuring char <= k, then current window is valid, calculate max, j++, increase frequency of s[j] in map
  // else decrease frequecy of s[i] in map, i++

  unordered_map<char, int> m;
  int i = 0, j = 0;
  int maxi = 0;

  m[s[i]]++;
  while (j < s.length())
  {
    int windowLen = j - i + 1;
    int maxFreq = findMaxFreq(m); // O(26)

    if (windowLen - maxFreq <= k)
    {
      maxi = max(maxi, windowLen);
      j++;
      m[s[j]]++;
    }
    else
    {
      m[s[i]]--;
      i++;
    }
  }

  return maxi;
}

// Approach 2 -> Time: O(N), Space: O(26)
int characterReplacement(string s, int k)
{
  // No need to create a separate function to calculate count of max occuring character

  unordered_map<char, int> m;
  int i = 0, j = 0;
  int maxi = 0;
  int maxFreq = 0;

  m[s[i]]++;
  while (j < s.length())
  {
    int windowLen = j - i + 1;
    maxFreq = max(maxFreq, m[s[j]]); // we only care about s[j] because it's incrementing and we want max occuring char

    if (windowLen - maxFreq <= k)
    {
      maxi = max(maxi, windowLen);
      j++;
      m[s[j]]++;
    }
    else
    {
      m[s[i]]--;
      i++;
    }
  }

  return maxi;
}
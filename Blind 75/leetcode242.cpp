// Valid Anagram

bool isAnagram(string s, string t)
{
    // 1. add occurrence of chars in map for s
    // 2. remove occurence of chars in map for t
    // 3. loop on map
    // 3.a. if occurrence of a char is not 0, return false
    // 4. return true

    unordered_map<char, int> m;

    for (int i = 0; i < s.length(); i++)
        m[s[i]]++;

    for (int i = 0; i < t.length(); i++)
        m[t[i]]--;

    for (auto it : m)
        if (it.second != 0)
            return false;

    return true;
}
// Time: O(max(N,M)), Space: O(N)
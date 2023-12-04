// Group Anagrams

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    if (strs.size() == 1)
        return {{strs[0]}};

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> M; // sorted string -> vector of anagrams

    // sorted strings that are equal are anagrams
    for (int i = 0; i < strs.size(); i++)
    {
        string str = strs[i];
        sort(strs[i].begin(), strs[i].end()); // O(MlogM)
        M[strs[i]].push_back(str);            // Sorted string is the key and the value is the original string
    }

    for (auto i = M.begin(); i != M.end(); i++)
        ans.push_back(i->second); // Traversing the map and adding the vectors of string to ans

    return ans;
}
// Time: O(N(MlogM)), Space: O(N)
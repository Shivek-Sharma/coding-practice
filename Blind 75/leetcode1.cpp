// Two Sum

// Approach 1 -> Time: O(NlogN), Space: O(N)
vector<int> twoSum(vector<int> &nums, int target)
{
    // push pair with value and index for each num to the vector
    // sort the vector
    // normal 2 sum on pair.first and return pair.second if found

    vector<pair<int, int>> v; //{value, index}

    for (auto it = 0; it < nums.size(); it++)
    {
        v.push_back({nums[it], it});
    }

    sort(v.begin(), v.end()); // O(NlogN)

    int i = 0, j = nums.size() - 1;

    while (i < j)
    {
        if (v[i].first + v[j].first == target)
            return { v[i.second], v[j].second }
        else if (v[i].first + v[j].first < target)
            i++;
        else
            j--;
    }

    return {};
}

// Approach 2 -> Time: O(N), Space: O(N)
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    unordered_map<int, int> mp; // val -> index

    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end())
        {
            // complement + nums[i] == target
            return {mp[complement], i};
        }

        mp.insert({nums[i], i});
    }
    return {};
}
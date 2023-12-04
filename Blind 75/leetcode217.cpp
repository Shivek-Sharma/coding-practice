// Contains Duplicate

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;

        if (m[nums[i]] > 1)
            return true;
    }

    return false;
}
// Time: O(N), Space: O(N)
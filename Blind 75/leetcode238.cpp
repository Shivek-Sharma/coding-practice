// Product of Array Except Self

vector<int> productExceptSelf(vector<int> &nums)
{
    // nums = [1,2,3,4]
    // prefix = [1,1,2,6]
    // postfix = [24,12,4,1]
    // for each i in nums[], ans[i] = prefix[i] * postfix[i]
    // for in-place, calculate prefix products forward, then postfix backwards in a 2nd pass

    int prefix = 1;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(prefix);
        prefix *= nums[i];
    }
    // ans = [1,1,2,6]

    int postfix = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        ans[i] *= postfix;
        postfix *= nums[i];
    }
    // ans = [24,12,8,6]

    return ans;
}
// Time: O(N), Space: O(1)
// 3Sum

// Approach 1 -> Time: O(N*N), Space: O(N) + O(No. of unique triplets)
vector<vector<int>> threeSum(vector<int> &nums)
{
  // for i: 0 to n
  //-> for j: i+1 to n
  //->-> nums[i]+nums[j]+nums[k] = 0 => nums[k] = -(nums[i]+nums[j])
  //->-> maintain a set1 and check if nums[k] exists in it
  //->-> if true, store that triplet, sort it and then store it in a set2 to maintain triplets uniqueness
  //->-> before moving to next j, store nums[j] in set1

  set<vector<int>> st;

  for (int i = 0; i < nums.size(); i++) // O(N*N)
  {
    unordered_set<int> hashset;

    for (int j = i + 1; j < nums.size(); j++) // O(N)
    {
      int third = -(nums[i] + nums[j]);

      if (hashset.count(third))
      { // triplet found
        vector<int> temp = {nums[i], nums[j], third};
        sort(temp.begin(), temp.end()); // O(3log3) ~ O(1)
        st.insert(temp);                // O(log3) ~ O(1)
      }

      hashset.insert(nums[j]); // O(1)
    }
  }

  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// Approach 2 -> Time: O(N*N), Space: O(1)
vector<vector<int>> threeSum(vector<int> &nums)
{
  // sort the given array
  // for i: 0 to n, where nums[i] != nums[i-1] to avoid duplicate triplets
  // -> apply 2 sum with nums[i] for j = i+1 and k = n-1
  // ->-> when the sum becomes 0, store the triplet and keep moving j and k until you reach to a different value to avoid duplicate triplets

  vector<vector<int>> ans;
  sort(nums.begin(), nums.end()); // O(NlogN)

  for (int i = 0; i < nums.size(); i++) // O(N*N)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    int j = i + 1;
    int k = nums.size() - 1;
    while (j < k) // O(N)
    {
      int sum = nums[i] + nums[j] + nums[k];

      if (sum > 0)
      {
        k--;
      }
      else if (sum < 0)
      {
        j++;
      }
      else
      {
        // triplet found
        ans.push_back({nums[i], nums[j], nums[k]});
        j++;
        k--;

        // keep moving until you find a different value
        while (j < k && nums[j] == nums[j - 1])
          j++;
        while (j < k && nums[k] == nums[k + 1])
          k--;
      }
    }
  }

  return ans;
}
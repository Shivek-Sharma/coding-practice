// Longest Consecutive Sequence

// Approach 1 -> Time: O(NlogN), Space: O(N + N)
int longestConsecutive(vector<int> &nums)
{
  // 1. insert all nums in a set to get unique elements in sorted order
  // 2. iterate on set
  // 2.a. if element+1 exists, push that element to the ith row in 2d array
  // 2.b. else i++
  // 3. return the size of longest array

  int n = nums.size();

  set<int> s;
  for (auto it : nums)
    s.insert(it); // O(logN)

  vector<vector<int>> v(n);
  int i = 0;

  for (auto it = s.begin(); it != s.end(); it++)
  {
    int elem = *it;

    if (s.count(elem + 1))
      v[i].push_back(elem);
    else
      i++;
  }

  int maxi = 0;
  for (auto it : v)
  {
    int size = it.size() + 1;
    maxi = max(maxi, size);
  }

  return maxi;
}

// Approach 2 -> Time: O(N), Space: O(N)
int longestConsecutive(vector<int> &nums)
{
  // 1. insert all nums in an unordered set to get unique elements
  // 2. iterate on nums
  // 2.a. if element-1 does not exists in the set, it's the start of a sequence
  // 2.a.i. while consecutive element exists in set, continue the sequence, so count++
  // 2.a.ii. maxi = max(maxi, count)
  // 3. return maxi

  unordered_set<int> s(nums.begin(), nums.end()); // O(N)

  int maxi = 0;

  for (auto it : nums) // O(N)
  {
    if (!s.count(it - 1))
    {
      int count = 1;
      while (s.count(it + count))
        count++;

      maxi = max(maxi, count);
    }
  }

  return maxi;
}
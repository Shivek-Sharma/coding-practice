// Find Minimum in Rotated Sorted Array

int findMin(vector<int> &nums)
{
  // pivot element will be the answer
  // nums = [3,4,5,1,2] -> [[3,4,5],[1,2]]
  // we need to find the first element of second array i.e. pivot using binary search
  // if nums[mid] >= nums[0], mid is in first array, so start = mid+1, because we want to go to second array
  // else, mid is in second array, so end = mid, because we want to stay on the second array

  int s = 0, e = nums.size() - 1;
  if (nums[e] >= nums[s])
    return nums[s];

  while (s < e)
  {
    int mid = s + (e - s) / 2;
    if (nums[mid] >= nums[0])
    {
      s = mid + 1;
    }
    else
    {
      e = mid;
    }
  }

  return nums[s]; // OR return nums[e]
}
// Time: O(logN), Space: O(1)
// Container with Most Water

// Approach 1 -> Time: O(N*N), Space: O(1)
int maxArea(vector<int> &height)
{
  int maxi = INT_MIN;

  for (int i = 0; i < height.size(); i++)
  {
    for (int j = i + 1; j < height.size(); j++)
    {
      int res = min(height[i], height[j]) * (j - i);
      maxi = max(maxi, res);
    }
  }

  return maxi;
}

// Approach 2 -> Time: O(N), Space: O(1)
int maxArea(vector<int> &height)
{
  // apply 2 pointer with i=0 and j=n-1
  // calculate the area and if it's greater than maxArea, store it
  // if height[i] is smaller move i pointer, else move j because we want max area

  int maxi = INT_MIN;
  int curr = 0;

  int i = 0, j = height.size() - 1;
  while (i < j)
  {
    curr = min(height[i], height[j]) * (j - i);
    maxi = max(maxi, curr);

    if (height[i] <= height[j])
      i++;
    else
      j--;
  }
  return maxi;
}
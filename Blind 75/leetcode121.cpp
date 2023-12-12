// Best Time to Buy and Sell Stock

int maxProfit(vector<int> &prices)
{
  // apply 2 pointer with i=0 for buy and j=1 for sell
  // if there is profit, calculate the max profit
  // else move i pointer to jth position, because we want to buy for the minimum price

  int i = 0, j = 1; // i->buy, j->sell
  int maxi = 0;

  while (j < prices.size())
  {
    int profit = prices[j] - prices[i];

    if (profit > 0)
      maxi = max(maxi, profit);
    else
      i = j;

    j++;
  }
  return maxi;
}
// Time: O(N), Space: O(1)
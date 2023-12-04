// Top K Frequent Elements

vector<int> topKFrequent(vector<int> &nums, int k)
{
    // nums: {1,1,1,2,2,3} , k: 2

    unordered_map<int, int> m; // element -> frequency
    for (int i = 0; i < nums.size(); i++)
        m[nums[i]]++;

    // m: {{1,3}, {2,2}, {3,1}}

    // Min Heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto it = m.begin(); it != m.end(); it++) // O(K(logN))
    {
        pq.push({it->second, it->first}); // O(logN)

        if (pq.size() > k)
            pq.pop();
    }

    // pq: {{3,1}, {2,2}}

    vector<int> ans;

    while (!pq.empty()) // O(K(logN))
    {
        int elem = pq.top().second; // O(1)
        ans.push_back(elem);
        pq.pop(); // O(logN)
    }

    return ans;
}
// Time: O(K(logN)), Space: O(N + K)
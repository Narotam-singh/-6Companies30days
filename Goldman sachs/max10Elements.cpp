class Solution
{
public:
    vector<int> kLargest(int arr[], int n)
    {
        // code here
        vector<int> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
            if (pq.size() > 10)
                pq.pop();
        }
        while (pq.size())
        {
            v.push_back(pq.top());
            pq.pop();
        }
        return v;
    }
};
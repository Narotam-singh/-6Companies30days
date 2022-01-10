class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *a, int n, int k)
    {
        // your code here
        deque<int> q;
    vector<int> ans;
    
    for(int i=0;i<k;i++)
    {
        while(!q.empty()&&a[q.back()]<a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);
    for(int i=k;i<n;i++)
    {
        if(q.front()==i-k)
        {
            q.pop_front();
        }
        while(!q.empty()&&a[q.back()]<a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    return ans;
    }
};
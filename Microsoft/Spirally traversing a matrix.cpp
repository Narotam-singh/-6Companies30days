class Solution
{
    {
        public :
            // Function to return a list of integers denoting spiral traversal of matrix.
            vector<int>
                spirallyTraverse(vector<vector<int>> a, int m, int n){
                    // code here
                    vector<int> v;
    if (a.size() == 0)
        return v;

    int i, h = 0, k = 0;
    while (h < m && k < n)
    {
        for (i = k; i < n; ++i)
        {
            v.push_back(a[h][i]);
        }
        h++;
        for (i = h; i < m; ++i)
        {
            v.push_back(a[i][n - 1]);
        }
        n--;
        if (h < m)
        {
            for (i = n - 1; i >= k; --i)
            {
                v.push_back(a[m - 1][i]);
            }
            m--;
        }
        if (k < n)
        {
            for (i = m - 1; i >= h; --i)
            {
                v.push_back(a[i][k]);
            }
            k++;
        }
    }
    return v;
}
}
;
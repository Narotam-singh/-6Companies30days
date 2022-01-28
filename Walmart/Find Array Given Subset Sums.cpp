class Solution
{
    bool traverse(vector<int> &ans, int target, int i)
    {
        if (i == ans.size())
            return target == 0;
        int n = ans[i];
        if (traverse(ans, target, i + 1))
            return true;
        ans[i] = -n;
        if (traverse(ans, target - n, i + 1))
            return true;
        ans[i] = n;
        return false;
    }

public:
    vector<int> recoverArray(int n, vector<int> &A)
    {
        int mn = *min_element(A.begin(), A.end());
        for (int &x : A)
            x += -mn;
        multiset<int> ms(A.begin(), A.end()), temp;
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            temp.clear();
            int num = *next(ms.begin());
            ans.push_back(num);
            while (ms.size())
            {
                int first = *ms.begin();
                temp.insert(first);
                ms.erase(s.begin());
                ms.erase(ms.find(first + num));
            }
            swap(ms, temp);
        }
        traverse(ans, -mn, 0);
        return ans;
    }
};
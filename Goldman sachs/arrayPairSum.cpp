class Solution
{
public:
    bool canPair(vector<int> arr, int k)
    {
        // Code here.
        vector<int> v(k, 0);
        for (int x : arr)
            v[x % k]++;

        if (v[0] % 2 == 1)
            return false;
        int i = 1, j = k - 1;
        while (i < j)
        {
            if (v[i] != v[j])
                return false;
            i++;
            j--;
        }
        if (i == j && v[i] % 2 == 1)
            return false;
        return true;
    }
};
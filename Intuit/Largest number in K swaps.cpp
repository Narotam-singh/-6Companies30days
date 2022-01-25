class Solution
{
public:
    void solve(
        string str, int k,
        string &max, int ctr)
    {

        if (k == 0)
            return;

        int n = str.length();

        char maxm = str[ctr];
        for (int j = ctr + 1; j < n; j++)
        {

            if (maxm < str[j])
                maxm = str[j];
        }

        if (maxm != str[ctr])
            --k;

        for (int j = n - 1; j >= ctr; j--)
        {

            if (str[j] == maxm)
            {

                swap(str[ctr], str[j]);

                if (str.compare(max) > 0)
                    max = str;

                solve(str, k, max, ctr + 1);

                swap(str[ctr], str[j]);
            }
        }
    }
    // Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        // code here.
        string res = str;
        solve(str, k, res, 0);
        return res;
    }
};
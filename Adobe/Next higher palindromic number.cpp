class Solution
{
public:
    string nextPalin(string N)
    {
        // complete the function here
        int n=N.size();
        if (n <= 3)
        return "-1";
        string ans;
        int mid = n/2-1;
        string s = N.substr(0, mid + 1);
        int m = s.length();
        int idx = m;
        for (int i = m - 1; i > 0; i--)
        {
            if (s[i] > s[i - 1])
            {
                idx = i - 1;
                break;
            }
        }
        if (idx == m)
        {
            return "-1";
        }
        for (int i = m - 1; i > 0; i--)
        {
            if (s[i] > s[idx])
            {
                swap(s[i], s[idx]);
                break;
            }
        }
        reverse(s.begin() + idx + 1, s.end());
        ans += s;
        if (n % 2)
        ans += N[N.size() / 2];
        reverse(s.begin(), s.end());
        ans += s;
        return ans;
    }

};
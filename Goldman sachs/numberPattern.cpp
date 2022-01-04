class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        // code here
        int n = s.size();
        vector<int> cd(n, 0);
        int c = 0, d = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'D')
                c++;
            else
                cd[i] = c, c = 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I')
                break;
            else
                d++;
        }
        string ans;
        if (s[0] == 'I')
        {
            ans = "1";
            int max1 = 1, l = 1, h = 1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'I')
                {
                    h = 1;
                    l += 1 + cd[i];
                    max1 = max(max1, l);
                    ans += to_string(max1);
                }
                else
                    ans += to_string(max1 - (h++));
            }
        }
        else
        {
            ans = to_string(d);
            int max1 = d, l = d, h = 1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'I')
                {
                    h = 1;
                    l += 1 + cd[i];
                    max1 = max(max1, l);
                    ans += to_string(max1);
                }
                else
                    ans += to_string(max1 - (h++));
            }
            return ans;
        }
    }
};
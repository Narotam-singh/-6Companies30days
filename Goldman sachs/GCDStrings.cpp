class Solution
{
public:
    int ascii(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans += 65 + (s[i] - 'A');
        }
        return ans;
    }

    string gcdOfStrings(string str1, string str2)
    {
        
        string small, big;
        if (str1.size() >= str2.size())
            big = str1, small = str2;
        else
            big = str2, small = str1;
        for (int i = small.size(); i >= 0; i--)
        {
            string temp = small.substr(0, i);
            int diff = 0;
            for (int j = 0; j < big.size(); j++)
            {
                if (j < i)
                {
                    if (temp[j] != big[j])
                        diff += 65 + (big[j] - 'A');
                }
                else
                    diff += 65 + (big[j] - 'A');
            }
            
            if (ascii(temp) != 0)
            {
                if (diff % ascii(temp) == 0 && ascii(small) % ascii(temp) == 0)
                    return temp;
            }
            else
                return "";
        }
        return "";
    }
};
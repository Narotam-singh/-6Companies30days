class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = nums.size();
        vector<int> prefix = nums;
        for (int i = 1; i < nums.size(); i++)
            prefix[i] += prefix[i - 1];

        if (prefix[ans - 1] < target)
            return 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (prefix[i] >= target)
            {
                ans = min(ans, i + 1);
                for (int j = 0; j < i; j++)
                {
                    if (prefix[i] - prefix[j] >= target)
                        ans = min(ans, i - j);
                    else
                        break;
                }
            }
        }
        return ans;
    }
};
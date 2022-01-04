class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &nums, int n, long long k)
    {
        if (n == 0)
            return 0;
        long long int ans = 0;
        int left = 0;
        long long int pro = 1;
        for (int i = 0; i < n; i++)
        {
            pro *= nums[i];

            while (pro >= k && left < i)
            {
                if (pro != 0)
                    pro /= nums[left++];
                else
                    break;
            }

            if (pro < k)
                ans += (i + 1 - left);
        }
        return ans;
    }
};
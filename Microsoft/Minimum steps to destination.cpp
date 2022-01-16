class Solution
{
public:
    int minSteps(int D)
    {
        // code here

        int sum = 0, ans = 0;

        while (sum < D || (sum - D) % 2 != 0)
        {
            ans++;
            sum += ans;
        }
        return ans;
    }
};
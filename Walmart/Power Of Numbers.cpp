class Solution
{
    int p = 1000000007;

public:
    // You need to complete this fucntion

    long long power(int N, int R)
    {
        // Your code here
        if (R == 0)
        {
            return 1;
        }
        if (R == 1)
        {
            return N;
        }

        long long temp = power(N, R / 2) % p;
        temp = (temp * temp) % p;
        if (R % 2 == 0)
        {
            return (temp) % p;
        }
        if (R % 2 != 0)
        {
            return (N * temp) % p;
        }
    }
};
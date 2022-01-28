class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return dividend == INT_MIN ? INT_MAX : -dividend;
        bool neg = (dividend < 0) ^ (divisor < 0);
        int ctn = 0;
        long long a = abs(dividend);
        long long b = abs(divisor);
        int ct = 1;

        while (b <= a)
        {
            ctn += ct;
            a = a - b;
            b = b << 1;
            ct = ct << 1;
        }
        divisor = abs(divisor);
        while (divisor <= a)
        {
            ctn++;
            a -= divisor;
        }
        return neg ? -ctn : ctn;
    }
};
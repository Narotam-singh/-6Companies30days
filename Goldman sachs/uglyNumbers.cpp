class Solution
{
public:
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n)
    {
        // code here
        ull v[n + 1];
        v[0] = 1;
        ull x(0), y(0), z(0);
        for (int i = 1; i <= n; i++)
        {
            v[i] = min(2 * v[x], min(3 * v[y], 5 * v[z]));
            if (2 * v[x] == v[i])
                x++;
            if (3 * v[y] == v[i])
                y++;
            if (5 * v[z] == v[i])
                z++;
        }
        return v[n - 1];
    }
};
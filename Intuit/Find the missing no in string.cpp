int solve(const string &str, int i, int m)
{
    if (i + m > str.length())
        return -1;

    int num = 0;
    for (int j = 0; j < m; j++)
    {
        int c = str[i + j] - '0';
        if (c < 0 || c > 9)
            return -1;
        num = num * 10 + c;
    }
    return num;
}

int missingNumber(const string &str)
{
    for (int m = 1; m <= 6; m++)
    {

        int n = solve(str, 0, m);
        if (n == -1)
            break;

        int no = -1;

        bool ans = false;

        for (int i = m; i != str.length(); i += 1 + log10l(n))
        {
            if ((no == -1) &&
                (solve(str, i, 1 + log10l(n + 2)) == n + 2))
            {
                no = n + 1;
                n += 2;
            }

            else if (solve(str, i, 1 + log10l(n + 1)) == n + 1)
                n++;

            else
            {
                ans = true;
                break;
            }
        }

        if (!ans)
            return no;
    }

    return -1;
}
class Solution
{
public:
    string decodedString(string s)
    {
        // code here
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ']')
            {
                string t, n;
                while (!st.empty() && st.top() != '[')
                {
                    t = st.top() + t;
                    st.pop();
                }

                st.pop();

                while (!st.empty() && isdigit(st.top()))
                {

                    n = st.top() + n;
                    st.pop();
                }
                int count = stoi(n);
                string rep;
                for (int j = 0; j < count; j++)
                    rep += t;
                for (char c : rep)
                    st.push(c);
            }

            else
                st.push(s[i]);
        }
        string ans;
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
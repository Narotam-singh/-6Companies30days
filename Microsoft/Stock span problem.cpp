class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int> st;
       vector<int> v(n,1);
       st.push(0);
       for(int i=1;i<n;i++)
       {
           if(price[i]<price[st.top()])
           {
               st.push(i);
           }
           else
           {
               int k=0;
               while(!st.empty()&&price[st.top()]<=price[i])
               {
                   //v[i]=i-st.top()+1;
                   st.pop();
               }
               if(st.empty())
               {
                   k=1;
                   st.push(0);
               }
               if(k==1)
               v[i]=i+1;
               else
               v[i]=i-st.top();
               st.push(i);
           }
       }
       return v;
       
    }
};
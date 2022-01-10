class Solution {
public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    int n=A.length();
		    char nrep='#';
		    string ans;
		    vector<int> v(26,0);
		    for(int i=0;i<n;i++)
		    {
		        if(v[A[i]-'a']==0)
		        {
		            if(nrep=='#')
		            nrep=A[i];
		            v[A[i]-'a']++;
		            ans+=nrep;
		            q.push(A[i]);
		        }
		        else
		        {
		            v[A[i]-'a']++;
		            if(nrep!='#')
		            {
		                if(nrep==A[i])
		                {
		                    int k=0;
                            while(!q.empty())
                            {
                                if(v[q.front()-'a']==1)
                                {
                                    k=1;
                                    nrep=q.front();
                                    break;
                                }
                                else
                                {
                                    q.pop();
                                }
                            }
                            if(k==0)
                            nrep='#';
		                }
		            }
		            ans+=nrep;
		        }
		    }
		    return ans;
		}

};
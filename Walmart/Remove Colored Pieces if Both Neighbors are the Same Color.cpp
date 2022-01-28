class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        if(n<=2)
        return false;
        int na=0,nb=0;
        for(int i=1;i<n-1;i++)
        {
            if(colors[i]=='A'&&colors[i-1]=='A'&&colors[i+1]=='A')
                na++;
            else if(colors[i]=='B'&&colors[i-1]=='B'&&colors[i+1]=='B')
                nb++;
        }
        return na>nb;
    }
};
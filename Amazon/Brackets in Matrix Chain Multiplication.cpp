class Solution{
public:
    string st;
    
    void printBrackets(int i, int j, vector<vector<int>> &b, char &res){
    
   
    if(i == j){
        st+=res;
        res++;
    } else {
        st+="(";
        
        
        printBrackets(i, b[i][j], b, res);
        
       
        printBrackets(b[i][j]+1, j, b, res);
        st+=")";
    }
}
    
    string matrixChainOrder(int p[], int n){
        vector<vector<int>> v(n,vector<int>(n,0)),b=v;
    	
    	for (int len = 2; len < n; len++){
    		for (int i = 1; i < n-len+1; i++){
    			int j = i+len-1;
    			m[i][j] = INT_MAX;
    			for (int k = i; k <= j-1; k++){
    				int sum = v[i][k] + v[k+1][j] + p[i-1]*p[k]*p[j];
    				if (sum < v[i][j]){
    					v[i][j] = sum;
    					b[i][j] = k;
    				}
    			}
    		}
    	}
    	char name = 'A';
    	printBrackets(1, n-1, b, name);
    	return st;
    }
};
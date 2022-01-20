#define p pair<int,pair<int,int>>
class Solution{
    public:
    
    
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          priority_queue<p,vector<p>,greater<p>>q;
        
        int min1=INT_MAX,max1=INT_MIN;
        int ans=INT_MAX;
        int st=0,en=0;
        for(int i=0;i<k;i++){
            q.push({arr[i][0],{i,0}});
            min1=min(arr[i][0],min1);
            max1=max(arr[i][0],max1);
            
        }
        
        while(1){
            p temp=q.top();
            q.pop();
            
           int min2=temp.first;
           
            if(ans>max1-min2){
                
                min1=min2;
                st=min1;
                en=max1;
                ans=max1-min1;
                
            }
          int i=temp.second.first;
          int j=temp.second.second;
          
          if(j==n-1)
          break;
          
          q.push({arr[i][j+1],{i,j+1}});
          max1=max(max1,arr[i][j+1]);
 
        }
        return {st,en};
    }
};
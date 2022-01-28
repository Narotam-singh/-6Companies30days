
class Solution {
public:
    
     struct cmp{
        bool operator()(string a,string b){
            if(a.length()!=b.length())return a.length()>b.length();
            return a>b;
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,cmp> pq;
        
        for(int i=0;i<k;i++)
        pq.push(nums[i]);
        for(int i=k;i<nums.size();i++)
        {
            pq.push(nums[i]);
            pq.pop();
        }
        
        return pq.top();
    }
};
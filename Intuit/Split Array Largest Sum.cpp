class Solution {
public:
    bool isValid(vector<int>& nums, int m,int mid){
        int sum=0;
        int s=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                s++;
                sum=nums[i];
            }
            if(s>m){
                return false;
            }
        }
        return s<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int ans=0;
        int low=INT_MIN,high=0;
        for(auto it : nums){
            low=max(low,it);
            high+=it;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isValid(nums,m,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
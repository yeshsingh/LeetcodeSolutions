class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid=0,ans=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]>target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                
                low=mid+1;
            }
            else 
            {
                ans=mid;
                low=high+1;
            }
        }
        if(ans==-1)
        {
            ans=nums.size();
        }
        return ans;
    }
};
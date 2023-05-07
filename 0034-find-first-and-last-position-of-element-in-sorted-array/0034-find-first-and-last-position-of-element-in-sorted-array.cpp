class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int low=0,high=nums.size()-1,mid,l1=-1,l2=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>target)
            {
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else 
            {
                l1=mid;
                high=mid-1;
            }
        }
        low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>target)
            {
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else 
            {
                l2=mid;
                low=mid+1;
            }
        }
        v.push_back(l1);
        v.push_back(l2);
        return v;
    }
};
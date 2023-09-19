class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1,high=nums.size(),mid=0;
        while(low<high)
        {
            int cnt=0;
            mid=low+(high-low)/2;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<=mid)
                {
                    cnt++;
                }
            }
            if(mid<cnt)
            {
                high=mid;
            }
            else 
            {
                low=mid+1;
            }
        }
        return low;
    }
};


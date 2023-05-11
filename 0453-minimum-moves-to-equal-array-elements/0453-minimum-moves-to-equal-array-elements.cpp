class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        sort(nums.begin(),nums.end());
        return sum-(nums[0]*nums.size());
    }
};

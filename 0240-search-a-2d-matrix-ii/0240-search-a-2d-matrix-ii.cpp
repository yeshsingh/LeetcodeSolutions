class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low;
        int high;
        for(low=0,high=matrix[0].size()-1;low<=high;)
        {
            int mid=low+(high-low)/2;
            if(matrix[0][mid]<target)
            {
                low=mid+1;
            }
            else if(matrix[0][mid]>target)
            {
                high=mid-1;
            }
            else 
            {
                return true;
            }
        }
        int row=high;
        
        if(row>=0)
        {
            for(int i=0;i<=row;i++)
            {
                for(low=0,high=matrix.size()-1;low<=high;)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid][i]<target)
            {
                low=mid+1;
            }
            else if(matrix[mid][i]>target)
            {
                high=mid-1;
            }
            else 
            {
                return true;
            }
        }
            }
            
        }
        return false;
    }
};
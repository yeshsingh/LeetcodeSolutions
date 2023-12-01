class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int low;
        int high;
        for(low=0,high=matrix.size()-1;low<=high;)
        {
            int mid=(high+low)/2;
            if(matrix[mid][0]<target)
            {
                low=mid+1;
            }
            else if(matrix[mid][0]>target)
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
            for(low=0,high=matrix[row].size()-1;low<=high;)
            {
                int mid=(high+low)/2;
            if(matrix[row][mid]<target)
            {
                low=mid+1;
            }
            else if(matrix[row][mid]>target)
            {
                high=mid-1;
            }
            else 
            { 
                return true;
            }
            }
        
    }
        return false;
    }
};
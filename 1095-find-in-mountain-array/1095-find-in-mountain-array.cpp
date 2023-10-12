/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low=0,high= mountainArr.length(),mid=0,h1;
        int z=high;
        while(low<high)
        {
            mid=low+(high-low)/2;
            int i=mountainArr.get(mid),i1,i2;
            if(0<=mid-1)
            {
                
                i1=mountainArr.get(mid-1);
            }
            if(mid+1<z)
            {
                i2=mountainArr.get((mid+1));
            }
            if(i1<i && i2<i)
            {
                h1=mid;
                low=high+1;
            }
            else if(i1<i && i<i2)
            {
                low=mid;
            }
            else if(i1>i && i>i2)
            {
                high=mid;
            }
            
        }
        low=0,high=h1,mid=0;
        int ans1=-1,ans2=-1,ans=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            int i=mountainArr.get(mid);
            if(i==target)
            {
                ans1=mid;
                low=high+1;
            }
            else if(i<target)
            {
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
            
        }
        low=h1,high=z,mid=0;
        while(low<high)
        {
            mid=low+(high-low)/2;
            int i=mountainArr.get(mid);
            if(i==target)
            {
                ans2=mid;
                low=high;
            }
            else if(i<target)
            {
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
            
        }
        if(ans1!=-1 && ans2!=-1)
        {
            if(ans1<ans2)
            {
                ans=ans1;
            }
            else 
            {
                ans=ans2;
            }
        }
        else if(ans1!=-1)
        {
            ans=ans1;
        }
        else if(ans2!=-1)
        {
            ans=ans2;
        }
        return ans;
    }
};
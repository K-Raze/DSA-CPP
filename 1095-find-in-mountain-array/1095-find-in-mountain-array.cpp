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
    int findInMountainArray(int target, MountainArray &marr) {
        
        int n=marr.length();
        int pk=-1;
        // find peak
        {
            int start=1,end=n-2;
            while(start<=end)
            {
                int mid=start+((end-start)>>1);
                int ele=marr.get(mid);
                int l=ele>marr.get(mid-1);
                int r=ele>marr.get(mid+1);
                if(l && r)
                {
                    if(ele==target)
                        return mid;
                    pk=mid;
                    break;
                }
                else if(l)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }

        // left area check
        {
            int start=0,end=pk-1;
            while(start<=end)
            {
                int mid=start+((end-start)>>1);
                int ele=marr.get(mid);
                if(ele==target)
                    return mid;
                else if(ele<target)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }

        // right area check
        {
            int start=pk+1,end=n-1;
            while(start<=end)
            {
                int mid=start+((end-start)>>1);
                int ele=marr.get(mid);
                if(ele==target)
                    return mid;
                else if(ele<target)
                    end=mid-1;
                else
                    start=mid+1;
            }
        }
        return -1;
    }
};
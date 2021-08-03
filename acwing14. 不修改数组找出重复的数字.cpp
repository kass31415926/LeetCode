14. 不修改数组找出重复的数字

给定一个长度为 n+1 的数组nums，数组中所有的数均在 1∼n 的范围内，其中 n≥1。

请找出数组中任意一个重复的数，但不能修改输入的数组。

class Solution {
public:
    int duplicateInArray(vector<int>& nums) 
    {
        int l=1,r=nums.size()-1;  
        while(l<r)
        {
            int mid=l+r>>1;
            int s=0;
            for(auto x:nums)s+=x>=l&&x<=mid;
            if(s>mid-l+1)r=mid;
            else l=mid+1;
        }
        return r;
    }
};
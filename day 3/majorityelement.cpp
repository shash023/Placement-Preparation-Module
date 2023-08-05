class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el=nums[0];
        int c=0;
        for(int i =0; i < nums.size();i++)
        {
            if(el==nums[i])
                c++;
            else
                c--;
            if(c==0)
                el=nums[i+1];
        }
        return el;
    }
};

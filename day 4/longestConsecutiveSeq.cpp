class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i =0; i <nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int max=0;
        int ans=0;
        for(int i =0; i < nums.size(); i++)
        {
            int x=nums[i];
            ans=0;
            if(m[nums[i]-1]==0)
            {
                while(m[x++]>0)
                {
                    ans++;
                }
            }
            if(max<ans)
            {
                max=ans;
            }
        }
        return max;
    }
};

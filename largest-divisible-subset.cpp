class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        sort(nums.begin(),nums.end());
        dp[n-1]=1;
        int mx=1;
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=1;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]%nums[i]==0)
                {
                dp[i]=max(dp[i],1+dp[j]);
                mx=max(mx,dp[i]);
                }
            }
        }
        vector<int>ans;
        int i=0,nm;
        while(i<n)
        {
            if(dp[i]==mx)
            {
                ans.push_back(nums[i]);
                nm=nums[i];
                mx--;
                i++;
                break;
            }
            i++;
        }
        while(i<n)
        {
            if(dp[i]==mx && nums[i]%nm==0)
            {
                ans.push_back(nums[i]);
                nm=nums[i];
                mx--;
            }
            i++;
        }
        return ans;
    }
};
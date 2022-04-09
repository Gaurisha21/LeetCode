class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        // two pointer approach 
		
        long long mod=1e9+7;
		
        int n=nums.size();
		
        int ans=0;
		
        long long sum;
		
        for(int i=0;i<n-2;i++)
        {
            int l=i+1;
			
            int r=n-1;
            
            while(l<r)
            {
                sum=nums[l]+nums[i]+nums[r];
             
                if(sum==target)
                {
                      int count1=1;
                      int count2=1;
                    while(l<r && nums[l]==nums[l+1])
                    {
                        l++;
                        count1++;
                    }
                    
                    while(l<r && nums[r]==nums[r-1])
                    {
                        r--;
                        count2++;
                    }
                                           
                    if(l==r)         
                    {                                  
                        ans = (ans%mod + (count1%mod *(count1-1)%mod)/2)%mod;
                    }
                    
                    if(l!=r)
                    {
                        ans = (ans%mod + (count1%mod* count2%mod)%mod)%mod;	 
                    }
                    
                    l++;
                    r--;
                }
                else
                {
                    if(sum>target)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }
        
        return ans;
        
    }
};
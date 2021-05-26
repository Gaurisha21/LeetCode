class Solution {
public:
   int totalFruit(vector<int>& tree) {
        int s=0, e=0, count=0, n=tree.size(), ans=0;
        vector<int> freq(40001,0);
        while(e<n)
        {
            if(freq[tree[e++]]++==0) count++;
            while(count>2)
                if(freq[tree[s++]]--==1) count--;
            ans = max( ans, e-s);
        }
        return ans;
    }
};
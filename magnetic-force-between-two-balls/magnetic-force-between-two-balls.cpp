class Solution {
public:
    bool canplace(vector<int>& position, int n, int m, int mid)
    {
        int last= position[0], cp=1;
        for(int i=1; i<n; i++)
        {
            if(position[i]-last>=mid)
            {
                last = position[i];
                cp++;
                if(cp==m)
                    return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(), ans;
        sort(position.begin(), position.end());
        int s=0, e=position[n-1]-position[0];
        while(s<=e)
        {
            int mid=(s+e)/2;
            bool placed = canplace(position, n, m, mid);
            if(placed)
            {
                ans = mid;
                s = mid+1;
            }
            else
                e = mid-1;
        }
        return ans;
    }
};
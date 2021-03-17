class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int flag=0, flag1=0, i;
        bool ans;
        for(i=0; i<arr.size()-1;i++)
        {
            if(arr[i]<arr[i+1])
                flag=1;
            else 
                break;
        }
        for(int j=i; j<arr.size()-1; j++)
        {
            if(arr[j]>arr[j+1])
                flag1=1;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1 and flag1==1)
            ans = true;
        else
            ans = false;
        return ans;        
    }
};
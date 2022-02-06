class Solution {
public:
    vector<int> merge2sortedArr(vector<int> a, vector<int> b)
    {
        int n=a.size(), m=b.size();
        vector<int> ans;
        int i=0, j=0, k=0;
        while(i<n and j<m)
        {
            if(a[i]<b[j])
            {
                ans.push_back(a[i]);
                i++;
            }
            else
            {
                ans.push_back(b[j]);
                j++;
            }
            // k++;
        }
        while(i<n)
        {
            ans.push_back(a[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }

    vector<int> mergeSort(vector<int> &arr, int s, int e)
    {
        if(s==e) return {arr[s]};
        int mid = s+((e-s)/2);
        vector<int> arr1 = mergeSort(arr, s, mid);
        vector<int> arr2 = mergeSort(arr, mid+1,e);
        vector<int> ans = merge2sortedArr(arr1,arr2);
        return ans;

    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums, 0, n-1);
    }
};
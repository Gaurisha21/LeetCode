class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int pt=-1, it=0;
        while(it!=A.size())
        {
            if(A[it]%2==1) it++;
            else
            {
                pt++;
                swap(A[pt], A[it]);
                it++;
            }
        }
       return A; 
    }
};
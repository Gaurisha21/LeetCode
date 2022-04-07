class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        if(s.size()==1) return s[0];
        sort(s.begin(), s.end());
        while(s.size()>1)
        {
            int i=s.size()-1;
            int x=s[i-1], y=s[i];
            if(x==y)
            {
                s.pop_back();
                s.pop_back();
            }
            else if(x!=y)
            {
                s.pop_back();
                s.pop_back();
                s.push_back(y-x);
            }
            sort(s.begin(),s.end());
        }
        if(s.size()==0) return 0;
        return s[0];
    }
};
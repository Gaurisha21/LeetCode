class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freqInStc(128,0);
        vector<bool> freqInAns(128,false);
        stack<int> st;
        int n=s.length();
        string ans = "";
        
        for(int i=0; i<n; i++)
            freqInStc[s[i]]++;
        
        for(int i=0; i<n; i++)
        {
            freqInStc[s[i]]--;
            if(freqInAns[s[i]]==true) 
                continue;
            while(!st.empty() and st.top()>s[i] and freqInStc[st.top()]>0 )
            {
                freqInAns[st.top()]=false;
                st.pop();
            }
            st.push(s[i]);
            freqInAns[s[i]]=true;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
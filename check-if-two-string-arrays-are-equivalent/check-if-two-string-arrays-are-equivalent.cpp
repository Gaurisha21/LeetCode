class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1, w2;
        for(int i=0; i<word1.size(); i++)
        {
            w1.append(word1[i]);
        }
        for(int i=0; i<word2.size(); i++)
        {
            w2.append(word2[i]);
        }
        if(w1 == w2)
            return true;
        else 
            return false;
    }
};
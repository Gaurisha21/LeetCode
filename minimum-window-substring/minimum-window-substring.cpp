class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.length(), nt = t.length();
        if (ns < nt)
            return "";
        vector<int>freq(128,0);
        for (int i = 0; i < nt; i++)
            freq[t[i]]++;

        int si = 0, ei = 0, count = nt, len = (int) 1e9, gsi = 0;
        while (ei < ns) {
            if (freq[s[ei]] > 0)
                count--;
            freq[s[ei]]--;
            ei++;

            while (count == 0) {
                if (ei - si < len) {
                    len = ei - si;
                    gsi = si;
                }

                if (freq[s[si]] == 0)
                    count++;
                freq[s[si]]++;
                si++;
            }
        }

        return len == (int) 1e9 ? "" : s.substr(gsi, len);
    }
};
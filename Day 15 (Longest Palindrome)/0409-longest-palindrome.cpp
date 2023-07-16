class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(char i:s)
            mp[i]++;
        int cnt = 0;
        bool flag = false;
        for(auto it:mp){
            if(it.second % 2){
                flag = true;
                cnt += (it.second - 1);
            }
            else
                cnt += it.second;
        }
        if(flag)
            cnt++;
        return cnt;
    }
};

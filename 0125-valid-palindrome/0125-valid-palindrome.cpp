class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        vector<char> arr;
        for(char i:s)
            if((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
                arr.push_back(i);
        for(int i = 0, j = arr.size() - 1; i < j; i++, j--)
            if(arr[i] != arr[j])
                return false;
        return true;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        if(a.length() < b.length())
            swap(a,b);
        while(a.length() != b.length())
            b += '0';
        string ans;
        bool flag = false;
        for(int i = 0; i < a.length(); i++){
            if(flag){
                if(a[i] == b[i]){
                    if(a[i] == '0') 
                        flag = false;
                    ans += '1';
                }
                else
                    ans += '0';
            }
            else{
                if(a[i] == b[i]){
                    if(a[i] == '1')
                        ans += '0', flag = true;
                    else
                        ans += '0';
                }
                else
                    ans += '1';
            }
        }
        if(flag)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
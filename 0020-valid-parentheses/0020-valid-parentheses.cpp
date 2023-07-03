class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char i:s){
            if(i == '(' || i == '{' || i == '[')
                st.push(i);     // pushing the opening chracters into stack
            else{
                if(st.empty())
                    return false;
                char x = st.top();  // checking top of the stack & current i form a pair or nor
                if((x == '(' && i != ')') || (x == '{' && i != '}') || (x == '[' && i != ']'))
                    break;
                st.pop();
            }
        }
        return st.empty();
    }
};
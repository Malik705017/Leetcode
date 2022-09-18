// https://leetcode.com/problems/decode-string/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(const string& str)
    {
        for (char const &c : str) {
            if (std::isdigit(c) == 0) return false;
        }
        return true;
    }
    
    string decodeString(string s) {
        stack<string> st;
        string res;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ']') {
                st.push(string(1, s[i]));
            } else {
                string sub_s;
                while(st.top() != "[") {
                    sub_s.insert(0, st.top());
                    st.pop();
                }
                
                st.pop(); // remove [
                string num_s;
                
                while( !st.empty() && isdigit(st.top()[0])) {
                    num_s.insert(0, st.top());
                    st.pop(); // remove number
                }
                
                int num = stoi(num_s); // get repeated num;
                
                for(int i = 0; i < num; i++) {
                    st.push(sub_s);
                }
            }
        }
        while(!st.empty()) {
            string cur_s = st.top();
            res.insert(0, cur_s); 
            st.pop();
        }
        return res;
    }
};
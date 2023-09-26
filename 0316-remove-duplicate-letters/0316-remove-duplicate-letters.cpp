class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.length();i++) 
            m[s[i]] = i;
        unordered_set<char>st;
        stack<char>stk; 
        for (int i = 0; i < s.length(); i++) 
        {
            char c = s[i];
            if(st.find(c) != st.end()) continue;
            while(!stk.empty() && stk.top()>c && i<m[stk.top()]) 
            {
                char popped = stk.top();
                stk.pop();
                st.erase(popped);
            }
            stk.push(c);
            st.insert(c);
        }
        string result;
        while(!stk.empty()) 
        {
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};
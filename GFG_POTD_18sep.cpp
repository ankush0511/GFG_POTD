bool ispar(string s)
    {
        // Your code here
        stack<char>st;
forint i=0; i<s.size(); i++) {
    if(s[i]=='{'||s[i]=='['||s[i]=='(')
        st.push(s[i]);
    else {
        if((!st.empty())&&st.top()=='('&&s[i]==')') {
            st.pop();
        }
        if((!st.empty())/&&st.top()=='['&&s[i]==']') {
            st.pop();
        }
        if((!st.empty())&&st.top()=='{'&&s[i]=='}') {
            st.pop();
        }
    }
}
return st.empty() ?  1:0;
        
    }
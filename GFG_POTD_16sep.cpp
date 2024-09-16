/*
***Time Complexity =>O(N)
Space Complexity =>O(1)

***
*/
int mx1=0;
int n=str.size();
int first=0,sec=0;
for(int i=0; i<n; i++) {
    if(str[i]=='(')
        first++;
    else
        sec++;
    if(sec>first)
        first=sec=0;

    if(first==sec)mx1=max(mx1,sec*2);
}
int mx2=0;
first=sec=0;
for(int i=n-1; i>=0; i--) {
    if(str[i]=='(')first++;
    else sec++;
    if(first>sec)first=sec=0;
    if(first==sec)mx2=max(mx2, first*2);

}
return max(mx1,mx2);


/*[APPROACH 2]
Time complexity =O(N)
Space Complexity =O(N)
*/
stack<int>st;
st.push(-1);
int n=str.size();
int ans=0;
for(int i=0; i<n; i++)
{
    if(str[i]=='(')
        st.push(i);
    else {
        if(!st.empty())
            st.pop();


        if(!st.empty())
            ans=max(ans,i-st.top());
        else
            st.push(i);
    }
}
return ans;





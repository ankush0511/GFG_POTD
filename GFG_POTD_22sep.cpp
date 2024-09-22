int n=str.size();
vector<int>lps(n,0);
int pre=0,suf=1;
while(suf<n) {
    if(str[pre]==str[suf]) {
        lps[suf]=pre+1;
        pre++;
        suf++;
    }
    else {
        if(pre==0) {
            lps[suf]=0;
            suf++;
        } else {
            pre--;
            pre=lps[pre];
        }
    }
}
return lps[str.size()-1];






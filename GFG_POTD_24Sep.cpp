string smallestWindow (string s, string p)
    {
        // Your code here
        int minlen=INT_MAX;
int l=0,r=0;
int sidx=-1;
vector<int>mp(256,0);
int m=s.size(),n=p.size();
for(int i=0; i<n; i++) {
    mp[p[i]]++;
}
int count=0;
while(r<m) {
    if(mp[s[r]]>0)count++;
    mp[s[r]]--;

    while(count==n) {
        if(r-l+1<minlen) {
            minlen=r-l+1;
            sidx=l;
        }
        mp[s[l]]++;
        if(mp[s[l]]>0)
            count--;
        l++;
    }
    r++;
}

return sidx==-1 ? "-1":s.substr(sidx,minlen);

    }
};

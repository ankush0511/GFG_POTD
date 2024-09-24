

int n=arr.size();
vector<int>temp(n,0);
vector<int>ans;
for(int i=0; i<n; i++) {
    temp[arr[i]-q]++;
}
//repeating
for(int i=0; i<n; i++) {
    if(temp[i]==2)
        ans.push_back(i+1);
}
//missii
for(int i=0; i<n; i++) {
    if(temp[i]==0)
        ans.push_back(i+1);
}
return ans;

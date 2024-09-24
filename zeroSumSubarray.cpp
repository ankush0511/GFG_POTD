
unordered_map<long long int,long long int>m;
m[0]=1;
long long int total=0;
long long int ans=0;
for(int i=0; i<n; i++) {
    ans+=arr[i];
    if(m[ans]) {
        total+=m[ans];
        m[ans]++;
    } else {
        m[ans]=1;
    }
}
return total;






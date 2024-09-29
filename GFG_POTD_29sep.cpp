APPROACH 1:
int count=0;
int n=arr.size();
for(int i=0; i<n; i++) {
    int x=arr[i];
    if(x==0) count++;
    if(x!=k)
    {
        while(x!=0) {
            count++;
            x-=k;
            if(x<0)
                break;
        }
    } else {
        count++;
    }
}
return count;

APPROACH 2:

int n=arr.size();
int count=0;
for(int i=0; i<n; i++) {

    if(arr[i]%k==0) {
        count+=arr[i]/k;
    }
    else
        count+=(arr[i]/k)+1;
}
return count;







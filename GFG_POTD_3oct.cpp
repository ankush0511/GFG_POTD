/*

APPROACH 1
TIME COMPLEXITY =O(n)
SPACE COMPLEXITY =O(n)
*/
int n=arr.size();
int maxi=INT_MIN;
for(int i=0; i<n; i++) {

    maxi=max(maxi,arr[i]--);
}
vector<int>temp(maxi,0);
for(int i=0; i<n; i++) {
    temp[arr[i]]++;
}
vector<int>ans;
for(int i=0; i<n; i++) {
    if(temp[arr[i]]>n/3) {
        ans.push_back(arr[i]+1);
        temp[arr[i]]=0;
    }
}
return ans.empty() ? vector<int> {-1}:
       ans;

/*
APPROACH 2
TIME COMPLEXITY =O(n)
  SPACE COMPLEXITY=O(1)
*/

vector<int> findMajority(vector<int>& arr) {
    // Your code goes here.
    int n=arr.size();
    int ele1=arr[0],ele2=arr[0],c1=0,c2=0;
    for(int i=0; i<n; i++) {

        if(arr[i]==ele1) {
            c1++;
        }
        else if(arr[i]==ele2)
            c2++;
        else if (c1 == 0) {
            ele1 = arr[i];
            c1 = 1;
        }
        else if (c2 == 0) {
            ele2 = arr[i];
            c2 = 1;
        }
        else {
            c1--;
            c2--;
        }

    }
    c1=0,c2=0;
    vector<int>ans;
    for(int i=0; i<n; i++) {
        if(arr[i]==ele1)c1++;
        else if(arr[i]==ele2)c2++;
    }
    if(c1>n/3)ans.push_back(ele1);
    if(c2>n/3)ans.push_back(ele2);
    return ans.empty() ? vector<int> {-1}:
           ans;
}
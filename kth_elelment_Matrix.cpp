int kthSmallest(int arr[MAX][MAX], int n, int k)
{
  //Your code here
  vector<pair<int,pair<int,int>>>temp;
for(int i=0; i<n; i++) {
    temp.push_back(make_pair(arr[i][0],make_pair(i,0)));
}
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(temp.begin(),temp.end());
                                    int ans;
pair<int,pair<int,int>>element;
int i,j;
while(k--)
{
    element=pq.top();
    pq.pop();
    ans=element.first;
    i=element.second.first;
    j=element.second.second;
    if(j+1<n)
        pq.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
}


return ans;
}

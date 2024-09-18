 vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        vector<pair<int,pair<int,int>>>temp;
for(int i=0; i<k; i++) {
    temp.push_back(make_pair(arr[i][0],make_pair(i,0)));
}
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(temp.begin(),temp.end());
                                    vector<int>ans;
pair<int,pair<int,int>>element;
int i,j;
while(!pq.empty())
{
    element=pq.top();
    pq.pop();
    ans.push_back(element.first);
    i=element.second.first;
    j=element.second.second;
    if(j+1<k)
        pq.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
}


return ans;
    }

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

    vector<int>ans;
    int temp=0;
    for(int i=0; i<queries.size(); i++)
    {
        int x=queries[i][0];
        int y=queries[i][1];

        for(int k=x; k<=y; k++) {
            temp^=arr[k];
        }
        ans.push_back(temp);
        temp=0;
    }
    return ans;
}

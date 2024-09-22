queue<int>q;
vector<bool>visited(v,0);
q.push(0);
visited[0]=1;
vector<int>ans;
int node;
while(!q.empty())
{   node=q.front();
    q.pop();
    ans.push_back(node);
    for(int i=0; i<adj[node].size(); i++) {
        if(!visited[adj[node][i]]) {
            visited[adj[node][i]]=1;
            q.push(adj[node][i]);
        }
    }
}
return ans;


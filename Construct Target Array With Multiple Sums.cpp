priority_queue<long long>pq;
long long sum=0;
for(int i=0; i<targe.size(); i++)
{
    pq.push(target[i]);
    sum+=target[i];
}
int maxele,remsum,ele;
while(pq.top()!=1) {
    maxele=pq.top();
    pq.pop();
    remsum=sum-maxele;
    if(remsum<=0||remsum>=maxele)
        return 0;
    ele=maxele%remsum;
    if(ele==0)
        if(remsum!=1)
            return 0;
        else
            return 1;
    sum=remsum+ele;
    pq.push(ele);

}
return sum;

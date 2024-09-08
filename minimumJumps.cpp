#include <iostream>
using namespace std;

    int minJumps(vector<int>& arr) {
        // Your code here
        if(!arr[0])return -1;
        int mx=0,jump=arr[0],ans=1;
        
        for(int i=1;i<arr.size();i++){
            mx--;
            jump--;
            mx=max(mx,arr[i]);
            
            if(!jump && i!=arr.size()-1){
                if(mx<=0) return -1;
                jump=mx;
                mx=0;
                ans++;
            }
        }
        return ans;
        

int main(){
vector<int>& arr;
arr[4]={2,0,0,0};
minJumps(arr);

}
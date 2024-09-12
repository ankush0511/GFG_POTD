#include<iostream>
using namespace std;
class maxheap{
    int * arr;
    int size;//total element of heap
    int total_size;//total size of array
    public:
    maxheap(int n){
        arr=new int(n);
        size=0;
        total_size=n;
    }
    //insertion a node
    void insert(int value){
        //check heap size is aviable or nor
        if(size==total_size){
            cout<<"overflow "<<endl;
            return;
        }
        arr[size]=value;
        int index=size;
        size++;
        //compare the value to check the max heap property
        while(index>0&&arr[(index-1)/2]<arr[index]){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
        cout<<arr[index]<<" inserted into the queue "<<endl;
    }

    void print(){
        for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;
    }
    void heapify(int idx){
        int large=idx;
        int left=2*idx+1;
        int right=2*idx+2;
        if(left<size&&arr[left]>arr[large]){
            large=left;
        }
        if(right<size&&arr[right]>arr[large]){
            large=right;
        }
        if(large!=idx){
            swap(arr[idx],arr[large]);
            heapify(large);
        }
    }
    void Delete(){
        if(size==0){
            cout<<"under flow "<<endl;
            return;
        }
        cout<<arr[0]<<"deleted from the heap"<<endl;
        arr[0]=arr[size-1];
        size--;
        if(size==0)
        return;
        heapify(0);
    }
};
int main()
{
    maxheap h(6);
    h.insert(5);
    h.insert(53);
    h.insert(1);
    h.insert(98);
    h.insert(51);
    h.insert(590);
    h.print();
    h.Delete();
    h.insert(5);
    h.print();
} 

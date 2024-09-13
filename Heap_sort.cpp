/ in increasing order when heapSort() is called.

class Solution
{
public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        // Your Code Here
        int lar=i;
        //acces the left children 2*i+1 for right child ..+2
        int left=2*i+1;
        int right=2*i+2;
        if(left<n&&arr[left]>arr[lar])
            lar=left;
        if(right<n&&arr[right]>arr[lar])
            lar=right;

        if(lar!=i) {
            swap(arr[lar],arr[i]);
            heapify(arr,n,lar);
        }
    }

public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // step down approach hai ise liye n/2-1
        //n/2-1->n ke middle mai the is no node that have child i.e they are children
        for(int i=n/2-1; i>=0; i--)
            heapify(arr,n,i);
    }
public:
//create a function that will sort the array in increasing order
    void sortar(int arr[],int n) {
        //n-1=>after swaping last wala will be always in soted
        for(int i=n-1; i>0; i--) {
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
        }
    }

public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        //build karo maxheap tree
        buildHeap(arr,n);
        //after max heap we have to sort the array i.e heap but array
        sortar(arr,n);
    }
};





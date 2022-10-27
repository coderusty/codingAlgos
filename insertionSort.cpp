//insertion sort iterative
//time complexity O(n^2)
//space complexity 1
//application playing cards, arranging clothes in wardrobe
//passes n-1

#include<bits/stdc++.h>
using namespace std;
void insertionSort(int a[],int n){
    //sorting while inserting any element
    //considering first element to be always sorted
    for(int j=1;j<n;j++){
        int i=j-1;
        int key=a[j];
        while(i>=0 && a[i]>key){
              a[i+1]=a[i];
               i-=1;

        }
        a[i+1]=key;
    }
    for(int i=0;i<n;i++) cout<<"Element A["<<i<<"]: "<<a[i]<<endl;
}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    insertionSort(a,n);
    return 0;
}

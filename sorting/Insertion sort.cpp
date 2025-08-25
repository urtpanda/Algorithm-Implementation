/*insertion sort*******/

#include <iostream>
using namespace std;


int main() {
    int n,i,key,j;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    for ( i = 1; i <= n; i++) {
        cin >> arr[i];
    }
   for ( i = 2; i <= n; i++) {
       key=arr[i];
       j=i-1;
       while(j>0 && arr[j]>key){
           arr[j+1]=arr[j];
           j--;
       }
       arr[j+1]=key;
        
}
cout<<"The Sorted Array is:";
for ( i = 1; i <= n; i++) {
        cout<<" "<< arr[i];}

    return 0;
}

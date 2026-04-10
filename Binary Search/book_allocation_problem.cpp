#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages){
    int n=arr.size();
    int students=1;
    int pageCount=0;
    for(int i=0;i<n;i++){
        if(pageCount+arr[i]>pages){
            students++;
            pageCount=arr[i];
        }
        else{
            pageCount+=arr[i];
        }
    }
    return students;
}
int findPages(vector<int> &arr, int m) {
    int n=arr.size();
    if(m>n) return -1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int low=*max_element(arr.begin(),arr.end());
    int high=sum;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(countStudents(arr,mid)<=m){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={12,34,67,90};
    int m=2;
    cout<<findPages(arr,m)<<endl;
    return 0;
}
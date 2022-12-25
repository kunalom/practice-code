#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e){
  int mid=s+(e-s)/2;
  int len1=mid-s+1;
  int len2=e-mid;

  int *a = new int[len1];
  int *b=new int[len2];
  //int ar[len1+len2];
  int k=s;

  for(int i=0; i<len1; i++){
    a[i]=arr[k++];
  }
  k=mid+1;
  for(int i=0; i<len2; i++){
    b[i]=arr[k++];
  }


  int i=0;
  int j=0;
  k=s;

  while((i<len1) && (j<len2)){
    if(a[i]<b[j]){
      arr[k++]=a[i++];
    }
    else{
      arr[k++]=b[j++];
    }
  }
  
  while(i<len1){
    arr[k++]=a[i++];
  }
  while(j<len2){
    arr[k++]=b[j++];
  }
  
  delete []a;
  delete []b;
}

void mergesort(int arr[], int s, int e){
  if(s>=e){
    return;
  }
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
  

}

int main(){
  
  int arr[5]={5,3,8,2,4};
  mergesort(arr,0,4);

  for(int i=0; i<=4; i++){
    cout<<arr[i]<<' ';
  }
  cout<<endl;

  return 0;
}

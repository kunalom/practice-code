#include<iostream>
using namespace std;

long long count(int arr[], int s, int mid, int e){
  long long inv=0;
  int len1=mid+1-s;
  int len2=e-mid;

  int *a=new int[len1];
  int *b=new int[len2];

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
    if(a[i]<=b[j]){
      arr[k++]=a[i++];
    }
    else{
      arr[k++]=b[j++];
      inv+=len1-i;
    }
  }

  while(i<len1){
    arr[k++]=a[i++];
  }

  while(j<len2){
    arr[k++]=b[j++];
  }
  return inv;
  delete []a;
  delete []b;

}


long long mergesort(int arr[], int s, int e){
  long long inv=0;
  if(s>=e){
    return 0;
  }
  
  int mid=s+(e-s)/2;
  inv+=mergesort(arr,s,mid);
  inv+=mergesort(arr,mid+1,e);
  inv+=count(arr,s,mid,e);
  
  return inv;
}
int main(){
  int arr[8]={3,5,6,9,1,2,7,8};
  cout<<mergesort(arr,0,7);
  return 0;
}

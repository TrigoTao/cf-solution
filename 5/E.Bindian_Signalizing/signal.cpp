#include<cstdio>
#include<iostream>

using namespace std;

#define MAXN 1000001

int h[MAXN]={0},l[MAXN]={0},r[MAXN]={0},c[MAXN]={0};
int n;

void rotate(int offset){
  int tmp[MAXN];
  for(int i=0; i<n; i++){
    tmp[i] = h[i];
  } 
  for(int i=0; i<n; i++){
    h[i] = tmp[(i+offset)%n];
  }
  h[n] = h[0];
}

void calInfo(){
  int i;

  l[0] = n;
  for(i=1; i<n ; i++){
    l[i] = i-1;
    while(h[i]>h[l[i]])
      l[i] = l[l[i]];
    if(h[i] == h[l[i]]){
      c[i] = c[l[i]]+1;
      l[i] = l[l[i]];
    }
  }

  r[n] = n;
  for(i=n-1; i>=0; i--){
    r[i] = i+1;
    while(h[i]>h[r[i]])
      r[i] = r[r[i]];
    if(h[i] == h[r[i]]){
      r[i] = r[r[i]];
    }
  }
}

long long getRes(){
  long long res =0;

  for(int i=1; i<n; i++){
    if(h[i] < h[0]){
      if(l[i] == 0 && r[i] == n){
        res ++;
      }else
        res += 2;
    }
    res += c[i];
    //cout<< c[i]<<"\t";
  }

  return res;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  int max=0,maxp;
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> h[i];
    if(h[i]>max){
      max = h[i];
      maxp = i;
    }
  }

  rotate(maxp);
  calInfo();
  cout<< getRes() <<endl;

#ifndef ONLINE_JUDGE
  fclose(stdin);
#endif

  return 0;
}

#include<cstdio>
#include<iostream>

using namespace std;

#define INF 10000000

int findLong(const string &s, int begin, int &len){
  int left=0,minleft = INF;
  int next = begin+1, step = begin;

  len=0;
  while(left>-1 && step<s.size()){
    if('(' == s[step])
      left++;
    else{
      left--;
      if(left<minleft)
        minleft = left;
    }

    if(left == 0){
      next = step+1;
      len = next - begin;
    }

    step++;
  }
  if(minleft>0)
    next += minleft-1;

  return next;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  string s;
  int maxl=0,len=0;
  int begin=0,next=0;
  int n=0;

  cin>>s;

  while(begin<s.size()){
    begin = findLong(s,begin,len);

#ifndef ONLINE_JUDGE
    cout<<begin<<endl;
#endif

    if(len>maxl){
      maxl = len;
      n=1;
    }else if(len==maxl)
      n++;
  }

  if(maxl==0){
    n=1;
  }
  cout<<maxl<<" "<<n<<endl;
#ifndef ONLINE_JUDGE
  fclose(stdin);
#endif

  return 0;
}

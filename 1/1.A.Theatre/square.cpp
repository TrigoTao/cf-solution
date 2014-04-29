#include<iostream>

using namespace std;

int main(){
  long long n,m,a;
  long long res,t1,t2;

  cin>>n>>m>>a;
  t1 = n/a + (n%a>0?1:0);
  t2 = m/a + (m%a>0?1:0);
  res = t1*t2;
  cout<<res;

  return 0;
}

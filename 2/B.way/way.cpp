#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

#define MAX 1003
#define INF 10000000

int m[MAX][MAX];
int keyfive[MAX][MAX];
int keytwo[MAX][MAX];
char wayfive[MAX][MAX];
char waytwo[MAX][MAX];
bool oflag = false;
int po[2];

int getn(int x,int key){
  int n=0;
  if(x==0){
    return INF-1;
  }
  while(x%key==0){
    n++;
    x/=key;
  }
  return n;
}

void fixforzero(int x, int y, int n){
  for(int i=x; i<n; i++){
    for(int j=y; j<n; j++){
      keyfive[i][j] = 1;
      keytwo[i][j] = 1;
    }
  }
  if(y!=0)
    waytwo[x][y]=wayfive[x][y]='R';
  else
    waytwo[x][y]=wayfive[x][y]='D';
  for(int t=x+1; t<n; t++){
    waytwo[t][y] = wayfive[t][y]='D';
  }
  for(int t=y+1; t<n; t++){
    waytwo[n-1][t] = wayfive[n-1][t]='R';
  }
  return ;
}

void search(int x,int y){
  int fiveval=0,twoval=0;
  int lfive=0,ltwo=0,ufive=0,utwo=0;

  if(keyfive[x][y] != -1)
    return;
  fiveval = getn(m[x][y],5);
  twoval = getn(m[x][y],2);

  if(fiveval==INF-1){
    oflag = true;
    po[0] = x;
    po[1] = y;
  }

  ufive = x>0?keyfive[x-1][y]:INF;
  utwo  = x>0?keytwo[x-1][y]:INF;
  lfive = y>0?keyfive[x][y-1]:INF;
  ltwo  = y>0?keytwo[x][y-1]:INF;

  if( lfive<=ufive ){
    wayfive[x][y] = 'R';
    keyfive[x][y] = lfive+fiveval;
  }else{
    wayfive[x][y] = 'D';
    keyfive[x][y] = ufive+fiveval;
  }

  if( ltwo<=utwo ){
    waytwo[x][y] = 'R';
    keytwo[x][y] = ltwo+twoval;
  }else{
    waytwo[x][y] = 'D';
    keytwo[x][y] = utwo+twoval;
  }

  return;
}

void clear(){
  memset(wayfive,'\0',sizeof(wayfive));
  memset(keyfive,-1,sizeof(keyfive));
}

int main(){
  int n,i,j;
  char resway[MAX*2];
  int resn;
  char (*way)[MAX];
  int bytwo,byfive;

#if defined(TEST)||defined(DEBUG)
  freopen("data","r",stdin);
#endif

  clear();
  cin>>n;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin>>m[i][j];
    }
  }

#ifdef DEBUG
  cout<<"after read"<<endl;
#endif
  keyfive[0][0] = getn(m[0][0],5);
  keytwo[0][0] = getn(m[0][0],2);

#ifdef DEBUG
  cout<<"after init"<<endl;
#endif
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      search(i,j);
    }
  }
  bytwo  = keytwo[n-1][n-1];
  byfive = keyfive[n-1][n-1];

#ifdef DEBUG
  cout<<"by two :  "<<bytwo<<endl;
  cout<<"by five:  "<<byfive<<endl;

  cout<<"keytwo"<<endl;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cout<<"\t"<<keytwo[i][j];
    }
    cout<<endl;
  }
  cout<<"waytwo"<<endl;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cout<<"\t"<<waytwo[i][j];
    }
    cout<<endl;
  }
  cout<<"keyfive"<<endl;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cout<<"\t"<<keyfive[i][j];
    }
    cout<<endl;
  }
  cout<<"wayfive"<<endl;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cout<<"\t"<<wayfive[i][j];
    }
    cout<<endl;
  }
#endif
  
  if(bytwo < byfive){
    resn = bytwo;
    way  = waytwo;
  }else{
    resn = byfive;
    way  = wayfive;
  }
  if(resn > 1 && oflag){
    resn = 1;
    fixforzero(po[0],po[1],n);
  }
  i = j = n-1;
  resway[i+j]='\0';
  while(i+j>0){
    resway[i+j-1] = way[i][j];
    if('R' == way[i][j]){
      j--;
    }else{
      i--;
    }
  }

  cout<<resn<<"\n"<<resway<<endl;

  return 0;
}

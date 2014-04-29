#include<cstdio>
#include<iostream>

using namespace std;

struct SumInfo{
  int horizontal[3];
  int vertical[3];
  int diagonal[2];
};

int data[3][3];
SumInfo sumInfo;
int won[2] = {0,0};
int counts[2] = {0,0};
bool draw = true;

int transData(char c){
  switch(c){
    case 'X':
      counts[0]++;
      return 1;
    case '0':
      counts[1]++;
      return 0;
    case '.':
      draw = false;
      return -10;
  }
}

void checkWon(int sum){
  switch(sum){
    case 0:
      won[1] = 1;
      break;
    case 3:
      won[0] = 1;
      break;
  }
}

void calsum(){
  int i,j;
  int sum;

  for(i=0;i<3;i++){
    sum = 0;
    for(j=0;j<3;j++){
      sum += data[i][j];
    }
    sumInfo.horizontal[i] = sum;
    checkWon(sum);
  }

  for(j=0;j<3;j++){
    sum = 0;
    for(i=0;i<3;i++){
      sum += data[i][j];
    }
    sumInfo.horizontal[j] = sum;
    checkWon(sum);
  }

  sumInfo.diagonal[0] = data[0][0] + data[1][1] + data[2][2];
  sumInfo.diagonal[1] = data[0][2] + data[1][1] + data[2][0];
  checkWon(sumInfo.diagonal[0]);
  checkWon(sumInfo.diagonal[1]);

  return ;
}

void answer(){
#ifdef DEBUG
  cout<<"won:\t"<<won[0]<<"\t"<<won[1]<<endl;
  cout<<"counts:\t"<<counts[0]<<"\t"<<counts[1]<<endl;
#endif
  if(won[0]+won[1]==2 || counts[0] > counts[1]+1 || counts[0] < counts[1])
    cout<<"illegal"<<endl;
  else if(won[0]+won[1]==1)
    if(won[0]==1)
      if(counts[0]==counts[1]+1)
        cout<<"the first player won"<<endl;
      else
        cout<<"illegal"<<endl;
    else
      if(counts[0]==counts[1])
        cout<<"the second player won"<<endl;
      else
        cout<<"illegal"<<endl;
  else if(draw)
    cout<<"draw"<<endl;
  else if(counts[0]==counts[1]+1)
    cout<<"second"<<endl;
  else if(counts[0]==counts[1])
    cout<<"first"<<endl;
}

int main(){
  int i,j;
  char c;

#ifdef DEBUG
  freopen("data","r",stdin);
#endif

  for(i=0;i<3;i++)
    for(j=0;j<3;j++){
      cin>>c;
      data[i][j] = transData(c);
    }

  calsum();
  answer();

  return 0;
}

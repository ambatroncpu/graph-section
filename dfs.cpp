//this code is pretty bad and not safe so you should check it before using it even once
#include<iostream>
#include<vector>
using namespace std;

void dfs(int to,vector<int>* link,bool* visited) {
  if(!visited[to]) {
    visited[to] = true;
    for(auto temp : link[to]) {
      dfs(temp,link,visited);
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int node,edge,type;
  cout<<"choose 1:directed , 2:indirected : ";
  cin>>type;
  cout<<endl;
  cin>>node>>edge;
  vector<int> garph[node];
  bool visited[node];
  for(int i=0;i<node;i++) {
    visited[i] = false;
  }
  for(int i=0;i<edge;i++) {
    int start,end;
    cin>>start>>end;
    garph[start].push_back(end);
    if (type==2) {
      garph[end].push_back(start);
    }
  }
  int start_node;
  cin>>start_node;
  dfs(start_node,garph,visited);
  for(int i=0;i<node;i++) {
    cout<<i<<" ";
    if(visited[i]) {
      cout<<"visited\n";
    }else{
      cout<<"not visited\n";
    }
  }
  return 0;
}

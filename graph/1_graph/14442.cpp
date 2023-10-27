#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> p;
int n,m,k,map[1001][1001];
int cnt[1001][1001], di[]={1,-1,0,0}, dj[]={0,0,1,-1};
queue<p> q;

int bfs(){
    q.push({1,1,1});
    cnt[1][1]=0;

    while(!q.empty()){
       
            int i,j,dist;
            tie(i,j,dist)=q.front();
            q.pop();
            
            if(i==n && j==m) return dist;

            //노드 방문의 모든 경우의 수를 push한다
            //같은 거리면 기수도 같다
            for(int d=0;d<4;d++){
                int ni=i+di[d], nj=j+dj[d];
                if(ni>n || ni<1 || nj>m || nj<1) continue;
                if(map[ni][nj]){
                    if(cnt[i][j]==k) continue;
                    if(cnt[ni][nj]<=cnt[i][j]+1) continue;
                    cnt[ni][nj]=cnt[i][j]+1;
                    q.push({ni,nj,dist+1});
                }
                else {
                    if(cnt[ni][nj]<=cnt[i][j]) continue;
                    cnt[ni][nj]=cnt[i][j];
                    q.push({ni,nj,dist+1});
                }
            }
    }
    return -1;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>k; 

    for(int i=1;i<=n;i++){
        string str;
        cin>>str;

        for(int j=1;j<=m;j++){
            map[i][j]=str[j-1]-'0';
            cnt[i][j]=k+1;
        }
    }

    cout<<bfs();

    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
// maxi
int mod=1e9+7;
int maxi= 5*1e11+10;
vector<pair<int,int>>dir={{1,0}, {0,1}, {-1,0}, {0,-1}};


signed main()
{
    
  int n,m,q;
  cin>>n>>m>>q;
  vector<vector<int>>matrix(n+1,vector<int>(n+1,maxi));

  
    for(int j=0;j<m;j++){
        int u,v, a;
        cin>>u>>v>>a;
        matrix[u][v]=min(matrix[u][v],a);
        matrix[v][u]=min(matrix[v][u],a);
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==j){
                matrix[i][j]=0;
            }else if( matrix[i][j]==0){
              matrix[i][j]=maxi;
            }
        }
    }

for(int k=1;k<n+1;k++){
 for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(matrix[i][k]<maxi && matrix[i][k]<maxi)
            matrix[i][j]=min(matrix[i][j],matrix[i][k] + matrix[k][j]);
        }
    }
}
    
for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(matrix[i][j]>=maxi){
                matrix[i][j]=-1;
            }
        }
    }

for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    cout<<matrix[x][y]<<endl;
}


    return 0;
} 

   
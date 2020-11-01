/**
 * Author:Gzking
 * Date  :2020-10-26
 * Task  :解救小哈
*/

#include<iostream>
#include<fstream>
using namespace std;

#define VISITED 1
#define UNVISITED 0
#define M_STEP 9999

//小哈坐标(p,q)，地图大小n*m
int p,q,n,m;
//最小步数
int _min=M_STEP;
//记录地图
char map[M_STEP][M_STEP];
//记录地图某处是否走过
int visited[M_STEP][M_STEP];
//上右下左
int det[4][2] = {{0,1},{1,0},{0,-1}, {-1,0}};

void dfs(int x,int y,int step){
    //下一步的坐标(tx,ty)
    int tx, ty;
    //如果到达小哈处
    if(x==p&&y==q){
        //步数如果为当前最小，更新_min值
        if(step<_min)
            _min = step;
        return;
    }
    //处理下一步
    for (int i=0; i < 3;i++){
        tx = x + det[i][0];
        ty = y + det[i][1];
        
        //判断是否过界
        if(tx<1||tx>n||ty<1||ty>m)
            continue;

        //判断所预测的下一步不是墙并且没走过
        if(map[tx][ty]=='.'&&visited[tx][ty]==UNVISITED){
            //走出这一步，记录
            visited[tx][ty] = VISITED;
            dfs(tx, ty, step + 1);
            //复位
            visited[tx][ty] = UNVISITED;
        }
    }
    return;
}

int main(){
    int sx, sy;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){ 
        for (int j = 1; j <= m;j++){
            cin >> map[i][j];
            visited[i][j] = UNVISITED;
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <=m ;j++){
            cout << map[i][j]<<" ";
        }
        cout << endl;
    }
    cin >> sx >> sy >> p >> q;
    visited[sx][sy] = VISITED;
    dfs(sx, sy, 0);
    cout << _min << endl;
    return 0;
}

/*
example:
5 4
. . # .
. . . .
. . # .
. # . .
. . . #
1 1 4 3
*/
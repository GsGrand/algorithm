/**
 * Author:Gzking
 * Date  :2020-10-27
 * Task  :BFS解救小哈
*/

#include<iostream>
#include<fstream>
using namespace std;

struct position{
    int x;
    int y;
    int s;
    int f;
}que[2501];

int map[50][50];
int book[50][50];

int main(){
    int n, m;
    int head = 1;
    int tail = 1;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> map[i][j];
            book[i][j] = 0;
        }
    }
    int sx, sy, p, q;
    cin >> sx >> sy >> p >> q;

    que[tail].x = sx;
    que[tail].y = sy;
    que[tail].s = 0;
    que[tail].f = 0;
    tail++;
    book[sx][sy] = 1;

    int tx, ty;
    int flag = 0;
    int det[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1,0}};
    while(head<tail){
        for (int k = 0; k <= 3;k++){
            tx = que[head].x + det[k][0];
            ty = que[head].y + det[k][1];
            
            if(tx<1||tx>n||ty<1||ty>m)
                continue;
            
            if(map[tx][ty]==0&&book[tx][ty]==0){
                
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].s = que[head].s + 1;
                que[tail].f = head;
                tail++;
            }
            
            if(tx==p&&ty==q){
                flag = 1;
                break;  
            }
        }
        if(flag==1)
            break;
        head++;
    }
 
    cout << que[tail-1].s << endl;
    int track = tail-1;
    cout << "(" <<  p << "," << q << ")";
    while(track>=1){
        cout << " -> (" << que[track].x << "," << que[track].y << ")";
        track = que[track].f;
    }    
}
/*
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3
*/
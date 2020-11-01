/**
 * Author:Gzking
 * Date  :2020-10-27
 * Task  :BFS解炸弹人
*/


#include<iostream>
using namespace std;

struct position{
    int x;
    int y;
} que[401];

char map[21][21];
int book[21][21];

int n, m;
int getnum(int x,int y){
    int sum = 0;
    for (int i = x; i <= n;i++)
        if(map[i][y]=='#'){
            break;
        }else if(map[i][y]=='G'){
            sum++;
        }
    for (int i = x; i > 0;i--)
        if(map[i][y]=='#'){
            break;
        }else if(map[i][y]=='G'){
            sum++;
        }
    for (int j = y; j <= m; j++)
        if(map[x][j] == '#'){
            break;
        }else if (map[x][j] == 'G')
        {
            sum++;
        }
    for (int j = y; j > 0;j--)
        if(map[x][j]=='#'){
            break;
        }else if(map[x][j]=='G'){
            sum++;
        }
    return sum;
}
int main(){
    
    int sx, sy,max_boom;
    int fx, fy;
    int tx, ty;
    int tmp;
    int s_flag = 0;
    int det[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    cin >> n >> m;
    for (int i = 1; i <=n;i++)
        for (int j = 1; j <=m;j++){
            cin >> map[i][j];
            if(map[i][j]=='.'&&s_flag==0){
                sx = i;
                sy = j;
                s_flag = 1;
            }
            book[i][j] = 0;                         
        }

    int head = 1;
    int tail = 1;
    que[tail].x = sx;
    que[tail].y = sy;
    tail++;
    book[sx][sy] = 1;
    fx = sx;
    fy = sy;
    max_boom = getnum(sx, sy);

    while(head<tail){
        for (int k = 0; k < 4;k++){
            tx = que[head].x + det[k][0];
            ty = que[head].y + det[k][1];

            if(tx<1||tx>n||ty<1||ty>m)
                continue;
            
            if(map[tx][ty]=='.'&&book[tx][ty]==0){
                que[tail].x = tx;
                que[tail].y = ty;
                tail++;
                book[tx][ty] = 1;
                tmp = getnum(tx, ty);
                if(tmp > max_boom){
                    max_boom = tmp;
                    fx = tx;
                    fy = ty;
                }
            }
        }
        head++;
    }
    cout << max_boom << endl;
    cout << "(" << fx << " , " << fy << ")" << endl;
}
/*
13 13
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.###
##G..G......#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/
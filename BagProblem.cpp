//
// Created by zqn on 2019/3/19.
//

#include <vector>
#include <iostream>
using namespace std;

//在n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，每个物品的大小为A[i]，价值为value


#define N 3 // N件物品

#define V 5 // C是背包的总capacity


int main() {
    int value[N + 1]  = {0, 60, 100, 120}; //价值
    int weight[N + 1] = {0, 1,  2,  3};    // 重量
    int f[N + 1][V + 1] = {0}; // f[i][j]表示在背包容量为j的情况下， 前i件宝贝的最大价值

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= V; j++){
            if(j < weight[i]){
                f[i][j] = f[i - 1][j];
            }
            else{
                int x = f[i - 1][j];
                int y = f[i - 1][j - weight[i]] + value[i];
                f[i][j] = x < y ? y : x;
            }
        }
    }

    for(int i = N; i >= 1; i--){
        for(int j = 1; j <= N; j ++){
            printf("%4d", f[i][j]);
        }
        cout << endl;
    }
    return 0;

}
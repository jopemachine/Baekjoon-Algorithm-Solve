/*
==============================+===============================================================
@ File Name : 1916.h
@ Author : jopemachine
@ Desc : 
@    최소비용 구하기
@    다익스트라 알고리즘을 알고 있으면 풀 수 있는 문제.
@    STL의 우선순위 큐를 이용했다.
@    
==============================+===============================================================
*/

#ifndef SELFMADE_ALGORITHM_1916_H
#define SELFMADE_ALGORITHM_1916_H

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

int N, M;

int startingPoint;
int destinationPoint;

int **map;
int *costs;


priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pQue;

void solve_Dijkstra(int s){

    pQue.push({0, s});

    while(pQue.size() > 0){

        int cost = pQue.top().first;
        int vertexID = pQue.top().second;

        pQue.pop();

        if(costs[vertexID] != -1){
            continue;
        }

        costs[vertexID] = cost;

        for(int i = 0; i < N; i++){
            if(map[vertexID][i] >= 0){

                int totalCost = map[vertexID][i] + costs[vertexID];

                if(costs[i] != -1){
                    continue;
                }

                pQue.push({totalCost, i});
            }
        }
    }

}

void solve_1916(){

    cin >> N;
    cin >> M;
    costs = new int[N];

    for(int i = 0; i < N; i++){
        costs[i] = -1;
    }

    map = new int*[N];

    for(int i = 0; i < N; i++){
        map[i] = new int[N];
        memset(map[i], -1, sizeof(int) * N);
    }

    for (int i = 0; i < M; i++){
        int startPoint;
        int destPoint;
        // ( 0 <= cost <= 100,000 )
        int cost;
        cin >> startPoint >> destPoint >> cost;

        if(map[startPoint - 1][destPoint - 1] != -1){
            if(cost < map[startPoint - 1][destPoint - 1]){
                map[startPoint - 1][destPoint - 1] = cost;
            }
            else{
                continue;
            }
        }
        else{
            map[startPoint - 1][destPoint - 1] = cost;
        }

    }

    for(int i = 0; i < N; i++){
        map[i][i] = 0;
    }

/*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
*/

    cin >> startingPoint >> destinationPoint;

    solve_Dijkstra(startingPoint - 1);

    cout << costs[destinationPoint - 1];

}
#endif //SELFMADE_ALGORITHM_1916_H

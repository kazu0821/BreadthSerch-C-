#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <string>

using namespace std;

int main(){


}

void bfs (vector <int> alists[], int size, int start, int target, string list[]){

    int *parents = new int[size];


    for(int i =0; i < size; i++) parents[i]= -1;
    parents[start]= start;
    queue<int> q;
    q.push(start);
    bool found = false;
    while(!q.empty() && !found){
        int v = q.front();
        if( v == target){
            found = true;
        }
        else{
            for(int i= 0; i < alists[v].size(); i++){
             int w = alists[v][i];

             if (parents[w] =-1){
                 parents[w] = v;
                 q.push(w);

             }


            }

        }


    }






}

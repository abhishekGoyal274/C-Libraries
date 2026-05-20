#include "_utility.h"
#include <bits/stdc++.h>

// Disjoint Set functions
DisjointSet::DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }
int DisjointSet::find(int index){
        if(parent[index] == index) return index;
        int parent = find(this->parent[index]);
        this->parent[index] = parent;
        return parent;
    }
void DisjointSet::union_sets(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);

        if(parent_u == parent_v) return;
        else if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }else{
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }

//
//  alt_final.hpp
//  Alt Final
//
//  Created by Brian Mak on 12/14/17.
//  Copyright © 2017 Brian Mak. All rights reserved.
//

#ifndef alt_final_hpp
#define alt_final_hpp

using namespace std;

#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <iostream>



class MinHeap
{
public:
    MinHeap( vector<int> v );
    void printHeap( );
    void buildHeap( );
    void insert( int n );
    int pop( );
    void percolateUp( int n );
    void percolateDown( int n );
    unsigned int parent( int n );
    vector<int> heap;
    
private:
    void swap( int n1, int n2 );
    unsigned int lchild( int n );
    unsigned int rchild( int n );


};


class MST
{
public:
    int Prims( MinHeap M );
    void buildKey( vector<int> v );
    void printTree( );
private:
    vector<int> mst;
    map<int, pair<int,int> > key;
    int num_nodes;
};



#endif /* alt_final_hpp */

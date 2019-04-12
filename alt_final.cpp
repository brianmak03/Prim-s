//
//  alt_final.cpp
//  Alt Final
//
//  Created by Brian Mak on 12/14/17.
//  Copyright © 2017 Brian Mak. All rights reserved.
//

#include "alt_final.hpp"

MinHeap::MinHeap( vector<int> v )
{
    heap = v;
}

unsigned int MinHeap::lchild( int n )
{
    return 2*n+1;
}

unsigned int MinHeap::rchild( int n )
{
    return 2*n+2;
}

unsigned int MinHeap::parent( int n )
{
    return (n-1)/2;
}


void MinHeap::percolateDown( int n )
{
  while( (rchild(n) < heap.size( )) && (heap[n] > heap[lchild(n)] || heap[n] > heap[rchild(n)]))
    {
        if( heap[lchild(n)] < heap[rchild(n)] )
        {
            swap(n,lchild(n));
            n = lchild(n);
        }
        else
        {
            swap(n,rchild(n));
            n = rchild(n);
        }

    }
    if( lchild(n) < heap.size( ) && heap[n] > heap[lchild(n)] )
    {
        swap(n,lchild(n));
    }
}

void MinHeap::percolateUp( int n )
{
    while( n > 0 && heap[n] < heap[parent(n)] )
    {
        swap(n,parent(n));
        n = parent(n);
    }
}

void MinHeap::swap( int n1, int n2 )
{
    int temp = heap[n1];
    heap[n1] = heap[n2];
    heap[n2] = temp;
}

int MinHeap::pop( )
{
    int min = heap[0];
    heap[0] = heap.back( );
    heap.pop_back( );
    percolateDown( 0 );
    return min;
}

void MinHeap::insert( int n )
{
    heap.push_back(n);
    percolateUp(heap.size( )-1);
}

void MinHeap::buildHeap(  )
{
    int i = parent( heap.size( ) - 1 );
    while( i >= 0 )
    {
        percolateDown( i );
        i--;
    }
}

void MinHeap::printHeap( )
{
    for ( int i = 0; i < heap.size( ); i++ )
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void MST::buildKey( vector<int> v )
{
    set<int> nodes;
    int node_num1,node_num2;
    for( int i = 0; i < v.size( ); i += 3 )
    {
        if( v[i] > v[i+1] )
        {
            node_num1 = v[i+1];
            node_num2 = v[i];
        }
        else
        {
            node_num1 = v[i];
            node_num2 = v[i+1];
        }
        key[v[i+2]] = make_pair(node_num1,node_num2);
        nodes.insert( node_num1 );
        nodes.insert( node_num2 );
    }
    num_nodes = nodes.size( );
}

int MST::Prims( MinHeap M )
{
    int first_cost;
    int cost;
    vector<int> reuse_costs;
    set<int> nodes;
    nodes.insert(1);
    while( nodes.size( ) < num_nodes )
    {
        cost = M.pop( );
        if( nodes.count(key[cost].first) == 1 ^ nodes.count(key[cost].second) == 1 )
        {
            if( nodes.size( ) == 1 )
            {
                first_cost = cost;
            }
            mst.push_back(cost);
            nodes.insert( key[cost].first );
            nodes.insert( key[cost].second );
            for( int i = 0; i < reuse_costs.size( ); i++)
            {
                M.insert( reuse_costs[i] );
            }
            reuse_costs.clear( );
        }
        else
        {
            reuse_costs.push_back(cost);
        }
    }
    return first_cost;
}

void MST::printTree( )
{
    for( int i = 0; i < mst.size( ); i++ )
    {
        cout << key[mst[i]].first << " " << key[mst[i]].second << " ";
    }
    cout << endl;
}




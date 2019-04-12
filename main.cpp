//
//  main.cpp
//  Alt Final
//
//  Created by Brian Mak on 12/16/17.
//  Copyright © 2017 Brian Mak. All rights reserved.
//

#include "alt_final.hpp"
#include <sstream>

int main( )
{
    string line;
    string command;
    do{
        getline(cin, line);
        stringstream ss(line);
        ss >> command;
        if( command == "MINHEAP" )
        {
            vector<int> input;
            for( string s; ss >> s; )
            {
                input.push_back(stoi(s));
            }
            MinHeap M(input);
            M.percolateDown( M.parent( M.heap.size( )-1 ) );
            M.printHeap( );
            M.buildHeap( );
            M.printHeap( );
            
        }
        else if( command == "PRIM" )
        {
            MST ptest;
            unsigned int fcost;
            vector<int> edges;
            vector<int> vect_weights;
            for( string s; ss >> s; )
            {
                edges.push_back(stoi(s));
            }
            for( int i = 2; i < edges.size( ); i+=3 )
            {
                vect_weights.push_back(edges[i]);
            }
            MinHeap weights( vect_weights );
            ptest.buildKey( edges );
            fcost = ptest.Prims( weights );
            cout << fcost << endl;
            ptest.printTree( );
            
        }
        else if( command == "TEST" )
        {
            return 0;
        }
    }while( command != "END" );
}

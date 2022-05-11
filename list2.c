#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list_node.h"

dll_insert( Node **frontp, Node **rearp, int value )
{
    register Node **fwdp;
    register Node *next;
    register Node *newnode;

    fwdp = frontp;
    
    while( (next = *fwdp) != NULL )
    {
        if( next–>value == value )
            return 0;
        if( next–>value > value )
            break;
        fwdp = &next–>fwd;
    }

    newnode = (Node *)malloc( sizeof( Node ) );

    if( newnode == NULL )
        return –1;
    
    newnode–>value = value;
    newnode–>fwd = next;
    *fwdp = newnode;
    
    if( fwdp != frontp )
    {
        if( next != NULL )
            newnode–>bwd = next–>bwd;
        else
            newnode–>bwd = *rearp;
    }
    else
        newnode–>bwd = NULL;
    
    if( next != NULL )
        next–>bwd = newnode;
    else
        *rearp = newnode;
    return 1;
}
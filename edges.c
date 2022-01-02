#include "graph.h"
#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>







//Adding an edge (source,destination,weight)
void add_edge(pnode Src, pnode Dest, int Weight)
{
    if (!n || !to)
        return;
    
    pedge new_edge = (pedge)malloc(sizeof(edge));

    new_edge->next = NULL;

    new_edge->weight = Weight;

    new_edge->endpoint = Dest;

    pedge EDG = Src->edges;

    while (EDG && ed->next)
    {

        EDG = ed->next;
    }

    if (!EDG)
    {
        Src->edges = new_edge;
        return;
    }

    EDG->next = new_edge;
}


//printing the edges
void printEdges(pnode node)
{
    if (node == NULL)
        return;

    pedge E = node->edges;
    printf("node %d edges are :\n", node->node_num);




    while (E)
    {
        printf("id %d weight %d , ", e->endpoint->node_num, e->weight);
        E = E->next;
    }
    printf("\n");
}




void delete_edges(pnode NODE, pnode n)
{
    if (NODE == NULL)
        return;

    
    while (NODE)//deleting the coming edges
    {
        pedge p = NODE->edges;
        pedge *previous = &NODE->edges;
        while (p)
        {
            if (p->endpoint == n)
            {
                *previous = p->next;
                free(p);
                p = *previous;
            }
            else
            {
                previous = &(p->next);
                p = p->next;
            }
        }

        NODE = NODE->next;
    }

    
    pedge ed = n->edges;//deleting going out edges
    while (ed)
    {
        pedge e = ed;
        ed = ed->next;
        free(e);
    }
}

void delete_out_edges(pnode n)
{
    // delete out edges
    pedge ed = n->edges;
    while (ed)
    {
        pedge e = ed;
        ed = ed->next;
        free(e);
    }
    n->edges = NULL;
}
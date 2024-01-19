#include "graph.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function used to initialize a graph structure.
struct Graph* graph_create(){
    struct Graph *newGraph = (struct Graph *)malloc(1 * sizeof(struct Graph));
    newGraph->visited = (uint32_t *)calloc(GRAPH_SIZE, sizeof(uint32_t));
    newGraph->adjList = (uint32_t **)malloc(GRAPH_SIZE * sizeof(uint32_t*));
    for(int i = 0; i < GRAPH_SIZE; i++){
        newGraph->adjList[i] = (uint32_t*)malloc(GRAPH_SIZE * sizeof(uint32_t));
    }
    for(int i = 0; i < GRAPH_SIZE; i++){ // Make a matrix of GRAPH_SIZE X GRAPH_SIZE to represent all possible edges.
        for(int j = 0; j < GRAPH_SIZE; j++){
            newGraph->adjList[i][j] = 0;
        }
    }
    return newGraph;
}

// Function to free up memory that was allocated to a graph.
void graph_delete(struct Graph *g){
    for(int i = 0; i < GRAPH_SIZE; i++){ // Free the memory allocated to edges nxn matrix.
        free(g->adjList[i]);
    }
    free(g->adjList);
    free(g->visited);
    free(g);
}

// Function to add an edge between two "nodes".
void add_edge(struct Graph *g, uint32_t src, uint32_t dest, bool bi_directional){
    g->adjList[src-65][dest-65] = 1; // Set edge from src to dest.
    if(bi_directional){
        g->adjList[dest-65][src-65] = 1; // Set edge from dest to src.
    }
    return;
};

// Function to print a graph - for debug purposes.
void print_graph(struct Graph *g){
    for(int i = 0; i < GRAPH_SIZE; i++){
        for(int j = 0; j < GRAPH_SIZE; j++){
            if(g->adjList[i][j]){ // Print nodes if there is an edge between them.
                printf("[%c->%c]", (char)i+65, (char)j+65);
            }
        }
    }
    printf("\n");
}
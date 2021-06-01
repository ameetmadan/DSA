#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define TIME_UNDEFINED -1

struct AdjacencyListNode
{
	int destination;
	int weight;
	struct AdjacencyListNode *next;
};

struct GraphVertex
{
	char label;
	int color;
	int start_time;
	int end_time;
	/* add predecessor here */
	struct AdjacencyListNode *head;
};

struct Graph
{
	struct GraphVertex **adjacency_list;
	int number_of_vertices;
	int time;
};

struct GraphVertex *create_graph_vertex(char label)
{
	struct GraphVertex *new_vertex = malloc(sizeof(struct GraphVertex));
	new_vertex->label = label;
	new_vertex->color = WHITE;
	new_vertex->start_time = TIME_UNDEFINED;
	new_vertex->end_time = TIME_UNDEFINED;
	new_vertex->head = NULL;
	return new_vertex;
}

struct Graph *create_graph(int number_of_vertices, char start_label)
{
	struct Graph *new_graph = malloc(sizeof(struct Graph));
	new_graph->number_of_vertices = number_of_vertices;
	new_graph->adjacency_list = malloc(number_of_vertices * sizeof(struct GraphVertex *));
	for (int i = 0; i < number_of_vertices; i++)
	{
		new_graph->adjacency_list[i] = create_graph_vertex(start_label + i);
	}
	new_graph->time = TIME_UNDEFINED;
	return new_graph;
}

int get_index(struct Graph *graph, char target_label)
{
	for (int i = 0; i < graph->number_of_vertices; i++)
	{
		if (graph->adjacency_list[i]->label == target_label)
		{
			return i;
		}
	}
	return -1;
}

void add_edge(struct Graph *graph, char source_label, char dest_label, int weight)
{
	int source = get_index(graph, source_label);
	int destination = get_index(graph, dest_label);
	struct AdjacencyListNode *new_edge = malloc(sizeof(struct AdjacencyListNode));
	new_edge->destination = destination;
	new_edge->weight = weight;
	new_edge->next = graph->adjacency_list[source]->head;
	graph->adjacency_list[source]->head = new_edge;
}

char get_label(struct Graph *graph, int adj_list_index)
{
	return graph->adjacency_list[adj_list_index]->label;
}

void print(struct Graph *graph)
{
	for (int i = 0; i < graph->number_of_vertices; i++)
	{
		printf("%c (%d/%d/%d): ", graph->adjacency_list[i]->label,
			   graph->adjacency_list[i]->color, graph->adjacency_list[i]->start_time,
			   graph->adjacency_list[i]->end_time);
		struct AdjacencyListNode *current = graph->adjacency_list[i]->head;
		while (current != NULL)
		{
			printf("--[%d]--> %c ", current->weight, get_label(graph, current->destination));
			current = current->next;
		}
		printf("\n");
	}
}

void dfs_tree(struct Graph *g, struct GraphVertex *start_node)
{
	printf("Calling DFS on vertex %c...\n", start_node->label);
	start_node->color = GRAY;
	g->time++;
	start_node->start_time = g->time;
	struct AdjacencyListNode *current = start_node->head;
	while (current != NULL)
	{
		struct GraphVertex *neighbor = g->adjacency_list[current->destination];
		if (neighbor->color == WHITE)
		{
			dfs_tree(g, neighbor);
		}
		current = current->next;
	}
	start_node->color = BLACK;
	g->time++;
	start_node->end_time = g->time;
}

struct GraphVertex *get_vertex(struct Graph *graph, char label)
{
	return graph->adjacency_list[get_index(graph, label)];
}

int main()
{
	struct Graph *test_graph = create_graph(11, 'A');
	add_edge(test_graph, 'A', 'B', 1);
	add_edge(test_graph, 'B', 'I', 1);
	add_edge(test_graph, 'B', 'E', 1);
	add_edge(test_graph, 'D', 'K', 1);
	add_edge(test_graph, 'E', 'G', 1);
	add_edge(test_graph, 'E', 'C', 1);
	add_edge(test_graph, 'F', 'D', 1);
	add_edge(test_graph, 'G', 'J', 1);
	add_edge(test_graph, 'G', 'C', 1);
	add_edge(test_graph, 'H', 'D', 1);
	add_edge(test_graph, 'I', 'H', 1);
	add_edge(test_graph, 'I', 'F', 1);
	print(test_graph);
	dfs_tree(test_graph, get_vertex(test_graph, 'A'));
	print(test_graph);
	return 0;
}

/* Additional exercises: 
Based on the structure provided above, amend the following:
    - number of components
    - cycle detection, edge classification
    - topological sorting
    - biconnected
    - finding articulation points (cut vertices)
    - print spanning tree
*/

#include "./GraphHelper.cpp"

// Structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};

// A utility function to find set of an element i (uses path compression)
int find(subset subsets[], int i)
{
    // Find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent; 
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to construct MST using Kruskal's algorithm
vector<Edge> KruskalMST(Graph &graph)
{
    vector<Edge> mst;
    int V = graph.V;
    sort(graph.edges.begin(), graph.edges.end(), compareEdge);

    subset *subsets = new subset[V];
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0;
    int i = 0;
    while (e < V - 1 && i < graph.edges.size())
    {
        Edge next_edge = graph.edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            mst.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    delete[] subsets;
    return mst;
}


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x): label(x) {};
};

UndirectedGraphNode*
cloneGraph(UndirectedGraphNode *node,
           unordered_map<int, UndirectedGraphNode*> &hash)
{
    if (node == NULL)
        return NULL;

    if (hash[node->label] != NULL)
        return hash[node->label];

    UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
    hash[node->label] = new_node;
    for (int i = 0; i < node->neighbors.size(); i++)
    {
        UndirectedGraphNode* tmp_node =
            cloneGraph(node->neighbors[i], hash);
        new_node->neighbors.push_back(tmp_node);
    }

    return new_node;
}

UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node)
{
    unordered_map<int, UndirectedGraphNode*> hash;

    return cloneGraph(node, hash);
}

int main()
{

    return 0;
}

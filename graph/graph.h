#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include <tuple>
#include <iostream>

namespace stu
{
class Graph
{
    private:
        int graphSize;

        std::vector<int> nodeArray;
        std::vector<int> edge1Array;
        std::vector<int> edge2Array;

        void addEdge(int node1, int node2)
        {
            edge1Array.push_back(node1);
            edge2Array.push_back(node2);
            std::cout << "adding edge" << node1 << node2 <<"\n";
        }

        void deleteEdge(int node1, int node2)
        {

            int out;
            out = checkEdge(node1, node2);
            if (out ==1 )
            {
                int count = 0;

                for (std::vector<int>::const_iterator i = edge1Array.begin(); i != (edge1Array.end()); i++)
                {
                    if (*((edge1Array.begin() + count)) == node1 && *((edge1Array.begin() + count)) == node2)
                    {
                        edge1Array.erase(edge1Array.begin() + count);
                        edge2Array.erase(edge2Array.begin() + count);
                    }
                    count++;
                }

            }
        }

    public:
        void addNode(int node)
        {
            nodeArray.push_back(node);
            std::cout << "adding node" << std::endl;
        }

        void addUEdge(int node1, int node2)
        {
            addEdge(node1,node2);
            addEdge(node2,node1);
        }

        int connectedComponents(void)
        {
        std::map<int,std::vector<int>> adjacency_list;
        int count = 0;

        for (std::vector<int>::const_iterator i = edge1Array.begin(); i != (edge1Array.end()); i++)
        {
            adjacency_list[edge1Array[count]].push_back(edge2Array[count]);
            count++;
        }

        for (std::map< int , std::vector<int> >::iterator it = adjacency_list.begin();it != adjacency_list.end();it++)
        {
            std::vector<int> value_list = it->second;
            for (int i =0; i < value_list.size(); i++){
            }
        }


        std::map<int,int> component_number;
        count = 0;
        for (int k = 0; k < nodeArray.size(); k++){
            if (component_number.find(count) == component_number.end())
            {

                int node = nodeArray[k];
                int original_node = node;
                std::vector<int> first_nodes = adjacency_list[node];
                for (int i = 0; i < first_nodes.size(); i++)
                {

                }
                while(!first_nodes.empty())
                {
                    int curr_node = first_nodes.back();
                    first_nodes.pop_back();
                    if (component_number.find(curr_node) == component_number.end())
                    {

                        component_number[curr_node] = original_node;
                        std::vector<int> curr_node_list = adjacency_list[curr_node];
                        for (int l = 0; l < curr_node_list.size() ; l++)
                        {
                        }
                        int node_list_len = curr_node_list.size();
                        for (int j = 0; j < node_list_len; j++){
                            first_nodes.push_back(curr_node_list.back());
                            curr_node_list.pop_back();
                        }

                    }

                }

            }
            else
            {

            }
            count++;
        }
        std::cout << "\n\nConnected Components\n";
        for (int l = 0;l < nodeArray.size(); l++)
        {
            int node = nodeArray[l];
            std::cout << "node is:" << node << "  connected_component:" << component_number[node] << std::endl;

        }
        return 1;
    }
        int checkNode(int node)
        {

            for(int i = 0; i < nodeArray.size(); i++)
            {
                if (nodeArray[i] == node)
                {
                    std::cout << "The node exists\n";
                    return 1;
                }
            }
            return 0;
        }

        int checkEdge(int node1 , int node2)
        {

            for(int i=0; i < edge1Array.size(); i++)
            {
                if (edge1Array[i] == node1 && edge2Array[i] == node2)
                {
                    return 1;
                }
            }
            return 0;
        }

        void deleteNode(int node)
        {

            int out;
            out = checkNode(node);
            if (out == 1 )
            {
                int count = 0;

                for (std::vector<int>::const_iterator i = nodeArray.begin(); i != (nodeArray.end());i++)
                {
                    if (*i == node)
                    {
                        nodeArray.erase(nodeArray.begin() + count);
                    }
                    count++;
                }

            }
        }

        void deleteUEdge(int node1, int node2)
        {
            deleteEdge(node1,node2);
            deleteEdge(node2,node1);
        }

        void printNodeList(void)
        {
            for (std::vector<int>::const_iterator i = nodeArray.begin(); i != (nodeArray.end());i++)
            {
                std::cout << "Node :" << (*i) << std::endl;
            }
        }

        Graph(int size)
        {
            std::cout << "Graph object being created with max nodes size:" << size << "\n\n";
            graphSize = size;
        }
};




}
#endif // GRAPH_H

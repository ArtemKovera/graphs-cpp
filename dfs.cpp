//Depth First Search (Traversal) Algorithm in C++

#include <iostream>
#include <vector>

//this function takes a two-dimensional array 10X10, starting vertix, and the number of virtices + 1 as its parameters
//this function returns a vector of the virtices in the order they follow by using depth first traversal
std::vector<int> depthFirstSearch (int graph [][10], int start, int size)
{
    static std::vector<int> vec;
    static int visitedVertices [9] = {0};

    if(visitedVertices[start] == 0)
    {
        vec.push_back(start);
        visitedVertices[start]=1;
     
        for(int i = 1; i < size; i++)
        {
            if(graph[start][i]==1 && visitedVertices[i]==0)
                depthFirstSearch(graph, i, size);
        }
    }
    
    
    return vec;    
}

int main ()
{
    
    //graph representation by using adjacent matrix
    //this graph has 9 vertices 
    int graph [10][10] = 
    {
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
       {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
       {0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
       {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
       {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 1, 0, 0, 0}
    };
    

    std::vector<int> vec1 = depthFirstSearch(graph, 5, 10);
    
    for(auto el : vec1)
        std::cout << el << " ";

    std::cout << std::endl;    

    return 0;
}

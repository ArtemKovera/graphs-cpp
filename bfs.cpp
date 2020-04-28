//Breadth First Search (Traversal) Algorithm in C++
#include <iostream>
#include <queue>
#include <vector>

//this function takes a two-dimensional array, starting vertix, and the number of virtices + 1 as its parameters
//this function returns a vector of the virtices in the order they follow by using breadth first traversal
std::vector<int> breadthFirstSearch (int graph [][10], int start, int size)
{
    std::queue<int> q;
    std::vector<int> vec;
    vec.reserve(size);
    int i = start;

    int visitedVertices [9] = {0};

    vec.push_back(i);
    q.push(i);
    visitedVertices[start] = 1;

    while (!q.empty())
    {
        i = q.front();
        q.pop();

        for(int j=1;j<size;j++)
        {
            if(graph[i][j]==1 && visitedVertices[j]==0)
            {
                vec.push_back(j);
                visitedVertices[j]=1;
                q.push(j);
            }
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
    

    std::vector<int> vec1 = breadthFirstSearch(graph, 4, 10);
    
    for(auto el : vec1)
        std::cout << el << " ";

    std::cout << std::endl;

    return 0;
}
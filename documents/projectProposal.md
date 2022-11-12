## Leading Question: 
The six degrees of separation (or six handshakes rule) is a theory that everyone is six or less connections away from another person. Using a social network dataset of the social circles from Twitter, we wish to test this theory and find our own estimate on how many connections it takes to go from person to person. To find the shortest distance between these two Twitter users, we will use the A* search algorithm to find the shortest path between them. In addition, we will use Kosaraju’s algorithm to find different strongly connected social groups within Twitter.
 
## Dataset Acquisition and Processing (Data format, correction, and storage):
 http://snap.stanford.edu/data/ego-Twitter.html Our dataset comes from Stanford Large Network Dataset Collection. We are given a text file with edges for all egonets in the dataset. The edges from Twitter are directed. Each line in the file has two values, the nodeId of user and the nodeId of user b, with node a being directed to node b. There are 2420766 lines in this text file which will give us 1768149 edges. We can just parse the input data with basic input/output. Since we are given nodeIds, there shouldn’t be any issues with impossible values. If they are impossible, they will just be a node with no edges. We can use a graph to store the data, as we will only have as many vectors as nodes. We can use an adjacency list where storage size is O(V+E) (81306 nodes and 1768149 edges in the dataset) and adding edges is O(1). We can use a map to map each nodeId to values starting from 0 in order to populate the graph. This will allow the index of the graph to correspond to a nodeId.
 
## Graph Algorithms:
### A* algorithm: 
This search algorithm is one of the best and popular technique used in path-finding and graph traversals. This algorithm is essentially an extension of Djikstra’s algorithm, which calculator the distance from the start point. A* uses both the actual distance from the start and the estimated distance to the goal. 
 
Function input - Input required for A* is a graph as a set of nodes and edges, a starting node, and a target node. There will be minimal modifications needed to make our data fit for the algorithm as it already comes with nodes and edges. For heuristic (estimated distance to target),  we will get the smallest edges to reach target.
 
Function output -  the function output will be the list of order of nodes for the shortest path, the value of distance from start to end which can be an integer (which can be a length of the order list). 
 
Function efficiency - The complexity of the algorithm is O(vertices + edges)
 
 
### Kosaraju’s algorithm: 
This algorithm can be considered as an extension of DFS, except that we would be performing DFS two times. This algorithm assumes that there are strongly connected components in the graph, which works for our project because twitter accounts that share a singular description (school, work, interest, etc.) will likely have a very strongly connected component. Essentially, you do a DFS traversal on the graph and then you transpose the graph so that all edges are directed in the opposite direction. You do a DFS traversal again on the transposed graph. 
 
Function input - the function input will simply be the graph itself. To make it a little bit shorter we could input two graphs, the first one being the normal graph and the other one being the transposed graph.
 
Function output - the function output will be the list of order of nodes for the shortest path, the value of distance from start to end which can be a floating point.
 
Function efficiency - The complexity of the algorithm is O(vertices + edges)
 
## Timeline: 
Week 0 (11/04): Finished project proposal. Getting started and distributing work for upcoming week.
 
Week 1 (11/11): Populate the data in so that we can actually create an adjacency matrix for our social media. 
 
Week 2 (11/18): On a smaller sample of data, we will create our node struct for the graph and start implementing the A* algorithm.
 
Week 3 (11/25): Implement Kosaraju’s algorithms.
 
Week 4 (12/2): Testing our algorithm and linting our code and commenting
 
Week 5 (~12/8): Presentation preparation and code submission.

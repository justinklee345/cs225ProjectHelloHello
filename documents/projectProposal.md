####Leading Question:
 
#####Scenario:
With the rise in popularity of cryptocurrency, the bitcoin transaction market has been rapidly growing. However, with such a rise in popularity, there has also been a rise in scam transactions by fake accounts. To be safe from scammer transactions, bitcoin users should not blatantly make transactions with another user that they have no previous knowledge of. Thus, to determine whether to make transaction with an unknown user in these tense situations, we wish to use the data set we have chosen (more info on the dataset below) which consists of data on how one user rates the trustworthiness of another user after a transaction between them (as an edge and the rating as its weight). We will use Djikstra’s search algorithm between two users so that user A can find whether or not trading with user B is safe enough based on already-existing trust ratings stored in the internal nodes that connect between A and B. The output of this algorithm will return a list of users in order, starting with user A and ending with user B. If the sum of the edges’ weight in the path is below a certain threshold that the user decides (their standard for how good the ratings must be), we say that transaction between user A and B is safe. Otherwise, we can say that a transaction between user A and B is not safe.
 
Before we use the Djikstra’s search algorithm to find whether user A and B are trusted, we will use Kosaraju’s algorithm to find the strongly connected components between trusted users. (meaning that we will only consider edge weights from 1-11 as edges for this algorithm). If user A and B are in the same strongly connected components, we can automatically state that the transaction between user A and B will be safe, since both users are in a network with other bitcoin users that are all considered to be trustworthy users. Otherwise, we will move on to Djikstra’s search algorithm method (previously stated) to decide whether a transaction between user A and B is safe or not.
 

####Dataset Acquisition and Processing (Data format, correction, and storage): 
The Link to our Dataset - http://snap.stanford.edu/data/soc-sign-bitcoin-alpha.html (Bitcoin Alpha Trust Weighted Signed Network)

#####Data Format - 
Our dataset comes from Stanford Large Network Dataset Collection. We are given a csv file, in which each line stores one edge. SOURCE, TARGET, RATING, TIME is the exact format of the file. To summarize how the data works, the SOURCE rates the trust they have for the TARGET based on a transaction between the two parties. The RATING refers to the rating the SOURCE gives the TARGET and it ranges from -10 to 10 in steps of 1. The -10 refers to total distrust and 10 refers to total trust. TIME is the time at which the rating occurred so we can ignore this information. There are 3,783 nodes and 24,186 edges in the dataset and we will be using all of the dataset to create the most comprehensive graph of bitcoin alpha trust weighted network.

#####Data Correction - 
We will use the standard procedure in C++ to read in the file using ifstream. We will iterate through each line in the CSV file to parse and populate our private adjacency matrix. For each edge we parse in from the dataset, we will discard the TIME values and check that the rating ranges from -10 to 10 and are integers. Any part of the dataset that misses either the SOURCE or the TARGET or the RATING will be discarded as well, as we believe that our dataset is big enough that discarding one data point wouldn’t affect the success of our project.

#####Data Storage - 
We will be creating an adjacency matrix using a 2-dimensional array with a storage size of O(|V|^2), where V refers to the number of nodes (3,783). We believe that the dataset we have chosen doesn’t have too many nodes to make our adjacency matrix too big. For each element in the V x V array, we will have the rating that the SOURCE rates the TARGET. 0 would mean that there is no rating between the two nodes, but any values from 1 to 21 would mean that there is a rating between the two nodes. This would essentially be the original -10 to 10 rating range inverted so that 1 would be greatest trust and 21 would be least trust. The benefit of an adjacency matrix is that we have a O(1) time in accessing the rating if we know the “id” of the source and the target. Also, we won’t be adding any new nodes after initially populating the matrix, so an adjacency matrix would work fine.
 
####Graph Algorithms:
 
#####(COVERED ALGORITHM):
#####Dijkstra’s algorithm: 
This search algorithm is one of the best and most popular techniques used in path-finding and graph traversals. This algorithm finds the shortest path between the start node and the end node in a graph. In the dataset of Bitcoin Alpha trust weighted signed network, each edge weight represents how trusted/distrusted the target is by the source and is based on the outcome of previous transactions between the two parties. This method of keeping a rating of each user’s “overall reputation” is necessary in making bitcoin a reliable cryptocurrency as users are anonymous. Thus, if a user doesn’t want to risk making a transaction to someone that they have no information about, they can use the Dijkstra shortest path algorithm to find out whether or not the other user is trustworthy enough. For example, let’s say user A wants to make a transaction with user B. If user A doesn’t have a rating for user B, user A can guess how trustworthy user B is partially by finding out the shortest path of user ratings from A to B. We define a shorter path from adjacent nodes to be that the source node trusts the target node (better trust rating) meaning that there will be a higher chance that the source node would trade with the target node again. If we extend this definition of a short path to path with multiple internal nodes, we can get the trustworthiness of the target node using a referral-like system. If a user C recommends user B and user A has previously had a good transaction with user C, user A would likely view user B to also be relatively trustworthy since someone he/she trusts recommended user B.
 
Function input - Input for Djikstra’s algorithm will be the adjacency matrix generated using another function that processes the csv data to an adjacency matrix. We will also be given the starting and end nodes to find the shortest path between the two specified nodes. If the length of the shortest path (the sum of edge weights in safest path from A to B) is less than a certain threshold predetermined by the user, it would be a safe enough rating to continue the direct transaction.
 
Function output -  the function output will be the list of nodes in the shortest path from the start node to the end node (the input). The length of the path would be the size of the list returned.
 
Function efficiency - The complexity of the algorithm is O(vertices + edges).
 
#####TRAVERSALS:
 
We will use the BFS algorithm for pathfinding because BFS is optimal when finding the shortest from one node to another, where DFS is used to go in depth into connection choices to - for instance - find the longest path between two nodes, which isn’t what our project is focused on.
 
However, Kosaraju’s algorithm will be using DFS twice since depth search is required for finding all strongly connected components in the graph.
 
#####(UNCOVERED ALGORITHM):
#####Kosaraju’s algorithm:
 
*Our version of Kosaraju’s algorithm will only consider edges with weights 1-11, since we only want to find strongly connected components where users trust each other.*
 
This algorithm can be considered as an extension of DFS, except that we would be performing DFS two times. This algorithm works with strongly connected components in the graph as bitcoin users can trade within their own groups, which may be related to trading more frequently with those with higher trust factors. This may create strongly connected components and by implementing Kosaraju’s algorithm we can see if this observation is correct. If there are no strongly connected components, then it will return the list of all nodes separately. Essentially, you do a DFS traversal on the graph and then you transpose the graph so that all edges are directed in the opposite direction. You do a DFS traversal again on the transposed graph. 
 
Function input - the function input will simply be the adjacency matrix. To make it a little bit shorter we could input two adjacency matrices, the first one being the normal adjacency matrix and the other one being the transposed adjacency matrix. Additionally, our version of Kosaraju’s algorithm will only consider edges with weights 1-11, since we only want to find strongly connected components where users trust each other.
 
Function output - The function outputs the vertices and strongly connected components for trusted connections. If the unknown account you want to trade is within the same strongly connected component, you are safe to trade with them. If not, proceed to Dijkstra's algorithm for further trust analysis.
 
Function efficiency - The complexity of the algorithm is O(vertices + edges)
 
#####Timeline: 
Week 0 (11/04): Finished project proposal. Getting started and distributing work for the upcoming week.
 
Week 1 (11/11): Populate the data in so that we can actually create an adjacency matrix for our social media. 
 
Week 2 (11/18): We will start implementing BFS traversal and the Djikstra’s algorithm for pathfinding.
 
Week 3 (11/25): Implement Kosaraju’s algorithms.
 
Week 4 (12/2): Testing our algorithm and linting our code and commenting
 
Week 5 (~12/8): Presentation preparation and code submission.

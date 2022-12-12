# CS225: Final Project: Trustworthiness of Bitcoin trusted network

Seeks to determine trustworthy transcations between users in a bitcoin network.

# Running Instructions

Instructions on how to get this project up and running.

## Setup

1. git clone the repository into the cs 225 docker container.
```shell
git clone https://github.com/justinklee345/cs225ProjectHelloHello.git
```
2. navigate to the project and run the following in base directory.
```shell
mkdir build
cd build
```
3. navigate to newly created build directory and run the following
```shell
cmake ..
```
4. run make to compile the code
```shell
make
```

## Usage

To run tests, call ./test
```shell
./test
```
To run main, call ./main with second argument as file path and third argument as number of nodes
```shell
./main ../data/sorted-zero-soc-sign-bitcoinalpha.csv 7604
```


# Github Organization

## Code

All the code for constructing our adjacency matrix, traversing the graph (bfs), our two algorithms dijkstra and kosarajus, and various helper methods are contained in the /src directory.

## Tests

Our tests using catch2 to check for our constructor and algorithms being correct, as well as two additional test files to confirm other such similar datasets will work are contained in the /tests directory.

## Data

The original dataset as well as the manipulated datasets and the python code for them are all stored in the ./data directory.

## Written Report

The written report is saved as a results.md file.

## Video Presentation

Video is public on google drive: **insert link here**

## Documents

Documents pertaining to the final project such as our project proposal, development logs, and team contract.

## Feedback

Feedback from our project mentor concerning our project proposal and mid project check in taken from prairelearn.

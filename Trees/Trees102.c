/*

    In this module, we will discuss what a binary tree is, a binary tree is a tree which has at most 2 children. 
    Basically, binary tree has also types, which are listed as follows:

    1. Full Binary Tree: A binary tree in which every node has 2 children except the leaf node is called a full binary tree.
    
    2. Complete Binary tree: This is basically explained in two parts:
                            -- The binary tree is completely filled with a possible exception at bottom level.
                            -- The bottom level is filled from left to right.


        There are some important properties of a complete binary tree which are to be followed. The properties are:
            -- The parent of node i is the floor function of (i/2)
            -- The left child of the root node is (2i)
            -- The right child of the node is (2i+1)

    3. Perfect Binary Tree: In a perfect binary tree, each leaf is at the same level and all the interior nodes have at least 
                            two children. A perfect binary tree of height h has 2^(h+1) - 1 nodes.
                    

    We have to prove that the ,maximum number of nodes in a perfect binary tree is 2^(h+1)-1

        Number of nodes at level 0 = 2^0 = 1
        Number of nodes at level 1 = 2^1 = 2
        Number of nodes at level 2 = 2^2 = 4
        Number of nodes at level 3 = 2^3 = 8
        ...........................=.....= .
        ...........................=.....= .
        ...........................=.....= .
        ...........................=.....= .
        ...........................=.....= .
        Number of nodes at level h = 2^h = 2^h

        So, adding all this, we get 2^(h+1)-1
        So, applying log we get n = log((n+1)/2)

        Number of leaf nodes: 2^h
        Number of non-leaf nodes: 2^h -1 
        Adding all: 2^(h+1) -1 

        So, maximum number of nodes a binary tree can have is 2^(h+1)-1
            This is only in case of perfect binary tree.
            Minimum number of nodes possible: h+1 

*/
/*

Here, we are going to talk about trees. Trees is an important data structure that is, first of all it is a non-linear data structure, 
and it is useful for storing hierachially ordered data.

It is unlike linked list, stacks or queues, where we store data in a linear fashion.

A tree has basically 2 parts, these two parts are:
    -- This is the data part. 
    -- This is the link part.

    Both of these combined form the node of the tree.

Now before proceeding furthur, we must be aware of a few terms w.r.t trees.
    1. Root -- The topmost node of the hiearchy or the node from where the tree starts.
    2. Child -- Next nodes in the hierachy are the children of the previous node.
    3. parent -- The node just previous to the current node is called the parent node of the current node.
    4. siblings -- The nodes having same parent elements are called siblings.
    5. Ancestors -- All the nodes that come between the path from the root node to the current node are the 
                    ancestors of the current node.
    6. Descendents -- All nodes which are reachable from current node while moving downwards are called as descendents
    7. Internal nodes -- The nodes having at least one child are called as internal nodes.
    8. External nodes/Leaves -- The nodes which don't have any child are called external nodes or the leaves.
    9. Root is at level 0 and then the levels follow up and so on...
    10. Height of a tree: Height of a tree is basically the height of the root.
    11. Edge: The link between two adjacent nodes is a tree. 

    There are some properties that are to be followed in case of a tree:
        -- Tree should not have any breaks in between
        -- Every node in a tree must be reachable by the parent node.
        -- There should'nt be any cycles in a tree.


    Okay, so now to code a node of tree, we must have the data contained, its right and left child (In case of binary tree)
    and the parent of the node.

    Here is the syntax for the same.
*/

struct node{
    int data; //Data contained in the node.
    struct node *right_child; //right_child pointer
    struct node *left_child; //left child pointer
    struct node *parent; //parent element pointer
}

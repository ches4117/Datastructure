This program have two function, binary tree, and max heap. These two program use linked list to complete.
We can perform severl functions,insert ,delete ,search ,print using infixorder, and print using levelorder.
However, max heap doesn't have delete and infixorder these two function. 

First, binary tree. Insert, we should firt have a node to store the data we want to insert, and is less then
current data then turn to left, larger then turn to left. Delete, we should also have the node's parent node,
because we will use parent node to link the delete's next node. If it is root than just delete, have one sub tree
then link one sub tree, have two sub tree then we should find the biggest in the right subtree. Search, if
we find the node we want to find, we get 1, or get 0. And, go left if less, go right if bigger,Infixorder is easy, 
and levelorder we use queue to perform.

Second, max heap. It is hard to use linked list to perform the max heap. Insert, We use a queue to store the 
tree's route.If left is NULL then store in left, other store in right. And at the end, we update the tree to 
max heap form. Search, we search the queue to find whether have this data. Levelorder, because we store the
data is use queue ,we just dequeue than can perform the levelorder.


#include<stdio.h>
#include<stdlib.h>

void BST_insert();
void BST_delete();
void infixorder();
void levelorder();
void menu();
void addq();
void deleteq();
void infixorder();
void levelorder();

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    struct node* parent;
} node;

typedef struct queue
{
    struct queue* next;
    node* element;
} queue;

//a factory to create a node
node* get_a_node(int x, node* parent)
{
    node* nd = malloc(sizeof(node));
    nd->val = x;
    nd->left = NULL;
    nd->right = NULL;
    nd->parent = parent;
    return nd;
}

//a factory to create a queue element
queue* get_a_queue(node* element)
{
    queue* q = malloc(sizeof(queue));
    q->next = NULL;
    q->element = element;
    return q;
}

//function to free queue's memory
void free_queue(queue** q)
{
    queue* current_q = *q;
    while(current_q != NULL)
    {
        *q = current_q->next;
        free(current_q);
        current_q = *q;
    }
}

//put nodes into q
void queue_put(node* n, queue** last)
{
    if(n->left != NULL)
    {
        (*last)->next = get_a_queue(n->left);
        (*last) = (*last)->next;
    }
    if(n->right != NULL)
    {
        (*last)->next = get_a_queue(n->right);
        (*last) = (*last)->next;
    }
}

//insert a node into a heap
void heap_insert(node** root, int x)
{
    //insert new node if the heap is empty
    if(*root == NULL)
    {
        *root = get_a_node(x, NULL);
    }
    //serach for a proper insert point
    else
    {
        queue* q = get_a_queue(*root);
        queue* current_q = q;
        queue* last_q = q;
        node* current_node;

        while(current_q != NULL)
        {
            //get one node out of queue
            current_node = current_q->element;

            if(current_node->left == NULL)
            {
                current_node->left = get_a_node(x, current_node);
                current_node = current_node->left;
            }
            else if(current_node->right == NULL)
            {
                current_node->right = get_a_node(x, current_node);
                current_node = current_node->right;
            }
            else
            {
                queue_put(current_node, &last_q);
                //increment the current pointer
                current_q = current_q->next;
                continue;
            }

            //put the node to proper point
            while(current_node->parent != NULL && current_node->parent->val < current_node->val)
            {
                //swap the value
                int temp = current_node->parent->val;
                current_node->parent->val = current_node->val;
                current_node->val = temp;
                current_node = current_node->parent;
            }
            break;
        }
        free_queue(&q);
    }
    return;
}

int search_heap(node** root, int key)
{
    if(*root != NULL)
    {
        queue* q = get_a_queue(*root);
        queue* current_q = q;
        queue* last_q = q;
        node* test;

        while(current_q != NULL)
        {
            test = current_q->element;
            queue_put(test, &last_q);
            if(test->val == key)
                return 1;
            else
                current_q = current_q->next;
        }

        free_queue(&q);
        printf("\n");
        return 0;
    }
}
//print the heap with levelorder
void levelorder_heap(node** root)
{
    if(*root != NULL)
    {
        queue* q = get_a_queue(*root);
        queue* current_q = q;
        queue* last_q = q;
        node* test;

        while(current_q != NULL)
        {
            test = current_q->element;
            queue_put(test, &last_q);
            printf("%d, ",test->val);
            current_q = current_q->next;
        }

        free_queue(&q);
        printf("\n");
        return 0;
    }
}

typedef struct node2 *treenode;
typedef struct node2
{
    int data;
    treenode left;
    treenode right;
};

treenode SearchTree = NULL, queue2[100], heap = NULL;

int BST_search();
int Heap_search();
int main()
{
    node *root = NULL;
    int choose1, choose2, key;
    int insert_data, have;
    printf("choose which tree you want\n");
    printf("1.Binary search tree\n");
    printf("2.Max heap\n");

    scanf("%d",&choose1);
    if(choose1 == 1)
    {
        while(1)
        {
            menu();
            scanf("%d",&choose2);
            printf("\n");
            switch(choose2)
            {
            case 1:
                printf("Input insert data.\n");
                scanf("%d",&insert_data);
                have = BST_search(&insert_data);
                if(have != 0)
                    printf("This data already exist.\n");
                else
                    BST_insert(&insert_data);
                break;

            case 2:
                printf("Input the data you want to delete.\n");
                scanf("%d",&insert_data);
                have = BST_search(&insert_data);
                if(have == 0)
                    printf("Doesn't have this data.\n");
                else
                    BST_delete(&insert_data);
                break;

            case 3:
                printf("Which one you want to find?\n");
                scanf("%d",&key);
                have = BST_search(&key);
                if(have == 0)
                    printf("Doesn't have this data.\n");
                else
                    printf("The tree has this data.\n");

                break;
            case 4:
                infixorder(SearchTree);
                printf("\n");
                break;
            case 5:
                levelorder(SearchTree);
                printf("\n");
                break;
            }

        }
    }
    if(choose1 == 2)
    {
        while(1)
        {
            menu();
            scanf("%d",&choose2);
            printf("\n");
            switch(choose2)
            {
            case 1:
                printf("Input the insert data.\n");
                scanf("%d",&key);
                have = search_heap(&root, key);
                if(have == 1)
                    printf("This data already exist.\n");
                else
                    heap_insert(&root, key);
                break;

            case 2:
                printf("Didn't do this.\n");
                break;

            case 3:
                printf("Which one you want to find?\n");
                scanf("%d",&key);
                have = search_heap(&root, key);
                if(have == 0)
                    printf("Doesn't have this data.\n");
                else
                    printf("Having this data.\n");
                break;

            case 4:
                printf("Didn't do this.\n");
                break;

            case 5:
                levelorder_heap(&root);
                break;

            }
        }

    }
}
void menu()
{
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Print Infix order\n");
    printf("5. Print Level order\n");

}
//addq and delete use to perform levelorder
void addq(int *rear,treenode now)
{
    *rear = *rear + 1;
    queue2[*rear] = now;
}

treenode delete(int *front)
{
    *front = *front + 1;
    return queue2[*front];
}

int BST_search(int *key)
{
    //use new to begin the tree
    treenode new = SearchTree;
    while(new != NULL)
    {
        if(*key == new->data) return 1;
        //if smaller then go to left, or go to right.
        if(*key < new->data)
            new = new->left;
        else
            new = new->right;
    }

    return 0;
}

void BST_insert(int *key)
{
    int data;
    int insert = 0;
    treenode ptr, now;
    //Use ptr as a node to store the insert data.
    //And use now to record the current node.
    ptr = malloc(sizeof(*ptr));
    ptr->data = *key;
    ptr->left = ptr->right = NULL;
    if(SearchTree == NULL)
        SearchTree = ptr;
    else
    {
        now = SearchTree;
        //Use insert to record whether insert the data.
        while(!insert)
        {
            if(now->data > ptr->data)
            {
                if(now->left == NULL)
                {
                    now->left = ptr;
                    insert = 1;
                }
                else now = now->left;
            }
            else
            {
                if(now->right == NULL)
                {
                    now->right = ptr;
                    insert =1;
                }
                else now = now->right;
            }
        }

    }
}

void BST_delete(int *key)
{
    treenode new2, new, father;
    int find = 0;
    //Use father to store the previous node.
    new = father = SearchTree;
    while(new != NULL && !find)
    {
        //Use new to record the node want to delete.
        if(new->data == *key)
            find = 1;
        else
        {
            father = new;
            if(new->data > *key)
                new = new->left;
            else
                new = new->right;
        }
    }
    if(new == NULL)
        printf("This tree doesn't have this data.");
    //it is a root.
    else if(new->left == NULL && new->right == NULL && new == SearchTree)
    {
        SearchTree = NULL;
        new = NULL;
    }
    //it is a last node, doesn't link other, so use father to record NULL.
    else if(new->left == NULL && new->right == NULL)
    {
        if(father->left == new)
            father->left = NULL;
        else
            father->right = NULL;

        new = NULL;
    }
    //left is NULL, so we just need to link it's right sub tree.
    else if(new->left == NULL)
    {
        if(father != new)
        {
            if(father->left == new)
                father->left = new->right;
            else
                father->right = new->right;
        }
        //it is root, so just turn to next.
        else
            SearchTree = SearchTree->right;
        new = NULL;
    }

    else if(new->right == NULL)
    {
        if(father != new)
        {
            if(father->left == new)
                father->left = new->left;
            else
                father->right = new->left;
        }
        else
            SearchTree = SearchTree->left;
        new = NULL;
    }

    else
    {
        //
        father = new;
        new2 = new->left;
        //turn to left, then go to right until NULL.
        while(new2->right != NULL)
        {
            father = new2;
            new2 = new2->right;
        }

        //Replace the data at the delete node.
        new->data = new2->data;
        if(father->left == new2)
            father->left = new2->left;
        else
            father->right = new2->left;
        new2 = NULL;
    }
}

void infixorder(treenode new)
{
    if(new != NULL)
    {
        infixorder(new->left);
        printf("%d, ",new->data);
        infixorder(new->right);
    }
}
void levelorder(treenode new)
{
    int front =0, rear = 0;
    if(!new) printf("ERROR!!");
    else
    {
        addq(&rear, new);
        for(;;)
        {
            new = delete(&front);
            if(new)
            {
                printf("%d, ",new->data);
                if(new->left)
                    addq(&rear, new->left);
                if(new->right)
                    addq(&rear, new->right);
            }
            else break;
        }
    }
}

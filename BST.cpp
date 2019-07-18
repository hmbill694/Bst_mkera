#include "BST.h"
#include <iostream>

using namespace std;

// Constructor/ Destructor
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
}

bool BST::is_empty()
{
    return root == NULL;
}

void BST::insert(int d)
{
    // This implements the algorithm in page 261 of the textbook
    node *z = new node();
    z->key = d;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;

    node *y = NULL;
    node *x = root;

    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

//Finder methods
BST::node *BST::find_node(node *f_node, int input)
{
    if (f_node == NULL || input == f_node->key)
    {
        return f_node;
    }
    else
    {
        if (input < f_node->key)
        {
            return find_node(f_node->left, input);
        }
        else
        {
            return find_node(f_node->right, input);
        }
    }
}

BST::node *BST::find_parent(node *p_node, int input)
{
    if (p_node->right->key == input || p_node->left->key == input)
    {
        return p_node;
    }
    else
    {
        if (input < p_node->key)
        {
            return find_parent(p_node->left, input);
        }
        else
        {
            return find_parent(p_node->right, input);
        }
    }
}

BST::node *BST::find_max(node *root)
{
    node *max = root;

    if (root == NULL) // if the node is empty
    {
        cout << "The tree is empty" << endl; // print that the tree is empty
    }

    while (max->right != NULL) // while there is a right
    {
        max = max->right; // go to right
    }

    cout << "The max is: " << max->key << endl; // Print max
    return max;                                 // return pointer to node where max lives
}

BST::node *BST::find_min(node *root)
{
    node *min = root;

    if (root == NULL) // if the node is empty
    {
        cout << "The tree is empty" << endl; // print that the tree is empty
        return NULL;
    }

    while (min->left != NULL) // While there is a left
    {
        min = min->left; // go to left
    }

    return min; // return pointer to node where min lives
}

BST::node *BST::find_successor(node *s_node)
{
    if (s_node->right != NULL) // if there is a right tree
    {
        return find_min(s_node->right); // find the min of the right child element tree
    }
    else
    {
        node *parent = s_node->parent;
        while (parent != NULL && s_node == parent->right)
        {
            s_node = parent;
            parent = parent->parent;
        }

        return parent;
    }
}

// Deletion Methods
void BST::delete_max(node *m_node)
{

    node *max = find_max(m_node);
    node *del_node = delete_node(max);
    delete max;
}

BST::node *BST::delete_node(node *d_node)
{
    node *x = NULL; // Create two nodes
    node *y = NULL;
    if (d_node->left == NULL || d_node->right == NULL) // Case 1: Only one child
    {
        y = d_node; // Set pointer to deletion node
    }
    else
    {
        y = find_successor(d_node); // Case 2: Node has two children
    }

    if (y->left != NULL) // if there is a left child
    {
        x = y->left; // set x to it
    }
    else
    {
        x = y->right; // set x to right child
    }

    if (x != NULL) // if x isnt empty (NULL)
    {
        x->parent = y->parent; // x's parent will be the parent of y
    }

    if (y->parent == NULL) // if y is empty, then the root is x
    {
        root = x;
    }
    else
    {
        if (y == y->parent->left) // if y is its parent left child
        {
            y->parent->left = x; // the left child of y's parent is x
        }
        else
        {
            y->parent->right = x; // the right child of y's parent is x
        }
    }

    if (y != d_node) // if y is'nt the node we're deleting
    {
        d_node->key = y->key; // set the deletion key to y's key
    }

    return y; // return the deletion node
}

// Traversal Methods
void BST::in_order_traversal(node *t_node)
{
    if (t_node != NULL) // Base Case: Tree isn't NULL
    {
        if (t_node->left) // Go left if there is a left child
        {
            in_order_traversal(t_node->left); // Traverse Inorder left
        }

        cout << " " << t_node->key << " "; // Print node if no left child

        if (t_node->right) // Go right if there is a right child
        {
            in_order_traversal(t_node->right); // Traverse Inorder right
        }
    } //end if
} //end method

void BST::pre_order_traversal(node *t_node)
{
    if (t_node != NULL) // Base Case: Tree isn't NULL
    {
        cout << " " << t_node->key << " "; // Print parent of both children first

        if (t_node->left) // If left is availavle (ie. has a left child) go left
        {
            pre_order_traversal(t_node->left); // Pre Order Traverse to the left
        }

        if (t_node->right) // If right is available go right
        {
            pre_order_traversal(t_node->right); // Pre Order Traverse to the right
        }
    } //end if
} //end method

void BST::post_order_traversal(node *t_node)
{
    if (t_node != NULL) // Base Case: Tree isn't NULL
    {
        if (t_node->left) // If left is available go left
        {
            post_order_traversal(t_node->left); // post_order traverse to the left
        }

        if (t_node->right) // IF right is available go right
        {
            post_order_traversal(t_node->right); // post_order traverse to the right
        }

        cout << " " << t_node->key << " "; // Print the key at the node
    }                                      //end if
}
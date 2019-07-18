#include "M_BST.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor/ Destructor
M_BST::M_BST()
{
    root = NULL;
}

M_BST::~M_BST()
{
}

bool M_BST::is_empty()
{
    return root == NULL;
}

void M_BST::insert(int d, std::string name)
{
    // This implements the algorithm in page 261 of the textbook
    node *z = new node();
    z->key = d;
    z->data = name;
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
M_BST::node *M_BST::find_node(node *f_node, int input)
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

M_BST::node *M_BST::find_parent(node *p_node, int input)
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

M_BST::node *M_BST::find_max(node *root)
{
    node *max = root;

    if (root == NULL)
    {
        cout << "The tree is empty" << endl;
    }

    while (max->right != NULL)
    {
        max = max->right;
    }

    cout << "The max is: " << max->key << endl;
    return max;
}

M_BST::node *M_BST::find_min(node *root)
{
    node *min = root;

    if (root == NULL)
    {
        cout << "The tree is empty" << endl;
        return NULL;
    }

    while (min->left != NULL)
    {
        min = min->left;
    }

    return min;
}

M_BST::node *M_BST::find_successor(node *s_node)
{
    if (s_node->right != NULL)
    {
        return find_min(s_node->right);
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
void M_BST::delete_max(node *m_node)
{

    node *max = find_max(m_node);      //find the max
    node *del_node = delete_node(max); // delete the node where it is
    delete max;
}

M_BST::node *M_BST::delete_node(node *d_node)
{
    node *x = NULL; // create nodes to use during method
    node *y = NULL;
    if (d_node->left == NULL || d_node->right == NULL) // Case 1: The node you're deleting has no childre
    {
        y = d_node; // Y is the node you intend to delete
    }
    else // Case 2: The node you're deleting has at least one child
    {
        y = find_successor(d_node); // Y is now the successor (the smallest value larger than d_node->key)
    }

    if (y->left != NULL) // if Y has a left child
    {
        x = y->left; // X is that left
    }
    else
    {
        x = y->right;
    }

    if (x != NULL)
    {
        x->parent = y->parent;
    }

    if (y->parent == NULL)
    {
        root = x;
    }
    else
    {
        if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }
    }

    if (y != d_node)
    {
        d_node->key = y->key;
    }

    return y;
}

// Traversal Methods
void M_BST::in_order_traversal(node *t_node)
{
    if (t_node != NULL) // Base Case: Tree isn't NULL
    {
        if (t_node->left) // Go left if there is a left child
        {
            in_order_traversal(t_node->left); // Traverse Inorder left
        }

        cout << " " << t_node->key << " " << t_node->data << " "; // Print node if no left child

        if (t_node->right) // Go right if there is a right child
        {
            in_order_traversal(t_node->right); // Traverse Inorder right
        }
    } //end if
} //end method

void M_BST::in_order_traversal_no_print(node *t_node)
{
    if (t_node != NULL) // Base Case: Tree isn't NULL
    {
        if (t_node->left) // Go left if there is a left child
        {
            in_order_traversal_no_print(t_node->left); // Traverse Inorder left
        }

        if (t_node->right) // Go right if there is a right child
        {
            in_order_traversal_no_print(t_node->right); // Traverse Inorder right
        }
    } //end if
} //end method

void M_BST::pre_order_traversal(node *t_node)
{
    if (t_node != NULL) // Base Case: Tree isn't NULL
    {
        cout << " " << t_node->key << " " << t_node->data << " "; // Print node

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

void M_BST::post_order_traversal(node *t_node)
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

        cout << " " << t_node->key << " " << t_node->data << " "; // Print node
    }                                                             //end if
}

// valididate time gap
bool M_BST::validate_time_gap(node *v_node, int time_gap, int new_time)
{
    if (v_node != NULL) // Base Case: Tree isn't NULL
    {
        if (v_node->left) // Go left if there is a left child
        {
            in_order_traversal_no_print(v_node->left); // Traverse Inorder left
        }

        if (abs(v_node->key - new_time) >= time_gap && new_time >= time_gap)
        {
            return true;
        }
        else
        {
            return false;
        }

        if (v_node->right) // Go right if there is a right child
        {
            in_order_traversal_no_print(v_node->right); // Traverse Inorder right
        }
    } //end if

    return true; // if list is empty then we will insert regardless
}
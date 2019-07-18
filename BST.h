#include <string>
class BST
{
public:
    class node
    {
    public:
        node *left;
        node *right;
        node *parent;
        int key;
        std::string data;
    };
    node *root;
    BST();  // Constructor
    ~BST(); // Destructor
    void insert(int);
    void pre_order_traversal(node *);  // Preforms a preorder traversal of the tree starting at entered node
    void in_order_traversal(node *);   // Preforms a inorder traversal of the tree starting at entered node
    void post_order_traversal(node *); // Preforms a postorder traversal of the tree starting at entered node
    node *find_max(node *);            // Finds the min value of the tree and returns the node
    node *find_min(node *);            // Finds the max value of the tree and returns the node
    node *find_node(node *, int);      // Finds node with given value
    node *find_parent(node *, int);
    void delete_max(node *);      // Deletes the max
    node *find_successor(node *); // Finds the successor of a given node
    node *delete_node(node *);    // Deletes a given node
    bool is_empty();
};
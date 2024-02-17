#include <iostream>

/*
 * binary search tree: bst
 *     - root_node = nullptr
 *     - insert_node (int data);
 *     - delete_node (int data);
 *     - inorder_traversal ();
 */

class node
{
    public:
        node *lnode;
	int data;
	node *rnode;

	node ();
	node (int idata);
	~node ();
};

node::node ()
{
    lnode = nullptr;
    data = 0;
    rnode = nullptr;
}

node::node (int idata)
{
    lnode = nullptr;
    data = idata;
    rnode = nullptr;
}

node::~node ()
{

}

class bst
{
    private:
        node *root_node;
    public:
	bst ();
	~bst ();

	node* insert_node (node *root_ptr, int data);
	void delete_node (node *root_ptr, int data);
	void inorder_traversal (node *root_ptr);
	node* get_root ();
};

bst::bst ()
{
    root_node = nullptr;
}

bst::~bst ()
{

}

node* bst::insert_node (node *root_ptr, int idata)
{
    if (root_ptr == nullptr)
    {
        return new node (idata);
    }
    else if (root_ptr->data > idata)
    {
        root_ptr->lnode = insert_node (root_ptr->lnode, idata);
    }
    else
    {
        root_ptr->rnode = insert_node (root_ptr->rnode, idata);
    }
    root_node = root_ptr;
    return root_ptr;
}


void bst::inorder_traversal (node *node_ptr)
{
    if (node_ptr == nullptr)
    {
        return;
    }
    inorder_traversal (node_ptr->lnode);
    std::cout << node_ptr->data << " ";
    inorder_traversal (node_ptr->rnode);
    std::cout << std::endl;
}

node* bst::get_root()
{
    return root_node;
}

int main (int argc, char **argv)
{
    bst mybst;

    mybst.inorder_traversal(mybst.get_root());
    mybst.insert_node(mybst.get_root(), 50);
    mybst.inorder_traversal(mybst.get_root());
    mybst.insert_node(mybst.get_root(), 60);
    mybst.inorder_traversal(mybst.get_root());

    return 0;
}

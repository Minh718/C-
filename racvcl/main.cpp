#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *pRight;
    Node *pLeft;
    Node *pParent;

public:
    Node(int val) : val(val), pRight(NULL), pLeft(NULL), pParent(NULL) {};
};
class SplayTree
{
private:
    Node *root;

public:
    SplayTree() : root(NULL) {};

    Node *rotateRight(Node *root, Node *pRoot)
    {
        Node *newRoot = root->pLeft;
        if (pRoot)
        {
            if (pRoot->pLeft == root)
            {
                pRoot->pLeft = newRoot;
            }
            else
                pRoot->pRight = newRoot;
        }
        Node *branch = newRoot->pRight;
        newRoot->pRight = root;
        root->pParent = newRoot;
        root->pLeft = branch;
        if (branch)
            branch->pParent = root;
        newRoot->pParent = pRoot;
        return newRoot;
    }
    Node *rotateleft(Node *root, Node *pRoot)
    {
        Node *newRoot = root->pRight;
        if (pRoot)
        {
            if (pRoot->pLeft == root)
            {
                pRoot->pLeft = newRoot;
            }
            else
                pRoot->pRight = newRoot;
        }
        Node *branch = newRoot->pLeft;
        newRoot->pLeft = root;
        root->pParent = newRoot;
        root->pRight = branch;
        if (branch)
            branch->pParent = root;
        newRoot->pParent = pRoot;
        return newRoot;
    }
    Node *Splay(Node *root, Node *p)
    {
        while (p->pParent)
        {
            if (p->pParent == root)
            {

                if (p == root->pLeft)
                {
                    return rotateRight(root, root->pParent);
                }
                else
                    return rotateleft(root, root->pParent);
            }
            else
            {
                Node *parent = p->pParent;
                Node *gParent = parent->pParent;

                if (parent == gParent->pLeft)
                {
                    if (p == parent->pLeft)
                    {
                        parent = rotateRight(gParent, gParent->pParent);
                        p = rotateRight(parent, parent->pParent);
                    }
                    else
                    {
                        p = rotateleft(parent, parent->pParent);
                        p = rotateRight(gParent, gParent->pParent);
                    }
                }
                else if (parent == gParent->pRight)
                {
                    if (p == parent->pRight)
                    {
                        parent = rotateleft(gParent, gParent->pParent);
                        p = rotateleft(parent, parent->pParent);
                    }
                    else
                    {
                        p = rotateRight(parent, parent->pParent);
                        p = rotateleft(gParent, gParent->pParent);
                    }
                }
            }
        }
        return p;
    }
    Node *insert(Node *root, int val)
    {
        Node *p = new Node(val);
        Node *temp = root;
        Node *y = NULL;
        while (temp)
        {
            y = temp;
            if (temp->val > val)
                temp = temp->pLeft;
            else
                temp = temp->pRight;
            p->pParent = y;
        }
        if (y == NULL)
        {
            root = p;
        }
        else if (y->val > val)
            y->pLeft = p;
        else
            y->pRight = p;
        root = Splay(root, p);
        return root;
    }
    void display(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->val << " ";
        display(root->pLeft);
        display(root->pRight);
    }
    void display()
    {
        display(this->root);
        cout << endl;
    }
    void insert(int val)
    {
        this->root = insert(root, val);
    }
   Node* searchNode(int val,bool& check)
    {
    Node* curr = this->root;
    Node* prev = NULL;
    while(curr){
        prev = curr;
        if(curr->val>val) curr = curr->pLeft;
        else if(curr->val<val) curr = curr->pRight;
        else {
            check = true;
            return curr;
        }
    }
    return prev;
    }
    Node *deletehead(Node *root)
    {
        if (root->pLeft == NULL && root->pRight == NULL)
        {
            delete root;
            root = NULL;
            return root;
        }
        else if (root->pLeft == NULL)
        {
            Node *temp = root;
            root = root->pRight;
            root->pParent = NULL;
            delete temp;
        }
        else if (root->pRight == NULL)
        {
            Node *temp = root;
            root = root->pLeft;
             root->pParent = NULL;
            delete temp;
        }
        else
        {
            Node *nodeLeft = root->pLeft;
            nodeLeft->pParent = NULL;
            Node *nodeRight = root->pRight;
            nodeRight->pParent = NULL;
            Node *maxNodeLeft = nodeLeft;
            while (maxNodeLeft->pRight != NULL)
            {
                maxNodeLeft = maxNodeLeft->pRight;
            }
            delete root;
            root = NULL;
            nodeLeft = Splay(nodeLeft, maxNodeLeft);
            nodeLeft->pRight = nodeRight;
            nodeRight->pParent = nodeLeft;
            return nodeLeft;
        }
        return root;
    }
        Node *remove(int val)
        {
            bool check = false;
            Node* nodeD = searchNode(val, check);
            this->root = Splay(root, nodeD);

            cout<<root->val<<endl;
            if (check)
            {
                this->root = deletehead(root);
            }
            else
            {
                return NULL;
            }
            return this->root;
        }
    };
    int main()
    {
        SplayTree tree;
        tree.insert(15);
        tree.insert(3);
        tree.display();
        tree.remove(15);
        tree.display();
        tree.insert(5);
        tree.insert(1);
        tree.display();
        tree.remove(1);
        tree.display();
    }

#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

public:
    Node(int val) : val(val), left(NULL), right(NULL){};
};
class TreeAVT
{
private:
    Node *root;

public:
    TreeAVT() : root(NULL){};
    int getHeight(Node *root)
    {
        if (root == NULL)
            return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return l > r ? l + 1 : r + 1;
    }
    int getBalanceFactor(Node *root)
    {
        if (root == NULL)
            return 0;
        return getHeight(root->right) - getHeight(root->left);
    }
    Node *rotateLeft(Node *root)
    {
        Node *newRoot = root->right;
        Node *p = newRoot->left;
        newRoot->left = root;
        root->right = p;
        return newRoot;
    }
    Node *rotateRight(Node *root)
    {
        Node *newRoot = root->left;
        Node *p = newRoot->right;
        newRoot->right = root;
        root->left = p;
        return newRoot;
    }
    Node *findMax(Node *root)
    {
        while (root->right)
        {
            root = root->right;
        }
        return root;
    }
    Node *deleteNode(Node *root, int val)
    {
        if (root == NULL)
            return NULL;
        if (root->val > val)
            root->left = deleteNode(root->left, val);
        else if (root->val < val)
            root->right = deleteNode(root->right, val);
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
                return root;
            }
            else if (root->left == NULL)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            else if (root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            else
            {
                Node *maxLeft = findMax(root->left);
                root->val = maxLeft->val;
                root->left = deleteNode(root->left, maxLeft->val);
            }
        }
        int balance = getBalanceFactor(root);
        if (balance == 2)
        {

            if (getBalanceFactor(root->right) >= 0)
            {
                root = rotateLeft(root);
            }
            else
            {
                root->right = rotateRight(root->right);
                root = rotateLeft(root);
            }
        }
        else if (balance == -2)
        {
            if (getBalanceFactor(root->left) <= 0)
            {
                root = rotateRight(root);
            }
            else
            {
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        }
        return root;
    }
    void deleteNode(int val)
    {
        this->root = deleteNode(this->root, val);
    }
    Node *insert(Node *root, int val)
    {
        if (root == NULL)
        {
            Node *p = new Node(val);
            return p;
        }
        if (root->val > val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        int balance1 = getBalanceFactor(root);
        // ngieng right
        if (balance1 > 1)
        {
            if (root->right->val < val)
            {
                root = rotateLeft(root);
            }
            else
            {
                root->right = rotateRight(root->right);
                root = rotateLeft(root);
            }
        }
        else if (balance1 < -1)
        {
            if (root->left->val > val)
            {
                root = rotateRight(root);
            }
            else
            {
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        }
        return root;
    }
    void insert(int key)
    {
        this->root = insert(this->root, key);
    }
    void display(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->val << " ";
        display(root->left);
        display(root->right);
    }
    void display()
    {
        display(this->root);
    }
    int getHeight()
    {
        return getHeight(this->root);
    }
};
int main()
{
    int arr[] = {1, 12, 4, 16, 7, 6, 23, 17, 36, 9};
    TreeAVT s;
    for (int i = 0; i < 10; i++)
    {
        s.insert(arr[i]);
    }
    s.display();
    cout << endl;
    s.deleteNode(16);
//        s.deleteNode(12);

    s.display();
    //    cout<<endl<<s.getHeight();
}

#include<iostream>
#include<fstream>

using namespace std;

template <class T>
class BTreeNode
{
public:

    ofstream outfile;

    string file_num;

    int line_num;

    T* keys;  // An array of keys
    string* s_keys;
    int* i_keys;

    int t;      // Minimum degree (defines the range for number of keys)

    BTreeNode<T>** childnode; // An array of child pointers

    int number_keys;     // Current number of keys

    bool leaf_node; // Is true when node is leaf_node. Otherwise false


    BTreeNode(int t_1, bool leaf_node1)
    {
        // Copy the given minimum degree and leaf property
        t = t_1;

        leaf_node = leaf_node1;

        // Allocate memory for maximum number of possible keys
        // and child pointers
        keys = new T[2 * t - 1];
        s_keys = new string[2 * t - 1];
        i_keys = new int[2 * t - 1];

        childnode = new BTreeNode * [2 * t];

        number_keys = 0;
    }


    void Traverse(BTreeNode* temp_node)
    {

        outfile.open("btreeidfile.txt");

        int i = 0;
        while (i < number_keys)
        {

            if (leaf_node == false)
            {
                childnode[i]->Traverse(temp_node);
            }

            cout << keys[i] << endl;
            cout << s_keys[i] << endl;
            cout << i_keys[i] << endl;
            cout << endl << endl;
            outfile << keys[i] << endl;
            outfile << s_keys[i] << endl;
            outfile << i_keys[i] << endl;
            i++;

        }

        if (leaf_node == false)
            childnode[i]->Traverse(temp_node);
    }


    void insertNonFull(T k, string file_n, int l_no)
    {
        int i = number_keys - 1;

        if (leaf_node == true)
        {

            while (i >= 0 && keys[i] > k)
            {
                keys[i + 1] = keys[i];
                s_keys[i + 1] = s_keys[i];
                i_keys[i + 1] = i_keys[i];
                i--;
            }

            keys[i + 1] = k;
            s_keys[i + 1] = file_n;
            i_keys[i + 1] = l_no;
            number_keys = number_keys + 1;
        }
        else
        {
            while (i >= 0 && keys[i] > k)
                i--;

            if (childnode[i + 1]->number_keys == 2 * t - 1)
            {

                splitChild(i + 1, childnode[i + 1]);

                if (keys[i + 1] < k)
                    i++;
            }
            childnode[i + 1]->insertNonFull(k, file_n, l_no);
        }
    }

    void splitChild(int i, BTreeNode* temp_node_1)
    {
        BTreeNode* temp_node_2 = new BTreeNode(temp_node_1->t, temp_node_1->leaf_node);
        temp_node_2->number_keys = t - 1;

        for (int j = 0; j < t - 1; j++)
        {
            temp_node_2->keys[j] = temp_node_1->keys[j + t];
            temp_node_2->s_keys[j] = temp_node_1->s_keys[j + t];
            temp_node_2->i_keys[j] = temp_node_1->i_keys[j + t];
        }

        if (temp_node_1->leaf_node == false)
        {
            for (int j = 0; j < t; j++)
                temp_node_2->childnode[j] = temp_node_1->childnode[j + t];
        }

        temp_node_1->number_keys = t - 1;

        for (int j = number_keys; j >= i + 1; j--)
        {
            childnode[j + 1] = childnode[j];
        }


        childnode[i + 1] = temp_node_2;


        for (int j = number_keys - 1; j >= i; j--)
        {
            keys[j + 1] = keys[j];
            s_keys[j + 1] = s_keys[j];
            i_keys[j + 1] = i_keys[j];
        }


        keys[i] = temp_node_1->keys[t - 1];
        s_keys[i] = temp_node_1->s_keys[t - 1];
        i_keys[i] = temp_node_1->i_keys[t - 1];

        number_keys = number_keys + 1;
    }

    BTreeNode* search(int temp_node)
    {
        // Find the first key greater than or equal to k
        int i = 0;
        while (i < number_keys && temp_node > keys[i])
        {
            i++;
        }


        // If the found key is equal to k, return this node
        if (keys[i] == temp_node)
            return this;

        // If key is not found here and this is a leaf_node node
        if (leaf_node == true)
            return NULL;

        // Go to the appropriate child
        return childnode[i]->search(temp_node);
    }

    template <class T>
    friend class BTree;
};

template <class T>
class BTree
{
public:

    BTreeNode<T>* root;
    int t;  // Minimum degree


    BTree()
    {
        root = NULL;
    }

    void setkey(int temp_key)
    {
        this->t = temp_key;
    }

    void traverse()
    {

        if (root != NULL)
        {
            root->Traverse(this->root);
        }
    }



    BTreeNode<T>* search(int temp_k)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            return root->search(temp_k);
        }
    }

    void insert(T k, string file_nam, int no)
    {
        // If tree is empty
        if (this->root == NULL)
        {
            // Allocate memory for root
            this->root = new BTreeNode<T>(this->t, true);
            this->root->keys[0] = k;
            this->root->s_keys[0] = file_nam;
            this->root->i_keys[0] = no;
            this->root->number_keys = 1;
        }
        else
        {
            // If root is full, then tree grows in height
            if (this->root->number_keys == 2 * t - 1)
            {
                // Allocate memory for new root
                BTreeNode<T>* temp_node = new BTreeNode<T>(this->t, false);

                // Make old root as child of new root
                temp_node->childnode[0] = root;

                // Split the old root and move 1 key to the new root
                temp_node->splitChild(0, root);

                // New root has two children now.  Decide which of the
                // two children is going to have new key
                int i = 0;

                if (temp_node->keys[0] < k)
                {
                    i++;
                }
                temp_node->childnode[i]->insertNonFull(k, file_nam, no);

                // Change root
                this->root = temp_node;
            }
            else  // If root is not full, call insertNonFull for root
            {
                this->root->insertNonFull(k, file_nam, no);
            }

        }
    }


    void rangeSearch(BTreeNode<T>* root, T low, T high) {

        if (root == nullptr) {
            return;
        }

        ostream of;
        // If the current node's value is in the range, print it
        if (root->keys >= low && root->keys <= high) {
            int line_count = 0;
            ifstream of;
            string s;
            of.open(root->filename);
            while (!of.eof()) {
                if (line_count == root->line_num) {
                    break;
                }
                line_count++;

                getline(of, s);
            }

            cout << s << endl;
            //cout << root->data << " " << endl;
        }

        if (root->keys > low) {
            rangeSearch(root->leftchild, low, high);
            int line_count = 0;
            ifstream of;
            string s;
            of.open(root->filename);
            while (!of.eof()) {
                if (line_count == root->line_num) {
                    break;
                }
                line_count++;

                getline(of, s);
            }

            cout << s << endl;
            //cout << root->data << endl;

        }
        if (root->keys < high) {
            rangeSearch(root->rightchild, low, high);
            int line_count = 0;
            ifstream of;
            string s;
            of.open(root->filename);
            while (!of.eof()) {
                if (line_count == root->line_num) {
                    break;
                }
                line_count++;

                getline(of, s);
            }

            cout << s << endl;
            //cout << root->data << endl;
        }
    }


    bool pointSearch(BTreeNode<T>* root, T data) {
        if (root == nullptr) {
            cout << "Tree is Empty\n";

            return false;
        }

        if (root->data == data) {
            // If the value is present in the tree, return true
            cout << root->data << endl;
            cout << root->filename << endl;
            cout << root->line_num << endl;
            int line_count = 0;
            ifstream of;
            string s;
            of.open(root->filename);
            while (!of.eof()) {
                if (line_count == root->line_num) {
                    break;
                }
                line_count++;

                getline(of, s);
            }

            cout << s << endl;


            return true;
        }

        if (data < root->data) {

            return pointSearch(root->leftchild, data);
            cout << root->data << endl;
            cout << root->filename << endl;
            cout << root->line_num << endl;
            int line_count = 0;
            ifstream of;
            of.open(root->filename);
            string s;
            while (!of.eof()) {
                if (line_count == root->line_num) {
                    break;
                }
                line_count++;

                getline(of, s);
            }


            cout << s << endl;

        }

        else {
            return pointSearch(root->rightchild, data);
            cout << root->data << endl;
            cout << root->filename << endl;
            cout << root->line_num << endl;
            int line_count = 0;
            ifstream of;
            of.open(root->filename);
            string s;
            while (!of.eof()) {
                if (line_count == root->line_num) {
                    break;
                }

                line_count++;
                getline(of, s);
            }

            cout << s << endl;

        }
    }
};

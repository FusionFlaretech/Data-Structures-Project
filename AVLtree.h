#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

template <class T>
class SNode
{
public:

	T data;
	SNode <T>* next;
	string file_n;
	int line_number;


	SNode()
	{
		data = '\0';
		next = NULL;
		data = NULL;
	}

	SNode(string file, int line)
	{
		line_number = line;
		file_n = file;
		next = NULL;

	}

};

template <class T>
class SLinkedList {

public:

	SNode<T>* head;


	SLinkedList()
	{
		head = NULL;
	}

	void insert(string f, int l) {


		SNode<T>* n = new SNode<T>(f, l);
		n->next = NULL;
		if (head == NULL) {
			head = n;
		}
		else {

			SNode<T>* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;

			}
			temp->next = n;
		}

		print();
	}

	void insertAtHead(T data) {
		SNode<T>* n = new SNode<T>(data);
		n->next = head;
		head = n;
		
	}

	void InsertAtIndex(int v, int ind) {
		SNode<T>* n = new SNode<T>(v);
		SNode<T>* temp = head;
		int currindex = 1;

		while (currindex != ind) {
			temp = temp->next;
			currindex++;
		}
		n->next = temp->next;
		temp->next = n;
		//print();
	}

	int search(int x) {
		SNode<T>* temp = head;
		int i = 0;
		while (temp != NULL) {
			if (temp->data == x) {
				return i;
				break;
			}
			temp = temp->next;
			i++;
		}



	}

	void update(int index, int data2) {
		SNode<T>* temp = head;
		int i = 0;
		while (i != index) {
			temp = temp->next;
			i++;
		}
		temp->data = data2;

	}

	void remove(int ind) {
		SNode<T>* n = head;
		SNode<T>* temp = head;
		int i = 0;
		while (ind != i && n != NULL) {
			temp = n;
			n = n->next;
			i++;
		}
		temp->next = n->next;
		delete n;
	}


	void print() {

		SNode<T>* n = head;
		while (n->next != NULL) {

			cout << n->data << endl;
			cout << n->file_n << endl;
			cout << n->line_number << endl;
			n = n->next;
		}
		cout << n->data << endl;
		cout << n->file_n << endl;
		cout << n->line_number << endl;
		n = n->next;
	}

	void mergeLists(SLinkedList obj) {

		SLinkedList merge;
		SNode<T>* n = head;
		SNode<T>* n2 = obj.head;
		while (n != NULL && n2 != NULL) {
			merge.insert(n->data);
			merge.insert(n2->data);
			n = n->next;
			n2 = n2->next;
		}
		head = merge.head;

	}

};


template<class T>
class Treenode {
public:
	//SNode<T>* s;
	T data;
	Treenode<T>* leftchild;
	Treenode<T>* rightchild;
	int height;
	string filename;
	int line_num;

	Treenode() {
		data = '\0';
		leftchild = NULL;
		rightchild = NULL;
		height = 0;
		filename = '\0';
		line_num = 0;
	}

	Treenode(T d) {
		this->data = d;
	}

	Treenode(Treenode<T>* lc, Treenode<T>* rc) {
		leftchild = lc;
		rightchild = rc;
	}


	void storenode(ofstream& file) {
		file << data << endl;
		file << filename << endl;
		file << line_num << endl;

	}

	//void print(ofstream& f) {
	//	
	//	SLinkedList<T> sll;
	//	SNode<T>* n = sll.head;
	//	while (n != NULL) {
	//		f << n->data << endl;
	//		f << n->file_n << endl;
	//		f << n->line_number << endl;
	//		n = n->next;
	//	}
	//	//f << n->data << endl;
	//	f << n->file_n << endl;
	//	f << n->line_number << endl;
	//	n = n->next;
	//}

};



template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Treenode<T>* t;
	

	Node()
	{
		next = NULL;
		data = NULL;
	}

	Node(T d)
	{
		data = d;
		next = NULL;
	}

	Node(Treenode<T>*  t_n)
	{
		t = t_n;
		next = NULL;
	}

};


template <class T>
class Queue
{
public:
	Node <T>* front;
	Node <T>* rear;
	int count = 0;


	Queue()
	{
		front = NULL;
		rear = NULL;
	}

	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		else
			return false;
	}

	void enqueue(Treenode<T>* p)
	{
		Node<T>* temp = new Node<T>(p);
		if (isEmpty())
		{
			front = temp;
			rear = temp;
			count++;
		}
		else
		{
			rear->next=temp;
			rear = rear->next;
			count++;
		}
	}

	void dequeue()
	{
		Node <T>* temp = front;
		front = temp->next;
		delete temp;
		count--;
	}

	Treenode<T>* Front()
	{
		return front->t;
	}

	void print()
	{
		Node <T>* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

};



template<class T>
class AVLtree {
public:

	
	Treenode<T>* root;

	AVLtree() {
		root = NULL;
	}

	int TreeHeight(Treenode<T>* p) {
		if (p == NULL) {
			return -1;
		}
		else {
			return p->height;
		}
	}

	int Max_h(int a, int b) {
		if (a > b) {
			return a;
		}
		else {
			return b;
		}
	}

	int getBalance(Treenode<T>* N)
	{
		if (N == NULL)
			return -1;
		return TreeHeight(N->leftchild) - TreeHeight(N->rightchild);
	}




	Treenode<T>* newnode(T val, string name, int line) {
		Treenode<T>* Node = new Treenode<T>;
		Node->data = val;
		Node->filename = name;
		Node->line_num = line;
		Node->leftchild = NULL;
		Node->rightchild = NULL;
		Node->height = 0;
		return Node;
	}

	Treenode<T>* RR(Treenode<T>* n) {
		Treenode<T>* x = n->leftchild;
		Treenode<T>* temp = x->rightchild;

		x->rightchild = n;
		n->leftchild = temp;

		n->height = Max_h(TreeHeight(n->leftchild), TreeHeight(n->rightchild)) + 1;
		x->height = Max_h(TreeHeight(x->leftchild), TreeHeight(x->rightchild)) + 1;

		return x;
	}

	Treenode<T>* LL(Treenode<T>* x)
	{
		Treenode<T>* y = x->rightchild;
		Treenode<T>* T2 = y->leftchild;

		y->leftchild = x;
		x->rightchild = T2;

		x->height = Max_h(TreeHeight(x->leftchild), TreeHeight(x->rightchild)) + 1;
		y->height = Max_h(TreeHeight(y->leftchild), TreeHeight(y->rightchild)) + 1;

		return y;
	}

	Treenode<T>* Insert(Treenode<T>* n, T k, string file_nam, int no) {

		SLinkedList<string> SLL;

		if (n == NULL) { 

			return newnode(k, file_nam, no);

		}

		if (k < n->data) {
			n->leftchild = Insert(n->leftchild, k, file_nam, no);

		}
		else if (k > n->data) {
			n->rightchild = Insert(n->rightchild, k, file_nam, no);
		}

		else {
			SLL.insert(file_nam, no);

			return n;
		}


		n->height = 1 + Max_h(TreeHeight(n->leftchild), TreeHeight(n->rightchild));

		int balance = getBalance(n);


		if (balance > 1 && k < n->leftchild->data)
			return RR(n);

		// Right Right Case
		if (balance < -1 && k > n->rightchild->data)
			return LL(n);

		// Left Right Case
		if (balance > 1 && k > n->leftchild->data)
		{
			n->leftchild = LL(n->leftchild);
			return RR(n);
		}

		// Right Left Case
		if (balance < -1 && k < n->rightchild->data)
		{
			n->rightchild = RR(n->rightchild);
			return LL(n);
		}


		return n;
	}


	/*void deleteNodeFromFile(T value)
	{
		Treenode<T>* node = findNode(value);
		cout << node->data << endl;
		cout << node->filename << endl;
		cout << node->line_num << endl;
		string str = node->filename;
		ifstream read;
		read.open(node->filename);
		string s;

		int line_count = 0;
		while (!read.eof()) {
			if (line_count == node->line_num) {
				break;
			}

			line_count++;
			getline(read, s);
		}

		cout << s << endl;
		delete_node(root, value);
		
		
	}*/

	Treenode<T>* getMinNode(Treenode<T>* r)
	{
		Treenode<T>* temp = r;
		while (temp->leftchild != NULL)
		{
			temp = temp->leftchild;
		}
		return temp;
	}


	//Treenode<T>* delete_node(Treenode<T>* node, T d) {
	//	if (root == NULL) {
	//		return root;
	//	}

	//	if (d < node->data) {
	//		node->leftchild = delete_node(node->leftchild, d);
	//	}
	//	else if (d > node->data) {
	//		node->rightchild = delete_node(node->rightchild, d);
	//	}

	//	else {
	//		if (node->leftchild == NULL || node->rightchild == NULL) {
	//			Treenode<T>* temp = node->leftchild ? node->leftchild : node->rightchild;
	//			if (temp == NULL) {
	//				temp = root;
	//				root = NULL;
	//				return NULL;
	//			}

	//			else {
	//				*node = *temp;
	//			}
	//			delete (temp);
	//		}
	//		else
	//		{
	//			
	//			Treenode<T>* temp = getMinNode(node->rightchild);

	//			
	//			root->data = temp->data;

	//			// Delete the inorder successor 
	//			root->rightchild = delete_node(node->rightchild, temp->data);
	//		}
	//	}

	//	
	//	if (root == NULL) {
	//		return root;
	//	}
	//	node->height = 1 + Max_h(TreeHeight(root->leftchild), TreeHeight(root->rightchild));

	//	int balance = getBalance(root);

	//	

	//	// Left Left Case 
	//	if (balance > 1 && getBalance(root->leftchild) >= 0)
	//		return RR(root);

	//	// Left Right Case 
	//	if (balance > 1 && getBalance(root->leftchild) < 0)
	//	{
	//		root->leftchild = LL(root->leftchild);
	//		return RR(root);
	//	}

	//	// Right Right Case 
	//	if (balance < -1 && getBalance(root->rightchild) <= 0)
	//		return LL(root);

	//	// Right Left Case 
	//	if (balance < -1 && getBalance(root->rightchild) > 0)
	//	{
	//		root->rightchild = RR(root->rightchild);
	//		return LL(root);
	//	}

	//	return root;
	//}



	void printInorder(Treenode<T>* node)
	{
		if (node == NULL)
			return;

		printInorder(node->leftchild);

		cout << node->data << " ";

		printInorder(node->rightchild);
	}

	void printPreorder(Treenode<T>* node)
	{
		if (node == NULL)
			return;

		cout << node->data << " ";

		printPreorder(node->leftchild);

		printPreorder(node->rightchild);
	}


	void printPostorder(Treenode<T>* node)
	{
		if (node == NULL)
			return;

		printPostorder(node->leftchild);

		printPostorder(node->rightchild);

		cout << node->data << " ";
	}

	void rangeSearch(Treenode<T>* root, T low, T high) {

		if (root == nullptr) {
			return;
		}

		// If the current node's value is in the range, print it
		if (root->data >= low && root->data <= high) {
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

		if (root->data > low) {
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
		if (root->data < high) {
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


	bool pointSearch(Treenode<T>* root, T data) {
		if (root == nullptr) {
			cout << "Tree is Empty\n";
			
			return false;
		}

		if (root->data == data) {
			// If the value is present in the tree, return true
			cout << root->data << endl;
			cout << root->filename << endl;
			cout << root->line_num << endl;
			int line_count=0;
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

	void updateNode(T p_value, T n_value)
	{
		Treenode<T>* node = findNode(p_value);
		cout << node->data << endl;
		cout << node->filename << endl;
		cout << node->line_num << endl;
		string str = node->filename;
		ifstream read;
		read.open(node->filename);
		string s, s2;

		int line_count=0;
		while (!read.eof()) {
			if (line_count == node->line_num) {
				break;
			}

			line_count++;
			getline(read, s);
		}

		cout << s << endl;

		read.close();
		// Update the node's value
		node->data = n_value;

		Insert(root, n_value, node->filename, node->line_num);
		
		balanceTree(node);
	}

	Treenode<T>* findNode(T value)
	{
		
		Treenode<T>* current = root;

		while (current && current->data != value)
		{
			if (value < current->data)
				current = current->leftchild;
			else
				current = current->rightchild;
		}
		return current;
	}


	
	void balanceTree(Treenode<T>* node)
	{
		// Calculate the balance factor of the node
		int balance = getBalance(node);

		// If the node is unbalanced, perform the appropriate rotation
		if (balance < -1)
		{
			if (getBalance(node->rightchild) > 0)
				node->rightchild = RR(node->rightchild);
			node = LL(node);
		}
		else if (balance > 1)
		{
			if (getBalance(node->leftchild) < 0)
				node->leftchild = LL(node->leftchild);
			node = RR(node);
		}
	}

	

	void LevelOrder(string datafield)               

	{
		Queue<T>* q = new Queue<T>;
		ofstream output;
		string file = "AVL In ";

		file += datafield;
		file += ".txt";
		output.open(file, ios::app);

		

		if (root)
		{
			q->enqueue(root);
			while (!q->isEmpty())
			{
				if (q->Front()->leftchild)
				q->enqueue(q->Front()->leftchild);
				if (q->Front()->rightchild)
				q->enqueue(q->Front()->rightchild);
				Treenode<T>* temp = q->Front();
				temp->storenode(output);
				//temp->print(output);
				
				q->dequeue();
			}
		}
		delete q;
		output.close();

	}

};




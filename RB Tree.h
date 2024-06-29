#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
// Implementing Red-Black Tree in C++
template <typename T>
struct Nodes
{
	T key;
	bool red;
	Nodes* left, * right, * parent;

	Nodes(T value, bool color, Nodes* l, Nodes* r, Nodes* p)
		: key(value), red(color), left(l), right(r), parent(p) {}
};

// Red-black tree
template <typename T>
class rbtimp
{
private:
	Nodes<T>* root;

public:
	rbtimp() : root(nullptr) {}

	void insert(T key)
	{
		// Create new node
		Nodes<T>* node = new Nodes<T>(key, true, nullptr, nullptr, nullptr);

		// Insert node into tree
		insert(node);
	}

	void remove(T key)
	{
		// Search for node to remove
		Nodes<T>* node = search(key);
		if (node == nullptr)
			return;

		// Remove node from tree
		remove(node);
	}

	Nodes<T>* search(T key)
	{
		// Start at root node
		Nodes<T>* node = root;

		// Search for node with given key
		while (node != nullptr && key != node->key)
		{
			if (key < node->key)
				node = node->left;
			else
				node = node->right;
		}

		// Return node with given key, or nullptr if not found
		return node;
	}

private:
	void insert(Nodes<T>* node)
	{
		// Start at root node
		Nodes<T>* curr = root;
		Nodes<T>* prev = nullptr;

		// Find insertion point
		while (curr != nullptr)
		{
			prev = curr;
			if (node->key < curr->key)
				curr = curr->left;
			else
				curr = curr->right;
		}

		// Insert new node
		node->parent = prev;
		if (prev == nullptr)
			root = node;
		else if (node->key < prev->key)
			prev->left = node;
		else
			prev->right = node;

		// Fix red-black tree properties
		insertFixup(node);
	}

	void remove(Nodes<T>* node)
	{
		// Swap node with its successor
		Nodes<T>* succ = successor(node);
		if (succ != nullptr)
		{
			std::swap(node->key, succ->key);
			node = succ;
		}

		// Get child nodes
		Nodes<T>* left = node->left;
		Nodes<T>* right = node->right;


		//////////////////////////////////////////////////////////
		// Remove node from tree
		if (left == nullptr && right == nullptr)
		{
			// Node is a leaf, remove it
			if (node == root)
				root = nullptr;
			else
			{
				Nodes<T>* parent = node->parent;
				if (parent->left == node)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			delete node;
		}
		else if (left != nullptr && right == nullptr)
		{
			// Node has only left child, replace it with left child
			if (node == root)
				root = left;
			else
			{
				Nodes<T>* parent = node->parent;
				if (parent->left == node)
					parent->left = left;
				else
					parent->right = left;
			}
			left->parent = node->parent;
			delete node;
		}
		else if (left == nullptr && right != nullptr)
		{
			// Node has only right child, replace it with right child
			if (node == root)
				root = right;
			else
			{
				Nodes<T>* parent = node->parent;
				if (parent->left == node)
					parent->left = right;
				else
					parent->right = right;
			}
			right->parent = node->parent;
			delete node;
		}
		else
		{
			// Node has both left and right children, replace it with successor
			Nodes<T>* parent = node->parent;
			if (parent->left == node)
				parent->left = succ;
			else
				parent->right = succ;
			succ->left = left;
			left->parent = succ;
			delete node;
		}

		// Fix red-black tree properties
		removeFixup(node);
	}

	Nodes<T>* successor(Nodes<T>* node)
	{
		// Check for right child
		if (node->right != nullptr)
			return minimum(node->right);

		// Check for parent
		Nodes<T>* parent = node->parent;
		while (parent != nullptr && node == parent->right)
		{
			node = parent;
			parent = parent->parent;
		}

		// Return successor node
		return parent;
	}

	Nodes<T>* minimum(Nodes<T>* node)
	{
		// Find leftmost leaf
		while (node->left != nullptr)
			node = node->left;
		return node;
	}

	void insertFixup(Nodes<T>* node)
	{
		// Fix red-black tree properties after insert

		while (node != root && node->parent->red)
		{
			// Get parent, grandparent, and uncle nodes
			Nodes<T>* parent = node->parent;
			Nodes<T>* grandparent = parent->parent;
			Nodes<T>* uncle = (parent == grandparent->left) ? grandparent->right : grandparent->left;

			// Check for red uncle
			if (uncle != nullptr && uncle->red)
			{

				///////////////////////////////////////////
				// Color parent and uncle black, grandparent red
				parent->red = false;
				uncle->red = false;
				grandparent->red = true;

				// Set current node to grandparent
				node = grandparent;
			}
			else
			{
				// Uncle is black, perform rotation

				if (parent->right == node && grandparent->left == parent)
				{
					// Left-left case, rotate right
					rotateRight(parent);
					node = node->right;
				}
				else if (parent->left == node && grandparent->right == parent)
				{
					// Right-right case, rotate left
					rotateLeft(parent);
					node = node->left;
				}

				// Update parent and grandparent
				parent = node->parent;
				grandparent = parent->parent;

				// Perform rotation
				if (parent->left == node && grandparent->left == parent)
				{
					// Left-right case, rotate left then right
					rotateLeft(parent);
					rotateRight(grandparent);
				}
				else
				{
					// Right-left case, rotate right then left
					rotateRight(parent);
					rotateLeft(grandparent);
				}
			}
		}

		//void removeFixup(Node<T> *node)
		//{
		//	// Fix red-black tree properties after remove

		//	while (node != root && !node->red)
		//	{
		//		// Get sibling and parent nodes
		//		Node<T>* sibling = (node == node->parent->left) ? node->parent->right : node->parent->left;
		//		Node<T>* parent = node->parent;

		//		if (sibling->red)
		//		{
		//			// Sibling is red, rotate parent
		//			if (parent->left == sibling)
		//				rotateLeft(parent);
		//			else
		//				rotateRight(parent);

		//			// Update sibling and parent
		//			sibling = (node == parent->left) ? parent->right : parent->left;
		//			parent = node->parent;
		//		}

		//		// Check for black children
		//		if ((sibling->left == nullptr || !sibling->left->red) &&
		//			(sibling->right == nullptr || !sibling->right->red))
		//		{
		//			// Sibling has black children, color sibling red
		//			sibling->red = true;
		//			node = parent;
		//		}
		//		else
		//		{
		//			// Sibling has red children, rotate sibling
		//			if (parent->left == sibling &&
		//				(sibling->right == nullptr || !sibling->right->red))
		//			{
		//				rotateRight(sibling);
		//				sibling = sibling->parent;
		//			}
		//			else if (parent->right == sibling &&
		//				(sibling->left == nullptr || !sibling->left->red))
		//			{
		//				rotateLeft(sibling);
		//				sibling = sibling->parent;
		//			}

		//			// Color sibling and parent black, grandparent red
		//			sibling->red = false;
		//			parent->red = true;

		//			// Rotate parent
		//			if (parent->left == node)
		//				rotateLeft(parent);
		//			else
		//				rotateRight(parent);

		//			// Set current node to root
		//			node = root;
		//		}
		//	}


		//	//////////////////////////
		//	// Color root black
		//	node->red = false;
		//}

		//void rotateLeft(Node<T> *node)
		//{
		//	// Rotate node to the left

		//	Node<T>* right = node->right;
		//	node->right = right->left;
		//	if (right->left != nullptr)
		//		right->left->parent = node;
		//	right->parent = node->parent;
		//	if (node->parent == nullptr)
		//		root = right;
		//	else if (node->parent->left == node)
		//		node->parent->left = right;
		//	else
		//		node->parent->right = right;
		//	right->left = node;
		//	node->parent = right;
		//}

		//int rotateRight(Node<T> *node)
		//{
		//	// Rotate node to the right

		//	Node<T>* left = node->left;
		//	node->left = left->right;
		//	if (left->right != nullptr)
		//		left->right->parent = node;
		//	left->parent = node->parent;
		//	if (node->parent == nullptr)
		//		root = left;
		//	else if (node->parent->right == node)
		//		node->parent->right = left;
		//	else
		//		node->parent->left = left;
		//	left->right = node;
		//	node->parent = left;
		//}

	}
};

template <class T>
class coulredleaf
{
public:

	T shade;
	coulredleaf <T>* next;
	string file_n;
	int line_number;

	coulredleaf()
	{
		shade = '\0';
		next = NULL;
		shade = NULL;
	}

	coulredleaf(string file, int line)
	{
		line_number = line;
		file_n = file;
		next = NULL;

	}
};

template <class T>
class colour
{
public:
	T data;
	colour <T>* next;


	colour()
	{
		next = NULL;
		data = NULL;
	}

	colour(T d)
	{
		data = d;
		next = NULL;
	}
};

template <class T>
class colourcheck {

public:


	coulredleaf<T>* head;


	colourcheck()
	{
		head = NULL;
	}

	void insert(string red, int black) {


		coulredleaf<T>* col = new coulredleaf<T>(red, black);
		col->next = NULL;
		if (head == NULL) {
			head = col;
		}
		else {

			coulredleaf<T>* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;

			}
			temp->next = col;
		}
		print();

	}

	void insert(T data) {
		coulredleaf<T>* n = new coulredleaf<T>(data);
		n->next = head;
		head = n;

	}

	void insertatno(int v, int ind) {
		coulredleaf<T>* n = new coulredleaf<T>(v);
		coulredleaf<T>* temp = head;
		int currindex = 1;

		while (currindex != ind) {
			temp = temp->next;
			currindex++;
		}
		n->next = temp->next;
		temp->next = n;

	}

	int saerchingcolour(int x) {
		coulredleaf<T>* temp = head;
		int i = 0;
		while (temp != NULL) {
			if (temp->shade == x) {
				return i;
				break;
			}
			temp = temp->next;
			i++;
		}



	}

	void updation(int index, int data2) {
		coulredleaf<T>* temp = head;
		int i = 0;
		while (i != index) {
			temp = temp->next;
			i++;
		}
		temp->shade = data2;

	}

	void colourend(int ind) {
		coulredleaf<T>* n = head;
		coulredleaf<T>* temp = head;
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

		coulredleaf<T>* n = head;
		while (n->next != NULL) {
			cout << n->shade << "--";
			cout << n->file_n << "--";
			cout << n->line_number << "--";
			n = n->next;
		}
		cout << n->shade << endl;
		cout << n->file_n << endl;
		cout << n->line_number << endl;
		n = n->next;
	}

	void redandblack(colourcheck obj) {

		colourcheck merge;
		coulredleaf<T>* n = head;
		coulredleaf<T>* n2 = obj.head;
		while (n != NULL && n2 != NULL) {
			merge.insert(n->shade);
			merge.insert(n2->shade);
			n = n->next;
			n2 = n2->next;
		}
		head = merge.head;

	}

};
template <class T>
class colourinsert
{
public:
	colour<T>* firstred;
	colour<T>* firstblack;
	int count = 0;


	colourinsert()
	{
		firstred = NULL;
		firstblack = NULL;
	}

	bool colourstatus()
	{
		if (firstred == NULL)
		{
			return true;
		}
		else
			return false;
	}

	void redinsert(T d)
	{
		colour <T>* newNode = new colour<T>(d);
		if (colourstatus())
		{
			firstred = firstblack = newNode;
		}
		else
		{
			firstblack->next = newNode;
			firstblack = newNode;
		}
		count++;
	}

	void blackdel()
	{
		colour <T>* temp = firstred;
		firstred = temp->next;
		delete temp;
		count--;
	}

	T cloredcheck()
	{
		return firstred->data;
	}

	void colours()
	{
		colour <T>* temp = firstred;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

};

template<class T>
class children {
public:
	T data;
	children<T>* red;
	children<T>* black;
	int height;
	string name;
	int line;

	children() {
		data = '\0';
		red = NULL;
		black = NULL;
		height = 0;
		name = '\0';
		line = 0;
	}

	children(T d) {
		this->data = d;
	}

	children(children<T>* lc, children<T>* rc) {
		red = lc;
		black = rc;
	}

};

template<class T>
class redblacktree {
public:

	ofstream output;
	children<T>* root;

	redblacktree() {
		root = NULL;
	}

	int height(children<T>* p) {
		if (p == NULL) {
			return -1;
		}
		else {
			return p->height;
		}
	}

	int priority(int a, int b) {
		if (a > b) {
			return a;
		}
		else {
			return b;
		}
	}

	int evenout(children<T>* r)
	{
		if (r == NULL)
			return -1;
		return height(r->red) - height(r->black);
	}




	children<T>* colournew(T ans, string iden, int que) {
		children<T>* Node = new children<T>;
		Node->data = ans;
		Node->name = iden;
		Node->line = que;
		Node->red = NULL;
		Node->black = NULL;
		Node->height = 0;
		return Node;
	}

	children<T>* blacks(children<T>* a) {
		children<T>* r = a->red;
		children<T>* bl = r->black;

		r->black = a;
		a->red = bl;

		a->height = priority(height(a->red), height(a->black)) + 1;
		r->height = priority(height(r->red), height(r->black)) + 1;

		return r;
	}

	children<T>* reds(children<T>* x)
	{
		children<T>* y = x->black;
		children<T>* T2 = y->red;

		y->red = x;
		x->black = T2;

		x->height = priority(height(x->red), height(x->black)) + 1;
		y->height = priority(height(y->red), height(y->black)) + 1;

		return y;
	}

	children<T>* Insert(children<T>* n, T k, string point, int index) {

		colourcheck<string> SLL;

		if (n == NULL) {

			return colournew(k, point, index);

		}

		if (k < n->data) {
			n->red = Insert(n->red, k, point, index);

		}
		else if (k > n->data) {
			n->black = Insert(n->black, k, point, index);
		}

		else {
			SLL.insert(point, index);
			return n;
		}


		n->height = 1 + priority(height(n->red), height(n->black));

		int coleven = evenout(n);


		if (coleven > 1 && k < n->red->data)
			return blacks(n);


		if (coleven < -1 && k > n->black->data)
			return reds(n);


		if (coleven > 1 && k > n->red->data)
		{
			n->red = reds(n->red);
			return blacks(n);
		}


		if (coleven < -1 && k < n->black->data)
		{
			n->black = blacks(n->black);
			return reds(n);
		}


		return n;
	}


	children<T>* redblackmin(children<T>* r)
	{
		children<T>* r = r;
		while (r->red != NULL)
		{
			r = r->red;
		}
		return r;
	}


	children<T>* colourremove(children<T>* colour, T a) {
		if (root == NULL) {
			return root;
		}

		if (a < root->data) {
			root->red = colourremove(root->red, a);
		}
		else if (a > root->data) {
			root->black = colourremove(root->black, a);
		}

		else {
			if (root->red == NULL || root->black == NULL) {
				children<T>* temp = root->red ? root->red : root->black;
				if (temp == NULL) {
					temp = root;
					root = NULL;
					return NULL;
				}

				else {
					*root = *temp;
				}
				delete (temp);
			}
			else
			{

				children<T>* temp = redblackmin(root->black);


				root->data = temp->data;


				root->black = colourremove(root->black, temp->data);
			}
		}


		if (root == NULL) {
			return root;
		}
		root->height = 1 + priority(height(root->red), height(root->black));


		int balance = evenout(root);


		if (balance > 1 && evenout(root->red) >= 0)
			return blacks(root);


		if (balance > 1 && evenout(root->red) < 0)
		{
			root->red = reds(root->red);
			return blacks(root);
		}


		if (balance < -1 && evenout(root->black) <= 0)
			return reds(root);


		if (balance < -1 && evenout(root->black) > 0)
		{
			root->black = blacks(root->black);
			return reds(root);
		}

		return root;
	}

	children<T>* colouravailable(children<T>* col, T no) {

		if (col == NULL) {
			return NULL;
		}


		if (no < col->key) {
			return colouravailable(col->left, no);
		}


		else if (no > col->key)
		{
			return colouravailable(col->right, no);
		}

		else {
			return col;
		}
	}


	void redorder(children<T>* colour)
	{
		if (colour == NULL)
			return;

		redorder(colour->red);

		cout << colour->data << " ";

		redorder(colour->black);
	}

	void blackorder(children<T>* colour)
	{
		if (colour == NULL)
			return;

		cout << colour->data << " ";

		blackorder(colour->red);

		blackorder(colour->black);
	}


	void colourorder1(children<T>* node)
	{
		if (node == NULL)
			return;
		colourorder1(node->red);
		colourorder1(node->black);
		cout << node->data << " ";
	}


	void colourlevel(children<T>* n, string datafield)

	{
		string file="RB tree IN ";
		file += datafield;
		file += ".txt";
		output.open(file, ios::app);
		colourinsert<children<T>*> red;
		if (n == NULL)
		{
			return;
		}
		red.redinsert(n);
		while (!red.colourstatus())
		{
			children<T>* temp = red.cloredcheck();
			output << temp->data << endl;
			output << temp->name << endl;
			output << temp->line << endl << endl;
			if (temp->red != NULL)
			{
				red.redinsert(temp->red);
			}
			if (temp->black != NULL)
			{
				red.redinsert(temp->black);
			}
			red.blackdel();
		}
	}
	void rangeSearch(children<T>* root, T low, T high) {

		if (root == nullptr) {
			return;
		}

		// If the current node's value is in the range, print it
		if (root->data >= low && root->data <= high) {
			int line_count = 0;
			ifstream of;
			string s;
			of.open(root->name);
			while (!of.eof()) {
				if (line_count == root->line) {
					break;
				}
				line_count++;

				getline(of, s);
			}

			cout << s << endl;
			//cout << root->data << " " << endl;
		}

		// Recursively search the left and right subtrees if they may contain
		// values in the range
		if (root->data > low) {
			rangeSearch(root->red, low, high);
			//cout << root->data << endl;

		}
		if (root->data < high) {
			rangeSearch(root->black, low, high);
			//cout << root->data << endl;
		}
	}


	bool pointSearch(children<T>* root, T data) {
		if (root == nullptr) {
			cout << "Value not found\n";
			// If the tree is empty or the value is not present in the tree,
			// return false
			return false;
		}

		if (root->data == data) {
			// If the value is present in the tree, return true
			cout << root->data << endl;
			cout << root->name << endl;
			cout << root->line << endl;
			int line_count = 0;
			ifstream of;
			string s;
			of.open(root->name);
			while (!of.eof()) {
				if (line_count == root->line) {
					break;
				}
				line_count++;

				getline(of, s);
			}

			cout << s << endl;


			return true;
		}

		if (data < root->data) {
			// If the value is less than the current node's value, search the
			// left subtree

			return pointSearch(root->red, data);
			cout << root->data << endl;
			cout << root->name << endl;
			cout << root->line << endl;
			int line_count = 0;
			ifstream of;
			of.open(root->name);
			string s;
			while (!of.eof()) {
				if (line_count == root->line) {
					break;
				}
				line_count++;

				getline(of, s);
			}


			cout << s << endl;

		}

		else {
			// If the value is greater than the current node's value, search the
			// right subtree

			return pointSearch(root->black, data);
			cout << root->data << endl;
			cout << root->name << endl;
			cout << root->line << endl;
			int line_count = 0;
			ifstream of;
			of.open(root->name);
			string s;
			while (!of.eof()) {
				if (line_count == root->line) {
					break;
				}

				line_count++;
				getline(of, s);
			}

			cout << s << endl;

		}
	}
};



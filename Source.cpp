#include<iostream>
using namespace std;
#include <string>
#include <conio.h>
class Node {
public:
	int data;
	string name;
	Node *left;
	Node *right;
	Node(int d, string n) {
		data = d;
		left = NULL;
		right = NULL;
		name = n;
	}
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
		
	}
	
};
class Tree {
	

public:
	Node *root;
	Tree()
	{
		root = NULL;

	}
	void insertNode(int,string);
	void insertNodearr(int);
	void inorder(Node*ro);
	void preorder(Node*ro);
	void postorder(Node*ro);
	void searchNode(int d);
	void mirror(struct Node* node) {
		if (node == NULL) {
			return;
		}
		else {
			struct Node* temp;
			mirror(node->left);
			mirror(node->right);

			temp = node->left;
			node->left = node->right;
			node->right = temp;
		}
	}
};

void Tree::insertNode(int d,string n)
{
	Node*temp;
	temp = new Node(d,n);
	Node *cur;
	cur = root;
	Node*pre;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		do
		{
			pre = cur;
			if (temp->data < cur->data)
			{
				cur = cur->left;
				if (cur == NULL)
				{
					pre->left = temp;
					delete cur;
					return;
				}
			}

			else
			{
				cur = cur->right;
				if (cur == NULL)
				{
					pre->right = temp;
					delete cur;
					return;
				}
			}
		} while (cur!= NULL);
	}


}


void Tree::insertNodearr(int d)
{
	Node*temp;
	temp = new Node(d);
	Node *cur;
	cur = root;
	Node*pre;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		do
		{
			pre = cur;
			if (temp->data < cur->data)
			{
				cur = cur->left;
				if (cur == NULL)
				{
					pre->left = temp;
					delete cur;
					return;
				}
			}
			else
			{
				cur = cur->right;
				if (cur == NULL)
				{
					pre->right = temp;
					delete cur;
					return;
				}
			}
		} while (cur != NULL);
	}


}

void Tree::inorder(Node * ro)
{
	if (ro != NULL)
	{
		inorder(ro->left);
		cout << ro->data << " " << endl;
		inorder(ro->right);
	}
}
void Tree::preorder(Node * ro)
{
	if (ro != NULL)
	{
		cout << ro->data << " " << endl;
		preorder(ro->left);
		preorder(ro->right);
	}
}
void Tree::postorder(Node * ro)
{
	if (ro != NULL)
	{
		postorder(ro->left);
		postorder(ro->right);
		cout << ro->data << " " << endl;
	}
}

void Tree::searchNode(int q)

	{
	
		Node *cur;
		cur = root;
		Node*pre;
		if (root == NULL)
		{
			cout << "Tree is empty" << endl;
		}
		else
		{
			do
			{

				pre = cur;
				if (cur->data == q)
				{
					cout <<"Id: "<< cur->data<<endl;
					cout << "Name: " << cur->name << endl;
					return;
				}
				if (q < cur->data )
				{
					cur = cur->left;
					if (cur == NULL)
					{
						cout << "Node not found" << endl;
						return;
					}
				}
				else if(q>cur-> data)
				{
					cur = cur->right;
					if (cur == NULL)
					{
						cout << "Node not found" << endl;
						return;
					}
				}
			} while (cur->left != NULL || cur->right != NULL);
		}


}

int main()
{

	int option;

	Tree l1;

	do {

		cout << "1.Insert New Node" << endl;
		cout << "2.Preorder Traversal" << endl;
		cout << "3.Inorder Traversal" << endl;
		cout << "4.Postorder Traversal" << endl;
		cout << "5.Search specific node" << endl;
		cout << "6.Mirror Function" << endl;//mirror of the whole binary tree
		cout << "7.Array in question" << endl; // was an array given to us to check if our code works right by going through traversals
		cout << "8.Exit" << endl;
		cout << "Enter option: ";
		cin >> option;
		system("cls");
		switch (option)
		{
		case 1:
		{
			int a;
			string c;
			cout << "Enter index: ";
			cin >> a;
			cout << endl;
			cout << "Enter name: ";
			cin >> c;
			l1.insertNode(a, c);

			system("cls");
		}
		break;
		case 2:
		{
			l1.preorder(l1.root);
			system("pause");
			system("cls");
		}
		break;
		case 3:
		{
			l1.inorder(l1.root);
			system("pause");
			system("cls");
		}
		break;
		case 4:
		{
			l1.postorder(l1.root);
			system("pause");
			system("cls");
		}
		break;
		case 5:
		{int q;
		cout << "Enter the index to search: ";
		cin >> q;
		cout << endl;
		l1.searchNode(q);
		system("pause");
		system("cls");
		}
		break;
		case 6:
		{
			l1.mirror(l1.root);
			system("pause");
			system("cls");
		}
		break;
		case 7:
		{int arr[12] = { 7,8,4,3,6,16,15,11,9,17,86,2 };
		for (int i = 0; i < 12; i++)
		{
			l1.insertNodearr(arr[i]);
		}
			system("pause");
			system("cls");
		}
		break;
	

		case 8:
		{
			exit(0);
		}
		default:
		{
			cout << "Incorrect Input" << endl;
			system("pause");
			system("cls");
		}
		}
	} while (option != 8);
	return 0;
}

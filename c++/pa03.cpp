#include <iostream>
#include <string>

using namespace std;

class Node {
	public:
		string name;
		Node* left;
		Node* right;
		Node* parent;
		Node(string name_) {
			name = name_;
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}
		string get_name() {
			return	name;
		}
		string find_parent() {
			return this->parent->get_name();
		}
};

class binary_tree {
	private:
		Node* root;
		int size;
	public:
		binary_tree() {
			root = nullptr;
			size = 0;
		}
		binary_tree(int n) {
			root = nullptr;
			size = n;
		}
		int get_size() {
			return size;
		}
		void insert(const string& name) {
			if(this->root == nullptr) {
				this->root = new Node(name);
				return;
			}
			Node* new_node = new Node(name);
			Node* compare_node = root;
			while(compare_node != nullptr) {
				if(compare_node->get_name() < new_node->get_name()) {
					if(compare_node->right == nullptr) {
						compare_node->right = new_node;
						compare_node->right->parent = compare_node;
						break;
					}
					else {
						compare_node = compare_node->right;
					}
				}
				else {
					if(compare_node->left == nullptr) {
						compare_node->left = new_node;
						compare_node->left->parent = compare_node;
						break;
					}
					else {
						compare_node = compare_node->left;
					}
				}
			}
		}
	Node* find_node(string& name) {
		Node* compare_node = root;
		while(true) {
			if(compare_node->get_name() == name) {
				break;
			}
			else if(compare_node->get_name() < name) {
				compare_node = compare_node->right;
			}
			else {
				compare_node = compare_node->left;
			}
		}
		return compare_node;
	}
};

int main() {
	string first_person;
	string second_person;
	getline(cin, first_person);
	getline(cin, second_person);
	
	int n;
	cin >> n;
	cin.ignore();
	string people[n];
	binary_tree tree(n);
	for(int i=0;i<n;i++) {
		getline(cin, people[i]);
		tree.insert(people[i]);
	}
	
	Node* first_node = tree.find_node(first_person);
	Node* second_node = tree.find_node(second_person);
	string first_parents[n];
	string second_parents[n];
	
	int first_size = 0;
	while(true) {
		if(first_node->parent == nullptr) {
			break;
		}
		first_parents[first_size] = first_node->find_parent();
		first_node = first_node->parent;
		first_size++;
	}
	first_parents[first_size] = first_person;
	first_size++;
	
	int second_size = 0;
	while(true) {
		if(second_node->parent == nullptr) {
			break;
		}
		second_parents[second_size] = second_node->find_parent();
		second_node = second_node->parent;
		second_size++;
	}
	second_parents[second_size] = second_person;
	second_size++;
	
	for(int i=first_size-1;i>=0;i--) {
		for(int j=second_size-1;j>=0;j--) {
			if(first_parents[i] == second_parents[j]) {
				cout << first_parents[i] << endl;
			}
		}
	}
}
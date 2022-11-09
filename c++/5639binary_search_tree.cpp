#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Node {
	public:
		int value;
		Node* left;
		Node* right;
        Node* parent;
		Node(int value_) {
			value = value_;
			left = nullptr;
			right = nullptr;
            parent = nullptr;
		}
		int get_value() {
			return	value;
		}
        int find_parent() {
            return parent->get_value();
        }
};

class binary_tree {
	private:
		Node* root;
	public:
        int get_root_value() {
            return this->root->get_value();
        }
		binary_tree() {
			root = nullptr;
		}
		void insert(const int value) {
			if(this->root == nullptr) {
				this->root = new Node(value);
				return;
			}
			Node* new_node = new Node(value);
			Node* compare_node = root;
            Node* temp;
			while(compare_node != nullptr) {
				if(compare_node->get_value() < new_node->get_value()) {
                    temp = compare_node;
					compare_node = compare_node->right;
				}
				else {
					temp = compare_node;
					compare_node = compare_node->left;
				}
			}
			compare_node = new_node;
            compare_node->parent = temp;
		}
        Node* find_node(int value) {
            Node* compare_node = root;
            while(true) {
                if(compare_node->get_value() == value) {
					break;
				}
				else if(compare_node->get_value() < value){
					compare_node = compare_node->right;
				}
                else {
                    compare_node = compare_node->left;
                }
            }

            return compare_node;
        }
};

vector<bool> visited = {false,};

int main() {
    int n;
    binary_tree tree;
	while(cin >> n) {
        tree.insert(n);
    }
	visited.resize(1000000);
	int root_value = tree.get_root_value();
}
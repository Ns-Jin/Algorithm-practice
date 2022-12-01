// No skeleton code is provided
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

long long hash_function(long long n) {
	return n % 2147483647;
}

class Node {
	public:
		int value;
		string key;
		Node* next;
		Node() {
			value = -1;
			key = "";
			next = nullptr;
		}
		Node(int value, string key) {
			this->value = value;
			this->key = key;
			next = nullptr;
		}
};

vector<vector<string>> storage;

int main() {
	int a;
	float min_lf, max_lf;
	cin >> a >> min_lf >> max_lf;
	long long rep;
	long long count_i;
	cin >> rep;
	storage.resize(rep,vector<string>(3));
	for(long long i=0;i<rep;i++) {
		cin >> storage[i][0] >> storage[i][1] >> storage[i][2];
		if(storage[i][0] == "i") {
			count_i++;
		}
	}
	long long size = 512;
	while(true) {
		if(count_i/size > max_lf) {
			cout << "Rehashing: " << size << " -> ";
			size = size * 2;
			cout << size <<endl;
		}
		else {
			break;
		}
	}
	Node result[size];
	long long bucket[size] = {0,};
	long long entry_count = 0;
	
	for(long long i=0;i<rep;i++) {		//반복
		string key = storage[i][1];			//원래 key값
		long long hash_code = 0;
		for(int j=0;j<key.length();j++) {
			int num_i = int(key[j]);
			hash_code = hash_function(num_i + a*hash_code);			//key-> hashing => hash code
		}
		hash_code = hash_code % size;
		//저장 시작
		if (storage[i][0] == "i") {
			Node *new_node = new Node(stoi(storage[i][2]), key);
			if(result[hash_code].value == -1) {
				result[hash_code] = *new_node;
				entry_count++;
				bucket[hash_code]++;
				free(new_node);
			}
			else {
				Node* now_node = &result[hash_code];
				bool find_redup = false;
				while(now_node->next != nullptr) {
					if (now_node->value == stoi(storage[i][2]) && now_node->key == key) {
						find_redup = true;
					}
					now_node = now_node->next;
				}
				if (now_node->value == stoi(storage[i][2]) && now_node->key == key) {
					find_redup = true;
				}
				if (find_redup == false) {
					now_node->next = new_node;
					entry_count++;
					bucket[hash_code]++;
				}
			}
		}
		else if(storage[i][0] == "r") {
			if(result[hash_code].value != -1) {
				if(result[hash_code].value == stoi(storage[i][2])) {
					if(result[hash_code].next == nullptr) {
						result[hash_code] = *new Node();
					}
					else {
						result[hash_code] = *result[hash_code].next;
					}
					entry_count--;
					bucket[hash_code]--;
				}
				else {
					if(result[hash_code].next != nullptr) {
						Node* pre_node = &result[hash_code];
						Node* now_node = pre_node->next;
						while(true) {
							if(now_node == nullptr) {
								break;
							}
							if(now_node->value == stoi(storage[i][2])) {
								pre_node->next = now_node->next;
								entry_count--;
								bucket[hash_code]--;
								free(now_node);
								break;
							}
							pre_node = now_node;
							now_node = now_node->next;
						}
					}
				}
			}
		}
	}
	long long over_five_count = 0;
	long long max_index = 0;
	long long max_c = 0;
	for(long long i=size-1;i>=0;i--) {
		if(bucket[i] > max_c) {
			max_index = i;
			max_c = bucket[i];
		}
		if(bucket[i] > 5) {
			over_five_count++;
		}
	}
	cout << "Number of entries: " << entry_count << endl;
	cout << "Size of the bucket array: " << size << endl;
	cout << over_five_count << " buckets contain more than 5 elements" << endl;
	cout << "The longest bucket: ";
	if (entry_count == 0) {
		cout << size - 1 << endl;
	}
	else {
		cout << max_index << endl;
		Node now_node = result[max_index];
		while(now_node.next != nullptr) {
			cout << "(" << now_node.key << "," << now_node.value << ")" << endl;
			now_node = *now_node.next;
		}
		cout << "(" << now_node.key << "," << now_node.value << ")" << endl;
	}
}
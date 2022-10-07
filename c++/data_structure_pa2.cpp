#include <iostream>
#include <string>
#include <stack>

using namespace std;

class StringDecoder{
	private:
		string data_;
	// Implement your class here
	public:
        string get_data() {
            return this->data_;
        }
		friend istream &operator >>(istream& stream, StringDecoder& sd);
		friend ostream &operator <<(ostream& stream, const StringDecoder& sd);
};

// Implement your class here
istream &operator >> (istream& stream, StringDecoder& sd) {
	stream >> sd.data_;
	
	return stream;
}

ostream &operator << (ostream& stream, StringDecoder& sd) {
	string data = sd.get_data();
	stack<int> s_i;
	stack<char> s_s;
	string temp;
    string result;
    stack<string> result_temp;

    for(int i=0;i<data.length();i++) {
        if(data[i] == '{') {
            int t_int;
            if(s_s.top() - '0' >= 0 && s_s.top() - '0' <= 9) {
                t_int = s_s.top() - '0';
            }
            else if(s_s.top() - '7' >= 10 && s_s.top() - '7' <= 15) {
                t_int = s_s.top() - '7';
            }
            else {
                result = "ERROR: Invalid input";
                break;
            }
            s_i.push(t_int);
            s_s.pop();
            s_s.push(data[i]);
        }
        else if(data[i] == '}') {
            bool result_in = false;
            while(s_s.top() != '{') {
                temp.insert(0, 1, s_s.top());
                s_s.pop();
            }
            s_s.pop();
            if(temp == "") {
                if(s_i.top() == 0) {
                    result = "";
                }
                else {
                    temp = result;
                    for(int j=0;j<s_i.top()-1;j++) {
                        result += temp;
                    }
                    s_i.pop();
                    temp = "";
                }
            }
            else {
                if(s_i.top() == 0) {
                    result = "";
                    temp = "";
                }
                else {
                    result_in = true;
                }
            }
            if(!s_s.empty()) {
                string temp_;
                while(!s_s.empty() && s_s.top() != '{') {
                    temp_.insert(0, 1, s_s.top());
                    s_s.pop();
                }
                result.append(temp_);
            }
            if(result_in) {
                for(int j=0;j<s_i.top();j++) {
                    result += temp;
                }
                s_i.pop();
                temp = "";
            }
        }
        else {
            s_s.push(data[i]);
        }
    }

    if(result != "ERROR: Invalid input") {
        string temp;
        while(!s_s.empty()) {
            temp.insert(0, 1, s_s.top());
            s_s.pop();
        }
        result.append(temp);
    }
    
    stream << result;
	
	return stream;
}

int main(){
	StringDecoder sd;
	
	// Note:
	// encoded input strings are read from an input file using operator>>
	// your class may store a decoded string in data_ to print it using operator<<
	while(cin >> sd){
		cout << sd << endl;
	}
	
	return 0;
}
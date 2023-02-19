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
    bool isInvalid = false;

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
                isInvalid = true;
                break;
            }
            s_i.push(t_int);
            s_s.pop();
            if(!s_s.empty()) {
                while(!s_s.empty() && s_s.top() != '{') {
                    temp = s_s.top() + temp;
                    s_s.pop();
                }
                result_temp.push(temp);
                temp = "";
            }
            s_s.push(data[i]);
        }
        else if(data[i] == '}') {
            while(s_s.top() != '{') {
                temp = s_s.top() + temp;
                s_s.pop();
            }
            s_s.pop();
            if(temp == "") {
                if(s_i.top() == 0) {
                    if(!result_temp.empty()) {
                        result_temp.pop();
                    }
                    s_i.pop();
                }
                else {
                    string temp_ = result_temp.top();
                    temp = result_temp.top();
                    result_temp.pop();
                    for(int j=0;j<s_i.top()-1;j++) {
                        temp += temp_;
                    }
                    result_temp.push(temp);
                    s_i.pop();
                    temp = "";
                }
            }
            else {
                if(s_i.top() == 0) {
                    if(!result_temp.empty()) {
                        result_temp.pop();
                    }
                    s_i.pop();
                    temp = "";
                }
                else {
                    string temp_;
                    for(int j=0;j<s_i.top();j++) {
                        temp_ += temp;
                    }
                    s_i.pop();
                    result_temp.push(temp_);
                    temp = "";
                }
            }
        }
        else {
            s_s.push(data[i]);
        }
    }

    if(isInvalid) {
        stream << "ERROR: Invlid input";
    }
    else {
        while(!result_temp.empty()) {
            result = result_temp.top() + result;
            result_temp.pop();
        }
        string temp_;
        while(!s_s.empty()) {
            temp_ = s_s.top() + temp_;
            s_s.pop();
        }
        result += temp_;
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
#include <iostream>
#include <string>

using namespace std;

template <class T>
class SimpleBuffer{
	private:
		T data_;
	
	public:	
		SimpleBuffer(T data = 0) {
            data_ = data;
        };
        template<class O>
		friend ostream& operator<<(ostream&, const SimpleBuffer<O>&);
		template<class I>
        friend istream& operator>>(istream&, SimpleBuffer<I>&);
};

template<class O>
ostream & operator << (ostream& os, const SimpleBuffer<O>& out) {
	os << "Current data: " << out.data_;
	
	return os;
}
template<class I>
istream & operator >> (istream& is, SimpleBuffer<I>& in) {
    I temp;
	cin >> temp;
    in.data_ += temp;
	return is;
}

// main() of your program for test
int main() {
	SimpleBuffer<string> buf_str("");
	
	for(int k = 0; k < 3; k++){
    cin >> buf_str;
	cout << buf_str << endl;
	}
	
	SimpleBuffer<int> buf_int(0);
	
	for(int k = 0; k < 5; k++){
		cin >> buf_int;
		cout << buf_int << endl;
	}
	
	return 0;
}
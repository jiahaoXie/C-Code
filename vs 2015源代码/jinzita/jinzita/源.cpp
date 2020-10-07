#include<iostream>
#include<string>
using namespace std;
int main() {
	string str = "";
	for (int i = 0; i < 10; i++) {
		for (int j = 10; j > i; j--) {
			str += " ";
		}
		for (int j = 0; j < i; j++) {
			str += "*";
		}
		cout <<str<< endl;
		str = "";
	}
	return 0;
	

}
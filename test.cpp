#include<iostream>
#include "myvector.hpp"
#include<string>
using std::string;
using std::cout;
using std::endl;
int main() {

	MyVector<int> v;
	for (int i = 0; i < 70; i++)v.push_back(i);
	MyVector<int> v1 = v;
	MyVector<int> v2(v1);
//	MyVector<int> v1(v);
	v2.pop_back();
	v2.erase(2);
	v2.erase(2, 50);
//	cout << v2[2] << endl;
	/*for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}
	*/
	MyVector<MyVector<int>> t;
	t.push_back(v);
	t.push_back(v1);
	t.push_back(v2);
	cout << t.front().front();

	return 0;
}
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

// Return whether second element is twice the first
bool twice(int elem1, int elem2)
{
	return 2 * elem1 == elem2;
}

int main() 
{
	vector <int> v1, v2;
	list <int> L1;
	vector <int>::iterator Iter1, Iter2;
	list <int>::iterator L1_Iter, L1_inIter;

	int i;
	for (i = 0; i <= 5; i++)
	{
		v1.push_back(5 * i);
	}
	for (i = 0; i <= 5; i++)
	{
		v1.push_back(5 * i);
	}
	//ÏòÁ¿v1={0,5,10,15,20,25,0,5,10,15,20,25}

	int ii;
	for (ii = 4; ii <= 5; ii++)
	{
		L1.push_back(5 * ii);
	}

	int iii;
	for (iii = 2; iii <= 4; iii++)
	{
		v2.push_back(10 * iii);
	}

	cout << "Vector v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")" << endl;

	cout << "List L1 = ( ";
	for (L1_Iter = L1.begin(); L1_Iter != L1.end(); L1_Iter++)
		cout << *L1_Iter << " ";
	cout << ")" << endl;

	cout << "Vector v2 = ( ";
	for (Iter2 = v2.begin(); Iter2 != v2.end(); Iter2++)
		cout << *Iter2 << " ";
	cout << ")" << endl;

	// Searching v1 for first match to L1 under identity
	vector <int>::iterator result1;
	result1 = search(v1.begin(), v1.end(), L1.begin(), L1.end());

	if (result1 == v1.end())
		cout << "There is no match of L1 in v1."
		<< endl;
	else
		cout << "There is at least one match of L1 in v1"
		<< "\n and the first one begins at "
		<< "position " << result1 - v1.begin() << "." << endl;

	
	// Searching v1 for a match to L1 under the binary predicate twice
	vector <int>::iterator result2;
	result2 = search(v1.begin(), v1.end(), v2.begin(), v2.end(), twice);

	if (result2 == v1.end())
		cout << "There is no match of L1 in v1."
		<< endl;
	else
		cout << "There is a sequence of elements in v1 that are equivalent"
		<< "\n to those in v2 under the binary predicate twice"
		<< "\n and the first one begins at position "
		<< result2 - v1.begin() << "." << endl;

	system("pause");
}

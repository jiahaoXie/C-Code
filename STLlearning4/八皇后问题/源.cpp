#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX = 8;
vector<int> board(MAX);

void print_element(int n)
{
	cout << n << " ";
}

int check_cross()
{
	for (int i = 0; i < board.size() - 1; i++)
	{
		for (int j = i + 1; j < board.size(); j++)
		{//判断|y1-y1|==|x1-x2|,相等互斥 则不能够作为棋子下落的地方
			if ((j - i) == (int)abs(board[i] - board[j]))
				return 1;
		}
	}
	return 0;
}
void show_result()
{
	for (int i = 0; i < board.size(); i++)
		cout << "(" << i << "," << board[i] << ")";
	cout << endl;
}

void put_chess()
{
	while (next_permutation(board.begin(), board.end()))
	{
		if (!check_cross())
			show_result();
	}
}
void main()
{
	cout << "the original result:\n";
	for_each(board.begin(),board.end(),print_element);
	cout << endl;

	cout << "=============================================================\n";
	for (int i = 0; i < board.size(); i++)
		board[i] = i;
	put_chess();
	system("pause");
}
////жьеепРап
#include<iostream>

using namespace std;


int main()
{
	int t;
	cin >> t;
	int n,x;

	while (t--)
	{
	
		cin >> n;

		int count4 = 0;
		int count2 = 0;
		int count1 = 0;
		
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			if (x % 4 == 0)	count4++;
			else if (x % 2 == 0) count2++;
			else count1++;

			

		}
		if (count2 == 0)
		{
			if (count4 >= count1 - 1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
		{
			if (count4 >= count1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;

		}
	}

	system("pause");
	return 0;
}



//#include<iostream>
//
//using namespace std;
//
//int n;
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		int cnt4 = 0;
//		int cnt2 = 0;
//		int cnt1 = 0;
//		for (int i = 0; i < n; i++) {
//			int x;
//			cin >> x;
//			if (x % 4 == 0) cnt4++;
//			else if (x % 2 == 0) cnt2++;
//			else cnt1++;
//		}
//		if (cnt2 == 0) {
//			if (cnt4 >= cnt1 - 1)
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//		else {
//			if (cnt4 >= cnt1)
//				printf("Yes\n");
//			else
//				printf("No\n");
//		}
//	}
//	while (1) {}
//	return 0;
//}
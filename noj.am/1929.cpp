#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	int cnt = 0, result = 0;
	cin >> num;

	int* arr = new int[num];

		cin >> arr[i];

		for (int j = 1; j <= arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				cnt++;
			}
		}

		if (cnt == 2)  
			result++;

		cnt = 0;
	

	cout << result;

	return 0;
}
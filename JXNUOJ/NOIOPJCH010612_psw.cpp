#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int result[200];
	memset(result, 0, sizeof(result));
	result[50] = 1;
	
	//计算*2
	for (int i = 0; i < n; i++)
	{
		int temp1 = 50;
		for (int j = 0; j < 50; j++)
		{
			result[temp1] *= 2;
			temp1++;
		}
		//解决进位问题
		int temp2 = 100;
		for (int i = 0; i < 50; i++)
		{
			
			if (result[temp2] >= 10)
			{
				result[temp2] = result[temp2] % 10;
				result[temp2 -1] += result[temp2] / 10;
				temp2--;
			}
		}
	}

	//输出结果
	int temp3 = 50;
	while (result[temp3] != 0)
	{
		cout << result[temp3];
		temp3++;
	}
	return 0;
}
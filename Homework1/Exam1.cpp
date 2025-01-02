#include <iostream>
#include <vector>
#include <algorithm> // sort 함수 사용 가능
using namespace std;


int add(vector<int> a, int input) // 총합
{
	int sum = 0;

	for (int i = 0; i < input; i++)
	{
		sum += a[i];
	}

	return sum;
}

int Avg(int sum, int input) // 평균
{
	return sum/input;
}


int main()
{
	int input = 0;
	vector<int> a;

	cout << "입력받을 숫자의 갯수를 입력해주세요 : " << endl;
	cin >> input;
	a.resize(input); // 배열 사이즈 Input값만큼 초기화
	
	for (int i = 0; i < input; i++)
	{
		cout << "숫자를 입력해주세요 : " << endl;
		cin >> a[i];
	}

	sort(a.begin(), a.end()); // 정렬

	int sum = add(a, input);
	int average = Avg(sum, input);

	cout << "입력받은 숫자의 합은 : " << sum << endl;
	cout << "입력받은 숫자의 평균은 : " << average << endl;

	return 0;

}
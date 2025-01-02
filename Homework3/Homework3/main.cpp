#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 조건1. 타입에 의존하지 않고 데이터를 받을 수 있는 '배열'을 멤버변수로 갖는다
//생성자는 아래와 같이 구현한다
//* 기본 생성자의 크기가 10인 배열을 만든다
//* 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만든다
//
//아래와 같은 멤버함수를 구현한다
//push_back 인자로 받은 원소를 맨 뒤에 추가한다. 반환값은 없다. 배열의 크기가 꽉 찼는데 원소가 더 들어올 경우 아무 동작도 하지 않는다
//
//pop_back 벡터의 마지막 원소를 제거한다. 제거할 원소가 없다면 아무 동작도 하지 않으며, 인자 및 반환값은 없다
//
//size 인자가 없고 현재 원소의 개수를 반환한다
//
//capacity 현재 내부 배열의 크기를 반환한다



// 도전 기능
// 복사 생성자 구현
// 멤버함수 추가 구현
// push_back 에서 배열의 크기가 꽉 찼는데 원소가 더 들어올 경우, 기존 배열보다 크기를 5만큼 더 늘리고 새로운 원소까지 추가됩니다.( 기존 원소 유지 )
// resize는 정수 하나를 인자로 받습니다. 해당 정수가 현재 배열의 크기보다 작으면 아무 동작도 하지 않는다.
// 만약 현재 배열보다 크기가 크면 해당 값만큼 크기를 재할당 합니다.(기존 원소 유지)
// sortData는 내부 데이터를 정렬하는 함수입니다. 직접 정렬하지 않고 STL의 sort 함수를 활용해서 정렬 합니다.

// TODO : 템플릿 사용법 재확인, 정렬된 데이터 확인하는 기능 추가, 멤버변수 이름교체

template <typename T>
class SimpleVector
{
private:
	T* arr;
	int newCapacity;
	int CurrentCapacity;
	int CurrentSize;

public:
	SimpleVector() : CurrentCapacity(10), CurrentSize(0)
	{
		arr = new T[CurrentCapacity];
	}

	SimpleVector(int cap) : CurrentCapacity(cap), CurrentSize(0)
	{
		arr = new T[CurrentCapacity];
	}

	SimpleVector(const SimpleVector& copy)
		:CurrentCapacity(copy.CurrentCapacity), CurrentSize(copy.CurrentSize)
	{
		arr = new T[CurrentCapacity];
		for (int i = 0; i < CurrentSize; i++)
		{
			arr[i] = copy.arr[i];
		}
	}

	~SimpleVector()
	{
		delete[] arr;
	}

	void push_back(T input) {
		if (CurrentSize >= CurrentCapacity)
		{

			resize(CurrentCapacity + 5);
		}
		arr[CurrentSize] = input;
		CurrentSize++;
	}

	void pop_back()
	{
		if (CurrentSize > 0)
		{
			CurrentSize--;
		}
		else
			cout << "제거할 원소가 없습니다. " << endl;
	}

	void resize(int newCapacity) {
		if (newCapacity <= CurrentCapacity)
		{
			cout << "입력 값이 현재 배열 크기보다 작습니다." << endl;
			return;
		}

		T* newArr = new T[newCapacity];
		for (int i = 0; i < CurrentSize; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		CurrentCapacity = newCapacity;
	}

	void sortdata()
	{
		sort(arr, arr + CurrentSize);
	}

	int getsize() const
	{
		return CurrentSize;
	}

	int getcapacity() const
	{
		return CurrentCapacity;
	}

	void check() const {
		if (CurrentSize == 0) {
			cout << "내용물이 없습니다." << endl;
			return;
		}

		cout << "현재 배열 상태 : ";
		for (int i = 0; i < CurrentSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

};

int main()
{
	int choice = 0;
	int Capacity = 0;
	int NewCapacity = 0;

	SimpleVector<int> vec(Capacity);

	cout << "배열의 크기를 입력하세요. " << endl;
	cout << "배열의 기본 크기는 10입니다." << endl;
	cout << "입력 : ";
	cin >> Capacity;

	do {
		cout << "1. 원소 추가 " << endl;
		cout << "2. 원소 제거 " << endl;
		cout << "3. 원소 개수 확인 " << endl;
		cout << "4. 배열 크기 확인 " << endl;
		cout << "5. 배열 크기 재할당 " << endl;
		cout << "6. 배열 데이터 정렬(내림차순) " << endl;
		cout << "9. 원소 확인하기 " << endl;
 		cout << "0. 프로그램 종료하기 " << endl;
		cout << "입력 : " << endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			int n = 0;
			cout << "추가할 값을 입력하세요: ";
			cin >> n;
			vec.push_back(n);
			break;
		}
		case 2:
			vec.pop_back();
			break;
		case 3:
			cout << "현재 원소 개수: " << vec.getsize() << endl;
			break;
		case 4:
			cout << "배열 용량: " << vec.getcapacity() << endl;
			break;
		case 5:
			int newCap;
			cout << "재할당할 배열 크기를 입력하세요: ";
			cin >> newCap;
			vec.resize(newCap);
			break;
		case 6:
			vec.sortdata();
			cout << "데이터가 정렬되었습니다." << endl;
			break;
		case 9:
			vec.check();
			break;
		case 0:
			cout << "프로그램을 종료합니다." << endl;
			break;
		default:
			cout << "잘못된 입력입니다. " << endl;
		}
	} while (choice != 0);

	return 0;
}
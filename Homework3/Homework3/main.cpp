#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����1. Ÿ�Կ� �������� �ʰ� �����͸� ���� �� �ִ� '�迭'�� ��������� ���´�
//�����ڴ� �Ʒ��� ���� �����Ѵ�
//* �⺻ �������� ũ�Ⱑ 10�� �迭�� �����
//* ���ڸ� �ϳ� �޴� �����ڴ� �ش� ���ڿ� �ش�Ǵ� ũ���� �迭�� �����
//
//�Ʒ��� ���� ����Լ��� �����Ѵ�
//push_back ���ڷ� ���� ���Ҹ� �� �ڿ� �߰��Ѵ�. ��ȯ���� ����. �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���� ��� �ƹ� ���۵� ���� �ʴ´�
//
//pop_back ������ ������ ���Ҹ� �����Ѵ�. ������ ���Ұ� ���ٸ� �ƹ� ���۵� ���� ������, ���� �� ��ȯ���� ����
//
//size ���ڰ� ���� ���� ������ ������ ��ȯ�Ѵ�
//
//capacity ���� ���� �迭�� ũ�⸦ ��ȯ�Ѵ�



// ���� ���
// ���� ������ ����
// ����Լ� �߰� ����
// push_back ���� �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���� ���, ���� �迭���� ũ�⸦ 5��ŭ �� �ø��� ���ο� ���ұ��� �߰��˴ϴ�.( ���� ���� ���� )
// resize�� ���� �ϳ��� ���ڷ� �޽��ϴ�. �ش� ������ ���� �迭�� ũ�⺸�� ������ �ƹ� ���۵� ���� �ʴ´�.
// ���� ���� �迭���� ũ�Ⱑ ũ�� �ش� ����ŭ ũ�⸦ ���Ҵ� �մϴ�.(���� ���� ����)
// sortData�� ���� �����͸� �����ϴ� �Լ��Դϴ�. ���� �������� �ʰ� STL�� sort �Լ��� Ȱ���ؼ� ���� �մϴ�.

// TODO : ���ø� ���� ��Ȯ��, ���ĵ� ������ Ȯ���ϴ� ��� �߰�, ������� �̸���ü

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
			cout << "������ ���Ұ� �����ϴ�. " << endl;
	}

	void resize(int newCapacity) {
		if (newCapacity <= CurrentCapacity)
		{
			cout << "�Է� ���� ���� �迭 ũ�⺸�� �۽��ϴ�." << endl;
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
			cout << "���빰�� �����ϴ�." << endl;
			return;
		}

		cout << "���� �迭 ���� : ";
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

	cout << "�迭�� ũ�⸦ �Է��ϼ���. " << endl;
	cout << "�迭�� �⺻ ũ��� 10�Դϴ�." << endl;
	cout << "�Է� : ";
	cin >> Capacity;

	do {
		cout << "1. ���� �߰� " << endl;
		cout << "2. ���� ���� " << endl;
		cout << "3. ���� ���� Ȯ�� " << endl;
		cout << "4. �迭 ũ�� Ȯ�� " << endl;
		cout << "5. �迭 ũ�� ���Ҵ� " << endl;
		cout << "6. �迭 ������ ����(��������) " << endl;
		cout << "9. ���� Ȯ���ϱ� " << endl;
 		cout << "0. ���α׷� �����ϱ� " << endl;
		cout << "�Է� : " << endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			int n = 0;
			cout << "�߰��� ���� �Է��ϼ���: ";
			cin >> n;
			vec.push_back(n);
			break;
		}
		case 2:
			vec.pop_back();
			break;
		case 3:
			cout << "���� ���� ����: " << vec.getsize() << endl;
			break;
		case 4:
			cout << "�迭 �뷮: " << vec.getcapacity() << endl;
			break;
		case 5:
			int newCap;
			cout << "���Ҵ��� �迭 ũ�⸦ �Է��ϼ���: ";
			cin >> newCap;
			vec.resize(newCap);
			break;
		case 6:
			vec.sortdata();
			cout << "�����Ͱ� ���ĵǾ����ϴ�." << endl;
			break;
		case 9:
			vec.check();
			break;
		case 0:
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�. " << endl;
		}
	} while (choice != 0);

	return 0;
}
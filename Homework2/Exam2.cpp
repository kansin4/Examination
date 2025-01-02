#include <iostream>
using namespace std;

/*
>> -Animal 기본 클래스와 makeSound() 순수가상 함수 정의 여부 O
- Dog, Cat, Cow 클래스가 제대로 구현되었는지 확인 O
- main 함수에서 포인터 배열을 사용해 동물 객체를 순회하면서 소리를 제대로 출력했는지 확인 O 
|
| **도전 * *| -zoo 클래스의 소멸자가 모든 동적 할당된 객체를 메모리에서 올바르게 해제하는지 확인 O
- zoo 클래스의 addAnimal()함수가 요구사항에 따라 동물을 추가할수 있는지 확인 

>> -클래스 설계가 과제 요구사항에 맞는지 확인 O
- 다형성을 올바르게 적용했는지 확인 O
- 본인이 작성한 코드의 의도를 명확하게 설명하는지 확인 
| **도전 * *| -동물 객체가 동적으로 생성 및 해제되어 메모리 누수가 발생하지 않도록 구현했는지 확인 

>> -기본 클래스의 생성자와 소멸자 호출 순서를 명확하게 인지하고 있는지 확인 

| **도전 * *| -zoo 클래스 내에 animals 배열이 있으며, 해당 배열의 크기가 제한 - 배열에 새로운 항목을 추가할 때, 제한된 크기를 고려하여 배열의 크기를 동적으로 확장하거나 적절히 처리하는 예외 사항이 반영되었는지 확인 |

*/

class Animal
{
public:
	Animal() {} // Animal 생성자 호출
	virtual void makeSound() = 0;
	virtual ~Animal() {} // Animal 소멸자 호출
};

class Dog : public Animal
{
public:
	Dog() {} // Dog 생성자 호출
	void makeSound()
	{
		cout << " WAL WAL! " << endl;
	}
	~Dog() {} // Dog 소멸자 호출
};

class Cat : public Animal
{
public:
	Cat() {} // Cat 생성자 호출
	void makeSound()
	{
		cout << " MEOW MEOW! " << endl;
	}
	~Cat() {} // Cat 소멸자 호출
};

class Cow : public Animal
{
public:
	Cow() {} // Cow 생성자 호출
	void makeSound()
	{
		cout << " MOOWWWWW " << endl;
	}
	~Cow() {} // Cow 소멸자 호출
};


int main()
{
	Animal* myAnimal[3]; // Animal 포인터 배열 선언
	Dog myDog; // Dog 객체 생성
	Cat myCat; // Cat 객체 생성
	Cow myCow; // Cow 객체 생성

	myAnimal[0] = &myDog; // myAnimal[0]에 myDog 객체 주소 할당
	myAnimal[0]->makeSound(); // myAnimal[0]이 가리키는 객체의 makeSound() 함수 호출
	myAnimal[1] = &myCat; // myAnimal[1]에 myCat 객체 주소 할당
	myAnimal[1]->makeSound();// myAnimal[1]이 가리키는 객체의 makeSound() 함수 호출
	myAnimal[2] = &myCow; // myAnimal[2]에 myCow 객체 주소 할당
	myAnimal[2]->makeSound() ;// myAnimal[2]이 가리키는 객체의 makeSound() 함수 호출


	return 0;

}
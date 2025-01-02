#include <iostream>
#include <vector>
#include <string>

using namespace std; // namespace std 사용

// 검색 기능을 추가
// 1. 책 제목으로 검색이 가능해야 합니다
// 2. 작가로 검색이 가능해야 합니다.
// 3. 책 제목이 동일한 경우는 없다고 가정.

// 도전

// 특정 책의 대여 여부를 알 수 있어야 합니다.
// 책의 이름으로 대여 여부를 검색하고 대여가 아닌 경우 대여할 수 있어야 합니다
// 책의 작가로 대여 여부를 검색하고 대여가 아닌 경우 대여할 수 있어야 합니다
// 책을 반납할 수 있어야 합니다
// 모든 책의 재고는 3권으로 통일합니다

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author){}
};

class BookManager
{
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author)
    {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks()
    {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 책 목록:" << endl;
        for (int i = 0; i < books.size(); i++) // size() 메서드 사용
        {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // 책 제목으로 검색하는 메서드
	void searchByTitle(const string& title)
    {
		bool found = false;
		for (int i = 0; i < books.size(); i++)
        {
			if (books[i].title == title)
            {
				cout << "찾아본 결과: " << books[i].title << " by " << books[i].author << endl;
				found = true;
				break;
			}
		}
		if (!found)
        {
			cout << "해당 제목의 책을 찾을 수 없습니다." << endl;
		}
	}

	void searchbyAuthor(const string& author)
    {
		bool found = false;
		for (int i = 0; i < books.size(); i++) {
			if (books[i].author == author) {
				cout << "찾아본 결과: " << books[i].title << " by " << books[i].author << endl;
				found = true;
			}
		}
		if (!found)
        {
			cout << "해당 저자의 책을 찾을 수 없습니다." << endl;
		}
	}
};


int main() {
    BookManager manager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
		cout << "3. 책 제목으로 검색" << endl; // 책 제목으로 검색
		cout << "4. 작가로 검색" << endl; // 작가로 검색
		cout << "0. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            manager.addBook(title, author); // 입력받은 책 정보를 추가
        }
        else if (choice == 2) {
            manager.displayAllBooks();
        }

        else if (choice == 3) {
			string title;
			cout << "검색할 책 제목: ";
			cin.ignore();
			getline(cin, title);
			manager.searchByTitle(title);
		}
        else if (choice == 4) {
            string author;
            cout << "검색할 저자: ";
            cin.ignore();
            getline(cin, author);
            manager.searchbyAuthor(author);
        }

        else if (choice == 0) {
            // 0번 선택: 종료
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else
		{
            cout << "잘못된 입력입니다." << endl;
        }
    }

    return 0;
}

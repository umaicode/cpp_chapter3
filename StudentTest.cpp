#include <iostream>
// #include <stdio.h>
using namespace std;
class Student {
private:
	int sno; // stack 영역에 공간 할당 -> block이 끝났을 때 객체가 사라지면서 알아서 사라짐
	char* name; // heap 영역에 공간 할당
	char dept[12]; // stack 영역에 공간 할당 -> 함수 끝나면 알아서 사라짐

public:
	void Show();
	Student() {
		sno = 0; 
	};

	Student(int, char*, char*); // 생성자를 선언 constructor
	Student Add(Student);
	~Student() {
		delete[]name;
	}
	/* {
		// 함수 바디를 만드는 첫번째 방법
		// 공간할당하고 주소를 가리키는 것에 값을 넣는다.
		this->sno = sno; // this는 class 객체 자신 : 포인터로 되어 있다.
		int len = strlen(name);
		this->name = new char[len];
		strcpy(this->name, name); // 공간할당하고 값 생성.
		// this->dept = dept; // dept는 주소여서 오류가 발생한다. 배열은 바이트를 할당받는다.
		strcpy(this->dept, dept);
	} */
};

Student Student::Add(Student s2) {
	// s3 = s1 + s2
	Student s3;
	s3.sno = this->sno + s2.sno;
	return s3;
}

void Student::Show() {
	cout << "sno = " << sno << " name = " << name << " dept = " << dept;
}

Student::Student(int sno, char* name, char* dept) // 생성자 정의
{
	// 함수 바디를 만드는 두번째 방법
	// 공간할당하고 주소를 가리키는 것에 값을 넣는다.
	this->sno = sno; // this는 class 객체 자신 : 포인터로 되어 있다.
	int len = strlen(name);
	this->name = new char[len+1];
	strcpy(this->name, name); // 공간할당하고 값 생성.
	// this->dept = dept; // dept는 주소여서 오류가 발생한다. 배열은 바이트를 할당받는다.
	strcpy(this->dept, dept);
}

int main() {
	int counter = 10;
	{
		// char p[] = "hong"
		// Student s1(11, p, p);
		Student s1(11, "hong", "컴퓨터"); // 문자열을 name에 넘겨주는 것이 아니라 "hong"의 주소를 전달한다. 객체 끝나면 sno 사라짐.
		Student s2(11, "hong", "컴퓨터");
		s1.Show();
		Student s3 = s1.Add(s2);
	}
	system("pause");
	return 1;
}
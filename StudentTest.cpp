#include <iostream>
// #include <stdio.h>
using namespace std;
class Student {
private:
	int sno; // stack ������ ���� �Ҵ� -> block�� ������ �� ��ü�� ������鼭 �˾Ƽ� �����
	char* name; // heap ������ ���� �Ҵ�
	char dept[12]; // stack ������ ���� �Ҵ� -> �Լ� ������ �˾Ƽ� �����

public:
	void Show();
	Student() {
		sno = 0; 
	};

	Student(int, char*, char*); // �����ڸ� ���� constructor
	Student Add(Student);
	~Student() {
		delete[]name;
	}
	/* {
		// �Լ� �ٵ� ����� ù��° ���
		// �����Ҵ��ϰ� �ּҸ� ����Ű�� �Ϳ� ���� �ִ´�.
		this->sno = sno; // this�� class ��ü �ڽ� : �����ͷ� �Ǿ� �ִ�.
		int len = strlen(name);
		this->name = new char[len];
		strcpy(this->name, name); // �����Ҵ��ϰ� �� ����.
		// this->dept = dept; // dept�� �ּҿ��� ������ �߻��Ѵ�. �迭�� ����Ʈ�� �Ҵ�޴´�.
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

Student::Student(int sno, char* name, char* dept) // ������ ����
{
	// �Լ� �ٵ� ����� �ι�° ���
	// �����Ҵ��ϰ� �ּҸ� ����Ű�� �Ϳ� ���� �ִ´�.
	this->sno = sno; // this�� class ��ü �ڽ� : �����ͷ� �Ǿ� �ִ�.
	int len = strlen(name);
	this->name = new char[len+1];
	strcpy(this->name, name); // �����Ҵ��ϰ� �� ����.
	// this->dept = dept; // dept�� �ּҿ��� ������ �߻��Ѵ�. �迭�� ����Ʈ�� �Ҵ�޴´�.
	strcpy(this->dept, dept);
}

int main() {
	int counter = 10;
	{
		// char p[] = "hong"
		// Student s1(11, p, p);
		Student s1(11, "hong", "��ǻ��"); // ���ڿ��� name�� �Ѱ��ִ� ���� �ƴ϶� "hong"�� �ּҸ� �����Ѵ�. ��ü ������ sno �����.
		Student s2(11, "hong", "��ǻ��");
		s1.Show();
		Student s3 = s1.Add(s2);
	}
	system("pause");
	return 1;
}
#include <iostream>

using namespace std;

// ����
class Shape {
public:
	// �ṩ�ӿڿ�ܵĴ��麯��
	virtual int getArea() = 0;
	
	void setWidth(int w) {
		width = w;
	}

	void setHeight(int h) {
		height = h;
	}
protected:
	int width;
	int height;
};

// ������
class Rectangle : public Shape {
public:
	int getArea() {
		return (width * height) / 2;
	}
};

class Triangle : public Shape {
public:
	int getArea() {
		return (width * height) / 2;
	}

};

int main() {
	Rectangle Rect;
	Triangle Tri;

	Rect.setWidth(5);
	Rect.setHeight(6);

	// �����������
	cout << "Total Rectangle area: " << Rect.getArea() << endl;

	Tri.setWidth(9);
	Tri.setHeight(10);

	// �����������
	cout << "Total Triangle area: " << Tri.getArea() << endl;

	return 0;
}

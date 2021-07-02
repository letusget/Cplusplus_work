#include <iostream>

using namespace std;

// 基类
class Shape {
public:
	// 提供接口框架的纯虚函数
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

// 派生类
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

	// 输出对象的面积
	cout << "Total Rectangle area: " << Rect.getArea() << endl;

	Tri.setWidth(9);
	Tri.setHeight(10);

	// 输出对象的面积
	cout << "Total Triangle area: " << Tri.getArea() << endl;

	return 0;
}

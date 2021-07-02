#include<iostream>
/*
继承的构造：
	先构造父类，再构造子类继承  （有父才有子）
继承的析构：
	先析构子类，再析构父类   （杀小再杀大）
	*/
class CGrandpa {
public:
	CGrandpa(){
		std::cout << "Grandpa constructor\n";
	}

	virtual ~CGrandpa() {
		std::cout << "Grandpa destructor\n";
	};
};

//继承父类
class CParent : public CGrandpa {
public:
	CParent() {
		std::cout << "parent constructor\n";
	}
	~CParent() {
		std::cout << "Parent destructor\n";
	}
};

//继承父类
class CChild : public CParent {
public:
	CChild() {
		std::cout << "Child constructor\n";
	}
	~CChild() {
		std::cout << "Child destructor\n";
	}
};

int main() {
	CChild hChild;
	
	return 0;
}
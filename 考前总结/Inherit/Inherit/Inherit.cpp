#include<iostream>
/*
�̳еĹ��죺
	�ȹ��츸�࣬�ٹ�������̳�  ���и������ӣ�
�̳е�������
	���������࣬����������   ��ɱС��ɱ��
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

//�̳и���
class CParent : public CGrandpa {
public:
	CParent() {
		std::cout << "parent constructor\n";
	}
	~CParent() {
		std::cout << "Parent destructor\n";
	}
};

//�̳и���
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
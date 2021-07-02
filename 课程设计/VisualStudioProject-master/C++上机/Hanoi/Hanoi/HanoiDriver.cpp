#include <iostream>

using namespace std;

class CHanoi {
private:
	CHanoi() // ���캯��˽��
	{
	}
	static CHanoi* m_pInstance; // ����һ��Ψһָ��ʵ���ľ�ָ̬��
	
	// nΪ�ڼ���Բ�̣�sourceΪԴ����targetΪĿ��������ʾ��ʽ��#n��source->target
	void Show(int n, char source, char target) {
		cout << "#" << n << source << "->" << target << endl;
	}

public:
	// ����ģʽ�����ö��Է�ʽ����ȫ��Ψһ��ʵ��������ȡΨһʵ������
	static CHanoi* GetInstance() {
		if (m_pInstance == NULL)
			m_pInstance = new CHanoi;
		return m_pInstance;
	}

	// n��ʾԲ��������source��ʾԴ������n��Բ�̳�ʼ���ڵ�����station��ʾ��ת������ʼΪ�գ�target��ʾĿ��������n��Բ��Ӧ�ñ��ƶ���������
	void Move(int n, char source, char station, char target) {
		if (n == 1) {
			Show(n, source, target);
		}
		else {
			Move(n - 1, source, target, station);
			Show(n, source, target);
			Move(n - 1, station, source, target);
		}
	}
};
CHanoi* CHanoi::m_pInstance = NULL;

int main() {
	CHanoi* p = CHanoi::GetInstance();
	p->Move(3, 'A', 'B', 'C');
	return 0;
}
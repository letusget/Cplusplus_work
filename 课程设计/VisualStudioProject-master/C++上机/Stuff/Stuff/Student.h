#pragma once
class CStuff {
	friend class CStudent;
	friend class CTeacher;
	friend class CExecutive;


public:
	virtual void Printf() = 0;
	void setBasic(int nId, const char* pszNo, const char* pszName, int nAge, char nGender);

private:
	long m_nId;
	char* m_pszNo;
	char* m_pszName;
	int m_nAge;
	char m_nGender;
	
	
};

class CStudent : public CStuff {
private:
	char* m_pszMajor;
public:
	void Printf();
	void setInfo(int nId, const char* pszNo, const char* pszName, int nAge, char nGender, const char* pszMajor);
};

class CTeacher : public CStuff {
private:
	char* m_pszTitle;
public:
	void Printf();
	void setInfo(int nId, const char* pszNo, const char* pszName, int nAge, char nGender, const char* pszTitle);
};

class CExecutive : public CStuff {
private:
	char* m_pszPosition;
public:
	void Printf();
	void setInfo(int nId, const char* pszNo, const char* pszName, int nAge, char nGender, const char* pszPosition);
};


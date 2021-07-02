#pragma once
#include <string>

class CCacheItem
{
public:
	CCacheItem();
	CCacheItem(const char* const pszUri, const char* const pszBody);
	CCacheItem(std::string sUri, std::string sBody);
	virtual ~CCacheItem();
	std::string GetUri();
	long GetSince() const;
	void SetSince(long nSince);
	std::string GetBody();
	
	void SetBody(const char* const pszBody);
	void SetBody(std::string sBody);
	
private:
	std::string m_sUri;
	long m_nSince;
	std::string m_sBody;

};

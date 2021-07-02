#pragma once
#ifndef _HTTP_CACHE_H
#define _HTTP_CACHE_H

#include <string>
#include <map>
#include "CacheItem.h"

//ио©н╫╡
class CHttpCache {
public:
	virtual ~CHttpCache(){}
	static CHttpCache& GetInstance();
	bool Cache(const char* const pszUri, const char* const pszBody);
	bool Cache(std::string sUri, std::string sBody);
	std::string Get(const char* const pszUri);
	std::string Get(std::string sUri);
	bool Delete(const char* const pszUri);
	bool Delete(std::string sUri);
	void pruge(long nDelta);
	std::map<std::string, CCacheItem*>& GetItem();

private:
	CHttpCache() {}
	static CHttpCache m_hInstance;
	std::map<std::string, CCacheItem*> m_hItems;

};


#endif // !_HTTP_CACHE_H

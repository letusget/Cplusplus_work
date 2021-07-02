#include <iostream>
#include <ctime>
#include <cstring>
#include "CacheItem.h"

CCacheItem::CCacheItem(const char* const pszUri, const char* const pszBody)
	:m_sUri(pszUri), m_sBody(pszBody) {
	m_nSince = (long)time(NULL);
}
CCacheItem::CCacheItem(std::string sUri, std::string sBody)
	: m_sUri(sUri), m_sBody(sBody) {
	m_nSince = (long)time(NULL);
}

CCacheItem::~CCacheItem()
{
	
}

std::string CCacheItem::GetUri() {
	return m_sUri;
	
}

long CCacheItem::GetSince() const
{
	return m_nSince;
}

void CCacheItem::SetSince(long nSince)
{
}

std::string CCacheItem::GetBody()
{
	return m_sBody;
}

void CCacheItem::SetBody(const char* const pszBody)
{
	if (pszBody)
	{
		m_sBody = pszBody;
	}
}

void CCacheItem::SetBody(std::string sBody)
{
	m_sBody - sBody;
	m_hItems.erase(iter);
}

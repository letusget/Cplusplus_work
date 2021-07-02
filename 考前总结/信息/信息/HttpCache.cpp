#include <ctime>
#include "HttpCache.h"

CHttpCache CHttpCache::m_hInstance;

CHttpCache& CHttpCache::GetInstance() {
	return CHttpCache::m_hInstance;
}

bool CHttpCache::Cache(const char* const pszUri, const char* const pszBody)
{
	return Cache(std::string(pszUri), std::string(pszBody));

}

bool CHttpCache::Cache(std::string sUri,std::string sBody)
{
	std::map<std::string, CCacheItem*>::iterator iter = m_hItems.find(sUri);
	if (iter==m_hItems.end())
	{
		CCacheItem* pItem = new CCacheItem(sUri, sBody);
		m_hItems[sUri] = pItem;
		return true;
	}
	iter->second->SetBody(sBody);
	iter->second->SetSince((long)time(NULL));

	return false;
}

std::string CHttpCache::Get(const char* const pszUri)
{
	std::map<std::string, CCacheItem*, CItemLess>::iterator iter = m_hItems.find((std::string)pszUri);
	if (iter==m_hItems.end())
	{
		return NULL;
	}
	return iter->second->GetBody();
}

std::string CHttpCache::Get(std::string sUri)
{
	return std::string();
}

bool CHttpCache::Delete(const char* const pszUri)
{
	std::map<std::string, CCacheItem*, CItemLess>::iterator iter = m_hItems.find((std::string)pszUri);
	if (iter==m_hItems.end())
	{
		return false;

	}
	CCacheItem* pItem = iter->second;
	m_hItems.erase(iter);
	delete pItem;

	return true;
}

bool CHttpCache::Delete(std::string sUri)
{
	return false;
}

void CHttpCache::pruge(long nDelta)
{
	long nNow = (long)time(NULL);
	for (std::map<std::string, CCacheItem*, CItemLess>::iterator iter = m_hItems.begin(); iter != m_hItems.end();)
	{
		if (iter->second->GetSince() > nNow - nDelta)
		{
			iter++;
			continue;
		}
		CCacheItem* pItem = iter->second;
		m_hItems.erase(iter++);
		delete pItem;
	}
}

std::map<std::string, CCacheItem*, CItemLess>& CHttpCache::GetInstance;


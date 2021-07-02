#include <iostream>
#include <Windows.h>  //调用系统函数
#include "HttpCache.h"

//上课讲
int main()
{
	CHttpCache::GetInstance().Cache("/students/195080101", "{id:10,no:\"195080101\",name:\"zhangsan\"}");

	CHttpCache::GetInstance().Cache("/students/195080102", "{id:11,no:\"195080102\",name:\"lisi\"}");

	CHttpCache::GetInstance().Cache("/students/195080103", "{id:12,no:\"195080103\",name:\"wangwu\"}");

	std::cout << "=======================before update=====================\n";
	std::map<std::string, CCacheItem*>& hItems = CHttpCache::GetInstance().GetInstance();
	for (std::map<std::string, CCacheItem*>::iterator iter = hItems.begin(); iter != hItems.end(); iter++)
	{
		std::cout << iter->second->GetSince() << " : " << iter->first << " => " << iter->second->GetBody() << "\n";
		Sleep(3000);
	}

	CHttpCache::GetInstance().Cache("/students/195080101", "{id:10,no:\"195080101\",name:\"zhangsan\"}");
	std::cout << "=======================after 3s=====================\n";
	for (std::map<std::string, CCacheItem*>::iterator iter = hItems.begin(); iter != hItems.end(); iter++)
		std::cout << iter->second->GetSince() << ": " << iter->first << " => " << iter->second->GetBody() << "\n";
	std::cout << "=======================beging purging=====================\n";
	CHttpCache::GetInstance().Purge(3);

	std::cout << "=======================after purging=====================\n";
	for (std::map<std::string, CCacheItem*>::iterator iter = hItems.begin(); iter != hItems.end(); iter++)
		std::cout << iter->second->GetSince() << ": " << iter->first << " => " << iter->second->GetBody() << "\n";


	return 0;
}
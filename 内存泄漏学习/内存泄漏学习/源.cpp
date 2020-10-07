//Windows平台下面Visual Studio 调试器和 C 运行时(CRT) 库为我们提供了检测和识别内存泄漏的有效方法，
//原理大致如下：内存分配要通过CRT在运行时实现，只要在分配内存和释放内存时分别做好记录，
//程序结束时对比分配内存和释放内存的记录就可以确定是不是有内存泄漏

//通过包括 crtdbg.h，将 malloc 和 free 函数映射到它们的调试版本，
//即 _malloc_dbg 和 _free_dbg，这两个函数将跟踪内存分配和释放。
//此映射只在调试版本（在其中定义了_DEBUG）中发生。 发布版本使用普通的 malloc 和 free 函数。
//
//#define 语句将 CRT 堆函数的基版本映射到对应的“Debug”版本。 
//并非绝对需要该语句；但如果没有该语句，内存泄漏转储包含的有用信息将较少。

#define _CRTDBG_MAP_ALLOC
#include<stdlib.h>
#include<crtdbg.h>

#include<iostream>
using namespace std;

//_CrtMemState s1, s2, s3;
//定位内存泄漏的另一种技术涉及在关键点对应用程序的内存状态拍快照。 
//CRT 库提供一种结构类型 _CrtMemState，您可用它存储内存状态的快照

void GetMemory(char *p, int num)
{
	p = (char *)malloc(sizeof(char *)*num);
}

void main()
{
	//_CrtMemCheckpoint(&s1);

	char *str = NULL;
	GetMemory(str,100);
	
	/*_CrtMemCheckpoint(&s2);
	if (_CrtMemDifference(&s3, &s2, &s1))
		_CrtMemDumpStatistics(&s3);*/

	cout << "Memory leak test!" << endl;
	_CrtDumpMemoryLeaks();
	//通过在程序中执行语句 	_CrtDumpMemoryLeaks()（通常应恰好放在程序退出位置之前）来转储内存泄漏信息：
	
	system("pause");
}
//Tracer.h
#ifndef _TRACER_H_
#define _TRACER_H_

#include <map>

#ifndef NDEBUG
void* operator new(size_t size, const char* file, long line);
void* operator new(size_t size);
void* operator new[](size_t size, const char* file, long line);
void* operator new[](size_t size);
void operator delete(void* p, const char*, long);
void operator delete(void* p);//重载
void operator delete[](void* p, const char*, long);//重载
void operator delete[](void* p);//重载

class Tracer
{
private:
	//嵌套类Entry
	class Entry
	{
	public:
		Entry(const char* file = 0, long line = 0)
			:file_(file), line_(line) {}
		const char* File() const { return file_; }
		long Line() const { return line_; }
	private:
		const char* file_;
		long line_;
	};
	//嵌套类Lock  用来实现加锁与解锁  
	class Lock
	{
	public:
		Lock(Tracer& tracer) :tracer_(tracer)
		{
			//构造函数调用加锁   析构函数解锁
			tracer_.lock();
		}
		~Lock()
		{
			tracer_.unlock();
		}
	private:
		Tracer& tracer_;
	};
	friend class Lock;
	//为了防止有的编译器Lock中访问不到lock(),unlock()函数  将其置为友元类


public:
	Tracer();
	~Tracer();
	static bool Ready;

	void Add(void* p, const char* file, long line);
	void Remove(void* p);
	void Dump();
private:
	std::map<void*, Entry>mapEntry_;
	int lockCount_;
	void lock() { ++lockCount_; }
	void unlock() { --lockCount_; }

};

extern Tracer NewTrace;

#endif//NDEBUG
#endif



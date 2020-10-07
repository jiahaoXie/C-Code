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
void operator delete(void* p);//����
void operator delete[](void* p, const char*, long);//����
void operator delete[](void* p);//����

class Tracer
{
private:
	//Ƕ����Entry
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
	//Ƕ����Lock  ����ʵ�ּ��������  
	class Lock
	{
	public:
		Lock(Tracer& tracer) :tracer_(tracer)
		{
			//���캯�����ü���   ������������
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
	//Ϊ�˷�ֹ�еı�����Lock�з��ʲ���lock(),unlock()����  ������Ϊ��Ԫ��


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



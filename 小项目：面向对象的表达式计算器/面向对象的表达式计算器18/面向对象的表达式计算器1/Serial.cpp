#include"Serial.h"
#include"Exception.h"
using std::ios;

const int Tru = 0xfab1fab2;
const int Fal = 0xbad1bad2;
//=====================Serializer==============================//


Serializer::Serializer(const std::string& fileName)
	:stream_(fileName.c_str(),ios::out|ios::binary)
{
	if (!stream_)
	{
		throw FileStreamError("Couldn't open file");
	}
}
Serializer& Serializer::put(int x) 
{
	stream_.write(reinterpret_cast<char*>(&x),sizeof(int));//以二进制的形式写入文件中
	if (stream_.bad())
		throw FileStreamError("File Write failed!");
	return *this;
}
Serializer& Serializer::put(unsigned int x) 
{
	stream_.write(reinterpret_cast<char*>(&x), sizeof(unsigned int));//以二进制的形式写入文件中
	if (stream_.bad())
		throw FileStreamError("File Write failed!");
	return *this;

}
Serializer&  Serializer::put(double x)
{
	stream_.write(reinterpret_cast<char*>(&x), sizeof(double));//以二进制的形式写入文件中
	if (stream_.bad())
		throw FileStreamError("File Write failed!");
	return *this;
}

Serializer& Serializer::put(long x) 
{
	stream_.write(reinterpret_cast<char*>(&x), sizeof(long));//以二进制的形式写入文件中
	if (stream_.bad())
		throw FileStreamError("File Write failed!");
	return *this;

}
Serializer& Serializer::put(unsigned long x) 
{
	stream_.write(reinterpret_cast<char*>(&x), sizeof(unsigned long));//以二进制的形式写入文件中
	if (stream_.bad())
		throw FileStreamError("File Write failed!");
	return *this;

}
Serializer& Serializer::put(const std::string x) 
{
	int len=x.length();//用来接收字符串的字节长度
	put(len);
	stream_.write(x.data(),x.length());
	if (stream_.bad())
		throw FileStreamError("File Write failed!");
	return *this;

}
Serializer& Serializer::put(bool x) 
{
	int n = x ? Tru : Fal;
	put(n);
	//便于bool类型的都写入4个字节
	return *this;

}

//operator<< 插入运算符
Serializer& Serializer::operator<<(int x) 
{
	return put(x);
}
Serializer& Serializer::operator<<(unsigned int x) 
{
	return put(x);

}

Serializer& Serializer::operator<<(double x) 
{
	return put(x);

}

Serializer& Serializer::operator<<(long x) 
{
	return put(x);

}
Serializer& Serializer::operator<<(unsigned long x) 
{
	return put(x);

}
Serializer& Serializer::operator<<(const std::string x) 
{
	return put(x);

}
Serializer& Serializer::operator<<(bool x) 
{
	return put(x);

}

//====================DeSerializer===========================/
DeSerializer::DeSerializer(const std::string& fileName)
	:stream_(fileName.c_str(), ios::in | ios::binary)
{
	if (stream_.eof())
	{ 
		throw FileStreamError("Couldn't open file");
	}
}
DeSerializer& DeSerializer::get(int& x)
{
	if (stream_.eof())
		throw FileStreamError("Unexpected end of file!");

	stream_.read(reinterpret_cast<char*>(&x),sizeof(int));
	if(stream_.bad())
		throw FileStreamError("File read failed!");

	return *this;
}
DeSerializer& DeSerializer::get(unsigned int& x)
{
	if (stream_.eof())
		throw FileStreamError("Unexpected end of file!");

	stream_.read(reinterpret_cast<char*>(&x), sizeof(unsigned int));
	if (stream_.bad())
		throw FileStreamError("File read failed!");

	return *this;

}

DeSerializer&  DeSerializer::get(double& x)
{
	if (stream_.eof())
		throw FileStreamError("Unexpected end of file!");

	stream_.read(reinterpret_cast<char*>(&x), sizeof(double));
	if (stream_.bad())
		throw FileStreamError("File read failed!");

	return *this;
}

DeSerializer& DeSerializer::get(long& x)
{
	if (stream_.eof())
		throw FileStreamError("Unexpected end of file!");

	stream_.read(reinterpret_cast<char*>(&x), sizeof(long));
	if (stream_.bad())
		throw FileStreamError("File read failed!");

	return *this;

}
DeSerializer& DeSerializer::get(unsigned long& x)
{
	if (stream_.eof())
		throw FileStreamError("Unexpected end of file!");

	stream_.read(reinterpret_cast<char*>(&x), sizeof(unsigned long));
	if (stream_.bad())
		throw FileStreamError("File read failed!");

	return *this;

}
DeSerializer& DeSerializer::get( std::string& x) 
{
	int len;
	 get(len);
	 if (stream_.eof())
		 throw FileStreamError("Unexpected end of file!");
	 x.resize(len);
	 stream_.read(&x[0],len);
	if (stream_.bad())
		throw FileStreamError("File read failed!");
	return *this;

}
DeSerializer& DeSerializer::get(bool& x)
{
	int n;
	get(n);
	if (n == Tru)
		x = true;
	else if (n == Fal)
		x = false;
	else
		throw FileStreamError("data error!");
	return *this;

}

//operator>> 输出运算符
DeSerializer& DeSerializer::operator>>(int& x)
{
	return get(x);
}
DeSerializer& DeSerializer::operator>>(unsigned int& x)
{
	return get(x);

}

DeSerializer& DeSerializer::operator>>(double& x)
{
	return get(x);

}

DeSerializer& DeSerializer::operator>>(long& x)
{
	return get(x);

}
DeSerializer& DeSerializer::operator>>(unsigned long& x)
{
	return get(x);

}
DeSerializer& DeSerializer::operator>>(std::string& x)
{
	return get(x);

}
DeSerializer& DeSerializer::operator>>(bool& x)
{
	return get(x);

}
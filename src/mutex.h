#ifndef MUTEX_H
#define MUTEX_H

#include <nan.h>
#include <windows.h>

NAN_METHOD(isActive);

class Mutex : public Nan::ObjectWrap {
public:
	static NAN_MODULE_INIT(Init);

private:
	explicit Mutex(const char *name, HANDLE mutex);
	~Mutex();

	static NAN_METHOD(New);
	static NAN_METHOD(Release);
	static NAN_METHOD(IsActive);
	static Nan::Persistent<v8::Function> constructor;
	
	const char* name_;
	HANDLE mutex_;
};

#endif // !MUTEX_H

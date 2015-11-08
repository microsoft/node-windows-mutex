#include "mutex.h"

NAN_METHOD(isActive) {
	if (!info[0]->IsString()) {
		return Nan::ThrowError(Nan::Error("Provide a mutex name"));
	}
	
	const char *name = *Nan::Utf8String(info[0]);
	HANDLE mutex = OpenMutex(
		SYNCHRONIZE,
		FALSE,
		name
	);
	
	if (mutex != NULL) {
		CloseHandle(mutex);
	}
	
	info.GetReturnValue().Set(mutex != NULL);
}

Nan::Persistent<v8::Function> Mutex::constructor;

NAN_MODULE_INIT(Mutex::Init) {
	v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
	tpl->SetClassName(Nan::New("Mutex").ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	Nan::SetPrototypeMethod(tpl, "release", Mutex::Release);
	Nan::SetPrototypeMethod(tpl, "isActive", Mutex::IsActive);

	constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
	Nan::Set(target, Nan::New("Mutex").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

Mutex::Mutex(const char *name, HANDLE mutex) : name_(name), mutex_(mutex) {
}

Mutex::~Mutex() {
	if (mutex_ != NULL) {
		CloseHandle(mutex_);
	}
}

NAN_METHOD(Mutex::New) {
	if (info.IsConstructCall()) {
		if (!info[0]->IsString()) {
			return Nan::ThrowError(Nan::Error("Provide a mutex name"));
		}
		
		const char *name = *Nan::Utf8String(info[0]);
		HANDLE mutex = CreateMutex(
			NULL,
			TRUE,
			name
		);
		
		if (mutex == NULL) {
			return Nan::ThrowError(Nan::Error("Error creating mutex"));
		}
		
		Mutex *obj = new Mutex(name, mutex);
		obj->Wrap(info.This());
		info.GetReturnValue().Set(info.This());
	}
	else {
		const int argc = 1;
		v8::Local<v8::Value> argv[argc] = { info[0] };
		v8::Local<v8::Function> cons = Nan::New(constructor);
		info.GetReturnValue().Set(cons->NewInstance(argc, argv));
	}
}

NAN_METHOD(Mutex::Release) {
	Mutex* obj = Nan::ObjectWrap::Unwrap<Mutex>(info.This());
	
	if (!obj->mutex_) {
		info.GetReturnValue().Set(FALSE);
		return;
	}
	
	CloseHandle(obj->mutex_);
	obj->mutex_ = NULL;
	info.GetReturnValue().Set(TRUE);
}

NAN_METHOD(Mutex::IsActive) {
	Mutex* obj = Nan::ObjectWrap::Unwrap<Mutex>(info.This());
	
	info.GetReturnValue().Set(obj->mutex_ != NULL);
}

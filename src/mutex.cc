#include "mutex.h"

Nan::Persistent<v8::Function> Mutex::constructor;

NAN_MODULE_INIT(Mutex::Init) {
	v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
	tpl->SetClassName(Nan::New("Mutex").ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	//Nan::SetPrototypeMethod(tpl, "plusOne", PlusOne);

	constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
	Nan::Set(target, Nan::New("Mutex").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

Mutex::Mutex(const char *name, HANDLE mutex) : name_(name), mutex_(mutex) {
}

Mutex::~Mutex() {
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

//NAN_METHOD(Mutex::PlusOne) {
//	Mutex* obj = Nan::ObjectWrap::Unwrap<Mutex>(info.This());
//	obj->value_ += 1;
//	info.GetReturnValue().Set(obj->value_);
//}

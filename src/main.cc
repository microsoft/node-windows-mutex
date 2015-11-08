#include <nan.h>
#include <windows.h>
#include "mutex.h"

NAN_MODULE_INIT(Init) {
	Nan::Set(target, Nan::New("isActive").ToLocalChecked(),
		Nan::GetFunction(Nan::New<v8::FunctionTemplate>(isActive)).ToLocalChecked());
	
	Mutex::Init(target);
}

NODE_MODULE(CreateMutex, Init)
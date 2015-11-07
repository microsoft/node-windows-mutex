#include <nan.h>
#include <windows.h>

namespace createmutex {

	using v8::FunctionCallbackInfo;
	using v8::FunctionTemplate;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;
	using v8::Handle;

	NAN_METHOD(Create) {
		HANDLE mutex = CreateMutex(
			NULL,
			TRUE,
			*String::Utf8Value(info[0]->ToString())
		);

		if (mutex == NULL) {
			info.GetReturnValue().Set(false);
			return;
		}

		info.GetReturnValue().Set(true);
		return;
	}

	void Init(Local<Object> exports, Handle<Object> module) {
		module->Set(Nan::New("exports").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(Create)).ToLocalChecked());
	}

	NODE_MODULE(CreateMutex, Init)

} // namespace createmutex
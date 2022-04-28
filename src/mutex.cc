#include "mutex.h"

Napi::Object Mutex::Init(Napi::Env env, Napi::Object exports) {
  Napi::FunctionReference* constructor = new Napi::FunctionReference();
	Napi::Function definition = DefineClass(env, "Mutex", {
    InstanceMethod<&Mutex::Release>("release"),
    InstanceMethod<&Mutex::IsActive>("isActive"),
  });
  *constructor = Napi::Persistent(definition);
  exports.Set("Mutex", definition);
  env.SetInstanceData<Napi::FunctionReference>(constructor);
  return exports;
}

Mutex::Mutex(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<Mutex>(info) {
  Napi::Env env(info.Env());

  if (!info[0].IsString()) {
			throw Napi::Error::New(env, "Provide a mutex name");
	}

	name_ = info[0].As<Napi::String>();
	mutex_ = CreateMutex(
		NULL,
		TRUE,
		name_.c_str()
	);

  DWORD err = GetLastError();
  if (mutex_ == NULL) {
    if (err == ERROR_INVALID_HANDLE) {
      throw Napi::Error::New(env, "Error provided name is already used for another HANDLE");
    } else {
		  throw Napi::Error::New(env, "Error creating mutex");
    }
	}

  if (err == ERROR_ALREADY_EXISTS) {
    CloseHandle(mutex_);
    mutex_ = NULL;
    throw Napi::Error::New(env, "Error mutex already exists");
	}
}

Mutex::~Mutex() {
	if (mutex_ != NULL) {
		CloseHandle(mutex_);
	}
}

void Mutex::Release(const Napi::CallbackInfo& info) {
	if (!mutex_) {
		return;
	}

	CloseHandle(mutex_);
	mutex_ = NULL;
}

Napi::Value Mutex::IsActive(const Napi::CallbackInfo& info) {
  Napi::Env env(info.Env());
	return Napi::Boolean::New(env, mutex_ != NULL);
}

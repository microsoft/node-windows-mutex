#include <napi.h>
#include "mutex.h"

Napi::Value IsActive(const Napi::CallbackInfo& info) {
  Napi::Env env(info.Env());

  if (!info[0].IsString()) {
    throw Napi::Error::New(env, "Provide a mutex name");
  }

  std::string name = info[0].As<Napi::String>();
  HANDLE mutex = OpenMutex(
    SYNCHRONIZE,
    FALSE,
    name.c_str()
  );

  bool is_active = false;
  if (mutex != NULL) {
    is_active = true;
    CloseHandle(mutex);
  }

  return Napi::Boolean::New(env, is_active);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("isActive", Napi::Function::New(env, IsActive));
  Mutex::Init(env, exports);
  return exports;
}

NODE_API_MODULE(CreateMutex, Init)
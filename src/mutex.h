#ifndef MUTEX_H
#define MUTEX_H

#include <napi.h>
#include <windows.h>

class Mutex : public Napi::ObjectWrap<Mutex> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  explicit Mutex(const Napi::CallbackInfo& info);

private:
  friend class Napi::ObjectWrap<Mutex>;
  ~Mutex();

  void Release(const Napi::CallbackInfo& info);
  Napi::Value IsActive(const Napi::CallbackInfo& info);

  std::string name_;
  HANDLE mutex_ = NULL;
};

#endif // !MUTEX_H

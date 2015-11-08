#include <nan.h>
#include <windows.h>
#include "mutex.h"

NAN_MODULE_INIT(Init) {
	Mutex::Init(target);
}

NODE_MODULE(CreateMutex, Init)
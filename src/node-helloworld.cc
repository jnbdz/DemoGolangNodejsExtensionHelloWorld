#include "helloworld.h"
#include <node.h>

namespace demo {

  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void printHelloWorldMsg(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Perform the operation
    String msg = HelloWorld();
    Local<String> printMsg = String::NewFromUtf8(isolate, msg);

    // Set the return value (using the passed in
    // FunctionCallbackInfo<Value>&)
    args.GetReturnValue().Set(printMsg);
  }

  void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "print", printHelloWorldMsg);
  }

  NODE_MODULE(calculator, init)
}
/* Node.js Crypt(3) implementation */

#include <node.h>
#include <v8.h>

#include <stdlib.h>
#include <unistd.h>

using namespace v8;

/* GetApacheSalt: generates 2 char salt. */
const char* GetApacheSalt()
{
    char *salt = new char[3];
    const char *const saltchars = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    /* Using current time as seed. */
    srand(time(NULL));

    /* Pick two random chars from saltchars. */
    salt[0] = saltchars[rand() % 64];
    salt[1] = saltchars[rand() % 64];
    salt[2] = '\0';

    return salt;
}

Handle<Value> Method(const Arguments& args) {
	HandleScope scope;

    if (args.Length() == 0) {
        ThrowException(Exception::TypeError(String::New("Password is required")));
        return scope.Close(Undefined());
    }

    if (!args[0]->IsString() || (args.Length() > 1 && !args[1]->IsString())) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }


    v8::String::Utf8Value password(args[0]->ToString());
    v8::String::Utf8Value salt(args.Length() > 1 ? args[1]->ToString() : String::New(GetApacheSalt()));

    Local<String> res = String::New( crypt(*password, *salt ) );
    return scope.Close(res);
}

void init(Handle<Object> exports) {
	exports->Set(String::NewSymbol("crypt"), FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(crypt3, init)

/* EOF */
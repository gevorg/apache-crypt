
#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>

extern "C" {
char* cpx_crypt_md5(const char* password, const char* salt);

char* cpx_sha256_crypt(const char* password, const char* salt);

char* cpx_sha512_crypt(const char* password, const char* salt);

char* cpx_crypt_des(const char* password, const char* salt);

char* cpx_crypt_apr1(const char* password, const char* salt);

char* crypt(const char* password, const char* salt) {
  if(strncmp(salt, "$1$", 3) == 0) {
    return cpx_crypt_md5(password, salt);
  }
  else if(strncmp(salt, "$6$", 3) == 0) {
    return cpx_sha512_crypt(password, salt);
  }
  else if(strncmp(salt, "$5$", 3) == 0) {
   return cpx_sha256_crypt(password, salt);
  }
  else if(salt[0] && salt[0] != '$') {
   return cpx_crypt_des(password, salt);
  }
  else if(strncmp(salt, "$apr1$", 6) == 0) {
    return cpx_crypt_apr1(password, salt);
  }
  else {
    return strdup("*0");
  }
}

}

std::string crypt_cpp(std::string key, std::string setting) {
  const char* salt = setting.c_str();
  const char* password = key.c_str();

  return crypt(password, salt);
}


#ifdef EMSCRIPTEN
#include <emscripten/bind.h>
EMSCRIPTEN_BINDINGS(main) {
    emscripten::function("crypt", &crypt_cpp);
}

#endif

#ifdef TEST

int main(void)
{
    std::string res = crypt_js("passwd", "$5$dd");
    printf("%s\n", res.c_str());
    return 0;
}

#endif
{
  "targets": [
    {
      "target_name": "crypt3",
      "sources": [ "./deps/crypt3.cc", "src/crypt_to64.c" , "src/des.c", "src/md5.c", "src/md5crypt.c", "src/sha256crypt.c", "src/sha512crypt.c", "src/interface.cpp" ],
      "cflags" : ["-DARCH_IS_BIG_ENDIAN=0 -fno-strict-aliasing"],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
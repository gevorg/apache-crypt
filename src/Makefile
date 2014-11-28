all: libcrypt.js

CC=emcc
CXX=em++

CFLAGS=-DARCH_IS_BIG_ENDIAN=0 -O3  --llvm-lto 1
CXXFLAGS=--bind -Os --closure 1 -O3 --llvm-lto 1

libcrypt.js: interface.cpp sha512crypt.o sha256crypt.o md5crypt.o md5.o des.o crypt_to64.o Makefile
	$(CXX) $(CXXFLAGS) interface.cpp sha512crypt.o sha256crypt.o md5crypt.o md5.o des.o crypt_to64.o -o libcrypt.js
	@sed -i 's/"libcrypt.js.mem"/__dirname + "\/libcrypt.js.mem"/' libcrypt.js
	@sed -i 's/"uncaughtException"/"em_uncaughtException"/' libcrypt.js

.c.o :
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o libcrypt.js
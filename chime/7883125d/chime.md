# Todo: Cryptopp - Consider to document crypto build and install on Macbook Air?

```#7883125d``` *As of 2016-10-13 10:36*

[mail plain/text](mail.txt)

{% raw %}
So, could it be good for future reference to document the download, build and install of the cryptopp library?

1) This seem to be what the final installation looks like on my Macbook air?

> Kjell-Olovs-MacBook-Air:include kjell-olov$ pwd  
> **/usr/local/include**  
> Kjell-Olovs-MacBook-Air:include kjell-olov$ tree cryptopp/  
> cryptopp/  
> ├── 3way.h  
> ├── adler32.h  
> ├── aes.h  
> ├── algebra.h  
> ├── algparam.h  
> ├── arc4.h  
> ├── argnames.h  
> ├── asn.h  
> ├── authenc.h  
> ├── base32.h  
> ├── base64.h  
> ├── basecode.h  
> ├── bench.h  
> ├── blake2.h  
> ├── blowfish.h  
> ├── blumshub.h  
> ├── camellia.h  
> ├── cast.h  
> ├── cbcmac.h  
> ├── ccm.h  
> ├── chacha.h  
> ├── channels.h  
> ├── cmac.h  
> ├── config.h  
> ├── cpu.h  
> ├── crc.h  
> ├── cryptlib.h  
> ├── default.h  
> ├── des.h  
> ├── dh.h  
> ├── dh2.h  
> ├── dll.h  
> ├── dmac.h  
> ├── dsa.h  
> ├── eax.h  
> ├── ec2n.h  
> ├── eccrypto.h  
> ├── ecp.h  
> ├── elgamal.h  
> ├── emsa2.h  
> ├── eprecomp.h  
> ├── esign.h  
> ├── factory.h  
> ├── fhmqv.h  
> ├── files.h  
> ├── filters.h  
> ├── fips140.h  
> ├── fltrimpl.h  
> ├── gcm.h  
> ├── gf256.h  
> ├── gf2_32.h  
> ├── gf2n.h  
> ├── gfpcrypt.h  
> ├── gost.h  
> ├── gzip.h  
> ├── hex.h  
> ├── hkdf.h  
> ├── hmac.h  
> ├── hmqv.h  
> ├── hrtimer.h  
> ├── ida.h  
> ├── idea.h  
> ├── integer.h  
> ├── iterhash.h  
> ├── keccak.h  
> ├── lubyrack.h  
> ├── luc.h  
> ├── mars.h  
> ├── md2.h  
> ├── md4.h  
> ├── md5.h  
> ├── mdc.h  
> ├── mersenne.h  
> ├── misc.h  
> ├── modarith.h  
> ├── modes.h  
> ├── modexppc.h  
> ├── mqueue.h  
> ├── mqv.h  
> ├── nbtheory.h  
> ├── network.h  
> ├── nr.h  
> ├── oaep.h  
> ├── oids.h  
> ├── osrng.h  
> ├── ossig.h  
> ├── panama.h  
> ├── pch.h  
> ├── pkcspad.h  
> ├── polynomi.h  
> ├── pssr.h  
> ├── pubkey.h  
> ├── pwdbased.h  
> ├── queue.h  
> ├── rabin.h  
> ├── randpool.h  
> ├── rc2.h  
> ├── rc5.h  
> ├── rc6.h  
> ├── rdrand.h  
> ├── resource.h  
> ├── rijndael.h  
> ├── ripemd.h  
> ├── rng.h  
> ├── rsa.h  
> ├── rw.h  
> ├── safer.h  
> ├── salsa.h  
> ├── seal.h  
> ├── secblock.h  
> ├── seckey.h  
> ├── seed.h  
> ├── serpent.h  
> ├── serpentp.h  
> ├── sha.h  
> ├── sha3.h  
> ├── shacal2.h  
> ├── shark.h  
> ├── simple.h  
> ├── skipjack.h  
> ├── smartptr.h  
> ├── socketft.h  
> ├── sosemanuk.h  
> ├── square.h  
> ├── stdcpp.h  
> ├── strciphr.h  
> ├── tea.h  
> ├── tiger.h  
> ├── trap.h  
> ├── trdlocal.h  
> ├── trunhash.h  
> ├── ttmac.h  
> ├── twofish.h  
> ├── validate.h  
> ├── vmac.h  
> ├── wait.h  
> ├── wake.h  
> ├── whrlpool.h  
> ├── winpipes.h  
> ├── words.h  
> ├── xtr.h  
> ├── xtrcrypt.h  
> ├── zdeflate.h  
> ├── zinflate.h  
> └── zlib.h

> 0 directories, 145 files  
> Kjell-Olovs-MacBook-Air:include kjell-olov$

> Kjell-Olovs-MacBook-Air:lib kjell-olov$ pwd  
> **/usr/local/lib**  
> Kjell-Olovs-MacBook-Air:lib kjell-olov$ ls \*cryptopp\*  
> **libcryptopp.5.6.dylib libcryptopp.a libcryptopp.dylib**  
> Kjell-Olovs-MacBook-Air:lib kjell-olov$

3) This seem to be the steps I took to download, build and install the cryptopp library on my Macbook air?

> Last login: Thu Oct 13 09:21:20 on console  
> Kjell-Olovs-MacBook-Air:~ kjell-olov$ cd Documents/  
> Kjell-Olovs-MacBook-Air:Documents kjell-olov$ cd Github/  
> Kjell-Olovs-MacBook-Air:Github kjell-olov$ **git clone <https://github.com/weidai11/cryptopp.git>**  
> Cloning into 'cryptopp'...  
> remote: Counting objects: 10339, done.  
> remote: Compressing objects: 100% (55/55), done.  
> remote: Total 10339 (delta 20), reused 0 (delta 0), pack-reused 10284  
> Receiving objects: 100% (10339/10339), 8.88 MiB | 1.66 MiB/s, done.  
> Resolving deltas: 100% (7336/7336), done.  
> Checking connectivity... done.  
> Kjell-Olovs-MacBook-Air:Github kjell-olov$  
> Kjell-Olovs-MacBook-Air:cryptopp kjell-olov$ **mkdir build_xc**  
> Kjell-Olovs-MacBook-Air:cryptopp kjell-olov$ **cd build_xc/**  
> Kjell-Olovs-MacBook-Air:build_xc kjell-olov$ pwd  
> /Users/kjell-olov/Documents/Github/cryptopp/build_xc  
> Kjell-Olovs-MacBook-Air:build_xc kjell-olov$ cmake ..  
> -- The C compiler identification is AppleClang 8.0.0.8000038  
> -- The CXX compiler identification is AppleClang 8.0.0.8000038  
> -- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  
> -- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc -- works  
> -- Detecting C compiler ABI info  
> -- Detecting C compiler ABI info - done  
> -- Detecting C compile features  
> -- Detecting C compile features - done  
> -- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  
> -- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ -- works  
> -- Detecting CXX compiler ABI info  
> -- Detecting CXX compiler ABI info - done  
> -- Detecting CXX compile features  
> -- Detecting CXX compile features - done  
> -- Check if the system is big endian  
> -- Searching 16 bit integer  
> -- Looking for sys/types.h  
> -- Looking for sys/types.h - found  
> -- Looking for stdint.h  
> -- Looking for stdint.h - found  
> -- Looking for stddef.h  
> -- Looking for stddef.h - found  
> -- Check size of unsigned short  
> -- Check size of unsigned short - done  
> -- Using unsigned short  
> -- Check if the system is big endian - little endian  
> -- Performing Test COMPILER_OPT_ARCH_NATIVE_SUPPORTED  
> -- Performing Test COMPILER_OPT_ARCH_NATIVE_SUPPORTED - Success  
> -- Looking for pthread.h  
> -- Looking for pthread.h - found  
> -- Looking for pthread_create  
> -- Looking for pthread_create - found  
> -- Found Threads: TRUE  
> -- Compiler:  
> -- Flags: -march=native  
> -- Build type: RelWithDebInfo  
> --  
> -- The following OPTIONAL packages have been found:

> \* Threads

> -- Configuring done  
> -- Generating done  
> -- Build files have been written to: /Users/kjell-olov/Documents/Github/cryptopp/build_xc  
> Kjell-Olovs-MacBook-Air:build_xc kjell-olov$ ls  
> CMakeCache.txt TestData  
> CMakeFiles TestVectors  
> CTestTestfile.cmake cmake_install.cmake  
> Makefile cryptopp-config-version.cmake  
> Kjell-Olovs-MacBook-Air:build_xc kjell-olov$ **make**  
> Scanning dependencies of target cryptopp-object  
> &#91; 1%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/cryptlib.cpp.o  
> &#91; 2%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/cpu.cpp.o  
> &#91; 3%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/integer.cpp.o  
> &#91; 3%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/3way.cpp.o  
> &#91; 4%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/adler32.cpp.o  
> &#91; 5%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/algebra.cpp.o  
> &#91; 5%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/algparam.cpp.o  
> &#91; 6%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/arc4.cpp.o  
> &#91; 7%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/asn.cpp.o  
> &#91; 8%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/authenc.cpp.o  
> &#91; 8%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/base32.cpp.o  
> &#91; 9%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/base64.cpp.o  
> &#91; 10%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/basecode.cpp.o  
> &#91; 11%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/bfinit.cpp.o  
> &#91; 11%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/blake2.cpp.o  
> &#91; 12%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/blowfish.cpp.o  
> &#91; 13%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/blumshub.cpp.o  
> &#91; 14%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/camellia.cpp.o  
> &#91; 14%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/cast.cpp.o  
> &#91; 15%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/casts.cpp.o  
> &#91; 16%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/cbcmac.cpp.o  
> &#91; 17%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/ccm.cpp.o  
> &#91; 17%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/chacha.cpp.o  
> &#91; 18%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/channels.cpp.o  
> &#91; 19%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/cmac.cpp.o  
> &#91; 19%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/crc.cpp.o  
> &#91; 20%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/default.cpp.o  
> In file included from /Users/kjell-olov/Documents/Github/cryptopp/default.cpp:13:  
> /Users/kjell-olov/Documents/Github/cryptopp/default.h:146:43: warning:  
> 'DefaultDecryptor' is deprecated &#91;-Wdeprecated-declarations&#93;  
> class MACBadErr : public DefaultDecryptor::Err {public: MACBadEr...  
> ^  
> /Users/kjell-olov/Documents/Github/cryptopp/default.h:57:7: note:  
> 'DefaultDecryptor' has been explicitly marked deprecated here  
> class DefaultDecryptor : public ProxyFilter  
> ^  
> /Users/kjell-olov/Documents/Github/cryptopp/default.h:161:18: warning:  
> 'DefaultDecryptor' is deprecated &#91;-Wdeprecated-declarations&#93;  
> DefaultDecryptor::State CurrentState() const;  
> ^  
> /Users/kjell-olov/Documents/Github/cryptopp/default.h:57:7: note:  
> 'DefaultDecryptor' has been explicitly marked deprecated here  
> class DefaultDecryptor : public ProxyFilter  
> ^  
> 2 warnings generated.  
> &#91; 21%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/des.cpp.o  
> &#91; 22%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/dessp.cpp.o  
> &#91; 22%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/dh.cpp.o  
> &#91; 23%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/dh2.cpp.o  
> &#91; 24%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/dll.cpp.o  
> &#91; 25%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/dsa.cpp.o  
> &#91; 25%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/eax.cpp.o  
> &#91; 26%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/ec2n.cpp.o  
> &#91; 27%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/eccrypto.cpp.o  
> &#91; 28%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/ecp.cpp.o  
> &#91; 28%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/elgamal.cpp.o  
> &#91; 29%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/emsa2.cpp.o  
> &#91; 30%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/eprecomp.cpp.o  
> &#91; 30%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/esign.cpp.o  
> &#91; 31%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/files.cpp.o  
> &#91; 32%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/filters.cpp.o  
> &#91; 33%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/fips140.cpp.o  
> &#91; 33%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/gcm.cpp.o  
> &#91; 34%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/gf256.cpp.o  
> &#91; 35%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/gf2_32.cpp.o  
> &#91; 36%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/gf2n.cpp.o  
> &#91; 36%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/gfpcrypt.cpp.o  
> &#91; 37%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/gost.cpp.o  
> &#91; 38%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/gzip.cpp.o  
> &#91; 39%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/hex.cpp.o  
> &#91; 39%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/hmac.cpp.o  
> &#91; 40%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/hrtimer.cpp.o  
> &#91; 41%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/ida.cpp.o  
> &#91; 42%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/idea.cpp.o  
> &#91; 42%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/iterhash.cpp.o  
> &#91; 43%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/keccak.cpp.o  
> &#91; 44%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/luc.cpp.o  
> &#91; 44%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/mars.cpp.o  
> &#91; 45%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/marss.cpp.o  
> &#91; 46%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/md2.cpp.o  
> &#91; 47%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/md4.cpp.o  
> &#91; 47%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/md5.cpp.o  
> &#91; 48%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/misc.cpp.o  
> &#91; 49%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/modes.cpp.o  
> &#91; 50%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/mqueue.cpp.o  
> &#91; 50%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/mqv.cpp.o  
> &#91; 51%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/nbtheory.cpp.o  
> &#91; 52%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/network.cpp.o  
> &#91; 53%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/oaep.cpp.o  
> &#91; 53%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/osrng.cpp.o  
> &#91; 54%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/panama.cpp.o  
> &#91; 55%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/pkcspad.cpp.o  
> &#91; 55%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/polynomi.cpp.o  
> &#91; 56%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/pssr.cpp.o  
> &#91; 57%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/pubkey.cpp.o  
> &#91; 58%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/queue.cpp.o  
> &#91; 58%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rabin.cpp.o  
> &#91; 59%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/randpool.cpp.o  
> &#91; 60%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rc2.cpp.o  
> &#91; 61%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rc5.cpp.o  
> &#91; 61%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rc6.cpp.o  
> &#91; 62%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rdrand.cpp.o  
> &#91; 63%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rdtables.cpp.o  
> &#91; 64%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rijndael.cpp.o  
> &#91; 64%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/ripemd.cpp.o  
> &#91; 65%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rng.cpp.o  
> &#91; 66%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rsa.cpp.o  
> &#91; 67%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/rw.cpp.o  
> &#91; 67%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/safer.cpp.o  
> &#91; 68%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/salsa.cpp.o  
> &#91; 69%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/seal.cpp.o  
> &#91; 69%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/seed.cpp.o  
> &#91; 70%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/serpent.cpp.o  
> &#91; 71%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/sha.cpp.o  
> &#91; 72%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/sha3.cpp.o  
> &#91; 72%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/shacal2.cpp.o  
> &#91; 73%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/shark.cpp.o  
> &#91; 74%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/sharkbox.cpp.o  
> &#91; 75%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/skipjack.cpp.o  
> &#91; 75%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/socketft.cpp.o  
> &#91; 76%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/sosemanuk.cpp.o  
> &#91; 77%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/square.cpp.o  
> &#91; 78%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/squaretb.cpp.o  
> &#91; 78%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/strciphr.cpp.o  
> &#91; 79%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/tea.cpp.o  
> &#91; 80%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/tftables.cpp.o  
> &#91; 80%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/tiger.cpp.o  
> &#91; 81%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/tigertab.cpp.o  
> &#91; 82%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/trdlocal.cpp.o  
> &#91; 83%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/ttmac.cpp.o  
> &#91; 83%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/twofish.cpp.o  
> &#91; 84%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/vmac.cpp.o  
> &#91; 85%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/wait.cpp.o  
> &#91; 86%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/wake.cpp.o  
> &#91; 86%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/whrlpool.cpp.o  
> &#91; 87%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/xtr.cpp.o  
> &#91; 88%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/xtrcrypt.cpp.o  
> &#91; 89%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/zdeflate.cpp.o  
> &#91; 89%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/zinflate.cpp.o  
> &#91; 90%&#93; Building CXX object CMakeFiles/cryptopp-object.dir/zlib.cpp.o  
> &#91; 90%&#93; Built target cryptopp-object  
> Scanning dependencies of target cryptopp-static  
> &#91; 91%&#93; Linking CXX static library libcryptopp.a  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(algebra.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(dh.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(eccrypto.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(elgamal.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(eprecomp.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(mqv.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(polynomi.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(strciphr.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(algebra.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(dh.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(eccrypto.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(elgamal.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(eprecomp.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(mqv.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(polynomi.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: libcryptopp.a(strciphr.cpp.o) has no symbols  
> &#91; 91%&#93; Built target cryptopp-static  
> Scanning dependencies of target cryptest  
> &#91; 91%&#93; Building CXX object CMakeFiles/cryptest.dir/test.cpp.o  
> In file included from /Users/kjell-olov/Documents/Github/cryptopp/test.cpp:14:  
> /Users/kjell-olov/Documents/Github/cryptopp/default.h:146:43: warning:  
> 'DefaultDecryptor' is deprecated &#91;-Wdeprecated-declarations&#93;  
> class MACBadErr : public DefaultDecryptor::Err {public: MACBadEr...  
> ^  
> /Users/kjell-olov/Documents/Github/cryptopp/default.h:57:7: note:  
> 'DefaultDecryptor' has been explicitly marked deprecated here  
> class DefaultDecryptor : public ProxyFilter  
> ^  
> /Users/kjell-olov/Documents/Github/cryptopp/default.h:161:18: warning:  
> 'DefaultDecryptor' is deprecated &#91;-Wdeprecated-declarations&#93;  
> DefaultDecryptor::State CurrentState() const;  
> ^  
> /Users/kjell-olov/Documents/Github/cryptopp/default.h:57:7: note:  
> 'DefaultDecryptor' has been explicitly marked deprecated here  
> class DefaultDecryptor : public ProxyFilter  
> ^  
> 2 warnings generated.  
> &#91; 92%&#93; Building CXX object CMakeFiles/cryptest.dir/bench1.cpp.o  
> &#91; 93%&#93; Building CXX object CMakeFiles/cryptest.dir/bench2.cpp.o  
> &#91; 93%&#93; Building CXX object CMakeFiles/cryptest.dir/validat1.cpp.o  
> &#91; 94%&#93; Building CXX object CMakeFiles/cryptest.dir/validat2.cpp.o  
> &#91; 95%&#93; Building CXX object CMakeFiles/cryptest.dir/validat3.cpp.o  
> &#91; 96%&#93; Building CXX object CMakeFiles/cryptest.dir/datatest.cpp.o  
> &#91; 96%&#93; Building CXX object CMakeFiles/cryptest.dir/regtest.cpp.o  
> &#91; 97%&#93; Building CXX object CMakeFiles/cryptest.dir/fipsalgt.cpp.o  
> &#91; 98%&#93; Building CXX object CMakeFiles/cryptest.dir/dlltest.cpp.o  
> &#91; 99%&#93; Building CXX object CMakeFiles/cryptest.dir/fipstest.cpp.o  
> &#91; 99%&#93; Linking CXX executable cryptest.exe  
> &#91; 99%&#93; Built target cryptest  
> Scanning dependencies of target cryptopp-shared  
> &#91;100%&#93; Linking CXX shared library libcryptopp.dylib  
> &#91;100%&#93; Built target cryptopp-shared  
> Kjell-Olovs-MacBook-Air:build_xc kjell-olov$ ls  
> CMakeCache.txt cmake_install.cmake  
> CMakeFiles cryptest.exe  
> CTestTestfile.cmake cryptopp-config-version.cmake  
> Makefile libcryptopp.5.6.dylib  
> TestData libcryptopp.a  
> TestVectors libcryptopp.dylib

> Kjell-Olovs-MacBook-Air:build_xc kjell-olov$ **make install PREFIX=/usr/local**  
> &#91; 90%&#93; Built target cryptopp-object  
> &#91; 91%&#93; Built target cryptopp-static  
> &#91; 99%&#93; Built target cryptest  
> &#91;100%&#93; Built target cryptopp-shared  
> Install the project...  
> -- Install configuration: "RelWithDebInfo"  
> -- Installing: /usr/local/lib/libcryptopp.5.6.dylib  
> -- Installing: /usr/local/lib/libcryptopp.dylib  
> -- Installing: /usr/local/lib/libcryptopp.a  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: /usr/local/lib/libcryptopp.a(algebra.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: /usr/local/lib/libcryptopp.a(dh.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: /usr/local/lib/libcryptopp.a(eccrypto.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: /usr/local/lib/libcryptopp.a(elgamal.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: /usr/local/lib/libcryptopp.a(eprecomp.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: /usr/local/lib/libcryptopp.a(mqv.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: /usr/local/lib/libcryptopp.a(polynomi.cpp.o) has no symbols  
> /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib: file: /usr/local/lib/libcryptopp.a(strciphr.cpp.o) has no symbols  
> -- Installing: /usr/local/include/cryptopp/3way.h  
> -- Installing: /usr/local/include/cryptopp/adler32.h  
> -- Installing: /usr/local/include/cryptopp/aes.h  
> -- Installing: /usr/local/include/cryptopp/algebra.h  
> -- Installing: /usr/local/include/cryptopp/algparam.h  
> -- Installing: /usr/local/include/cryptopp/arc4.h  
> -- Installing: /usr/local/include/cryptopp/argnames.h  
> -- Installing: /usr/local/include/cryptopp/asn.h  
> -- Installing: /usr/local/include/cryptopp/authenc.h  
> -- Installing: /usr/local/include/cryptopp/base32.h  
> -- Installing: /usr/local/include/cryptopp/base64.h  
> -- Installing: /usr/local/include/cryptopp/basecode.h  
> -- Installing: /usr/local/include/cryptopp/bench.h  
> -- Installing: /usr/local/include/cryptopp/blake2.h  
> -- Installing: /usr/local/include/cryptopp/blowfish.h  
> -- Installing: /usr/local/include/cryptopp/blumshub.h  
> -- Installing: /usr/local/include/cryptopp/camellia.h  
> -- Installing: /usr/local/include/cryptopp/cast.h  
> -- Installing: /usr/local/include/cryptopp/cbcmac.h  
> -- Installing: /usr/local/include/cryptopp/ccm.h  
> -- Installing: /usr/local/include/cryptopp/chacha.h  
> -- Installing: /usr/local/include/cryptopp/channels.h  
> -- Installing: /usr/local/include/cryptopp/cmac.h  
> -- Installing: /usr/local/include/cryptopp/config.h  
> -- Installing: /usr/local/include/cryptopp/cpu.h  
> -- Installing: /usr/local/include/cryptopp/crc.h  
> -- Installing: /usr/local/include/cryptopp/cryptlib.h  
> -- Installing: /usr/local/include/cryptopp/default.h  
> -- Installing: /usr/local/include/cryptopp/des.h  
> -- Installing: /usr/local/include/cryptopp/dh.h  
> -- Installing: /usr/local/include/cryptopp/dh2.h  
> -- Installing: /usr/local/include/cryptopp/dll.h  
> -- Installing: /usr/local/include/cryptopp/dmac.h  
> -- Installing: /usr/local/include/cryptopp/dsa.h  
> -- Installing: /usr/local/include/cryptopp/eax.h  
> -- Installing: /usr/local/include/cryptopp/ec2n.h  
> -- Installing: /usr/local/include/cryptopp/eccrypto.h  
> -- Installing: /usr/local/include/cryptopp/ecp.h  
> -- Installing: /usr/local/include/cryptopp/elgamal.h  
> -- Installing: /usr/local/include/cryptopp/emsa2.h  
> -- Installing: /usr/local/include/cryptopp/eprecomp.h  
> -- Installing: /usr/local/include/cryptopp/esign.h  
> -- Installing: /usr/local/include/cryptopp/factory.h  
> -- Installing: /usr/local/include/cryptopp/fhmqv.h  
> -- Installing: /usr/local/include/cryptopp/files.h  
> -- Installing: /usr/local/include/cryptopp/filters.h  
> -- Installing: /usr/local/include/cryptopp/fips140.h  
> -- Installing: /usr/local/include/cryptopp/fltrimpl.h  
> -- Installing: /usr/local/include/cryptopp/gcm.h  
> -- Installing: /usr/local/include/cryptopp/gf256.h  
> -- Installing: /usr/local/include/cryptopp/gf2_32.h  
> -- Installing: /usr/local/include/cryptopp/gf2n.h  
> -- Installing: /usr/local/include/cryptopp/gfpcrypt.h  
> -- Installing: /usr/local/include/cryptopp/gost.h  
> -- Installing: /usr/local/include/cryptopp/gzip.h  
> -- Installing: /usr/local/include/cryptopp/hex.h  
> -- Installing: /usr/local/include/cryptopp/hkdf.h  
> -- Installing: /usr/local/include/cryptopp/hmac.h  
> -- Installing: /usr/local/include/cryptopp/hmqv.h  
> -- Installing: /usr/local/include/cryptopp/hrtimer.h  
> -- Installing: /usr/local/include/cryptopp/ida.h  
> -- Installing: /usr/local/include/cryptopp/idea.h  
> -- Installing: /usr/local/include/cryptopp/integer.h  
> -- Installing: /usr/local/include/cryptopp/iterhash.h  
> -- Installing: /usr/local/include/cryptopp/keccak.h  
> -- Installing: /usr/local/include/cryptopp/lubyrack.h  
> -- Installing: /usr/local/include/cryptopp/luc.h  
> -- Installing: /usr/local/include/cryptopp/mars.h  
> -- Installing: /usr/local/include/cryptopp/md2.h  
> -- Installing: /usr/local/include/cryptopp/md4.h  
> -- Installing: /usr/local/include/cryptopp/md5.h  
> -- Installing: /usr/local/include/cryptopp/mdc.h  
> -- Installing: /usr/local/include/cryptopp/mersenne.h  
> -- Installing: /usr/local/include/cryptopp/misc.h  
> -- Installing: /usr/local/include/cryptopp/modarith.h  
> -- Installing: /usr/local/include/cryptopp/modes.h  
> -- Installing: /usr/local/include/cryptopp/modexppc.h  
> -- Installing: /usr/local/include/cryptopp/mqueue.h  
> -- Installing: /usr/local/include/cryptopp/mqv.h  
> -- Installing: /usr/local/include/cryptopp/nbtheory.h  
> -- Installing: /usr/local/include/cryptopp/network.h  
> -- Installing: /usr/local/include/cryptopp/nr.h  
> -- Installing: /usr/local/include/cryptopp/oaep.h  
> -- Installing: /usr/local/include/cryptopp/oids.h  
> -- Installing: /usr/local/include/cryptopp/osrng.h  
> -- Installing: /usr/local/include/cryptopp/ossig.h  
> -- Installing: /usr/local/include/cryptopp/panama.h  
> -- Installing: /usr/local/include/cryptopp/pch.h  
> -- Installing: /usr/local/include/cryptopp/pkcspad.h  
> -- Installing: /usr/local/include/cryptopp/polynomi.h  
> -- Installing: /usr/local/include/cryptopp/pssr.h  
> -- Installing: /usr/local/include/cryptopp/pubkey.h  
> -- Installing: /usr/local/include/cryptopp/pwdbased.h  
> -- Installing: /usr/local/include/cryptopp/queue.h  
> -- Installing: /usr/local/include/cryptopp/rabin.h  
> -- Installing: /usr/local/include/cryptopp/randpool.h  
> -- Installing: /usr/local/include/cryptopp/rc2.h  
> -- Installing: /usr/local/include/cryptopp/rc5.h  
> -- Installing: /usr/local/include/cryptopp/rc6.h  
> -- Installing: /usr/local/include/cryptopp/rdrand.h  
> -- Installing: /usr/local/include/cryptopp/resource.h  
> -- Installing: /usr/local/include/cryptopp/rijndael.h  
> -- Installing: /usr/local/include/cryptopp/ripemd.h  
> -- Installing: /usr/local/include/cryptopp/rng.h  
> -- Installing: /usr/local/include/cryptopp/rsa.h  
> -- Installing: /usr/local/include/cryptopp/rw.h  
> -- Installing: /usr/local/include/cryptopp/safer.h  
> -- Installing: /usr/local/include/cryptopp/salsa.h  
> -- Installing: /usr/local/include/cryptopp/seal.h  
> -- Installing: /usr/local/include/cryptopp/secblock.h  
> -- Installing: /usr/local/include/cryptopp/seckey.h  
> -- Installing: /usr/local/include/cryptopp/seed.h  
> -- Installing: /usr/local/include/cryptopp/serpent.h  
> -- Installing: /usr/local/include/cryptopp/serpentp.h  
> -- Installing: /usr/local/include/cryptopp/sha.h  
> -- Installing: /usr/local/include/cryptopp/sha3.h  
> -- Installing: /usr/local/include/cryptopp/shacal2.h  
> -- Installing: /usr/local/include/cryptopp/shark.h  
> -- Installing: /usr/local/include/cryptopp/simple.h  
> -- Installing: /usr/local/include/cryptopp/skipjack.h  
> -- Installing: /usr/local/include/cryptopp/smartptr.h  
> -- Installing: /usr/local/include/cryptopp/socketft.h  
> -- Installing: /usr/local/include/cryptopp/sosemanuk.h  
> -- Installing: /usr/local/include/cryptopp/square.h  
> -- Installing: /usr/local/include/cryptopp/stdcpp.h  
> -- Installing: /usr/local/include/cryptopp/strciphr.h  
> -- Installing: /usr/local/include/cryptopp/tea.h  
> -- Installing: /usr/local/include/cryptopp/tiger.h  
> -- Installing: /usr/local/include/cryptopp/trap.h  
> -- Installing: /usr/local/include/cryptopp/trdlocal.h  
> -- Installing: /usr/local/include/cryptopp/trunhash.h  
> -- Installing: /usr/local/include/cryptopp/ttmac.h  
> -- Installing: /usr/local/include/cryptopp/twofish.h  
> -- Installing: /usr/local/include/cryptopp/validate.h  
> -- Installing: /usr/local/include/cryptopp/vmac.h  
> -- Installing: /usr/local/include/cryptopp/wait.h  
> -- Installing: /usr/local/include/cryptopp/wake.h  
> -- Installing: /usr/local/include/cryptopp/whrlpool.h  
> -- Installing: /usr/local/include/cryptopp/winpipes.h  
> -- Installing: /usr/local/include/cryptopp/words.h  
> -- Installing: /usr/local/include/cryptopp/xtr.h  
> -- Installing: /usr/local/include/cryptopp/xtrcrypt.h  
> -- Installing: /usr/local/include/cryptopp/zdeflate.h  
> -- Installing: /usr/local/include/cryptopp/zinflate.h  
> -- Installing: /usr/local/include/cryptopp/zlib.h  
> -- Installing: /usr/local/lib/cmake/cryptopp/cryptopp-config.cmake  
> -- Installing: /usr/local/lib/cmake/cryptopp/cryptopp-config-version.cmake  
> -- Installing: /usr/local/lib/cmake/cryptopp/cryptopp-targets.cmake  
> -- Installing: /usr/local/lib/cmake/cryptopp/cryptopp-targets-relwithdebinfo.cmake  
> -- Installing: /usr/local/bin/cryptest.exe  
> -- Installing: /usr/local/share/cryptopp/TestData  
> -- Installing: /usr/local/share/cryptopp/TestData/3desval.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/3wayval.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/camellia.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/cast128v.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/cast256v.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/descert.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/dh1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/dh2048.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/dlie1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/dlie2048.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/dsa1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/dsa1024b.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/dsa512.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/elgc1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/esig1023.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/esig1536.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/esig2046.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/fhmqv160.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/fhmqv256.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/fhmqv384.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/fhmqv512.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/gostval.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/hmqv160.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/hmqv256.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/hmqv384.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/hmqv512.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/ideaval.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/luc1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/luc2048.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/lucc1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/lucc512.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/lucd1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/lucd512.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/lucs1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/lucs512.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/marsval.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/mqv1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/mqv2048.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/nr1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/nr2048.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rabi1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rabi2048.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rc2val.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rc5val.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rc6val.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rijndael.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rsa1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rsa2048.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rsa400pb.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rsa400pv.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rsa512a.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rw1024.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/rw2048.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/saferval.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/serpentv.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/shacal2v.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/sharkval.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/skipjack.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/squareva.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/twofishv.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/usage.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/xtrdh171.dat  
> -- Installing: /usr/local/share/cryptopp/TestData/xtrdh342.dat  
> -- Installing: /usr/local/share/cryptopp/TestVectors  
> -- Installing: /usr/local/share/cryptopp/TestVectors/aes.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/all.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/blake2.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/blake2b.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/blake2s.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/camellia.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/ccm.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/chacha.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/cmac.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/dlies.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/dsa.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/dsa_1363.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/dsa_rfc6979.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/eax.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/esign.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/gcm.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/hkdf.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/hmac.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/keccak.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/mars.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/nr.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/panama.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/Readme.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/rsa_oaep.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/rsa_pkcs1_1_5.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/rsa_pss.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/rw.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/salsa.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/seal.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/seed.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/sha.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/sha3_224_fips_202.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/sha3_256_fips_202.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/sha3_384_fips_202.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/sha3_512_fips_202.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/sha3_fips_202.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/shacal2.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/sosemanuk.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/tea.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/tls_chacha.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/ttmac.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/vmac.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/wake.txt  
> -- Installing: /usr/local/share/cryptopp/TestVectors/whrlpool.txt  
> Kjell-Olovs-MacBook-Air:build_xc kjell-olov$

{% endraw %}

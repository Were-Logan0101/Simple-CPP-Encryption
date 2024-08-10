# Simple-CPP-Encryption
## A Simple App To Make MD5 Hashes And Caeser Cipher
### Installing
```sh
git clone https://github.com/Were-Logan0101/Simple-CPP-Encryption
cd Simple-CPP-Encryption
```
### Building
#### If you are on windows just do 
```sh
./build.bat
./encrypt.exe
```
After installing mingw
#### If you are on windows just do 
```sh
mkdir build
cd build
cmake ..
make
cd ..
./encrypt.exe
```
### Expected Output
```sh
Usage: Simple-Encrypter [command] [argument]
Commands:
  md5 [text]   Generate MD5 Hash Of The Given Text
  encrypt [text]     Apply Caeser Cipher On The Given Text
  decrypt [text]     Decrypt Caeser Cipher On Given Text
```

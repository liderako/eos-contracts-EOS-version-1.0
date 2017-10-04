# message

## Description

This contract must, take input string in `./eosc push message etc.` and on output, print string in eosd.


# Usage

### INSTALL 

```
cd ~eos/contracts
git clone https://github.com/asvirido/eos-contracts.git
cd eos-contracts
mv message ../

add text "add_subdirectory(helloworld)" in ~/eos/contracts/CMakeList.txt

```
### MAKE

`
cd ~/eos/build && cmake -DBINARYEN_BIN=~/binaryen/bin -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl -DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib .. && make -j2
`
### How to upload contract in account?
`
cd ~/eos/build/programs/eosc && ./eosc set contract NAME_ACCOUNT ~/eoc/contracts/message/message.wast ~/eos/contract/message/message.abi
`
### How to start?
+ Action output

```
  ./eosc push message NAME_ACCOUNT output '{"text":"Hello World"}' -S NAME_ACCOUNT
```
+ Action dynamic
```
  ./eosc push message NAME_ACCOUNT dynamic "0hello" -S NAME_ACCOUNT`
```
P.S
Output in eosd win!

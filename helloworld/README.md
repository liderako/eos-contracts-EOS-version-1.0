# Hello World smart contract

### Install
mv dir helloworld in `~/eos/contracts` and add `add_subdirectory(helloworld)` in ~/eos/contracts/CMakeList.txt
### Make
`cd ~/eos/build && cmake -DBINARYEN_BIN=~/binaryen/bin -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl -DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib .. && make -j2`

### How to upload contract in account?
` cd ~/eos/build/programs/eosc &&`
`./eosc set contract NAME_ACCOUNT ~/eoc/contracts/helloworld/helloworld.wast ~/eos/contract/helloworld/helloworld.abi` 

### How to start?

`./eosc push message NAME_ACCOUNT helloworld '{}' -S NAME_ACCOUNT`
### OUTPUT IN EOSD!

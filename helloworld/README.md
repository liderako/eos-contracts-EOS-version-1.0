# Hello World smart contract

### Install
mv dir helloworld in ~/eos/contracts and add `add_subdirectory(helloworld)` in ~/eos/contracts/CMakeList.txt

### How to upload contract in account?
` ./eosc set contract NAME_ACCOUNT ~/eoc/contracts/helloworld/helloworld.wast ~/eos/contract/helloworld/helloworld.abi` 

### How to start?

`./eosc push message NAME_ACCOUNT helloworld '{}' -S NAME_ACCOUNT`
### OUTPUT IN EOSD!

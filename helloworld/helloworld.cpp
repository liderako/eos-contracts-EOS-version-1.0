#include <eoslib/eos.hpp>

extern "C" {
    void init() {
    }

    void apply(uint64_t code, uint64_t action)  {
          if (action == N(helloworld)) {
            eosio::print("Hello World!\n");
          }
    }
}

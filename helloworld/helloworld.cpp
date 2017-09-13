/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   author: asvirido                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Title: I what to know                             #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <eoslib/eos.hpp>

extern "C" {
    void init() {
    }

    void apply(uint64_t code, uint64_t action)  {
          if (action == N(helloworld)) {
            eos::print("Hello World!\n");
          }
    }
}

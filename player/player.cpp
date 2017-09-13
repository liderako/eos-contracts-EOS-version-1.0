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

#include <player/player.hpp>

namespace player  {
   void sendMsg(const player::Message& msg) {
      eos::print("Hello, World: ");
      eos::print(&msg.name);
   }
}

extern "C" {
    void init() {

    }

    void apply(uint64_t code, uint64_t action)  {
        if(code == N(player))  {
          if(action == N(hello)) {
            player::sendMsg(eos::currentMessage<player::Message>());
          }
        }
    }
}


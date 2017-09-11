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

namespace player
{
   using namespace eos;

   void sendMsg(const player::Message& msg)
   {
      print(&msg.name);
      printi(msg.count);
   }
}

using namespace player;

extern "C"
{
    
  void init()
  {

  }

  void apply(uint64_t code, uint64_t action)
  {
    if (code == N(player))
    {
      if (action == N(hello))
      { 
        player::sendMsg(currentMessage< player::Message >());
      }
    }
  }
}

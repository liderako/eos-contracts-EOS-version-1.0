/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mydice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/09/18 15:23:07 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mydice/mydice.hpp>

using namespace eos;
using namespace player;

namespace mydice {
  void  Gameplay(const mydice::Game& game) { 
   //   requireNotice( game.one);
   //   requireNotice( game.two );// Add the specified account to set of accounts to be notified
  //  requireAuth( game.one ); //Verifies that name exists in the set of provided auths on a message. Throws if not found
  //  requireAuth( game.two ); // Verifies that name exists in the set of provided auths on a message. Throws if not found

      auto two = getAccount( game.two );
      auto one   = getAccount( game.one );

       one.win = 1;
       two.win = 1;
       eos::print("ONE");
       eos::print(one.win);
       eos::print("\n");
      //Accounts::remove(one, game.one);
      Accounts::store( one, game.one );
      Accounts::store( two, game.two );

      auto one1  = getAccount( game.one );
      eos::print("LALA ");
      eos::print(one1.win);
      eos::print("\n");
      //eos::print("error\n");
      //player::Store( game.one, one );
      //player::Store( game.two, two );
  }
}

extern "C" {
    void init() {
    }

    void apply(uint64_t code, uint64_t action)  {
      if ( code == N( mydice ) )
        if ( action == N( game ) ) {
          mydice::Gameplay( currentMessage< mydice::Game >() );
        }
    }
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/09/27 14:45:05 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <player/player.hpp>

using namespace eos;

namespace player  {

    void  Store( Account account ) {
      Accounts::store( account.name, N(account), &account, sizeof(account) );
    }

    void Win( AccountName name ) {
      requireNotice( name );
      requireAuth( name );
      
      auto var = getAccount( name );
      
      var.win += 1;
      player::Store( var );
    } 
}

extern "C" {
    void init() {
      player::Store( player::Account() );
    }

    void apply( uint64_t code, uint64_t action )  {
      if ( action == N(win) )
       player::Win( currentCode() );


     /* 
        AccountName name = currentCode();
        eos::print("Name:", name , " res N(player):", N(player), " res N(name):", N(name));
        eos::print(" \n");
      */
    }
}


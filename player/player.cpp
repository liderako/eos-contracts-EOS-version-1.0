/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/09/20 18:18:11 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <player/player.hpp>

using namespace eos;

namespace player  {
  
    void  Store( const Account& account ) {
      Accounts::store( account, account.name );
    }
    void Remove( const Account& account ) {
     Accounts::remove ( account, account.name ); 
    }
    void Win ( AccountName name ) {

      // requireNotice( name );
      // requireAuth( name );
      
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
      if ( action == N(remove) )
        player::Remove( player::getAccount( currentCode()) );
      if ( action == N(win) )
        player::Win( currentCode() ); 
   // end new code
    }
}


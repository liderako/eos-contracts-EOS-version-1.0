/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/09/17 17:24:50 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <player/player.hpp>

using namespace eos;

namespace player  {
  
  // new code
    void  Store( const Account& account ) {
      Accounts::store( account, account.name );
    }
    void Remove( const Account& account ) {
     Accounts::remove ( account, account.name ); 
    }
    void Win ( AccountName name ) {
      auto var = Accounts::getAccount( name );
      
      var.win += 1;
      player::Store( var );
    } // END new code
  
// OLD CODE
//   void  Store( AccountName account, const Account& a ) {
//     Accounts::store( a, account );
//   }
//  void Remove( AccountName account, const Account& a ) {
//    Accounts::remove( a, account );
//  }

}

extern "C" {
    void init() {
      //AccountName name = currentCode(); old code
      //player::Remove( name, player::Account() ); old code
      //player::Store( name, player::Account() ); old code
      player::Store( player::Account() );
    }

    void apply( uint64_t code, uint64_t action )  {
     // new code
   //   if ( action == N(remove) )
   //     player::Remove( getAccount( currentCode()) );
   //     if ( action == N(win) )
   //       player::Win( currentCode() ); 
   // end new code
    }
}


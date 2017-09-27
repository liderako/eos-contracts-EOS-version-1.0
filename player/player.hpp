/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/09/27 14:38:40 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <eoslib/eos.hpp>
#include <eoslib/db.h>
#include <eoslib/db.hpp>
#include <eoslib/types.h>

namespace player {
   
   struct PACKED(Account) {

        AccountName       name;
        uint64_t          win;

        Account() {
            name = currentCode();
            win = 0;
        }
   };

   struct Accounts {

    static int32_t get(uint64_t scope, uint64_t code, uint64_t table, void* data, uint32_t len) {
      return ( load_i64( scope, code, table, data, len) );
    }

    static int32_t store(uint64_t scope, uint64_t table, const void* data, uint32_t len)  {
      return ( store_i64( scope, table, data, len ) );
    }
  };

  inline Account getAccount( AccountName owner ) {
    Account   account;

    Accounts::get(owner, currentCode(), N( account ), &account, sizeof(account) );
    return ( account );
   }

  void    Win( AccountName name );
  void    Store( Account account ); 
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/10/09 13:04:25 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <eoslib/eos.hpp>
#include <eoslib/db.h>
#include <eoslib/db.hpp>

namespace player {

  struct Account {

        AccountName       name;
        uint64_t          win;

        Account() {
            name = currentCode();
            win = 0;
        }
   };

   struct Accounts {

    static int32_t get(uint64_t scope, uint64_t code, uint64_t table, void* data, uint32_t len) {
      return ( load_i64( scope, code, table, data, len ) );
    }
     static int32_t store(AccountName scope, TableName table, void* data, uint32_t len)  {
       return ( store_i64( scope, table, data, len ) );
     }
    static int32_t update(AccountName scope, TableName table, void* data, uint32_t len) {
      return ( update_i64(scope, table, data, len));
    }
  };

  /*
    uint64_t  scope == account name;
    uint64_t  table == name table;
    void*     data;
    uint32_t  len == sizeof(data);
  */
  void      Store( Account account ) {
    int res = Accounts::store( account.name, N(account), &account, sizeof(account) );
    eos::print("Store: ",res, "\n");
  }

  void      Update( Account account ) {
    int res = Accounts::update(account.name, N(account), &account, sizeof(account) );
    eos::print("Update: ", res, "\n");
  }

  inline    Account getAccount( AccountName owner ) {
    Account   account;

    account.name = owner;
    Accounts::get(owner, currentCode(), N( account ), &account, sizeof(account) );
    return ( account );
  }

  void    Win( AccountName name ) {
    //requireNotice( name );
    //requireAuth( name );
      
    auto var = getAccount( name );
      
    var.win += 1;
    player::Store( var );
  //  player::Update( var );
  }
}

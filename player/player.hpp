/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/09/20 18:32:39 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <eoslib/eos.hpp>
#include <eoslib/db.h>

#include <eoslib/eos.hpp>
#include <eoslib/token.hpp>
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

   using Accounts = Table<N(currentCode()),N(player),N(account),Account,uint64_t>;

   inline Account getAccount( AccountName owner ) {
      Account   account;

      Accounts::get( account, owner );
      return ( account );
   }
}

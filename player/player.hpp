/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/10/22 23:18:51 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <eoslib/eos.hpp>
#include <eoslib/db.h>
#include <eoslib/db.hpp>

namespace player {

	// Account == data for table
	struct Account {
		AccountName		name;
		uint64_t		money;

		Account() {
			name = currentCode();
			money = 100;
		}
	};
   
   /* 
    * Use for Table
    */
	struct Accounts {
		static int32_t get(uint64_t scope, uint64_t code, uint64_t table, void* data, uint32_t len)	{
			return ( load_i64( scope, code, table, data, len ) );
		}
		static int32_t store(AccountName scope, TableName table, void* data, uint32_t len)  {
			return ( store_i64( scope, table, data, len ) );
		}
    };
    inline		Account getAccount( AccountName owner ) {
    	Account 	account;

		account.name = owner;
		Accounts::get(owner, owner, N( account ), &account, sizeof(account) );
		return ( account );
    }
    void	Store( Account account ) {
		uint32_t res = Accounts::store( account.name, N(account), &account, sizeof(account) );
	}
}

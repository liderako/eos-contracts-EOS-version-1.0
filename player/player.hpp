/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/11/07 14:20:44 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <eoslib/eos.hpp>
#include <eoslib/db.h>
#include <eoslib/db.hpp>
#include <player/Account.cpp>

namespace player {

	/*
	* This struct for work with table.
	*/
	struct Table {
		static int32_t get(uint64_t scope, uint64_t code, uint64_t table, void* data, uint32_t len) {
			return ( load_i64( scope, code, table, data, len ) );
		}
		static int32_t store(AccountName scope, TableName table, void* data, uint32_t len)  {
			return ( store_i64( scope, table, data, len ) );
		}
	}; 
	/*
	* This function is used to download data from a table.
	*/
	inline		Account getAccount( AccountName owner ) {
		Account 	account(owner);

		Table::get(owner, owner, N( account ), &account, sizeof(account) );
		return ( account );
	}
	/*
	* This function is used to set data to a table.
	*/
	void	Store( Account account ) {
		uint32_t res = Table::store( account.getName(), N(account), &account, sizeof(account) );
	}
} /* End namespace player */

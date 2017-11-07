/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/11/07 14:13:28 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <player/player.hpp>

using namespace eos;

namespace player{

	void	sendMoney( AccountName name, int quantity) {
		Account 	account;

		account = getAccount( name );
		account.moneySub(quantity);
		player::Store( account );
	}

	void	getMoney( AccountName name, int quantity) {
		Account 	account;

		account = getAccount( name );
		account.moneyAdd(quantity);
		player::Store( account );
	}
}

extern "C" {
	void init() {
		player::Store( Account() );
	}

	void apply( uint64_t code, uint64_t action )  {
		if ( action == N(sendmoney) ) {
			player::sendMoney( code, 10 );
		}
		else if ( action == N(win) ) {
			player::getMoney( code, 20 );
		}
    }
}

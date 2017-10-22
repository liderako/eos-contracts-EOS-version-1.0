/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/10/22 23:07:46 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <player/player.hpp>

using namespace eos;

namespace player{

	void	sendMoney( AccountName name, int countMoney) {
		Account var = getAccount( name );

		var.money -= countMoney;
		player::Store( var );
	}

	void	getMoney( AccountName name, int countMoney) {
		Account var = getAccount( name );

		var.money += countMoney;
		player::Store( var );
	}
}

extern "C" {
	void init() {
		player::Store( player::Account() );
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

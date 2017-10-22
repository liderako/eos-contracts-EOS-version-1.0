/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mydice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/10/22 23:06:16 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mydice/mydice.hpp>

using namespace eos;

namespace mydice {

	int  getWiner() {
		Time	random;
		int 	result;

		random = now();
		result = random % 2;
		return (result);
	}

	void	messageWin(AccountName name) {
		Message message = Message(name, N(win));
		message.send();
	}

	void 	messageLose(AccountName name) {
		Message message = Message(name, N(lose));
		message.send();
	}

	void	messageSendMoney(AccountName name) {
		Message message = Message(name, N(sendmoney) );
		message.send();
	}

	void  getMoney(AccountName one, AccountName two) {
		Account mydice = player::getAccount( N(mydice) );
		mydice::messageSendMoney(one); // get moneys player one
		mydice::messageSendMoney(two); // get moneys player two

		mydice.money += 20; // add balance in table mydice
		player::Store(mydice);
	}
	// one is win, two is lose
	void sendMoney(AccountName one, AccountName two) {
		Account mydice = player::getAccount( N(mydice) );
		mydice::messageWin(one); // send money player, which winner
		mydice::messageLose(two); // send message players; which lose
		
		mydice.money -= 20; // delete balance in table mydice
		player::Store(mydice);
	}

	void  Gameplay(const mydice::Game& game) {

	int whoWin;

	mydice::getMoney(game.one, game.two);
	whoWin = getWiner(); /* if 1 winner two if 0 winner 0 */
	if (whoWin == 0) {
		mydice::sendMoney(game.one, game.two);
	}
	else {
		mydice::sendMoney(game.two, game.one);
	}
  }
}

extern "C" {
    void init() {
    	player::Store( player::Account() ); // create table for balance bank for mydice
    }

    void apply(uint64_t code, uint64_t action)  {
      /*  Message(code, N(transfer), newTransfer, self, N(code))
      *
      *   first argument AccountName code, which owns the contract code to execute
      *   second argument FuncName type, type of this message
      *   third argument Payload payload, the payload data for this message
      *
      *   Indicates that a given pending message requires a certain permission {
      *     fourth argument AccountName account
      *     fifth argument PermissionName permission 
      *   }
      *
      */
      if ( code == N( mydice ) )
        if ( action == N( game ) ) {
          mydice::Gameplay( currentMessage< mydice::Game >() );
        }
    }
}


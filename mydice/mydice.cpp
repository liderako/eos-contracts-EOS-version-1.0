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

	void	messageSend(AccountName name, uint64_t action) {
		Message message = Message(name, action);
		message.send();
	}

	void  getMoney(AccountName one, AccountName two) {
		Account mydice = player::getAccount( N(mydice) );
		mydice::messageSend(one, N(sendmoney));
		mydice::messageSend(two, N(sendmoney));

		mydice.moneyAdd(20);/* add balance in table mydice */
		player::Store(mydice); /* update data in table */
	}

	void sendMoney(AccountName win, AccountName lose) {
		Account mydice = player::getAccount( N(mydice) );
		mydice::messageSend(win, N(win));
		mydice::messageSend(lose, N(lose));
		
		mydice.moneySub(20);/* sub balance in table mydice */
		player::Store(mydice); /* update data in table */
	}

	void  Gameplay(const mydice::Game& game) {

		int 			whoWin;
		AccountName 	win;
		AccountName		lose;

		mydice::getMoney(game.one, game.two);
		whoWin = getWiner();
		if (whoWin == 0) {
			win = game.one;
			lose = game.two;
		}
		else {
			win = game.two;
			lose = game.one;
		}
		mydice::sendMoney(win, lose);
	}
}

extern "C" {
	void init() {
		player::Store( Account() ); /* create table for balance bank for mydice */
	}

	void apply(uint64_t code, uint64_t action)  {

		if ( code == N(mydice) && action == N(game) ) {
			mydice::Gameplay( current_message< mydice::Game >() );
		}
	}
}

#include <mydice/mydice.hpp>

using namespace eosio;

namespace mydice {

	int  getWiner() {
		Time	random;
		int 	result;

		random = now();
		result = random % 2;
		return (result);
	}

	void	messageSend(uint64_t accountName, uint64_t action) {
		Message message = Message(accountName, action);
		message.send();
	}

	void  getMoney(uint64_t accountNameOne, uint64_t accountNameTwo) {
		Account mydice = player::getAccount( N(mydice) );
		mydice::messageSend(accountNameOne, N(sendmoney));
		mydice::messageSend(accountNameTwo, N(sendmoney));

		mydice.moneyAdd(20);/* add balance in table mydice */
		player::Store(mydice); /* update data in table */
	}

	void sendMoney(uint64_t accountNameWin, uint64_t accountNameLose) {
		Account mydice = player::getAccount( N(mydice) );
		mydice::messageSend(accountNameWin, N(win));
		mydice::messageSend(accountNameLose, N(lose));
		
		mydice.moneySub(20);/* sub balance in table mydice */
		player::Store(mydice); /* update data in table */
	}

	void  Gameplay(const mydice::Game& game) {

		int 			whoWin;
		uint64_t 		accountNameWin;
		uint64_t		accountNameLose;

		mydice::getMoney(game.accountNameOne, game.accountNameTwo);
		whoWin = getWiner();
		if (whoWin == 0) {
			accountNameWin = game.accountNameOne;
			accountNameLose = game.accountNameTwo;
		}
		else {
			accountNameWin = game.accountNameTwo;
			accountNameLose = game.accountNameOne;
		}
		mydice::sendMoney(accountNameWin, accountNameLose);
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

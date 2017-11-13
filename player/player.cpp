#include <player/player.hpp>

namespace player{

	void	sendMoney( uint64_t accountName, int quantity ) {
		Account 	account;

		account = getAccount( accountName );
		account.moneySub(quantity);
		player::Store( account );
	}

	void	getMoney( uint64_t accountName, int quantity ) {
		Account 	account;

		account = getAccount( accountName );
		account.moneyAdd( quantity );
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

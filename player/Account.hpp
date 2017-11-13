#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

/* 
*	This class used, how "dataTable" for table struct in player.hpp.
*/
class Account {
	private:
		uint64_t		accountName_;
		uint64_t		money_;
		
	public:
		Account();
		Account(uint64_t accountName, uint64_t money);
		uint64_t getAccountName();
		void moneyAdd(uint64_t quantity);
		void moneySub(uint64_t quantity);
};

#endif

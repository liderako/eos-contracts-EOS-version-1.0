#include "Iso.hpp";

class iErc20 {
	public:
		template<typename Transfer>
		/*
		* Send quanity of tokens from adress from to adress to
		*/
		virtual void transferFrom(Transfer transfer);
		/*
		* Get the total token supply.
		*/
		virtual uint64_t totalSupply();
		/*
		* Get the account balance of another account with AccountName name.
		*/
		virtual	uint64_t balanceOf(AccountName name);	
};

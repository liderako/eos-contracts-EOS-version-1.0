#include "Iso.hpp";
/*
* eos::token<uint64_t, N(42coin)> Tokens
*/
template<typename Token>
class Transfer {
	private:
		/*
		* Name of the account who sends the token.
		*/
		adress 	from_;
		/*
		* Name of the account who receives the token.
		*/
		adress 	to_;
		/*
		* Quantity of token to be transferred.
		*/
		Token 	quantity_;
	public:
		Transfer(adress from = 0, adress to = 0, uint64_t amount = 0) {
			from_ = from;
			to_ = to;
			// quantity_ = Tokens(amount);  // for eos
			quantity_ = amount; // for test
		}
};

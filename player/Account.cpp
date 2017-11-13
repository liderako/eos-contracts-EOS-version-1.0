#include "Account.hpp"

Account::Account() {
	accountName_ = current_code();
	money_ = 100;
}
Account::Account(uint64_t accountName, uint64_t money = 0) {
	accountName_ = accountName;
	money_ = money;
}
uint64_t Account::getAccountName() {
	return (accountName_);
}
void Account::moneyAdd(uint64_t add) {
	money_ += add;
}
void Account::moneySub(uint64_t sub) {
	money_ -= sub;
}
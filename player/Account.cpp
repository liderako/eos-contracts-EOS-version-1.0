/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:24:57 by asvirido          #+#    #+#             */
/*   Updated: 2017/11/07 14:42:13 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account() {
	name_ = current_code();
	money_ = 100;
}
Account::Account(AccountName name, uint64_t money = 0) {
	name_ = name;
	money_ = money; 
}
AccountName Account::getName() {
	return (name_);
}
void Account::moneyAdd(uint64_t add) {
	money_ += add;
}
void Account::moneySub(uint64_t sub) {
	money_ -= sub;
}
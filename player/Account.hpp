/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:20:56 by asvirido          #+#    #+#             */
/*   Updated: 2017/11/07 14:42:20 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

/* 
*	This class used, how "data table" for table.
*/

class Account {
	private:
		AccountName		name_;
		uint64_t		money_;
		
	public:
		Account();
		Account(AccountName name, uint64_t money);
		AccountName getName();
		void moneyAdd(uint64_t quantity);
		void moneySub(uint64_t quantity);
};

#endif

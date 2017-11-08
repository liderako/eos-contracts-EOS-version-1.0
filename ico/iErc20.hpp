/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iErc20.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:48:27 by asvirido          #+#    #+#             */
/*   Updated: 2017/11/06 14:54:50 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transfer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:48:27 by asvirido          #+#    #+#             */
/*   Updated: 2017/11/08 12:24:41 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Transfer.hpp";


Transfer::Transfer(adress from = 0, adress to = 0, uint64_t amount = 0) {
	from_ = from;
	to_ = to;
	// quantity_ = Tokens(amount);  // for eos
	quantity_ = amount; // for test
}

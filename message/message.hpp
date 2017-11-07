 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/10/03 17:54:49 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <eoslib/eos.hpp>

namespace message {

typedef uint64_t String;

  struct Input {
  	String text;
  };
}

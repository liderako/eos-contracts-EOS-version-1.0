/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mydice.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/10/22 21:22:29 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <eoslib/eos.hpp>
#include <eoslib/db.h>
#include <eoslib/db.hpp>
#include <player/player.hpp>

namespace mydice {
using namespace player;

  struct Game {
    AccountName   one;
    AccountName   two;
  };
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/09/17 17:16:20 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <player/player.hpp>

using namespace eos;

namespace player  {

  void  Store( AccountName account, const Account& a ) {
    Accounts::store( a, account);
  }
  void Remove( AccountName account, const Account& a) {
    Accounts::remove( a, account);
  }
}

extern "C" {
    void init() {
      player::Remove( N(player), player::Account() );
      player::Store( N(player), player::Account() );
    }

    void apply(uint64_t code, uint64_t action)  {;
    }
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/09/28 16:15:18 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <player/player.hpp>

using namespace eos;

extern "C" {
    void init() {
      player::Store( player::Account() );
    }

    void apply( uint64_t code, uint64_t action )  {
      if ( action == N(win) )
       player::Win( currentCode() );
    }
}

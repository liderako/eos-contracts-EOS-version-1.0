/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mydice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/09/28 16:38:27 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mydice/mydice.hpp>

using namespace eos;

namespace mydice {

  // int  getWiner() {
  //   Time  random;
  //   int   result;

  //   random = now();
  //   result = random % 2;
  //   return (result);
  // }

  void  Gameplay(const mydice::Game& game) {
    player::Win(game.one);
  }
}

extern "C" {
    void init() {
    }

    void apply(uint64_t code, uint64_t action)  {
      if ( code == N( mydice ) )
        if ( action == N( game ) ) {
          mydice::Gameplay( currentMessage< mydice::Game >() );
        }
    }
}





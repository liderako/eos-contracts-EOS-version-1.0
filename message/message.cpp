/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/10/02 21:14:55 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <message/message.hpp>

using namespace eos;

  // void  Gameplay(const mydice::Game& game) {
  //   //player::Win(game.one);
  // }

  //         if ( action == N( game ) ) {
  //         mydice::Gameplay( currentMessage< mydice::Game >() );
  //       }

namespace message {
  void output(const message::Input input) { 
    //char text[2] = {'a','n'};
    eos::print("Text: == ", &input.text,"\n");
    eos::print("NUM: == ", input.num, "\n");
   // prints(input.text);
   // prints(" \n");
    //eos::print(input.text);
  }
}

extern "C" {
    void init() {
    }

    void apply( uint64_t code, uint64_t action )  {
      if ( action == N(output) )  {
        message::output( currentMessage< message::Input >() );
      }
    }
}
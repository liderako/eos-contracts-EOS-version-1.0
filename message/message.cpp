/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/10/03 17:51:06 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <message/message.hpp>

using namespace eos;

namespace message {
  void output(const message::Input input) { 
    printn(input.text);
    prints("\n");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 15:41:12 by asvirido          #+#    #+#             */
/*   Updated: 2017/10/04 14:11:32 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <message/message.hpp>

using namespace eos;

namespace message {
  void output(const message::Input input) { 
    printn(input.text);
    prints("\n");
  }

  void dynamicOutput(){
    uint32_t len2 = messageSize();
    char     str[len2];

    readMessage(str, len2);
    prints(str);
    eos::print("\n");
  }
}

extern "C" {
    void init() {
    }

    void apply( uint64_t code, uint64_t action )  {
      if ( action == N(output) )  {
        message::output( currentMessage< message::Input >() );
      }
      else if ( action == N(dynamic) ) {
        message::dynamicOutput();
      }
    }
}

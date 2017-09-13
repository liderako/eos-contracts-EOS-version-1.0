/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   author: asvirido                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Title: I what to know                             #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <eoslib/eos.hpp>

namespace player
{
   struct Message
   {
     char name = 0;
     int  count = 0;
   };
}

// struct PACKED(test) {
// 	int key = 0;
// };

    // "tables": [
    //   {
    //     "table": "test",
    //     "type": "test",
    //   }
    // ]

    // ,{
    //   "name": "test",
    //   "fields":{
    //     "key": "UInt64"
    //   }
    //   }
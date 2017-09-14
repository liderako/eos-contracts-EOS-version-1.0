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
#include <eoslib/db.h>

// namespace player
// {
//    struct Var
//    {
//      char name = 0;
//      int  count = 0;
//    };
// }

struct PACKED(table) {
	uint64_t key;
};

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
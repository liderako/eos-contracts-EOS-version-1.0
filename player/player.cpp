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

#include <player/player.hpp>

/* Function

  store_i64(AccountName scope, TableName table, const void *data, uint32_t datalen)

  scope - the account scope that will be read, must exist in the transaction scopes list
  
  table - the ID/name of the table within the current scope/code context to modify
  
  RETURN == 1 if a new record was created, 0 if an existing record was updated
*/


/* Function 
AccountName currentCode()

Get the account which specifies the code that is being run

return type AccountName

*/

/* Function 
int32_t load_i64(AccountName scope, AccountName code, TableName table, void* data,uint32_t  datalen)

*/

namespace player  {

}

extern "C" {
    void init() {
    table   tmp;
    int     res;

    readMessage(&tmp, sizeof(tmp)); // sizeof(tmp) write in tmp
    res = store_i64(currentCode(), N(table), &tmp, sizeof(tmp)); // create or updated 
    
    // test store
    eos::print("store_i64 == ");
    eos::print(res);
    eos::print("\n");
    //
    res = load_i64(currentCode(), currentCode(), N(test_table), &alice, sizeof(TestModel) );
    }

    void apply(uint64_t code, uint64_t action)  {
    
    }
}


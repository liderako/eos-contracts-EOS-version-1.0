#include <eoslib/eos.hpp>
#include <eoslib/db.h>
#include <eoslib/db.hpp>
#include <player/Account.cpp>

namespace player {

	/*
	* This struct for work with table.
	*/
	struct Table {
		static int32_t get( uint64_t accountName, uint64_t code, uint64_t tableName, void* dataTable, uint32_t sizeData ) {
			return ( load_i64( accountName, code, tableName, dataTable, sizeData ) );
		}
		static int32_t store( uint64_t accountName, uint64_t tableName, void* dataTable, uint32_t sizeData )  {
			return ( store_i64( accountName, tableName, dataTable, sizeData ) );
		}
	}; 
	/*
	* This function is used to download data from a table.
	*/
	inline		Account getAccount( uint64_t accountNameOwner ) {
		Account 	account(accountNameOwner);
		uint64_t	tableName;

		tableName = N(account);
		Table::get(accountNameOwner, accountNameOwner, tableName, &account, sizeof(account) );
		return ( account );
	}
	/*
	* This function is used to set data to a table.
	*/
	void	Store( Account account ) {
		uint32_t res = Table::store( account.getAccountName(), N(account), &account, sizeof(account) );
	}
} /* End namespace player */

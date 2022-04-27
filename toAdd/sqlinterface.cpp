#include "sqlinterface.h"

sqlConnection::sqlConnection(std::string* fileLocation){
	std::string prefix = "file:"; 
	std::string syntax = prefix + *fileLocation; //fileLocation must be formatted as
	const char* formattedFileLocation = syntax.c_str();
	connectionStatus = sqlite3_open(formattedFileLocation,&dbHandle);
	if (connectionStatus != SQLITE_OK){
		std::cout << "\nCannot Open Database: " << sqlite3_errmsg(dbHandle) << " " << formattedFileLocation << std::endl;
		sqlite3_close(dbHandle);
		throw("connection failed");
	}
}

sqlConnection::~sqlConnection(){
	sqlite3_close(dbHandle);
}

bool sqlConnection :: loginQuery(std::string* username,std::string* password){
	char *query = "SELECT * FROM users WHERE username= :username ";
	sqlite3_stmt *res;
	std::string salted;
	std::string hashToComp;

	int resCode = sqlite3_prepare_v2(dbHandle,query,-1,&res,0);//prepares the query

	if (resCode == SQLITE_OK){
		int index = sqlite3_bind_parameter_index(res,":username");//binds the username
		sqlite3_bind_text(res,index,username->c_str(),-1,SQLITE_STATIC); //parameter to the query
	}
	else{
		std::cout << "failed to execute statement:" << sqlite3_errmsg(dbHandle);
	}

	int step = sqlite3_step(res);//step to first result



	if(step == SQLITE_ROW){
		salted = reinterpret_cast<char *>(const_cast<unsigned char*>(sqlite3_column_text(res,3)));//double cast from const unsigned char* to char*. 3 is the salt column
		hashToComp = reinterpret_cast<char*>(const_cast<unsigned char*>(sqlite3_column_text(res,1)));//1 is pass column
		salted.append(*password);
		std::vector<unsigned char> hash(picosha2::k_digest_size);
		picosha2::hash256(salted.begin(),salted.end(),hash.begin(),hash.end());//creates hash from string
		std::string saltedHash = picosha2::bytes_to_hex_string(hash.begin(),hash.end());//converts hash to string
		
		if(saltedHash.compare(hashToComp) == 0){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		throw("empty database");
		return false;
	}

}
	

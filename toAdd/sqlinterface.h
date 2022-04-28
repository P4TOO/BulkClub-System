#ifndef SQLINTERFACE_H_
#define SQLINTERFACE_H_

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include "sqlite3.c"
#include "picosha2.h"

class sqlConnection {
	sqlite3 *dbHandle;
	int connectionStatus;

public:
	sqlConnection(std::string* fileLocation);
	~sqlConnection();
	bool loginQuery(std::string* username,std::string* password);	




};







#endif

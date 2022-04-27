BASIC USAGE

class sqlConnection must be called using

	sqlConnection objectname("filelocation");

where filelocation is the location of the .db file

login checks can be performed with

	objectname.loginQuery(string* username,string* password);

which will return a bool value. 

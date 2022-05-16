#include <stdio.h>
#include <stdlib.h>
#include "LoadConfig.h"


int main(){
	//printf("Hello %s\n",NULL);
	const char* File = "Test.conf";
	struct configData* MyConf = readConfig(File);
	printConfig(MyConf);
	
	printf("Value of value = %s\n",getConfValue("value",MyConf));
	printf("Value of value12434 = %s\n",getConfValue("value12434",MyConf));
	
	destroyConfig(MyConf);
	
}

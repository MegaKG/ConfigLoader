#include <stdio.h>
#include <stdlib.h>
#include "LoadArgs.h"


int main(int argc, char** argv){
	if (argc == 1){
		printf("Warning, No Arguments, try something like %s -tag Hello\n",argv[0]);
	}
	struct configData* MyConf = readArgs(argc, argv);
	printConfig(MyConf);
	
	printf("Value of -value = %s\n",getConfValue("-value",MyConf));
	printf("Value of -value12434 = %s\n",getConfValue("-value12434",MyConf));
	
	destroyConfig(MyConf);
	
}

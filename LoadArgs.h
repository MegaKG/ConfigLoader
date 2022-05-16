#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
	char* Key;
	char* Value;
};

struct configData {
	struct configData* Next;
	struct data MyData;
};

struct configData* readArgs(int argc, char** argv){
	
	
	struct configData* Head = (struct configData*)malloc(sizeof(struct configData));
	Head->Next = NULL;
	Head->MyData.Key = NULL;
	Head->MyData.Value = NULL;
	
	int KeyPtr = -1;
	int ValuePtr = -1;
	
	char* ptr;
	
	int i;
	for (i = 1; i < argc; i++){
		//printf("arg %s\n",argv[i]);
		if (argv[i][0] =='-'){
				if ((KeyPtr > 0) && (ValuePtr > 0)){
					//Copy to Dedicated pointers
					Head->MyData.Key = argv[KeyPtr];
					//printf("Loaded Key %s -> ",ptr);
					
					
					Head->MyData.Value = argv[ValuePtr];
					//printf("%s\n",ptr);
					
					//Generate a new head
					struct configData* NewHead = (struct configData*)malloc(sizeof(struct configData));
					NewHead->Next = Head;
					Head = NewHead;
					Head->MyData.Key = NULL;
					Head->MyData.Value = NULL;
				
				}
				else {
					//printf("Line was Empty\n");
					;
				}
				
				//Attach new key
				//printf("Key %s\n",argv[i]);
				KeyPtr = i;
		}
		else {
				//printf("Value %s\n",argv[i]);
				ValuePtr = i;
		}
		
		
			
	}
	
	
	//Clean up Residual
	if ((KeyPtr > 0) && (ValuePtr > 0)){
		//Copy to Dedicated pointers
		Head->MyData.Key = argv[KeyPtr];
		//printf("Loaded Key %s -> ",ptr);
					
		Head->MyData.Value = argv[ValuePtr];
		//printf("%s\n",ptr);
					
		//Generate a new head
		struct configData* NewHead = (struct configData*)malloc(sizeof(struct configData));
		NewHead->Next = Head;
		Head = NewHead;
		Head->MyData.Key = NULL;
		Head->MyData.Value = NULL;
	}
	
	


	return Head;
}



void printConfig(struct configData* Config){
	if (Config->Next == NULL){
		printf("Next is NULL, Error\n");
		return;
	}
	
	struct configData* Sel = Config->Next;
	while (1){
		printf("Config: %s -> %s\n",Sel->MyData.Key,Sel->MyData.Value);
		if (Sel->Next == NULL){
			break;
		}
		else {
			Sel = Sel->Next;
		}
	}
	
}


char* getConfValue(char* Key,struct configData* Config){
	if (Config->Next == NULL){
		printf("Next is NULL, Error\n");
		return;
	}
	
	struct configData* Sel = Config->Next;
	while (1){
		
		if (strcmp(Sel->MyData.Key,Key) == 0){
			return Sel->MyData.Value;
		}
		
		
		if (Sel->Next == NULL){
			break;
		}
		else {
			Sel = Sel->Next;
		}
	}
	return NULL;
	
}

void destroyConfig(struct configData* Config){
	if (Config->Next == NULL){
		printf("Next is NULL, Error\n");
		return;
	}
	
	else {
		struct configData* ptr;
		int depth;
		while (Config->Next != NULL){
			ptr = Config;
			depth = 0;
			while (1){
				//printf("Depth %i\n",depth);
				if (ptr->Next->Next != NULL){
					ptr = ptr->Next;
				}
				else {
					free(ptr->Next);
					ptr->Next = NULL;
					break;
				}
				depth += 1;
			}
		}
	}
	free(Config);
}

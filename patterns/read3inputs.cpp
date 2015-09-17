#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main(){
//const char * c = file_name.c_str();//converts string to const char*
/*   char *file_name;*/
   char line[80];
   int i;
   FILE *fp;
   char *token;
   char *name;
   char *name2;

   std::string search = ",";

   fp = fopen("patterns1.in","r");
   if( fp == NULL ){
        cout<<"Error while opening the file " <<"patterns1.in"<<endl;
        exit(0);
   }
   i=0;
   while( ( fgets(line,80,fp) ) != NULL )i+=1;
   fclose(fp);

   
   //brick=(struct Physical *)malloc(sizeof(struct Physical)*input.N);
   //brickim=(struct SDL_Surface **)malloc(sizeof(SDL_Surface)*input.N);
   i=0;
   fp = fopen("patterns1.in","r");
   while( ( fgets(line,80,fp) ) != NULL ){
        name = strtok(line, search.c_str());
        token = strtok(NULL,search.c_str());
	name2 = strtok(NULL, search.c_str());
	cout<<name<<","<<token<<","<<name2<<endl;
	
	//cout<<(int)atof(token)<<endl;
	//cout<<(int)atof(token)<<endl;
        //brickim[i]=load_map("objects/bloody_brick9.bmp",1);
	i+=1;
        }
   fclose(fp);
   return 0;
} 

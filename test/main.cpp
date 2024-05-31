#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

#include "mat_file.hpp"

int main (int argc, char *argv[])
{

   std::cout << "test = " << Z_BEST_COMPRESSION << std::endl;

   // uint8_t octets_ [1024];

   std::string inPath = "easy.mat";
   // std::string outPath = "../matFiles/matFiles/easy.mat";
   // std::ifstream inFile (path, ios_base::binary);
   // inFile.imbue(std::locale("C"));
   // std::string contents (std::istreambuf_iterator<char> (inFile),
   //                       std::istreambuf_terator<char> ());

   // FILE *f = fopen(path.c_str (), "r");
   // fseek(f, 0, SEEK_END);
   // long fsize = ftell(f);
   // fseek(f, 0, SEEK_SET);

   // char *octets_ = (char *)malloc(fsize + 1);
   // fread(string, fsize, 1, f);
   // fclose(f);

   mat::mat_file_5 mat_obj (inPath);

   return(EXIT_SUCCESS);
}
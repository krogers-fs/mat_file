
#ifndef mat_file_hpp
#define mat_file_hpp

#include <cstdint>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "zlib.h"

namespace mat
{
   struct header
   {
      static const std::size_t description_idx = 0;
      static const std::size_t description_size = 116;

      std::size_t subsystem_data_idx = 116;
      std::size_t subsystem_data_size = 8;

      std::size_t version_idx = 124;
      std::size_t version_size = 2;

      std::size_t endian_indicator_idx = 126;
      std::size_t endian_indicator_size = 2;
   };

   enum mdata_types
   {
      miINT8 = 1,
      miUINT8 = 2,
      miINT16 = 3,
      miUINT16 = 4,
      miINT32 = 5,
      miUINT32 = 6,
      miSINGLE = 7,
      RESERVED_8 = 8,
      miDOUBLE = 9,
      RESERVED_10 = 10,
      RESERVED_11 = 11,
      miINT64 = 12,
      miUINT64 = 13,
      miMATRIX = 14,
      miCOMPRESSED = 15,
      miUTF8 = 16,
      miUTF16 = 17,
      miUTF32 = 18
   };

   std::size_t
   mbyte_size (uint32_t mdata_type)
   {
      switch (mdata_type)
      {
         case (miINT8):
         case (miUINT8):
         case (miUTF8):
            return 1;
         case (miINT16):
         case (miUINT16):
         case (miUTF16):
            return 2;
         case (miINT32):
         case (miUINT32):
         case (miSINGLE):
         case (miUTF32):
            return 4;
         case (miINT64):
         case (miUINT64):
         case (miDOUBLE):
            return 8;
         default:
            return 0;
      }
   }

   struct tag
   {
      std::size_t data_type_idx = 0;
      std::size_t data_type_size = 4;

      std::size_t number_of_bytes_idx = 4;
      std::size_t number_of_bytes_size = 4;

      std::size_t data_idx = 8;
   };

   struct small_tag
   {
      std::size_t number_of_bytes_idx = 0;
      std::size_t number_of_bytes_size = 2;

      std::size_t data_type_idx = 2;
      std::size_t data_type_size = 2;

      std::size_t data_idx = 4;
      std::size_t data_size = 4;
   };

   class data_element
   {
      public:
         data_element ()
         {

         }

      private:
         uint8_t *data_;
   };

   class mat_file_5
   {
      public:
         mat_file_5 (std::string inFile,
                     std::string outFile = "out.mat")
         {
            // read_mat_file (inFile);
            // get_header ();
            // print (outFile);
         }

         // ~mat_file ()
         // {
         //    free (octets_);
         // }

      private:
         void
         read_mat_file (std::string inFile)
         {
            FILE *f = fopen (inFile.c_str (), "r");
            fseek (f, 0, SEEK_END);
            long fsize = ftell(f);
            fseek (f, 0, SEEK_SET);

            char *octets_ = (char *) malloc (fsize + 1);
            fread (octets_, sizeof (char), fsize, f);
            fclose (f);
         }

         void
         get_header ()
         {
            for (int i = 0; i < header::description_size; ++i)
            {
               
            }
         }

         void
         print (std::string outFile)
         {

            std::cout << "DESCRIPTION:" << "\n";

            for (int i = 0; i < header::description_size; ++i)
            {
               std::cout << octets_ [i];
            }

            std::cout << std::endl;

            FILE *f = fopen (outFile.c_str (), "wb");
            fwrite (octets_, sizeof (char), header::description_size, f);
            fclose (f);
         }

      private:
         char * octets_;
         char description [header::description_size];
   };
}

#endif
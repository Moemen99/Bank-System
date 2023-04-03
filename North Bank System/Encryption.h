#pragma once
#include "FilesHelper.h"
class Encryption
{
public:
   static string enscryptedInfo(string& fileLine) {

        for (int i = 0; i < fileLine.length(); i++) {
            fileLine[i]++;

        }
        return fileLine;

    }
   
      static  string descryptedInfo(string & fileLine) {


        for (int i = 0; i < fileLine.length(); i++) {
            fileLine[i]--;
        }
        ;
        return fileLine;

    }
};


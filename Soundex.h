#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>
int isBFPV(char test);
int isCGJ (char test);
int isDT (char test);
int  isL (char test);
int isMN(char test);
 int isR(char test);



char getSoundexCode(char test)
{
    test = toupper(test);
    int Result=0;
    Result= isBFPV (test);
}   
    

int isBFPV(char test)
{
 if(test== 'B' || 'F' || 'P' || 'V')
 return 1;
 else isCGJ(test);
}
    
    
int isCGJ (char test)
{
 if(test== 'C')
 return 2;
 else isDT(test);
}
  
int isDT (char test)
{ if(test=='D')
  return 3;
  else isL(test);
}


int  isL (char test)
{
 if(test=='L')  
 return 4;
 else isMN(test);
}

int isMN(char test)
{
 if(test == 'M')
 return 5;
 else isR(test);
}

 int isR(char test)
{
if(test == 'R')
return 6;
else return 0;
}
    
   


void generateSoundex(const char *name, char *soundex) 
{
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) 
    {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) 
        {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) 
    {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H

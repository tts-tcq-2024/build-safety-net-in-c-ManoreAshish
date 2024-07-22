#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>
int isBF(char test);
int isPV(char test);
int isCG (char test);
int isJK (char test);
int isQS (char test);
int isXZ (char test);
int isDT (char test);
int  isL (char test);
int isMN(char test);
int isR(char test);
int sIndex = 1;



char getSoundexCode(char test)
{
    test = toupper(test);
    int Result=0;
    Result= isBF (test);
}   
    

int isBF(char test)
{
 if(test== 'B' || 'F')
 return 1;
 else isPV(test);
}

int isPV(char test)
{
 if(test== 'P' || 'V')
 return 1;
 else isCG(test);
}
    
    
int isCG (char test)
{
 if(test== 'C' || 'G')
 return 2;
 else isJK(test);
}

int isJK (char test)
{
 if(test== 'J' || 'K')
 return 2;
 else isQS(test);
}

int isQS (char test)
{
 if(test== 'Q' || 'S')
 return 2;
 else isXZ(test);
}

int isXZ (char test)
{
 if(test== 'X' || 'Z')
 return 2;
 else isDT(test);
}
  
int isDT (char test)
{ if(test=='D' || 'T')
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
 if(test == 'M' || 'N')
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
    for (int i = 1; i < len && sIndex < 4; i++) 
    {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) 
        {
            soundex[sIndex++] = code;
        }
    }
    ZeroPadding(soundex[]);
}

void ZeroPadding(char *soundex)
{
    while (sIndex < 4) 
    {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

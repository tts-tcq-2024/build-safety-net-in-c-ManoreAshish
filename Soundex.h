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
void ZeroPadding(char *soundex);
void UpdateSoundex (char *soundex);
int sIndex = 1;
char code=0;



char getSoundexCode(char test)
{
    test = toupper(test);
    int Result=0;
    Result= isBF (test);
}   
    

int isBF(char test)
{
 if((test== 'B') || (test== 'F'))
 return 1;
 else isPV(test);
}

int isPV(char test)
{
 if((test== 'P') ||(test== 'V'))
 return 1;
 else isCG(test);
}
    
    
int isCG (char test)
{
 if((test== 'C' )|| (test=='G'))
 return 2;
 else isJK(test);
}

int isJK (char test)
{
 if((test== 'J') || (test=='K'))
 return 2;
 else isQS(test);
}

int isQS (char test)
{
 if((test== 'Q' || (test=='S'))
 return 2;
 else isXZ(test);
}

int isXZ (char test)
{
 if((test== 'X') || (test=='Z'))
 return 2;
 else isDT(test);
}
  
int isDT (char test)
{ if((test=='D') || (test=='T'))
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
 if((test == 'M') || (test=='N'))
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
        UpdateSoundex(soundex);
    }
    ZeroPadding(soundex);
}

void UpdateSoundex (char *soundex)
{
     if (code != '0' && code != soundex[sIndex - 1]) 
        {
            soundex[sIndex] = code;
            sIndex++;
        }
}

void ZeroPadding(char *soundex)
{
    while (sIndex < 4) 
    {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}
#endif // SOUNDEX_H

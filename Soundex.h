#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>
int Counter=0;

char getSoundexCode(char test)
{
    test = toupper(test);
    int Result=0;
    /*switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y */
    
    Result= isBFPV (test);
    if(Counter == 0) Result=isCGJ (test);
    if(Counter == 0) Result=isDT(test);
    if(Counter == 0) Result= isL(test);
    if(Counter==0) Result=isMN(test);
    if(Counter==0) Result= isR(test);
     else return 0;
}   
    

    int isBFPV(char test)
    {
        if(test== 'B' || 'F' || 'P' || 'V')
            return 1;
        Counter++;
    }
    
    
     int isCGJ (char test)
    {
            if(test== 'C')
                return 2;
            Counter++;
    }
  
     int isDT (char test)
    { if(test=='D')
        return 3;
        Counter++;
    }
    
   
    int  isL (char test)
     {
        if(test=='L')  
        return 4;
        Counter++;
     }
    
    
    
        int isMN(char test)
        {
            if(test == 'M')
                return 5;
            Counter++;
        }

       int isR(char test)
        {
            if(test == 'R')
                return 6;
            Counter++;
        }
    
   


void generateSoundex(const char *name, char *soundex) {
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

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H

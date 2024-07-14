#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char test) {
    test = toupper(test);
    int Counter=0;
    /*switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y */

    void isBFPV(char test)
    {
        if(test== 'B' || 'F' || 'P' || 'V')
            return 1;
        Counter++;
    }
    if(Counter == 0)
    {
     void isCGJ (char test)
        {
            if(test== 'C')
                return 2;
            Counter++;
        }
    }
    if(Counter == 0)
    {
        void isDT (char test)
    { if(test=='D')
        return 3;
        Counter++;
    }
    }
    if(Counter == 0)
    {
        isL (char test)
        {
          if(test=='L')  
              return 4;
            counter++;
        }
    }
    if(Counter==0)
    {
        isMN(char test)
        {
            if(test == 'M')
                return 5;
            Counter++;
        }
    }
    if(Counter ==0)
    {
        isR(char test)
        {
            if(test == 'R')
                return 6;
            Counter++;
        }
    }
    else return 0;
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

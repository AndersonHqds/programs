#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int binario [9];
int i=0; 


//Transform one number in binarie
void getBinary(int number){
        int o = 0;
        for(i = 7; i >= 0; i--){
                if( number >> i & 1)
                        binario[o] = 1;
                else
                        binario[o] = 0;
        o++;
        }
}

//Convert the decimal number in character
char convert(int n)
{
    switch(n){
    	case 0: return 'A';break;case 1: return 'B';break;case 2: return 'C';break;case 3: return 'D';break;case 4: return 'E';break;case 5: return 'F';break;case 6: return 'G';break;case 7: return 'H';break;
    	case 8: return 'I';break;case 9: return 'J';break;case 10: return 'K';break;case 11: return 'L';break;case 12: return 'M';break;case 13: return 'N';break;case 14: return 'O';break;case 15: return 'P';break;
    	case 16: return 'Q';break;case 17: return 'R';break;case 18: return 'S';break;case 19: return 'T';break;case 20: return 'U';break;case 21: return 'V';break;case 22: return 'W';break;case 23: return 'X';break;
    	case 24: return 'Y';break;case 25: return 'Z';break;case 26: return 'a';break;case 27: return 'b';break;case 28: return 'c';break;case 29: return 'd';break;case 30: return 'e';break;case 31: return 'f';break;
    	case 32: return 'g';break;case 33: return 'h';break;case 34: return 'i';break;case 35: return 'j';break;case 36: return 'k';break;case 37: return 'l';break;case 38: return 'm';break;case 39: return 'n';break;
    	case 40: return 'o';break;case 41: return 'p';break;case 42: return 'q';break;case 43: return 'r';break;case 44: return 's';break;case 45: return 't';break;case 46: return 'u';break;case 47: return 'v';break;
    	case 48: return 'w';break;case 49: return 'x';break;case 50: return 'y';break;case 51: return 'z';break;case 52: return '0';break;case 53: return '1';break;case 54: return '2';break;case 55: return '3';break;
    	case 56: return '4';break;case 57: return '5';break;case 58: return '6';break;case 59: return '7';break;case 60: return '8';break;case 61: return '9';break;case 62: return '+';break;case 63: return '/';break;
	}
}


int main(int argc, char * argv[]){

		//Check if it have one word to encode
        if(argc != 2){
                printf("Type ./base64coder \"Word to code\" ");
                exit(0);
        }
		
		//Store a space in the memory, size of text * 8 (8bits), Because each letter has 8 bits in binary
        int word [strlen(argv[1]) * 8 + 1];
        int i = 0, o = 0,aux = 0;

        for(i=0; i<strlen(argv[1]); i++){
        		//convert the number in binarie
                getBinary(argv[1][i]);
                //get all binaries in one vector, the variable aux will be
                //used for store the last result
                for(o = 0; o < 8; o++){
                        word[aux] = binario[o];
                        aux++;
                }
                
        }

        //get the size of word typed
        int size = strlen(argv[1]) * 8;
        aux = 0;
        
        //This "for" is very important, it will be used for calculate how many
        //is missing to complete 24bits and complete with "0s", Note: It is how the base64 work
        for(i=0; i<strlen(argv[1]) * 8; i++){
                if(size > 0){
                    aux++;
                }
                else{
                    break;
                }
                size -= 24;
        }
        
        //get the new word with the 0s added
        int wordnew [strlen(argv[1]) * 8 + (size*-1) + 1];
        for(i=0; i<strlen(argv[1]) * 8 + (size*-1); i++){
                if(i+1 <= sizeof(word)/sizeof(int) - 1)
                        wordnew[i] = word[i];
                else
                        wordnew[i] = 0;
        }
        //separates the word from 6 in 6 bits
        //final[size of the word with the 0s][7 <= It's beucase the 6 bits]
        int final[(sizeof(wordnew) / sizeof(int)) / 6][7];
        o = 0;
        aux = 1; 
        // The calcbin initialize with 32 because of 6 bits and It will help us
        // on the conversion
        int baseint, calcbin = 32,value = 0,j = 0;
        printf("[!] Word Encoded => ");
        for(i = 0; i < sizeof(wordnew) / sizeof(int) - 1; i++){
                final[o][j] = wordnew[i];
                //Convert the number in int
                baseint = (int)final[o][j];
                //Transform from binarie to Decimal
                //if is one add to value else we just devide by 2
                //For example:  32 - 16 - 8 - 4 - 2 - 1 - 0
                if(baseint == 1){
                	value = value + calcbin;
                	calcbin = calcbin / 2;
				}
				else{
					calcbin = calcbin / 2;
				}				   
                if(aux == 6){ 				                 
                       o++;
                       aux = 0;
                       j = 0;
                       //If the last character is "0", We add the character "="
                       if(i != sizeof(wordnew) / sizeof(int) - 2 && i != 0)
                      	 printf("%c",convert(value));
					   else
					   	 printf("=");                        
					   value = 0;
					   calcbin = 32;                         
                }
               
                aux++;
                j++;
        }
        
return 0;
}

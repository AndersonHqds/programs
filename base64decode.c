#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int binario [9];
int i=0; 


//Transform one number in binarie
void getBinary(int number,int qtd){
        int o = 0;
       // printf("number %d", number);
        for(i = qtd; i >= 0; i--){
                if( number >> i & 1)
                        binario[o] = 1;
                else
                        binario[o] = 0;
        o++;
        }
}

int reverse_convert(char n){
    switch(n){
        case 'A': return 0;break;case 'B': return 1;break;case 'C': return 2;break;case 'D': return 3;break;case 'E': return 4;break;case 'F': return 5;break;case 'G': return 6;break;case 'H': return 7;break;
        case 'I': return 8;break;case 'J': return 9;break;case 'K': return 10;break;case 'L': return 11;break;case 'M': return 12;break;case 'N': return 13;break;case 'O': return 14;break;case 'P': return 15;break;
        case 'Q': return 16;break;case 'R': return 17;break;case 'S': return 18;break;case 'T': return 19;break;case 'U': return 20;break;case 'V': return 21;break;case 'W': return 22;break;case 'X': return 23;break;
        case 'Y': return 24;break;case 'Z': return 25;break;case 'a': return 26;break;case 'b': return 27;break;case 'c': return 28;break;case 'd': return 29;break;case 'e': return 30;break;case 'f': return 31;break;
        case 'g': return 32;break;case 'h': return 33;break;case 'i': return 34;break;case 'j': return 35;break;case 'k': return 36;break;case 'l': return 37;break;case 'm': return 38;break;case 'n': return 39;break;
        case 'o': return 40;break;case 'p': return 41;break;case 'q': return 42;break;case 'r': return 43;break;case 's': return 44;break;case 't': return 45;break;case 'u': return 46;break;case 'v': return 47;break;
        case 'w': return 48;break;case 'x': return 49;break;case 'y': return 50;break;case 'z': return 51;break;case '0': return 52;break;case '1': return 53;break;case '2': return 54;break;case '3': return 55;break;
        case '4': return 56;break;case '5': return 57;break;case '6': return 58;break;case '7': return 59;break;case '8': return 60;break;case '9': return 61;break;case '+': return 62;break;case '/': return 63;break;
    }
}

void decode(char * argv[]){
    int i = 0, o = 0,aux = 0, size[strlen(argv[2]) * 8 + 8];
    memset(size, 0 ,sizeof(size));
    printf("[!] Word Decoded => ");
    for(i = 0; i< strlen(argv[2]); i++){
        getBinary(reverse_convert(argv[2][i]),5);
		for(o = 0; o < 6; o++){
        	size[aux] = binario[o];
   			aux++;
		   }		
	}
	
	i = 128;
	int value = 0,check = 1;
	for(o = 0; o < aux; o++){
		if(size[o] == 1){
			value += i;
			i = i/2;
		}
		else{
			i = i/2;
		}
		if(check == 8){
			if(o == aux - 1){
				break;
			}
			printf("%c",value);
			i = 128;
			value = 0;
			check = 0;
		}
		check++;
	}
	
}


int main(int argc, char * argv[]){

		//Check if it have one word to decode
        if(argc != 2){
                printf("Type ./base64decode \"Word to encode\" ");
                exit(0);
        }    
          	decode(argv);

return 0;
}

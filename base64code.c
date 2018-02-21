#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int binario [9];
int i=0; 


//Transform one number in binarie
//Transforma um numero em binario
void getBinary(int number,int qtd){
        int o = 0;
        for(i = qtd; i >= 0; i--){
                if( number >> i & 1)
                        binario[o] = 1;
                else
                        binario[o] = 0;
        o++;
        }
}

//Convert the decimal number in character
//Converte o numero decimal em caracter
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

//Return the decimal number by each letter of base64 table
//Retorna o decimal de cada letra da tabela da Base64
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

void encode(char * argv[]){
            //Store a space in the memory, size of text * 8 (8bits), Because each letter has 8 bits in binary
            //Reserva um espaço na memoria, tamanho do texto * 8 bits, porque cada letra pode ter 8 bits em binario
            int word [strlen(argv[2]) * 8 + 1];
            int i = 0, o = 0,aux = 0;

            for(i=0; i<strlen(argv[2]); i++){
                    //convert the number in binarie
                    //Converte o numero em binario
                    getBinary(argv[2][i],7);
                    //get all binaries in one vector, the variable aux will be
                    //used for store the last result
                    //Pega todos binarios em um vetor, a variavel aux ira ser 
                    //usada para armazenar o ultimo resultado
                    for(o = 0; o < 8; o++){
                            word[aux] = binario[o];
                            aux++;
                    }
                    
            }

            //get the size of word typed
            //pega o tamanho da palavra digitada
            int size = strlen(argv[2]) * 8;
            aux = 0;
            
            //This "for" is very important, it will be used for calculate how many
            //is missing to complete 24bits and complete with "0s", Note: It is how the base64 work
            //Esse for é muito importante, ira ser usado para calcular quanto está
            //faltando para completar 24bits e completa com 0. Obs: É assim que a base64 funciona
            for(i=0; i<strlen(argv[2]) * 8; i++){
                    if(size > 0){
                        aux++;
                    }
                    else{
                        break;
                    }
                    size -= 24;
            }
            
            //get the new word with the 0s added
            //pega a palavra nova com os 0 adicionados
            int wordnew [strlen(argv[2]) * 8 + (size*-1) + 1];
            for(i=0; i<strlen(argv[2]) * 8 + (size*-1); i++){
                    if(i+1 <= sizeof(word)/sizeof(int) - 1)
                            wordnew[i] = word[i];
                    else
                            wordnew[i] = 0;
            }
            //separates the word from 6 in 6 bits
            //final[size of the word with the 0s][7 <= It's beucase the 6 bits]
            //Separa o binario de 6 em 6 bits
            //final[tamanho da palavra com os 0s][7 por causa dos 6 bits e 1 por garantia na memória]
            int final[(sizeof(wordnew) / sizeof(int)) / 6][7];
            o = 0;
            aux = 1; 
            // The calcbin initialize with 32 because of 6 bits and It will help us
            // on the conversion
            // A calcbin inicializa com 32 por causa dos 6 bits e isso ira ajudar a gente na conversão
            int baseint, calcbin = 32,value = 0,j = 0;
            printf("[!] Word Encoded => ");
            for(i = 0; i < sizeof(wordnew) / sizeof(int) - 1; i++){
                    final[o][j] = wordnew[i];
                    //Convert the number in int
                    //Converte o numero em int
                    baseint = (int)final[o][j];
                    //Transform from binarie to Decimal
                    //if is one add to value else we just devide by 2
                    //For example:  32 - 16 - 8 - 4 - 2 - 1 - 0
                    //Transforma de binario para decimal
                    //se o valor adicional for 1 caso o contrario divide por 2
                    //Por exemplo:  32 - 16 - 8 - 4 - 2 - 1 - 0
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
                           //Se o ultimo caracter for 0, adicionamos o "="
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
        }

void decode(char * argv[]){
    //size[size of the word * 8 <== bits qtd for each letter]
    //size[tamanho da palavra * 8 <== quantidade de bits de cada letra]
    int i = 0, o = 0,aux = 0, size[strlen(argv[2]) * 8 + 8];
     //Limpa o lixo da memória
    //Clean the trash of memory
    memset(size, 0 ,sizeof(size));
    printf("[!] Word Decoded => ");
    for(i = 0; i< strlen(argv[2]); i++){
        //If is diffent of the character "=" continue the decode
        //Se for diferente do caracter "=" continua o decode
        if(argv[2][i] != '='){
            //Get the decimal of base64 table for each letter and transform in binary
            //Pega o decimal da tabela de base64 para cada letra e transforma em binario
                  
            getBinary(reverse_convert(argv[2][i]),5);
             //save all the binaries in just one vector
            //salva todos os binarios em um só vetor
        
            for(o = 0; o < 6; o++){
                size[aux] = binario[o];
                aux++;
               }
        }       
    }
    
    i = 128; //128 por causa de 8 bits, //128 because of 8 bits
    int value = 0,check = 1;
    for(o = 0; o < aux; o++){
        //Calculate the decimal by each group of 8 bits
        //Calcula o decimal de cada grupo de oito bits
        if(size[o] == 1){
            value += i;
            i = i/2;
        }
        else{
            i = i/2;
        }
        //If is 8(8bits) 
        if(check == 8){
            //Mostra o valor do numero decimal na tabela ASCII
            printf("%c",value);//Print the value of the decimal number on the ASCII Table
            //Volta para 128 para calcular os proximos 8 bits
            i = 128;//Change to 128 again for calculate the next 8 bits
            value = 0;
            check = 0;
        }
        check++;
    }
    
}


int main(int argc, char * argv[]){

		//Check if it have three parameters
        //Checa se tem 3 parametros
        if(argc != 3){
                printf("Type ./base64coder -d for decode and -e for encode \"Word to code\" ");
                printf("\nFor Example: ./base64 -e encodethisword");
                exit(0);
        }
        //Se for digitado -e encoda
        if(strcmp(argv[1], "-e") == 0){
		  encode(argv);
		}

        //Se for digitado -d faz o decode
		if(strcmp(argv[1],"-d") == 0){
          	decode(argv);
        }
return 0;
}

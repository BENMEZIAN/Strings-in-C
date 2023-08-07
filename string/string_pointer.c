#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void displayString(char* str);
char* copyed_string(char* str);
char* reverseString(char* str);
bool palindrome(char* str);
bool anagrams(char* str1,char* str2);



int main() {
	
	char* str = "silent";
	char* str1 = "listen";
	
	
	int len = strlen(str1); // count the length of the string
	
	printf("%d\n",len);

	printf("-------------------------------------\n");
	
	bool anag = anagrams(str,str1);
	
	if(anag==true){
		printf("Anagrams");
	}else{
		printf("Not anagrams");
	}
	
	
	return 0;
}

void displayString(char* str){
	
	int len = strlen(str); // count the length of the string

	printf("Iterate Over C String with while loop: ");
	int i = 0;
	while (str[i] != '\0'){
		printf("%c", str[i]);
		i++;
	}
	
	printf("\n");
	
	printf("Iterate Over C String with for loop: ");
	for (i = 0; i < len; i++){
		printf("%c", str[i]);
	}
	
	printf("\n");

}

char* copyed_string(char* str){
	
	char* p = (char*)malloc(strlen(str)+1);
	
	strcpy(p,str);
	
	return p;
	
}

char* reverseString(char* str){
	
    int len = strlen(str);
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    int i, j;
    
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = str[i];
    }
    
    reversed[j] = '\0';
    
    printf("\n");
    
    return reversed;

}

bool palindrome(char* str){
  
	int i = 0;
	int j = strlen(str)-1;
	  
	while(i<j){
		if(str[i]!=str[j]){
			return false;
	    }
	    i++;
	    j--;
	}
	
	return true;
}

bool anagrams(char* str1,char* str2){
	
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 != len2) {
        return false;
    }

    bool found;
    for (int i = 0; i < len1; i++) {
        found = false;
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            return false;
        }
        
    }
    
    return true;
}





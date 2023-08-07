#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> /* Used for isupper(), islower(), isblank(), isspace(), isprint() */


typedef struct CharFrequency {
    char character;
    int frequency;
}CharFrequency;


void display_with_space(char* str);
void display_with_space_reverse(char* str);
int number_words_in_string(char* str);
bool compare_two_strings(char* str1,char* str2);
void number_alphabets_digits_special_characters(char* str);
char* copy_string_to_anther(char* str1);
void vowels_consonants(char* str);
void highest_appearing(char* str,char* c);
void is_exist(CharFrequency charFrequency[], char ch, int* size);
CharFrequency highestAppearingCharacter(char* str);
void sort_ascending_string(char* str);
void sort_array_of_strings(char* words[],int len); // int len = sizeof(words)/sizeof(char*);
char* extract_substring(char* str,char* substr);
int common_substring_length(char* str,char* substr);
char* lowertoUpper_uppertoLower(char* str);
int countOccurrences(char* str, char* toSearch);
char* removeCharactersExceptAlphabet(char* str);
int countOccurencesChar(char* str,char ch);
char* concatenate(char* str1,char* str2);
void largest_smallest(char* str, char** largestWord, char** smallestWord); // return two strings
char* convert_to_uppercase(char* str);
char* convert_to_lowercase(char* str);
void digit_character(char* str,char ch);
void is_uppercase(char ch);
char* replace_space_with_astrix(char* str);
int numberOfPunctuations(char* str);
void print_before_newLine(char* str);
void is_lowercase(char ch);
char* delete_spaces_between_words(char* str);
void is_digit(char ch);
void split_string(char* str);
void printCharacterAndCount(char* str);
void first_repetitive_character(char* str);
char* convertVowelsToUppercase(char* str);
int longestSubstringWithoutRepeatingCharacters(char* str);
void isValid(char* str);
char* multiplyString(char* str,char* str1);
bool isVowel(char ch);
char* reverseVowels(char* str);
int isPalindrome(char* str, int start, int end);
char* longestPalindrome(char* str);
char* replaceLowercaseWithTheSameUppercase(char* str);
int length_substring_length(char* str,char* str1);
void printAscii(char* str);
char* reverse_string_without_strrev(char* str);
char* reverse_string_with_strrev(char* str);
void numberOfWords(char* str);
void numberOfSpaces(char* str);


int main(){
	
	
	
	
	
    return 0;
}


void display_with_space(char* str){
  
  for(int i=0;i<strlen(str);i++){
    printf("%c ",str[i]);
  }
  printf("\n");
}

void display_with_space_reverse(char* str){
  
  int l = strlen(str)-1;
  for(int i = l; i>=0; i--){
    printf("%c ",str[i]);
  }
  printf("\n");
}

int number_words_in_string(char* str){
  
  int l = strlen(str);
  int words=0;
  for(int i=0;i<=l;i++){
    if(str[i]==' ' || str[i]=='\0'){
      words++;
    }
  }
  
  return words;
}

bool compare_two_strings(char* str1,char* str2){
  
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  
  if(len1!=len2){
    return false;
  }else{
    int i = 0;
    int j = 0;
    while(i <= len1 && j <= len2){
      if(str1[i]!=str2[j]){
        return false;
      }
      i++;
      j++;
    }
  }
} 

void number_alphabets_digits_special_characters(char* str){
  
  int len = strlen(str);
  char character;
  int digits = 0,alphabets=0,specials=0;
  for(int i=0;i<=len;i++){
    if(str[i] >= '0' && str[i] <= '9'){
      digits++;
    }else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
      alphabets++;
    }else{
      specials++;
    }
  }
  
  printf("Digits = %d\n",digits);
  printf("Alpahbets = %d\n",alphabets);
  printf("specials = %d\n",specials);
  
}

char* copy_string_to_anther(char* str1){
  
  char* str2;
  int len1 = strlen(str1);
  str2 = (char*)malloc(len1*sizeof(char)+1);
  int i = 0;
  while(str1[i]!='\0'){
    str2[i] = str1[i];
    i++;
  }
  
  // to finish the str2
  str2[i] = '\0';
  
  return str2;
}

void vowels_consonants(char* str){
  
  int len = strlen(str);
  int vowels=0,consonants=0;
  for(int i=0;i<len;i++){
    if(str[i] =='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
      vowels++;
    }else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
      consonants++;
    }
  }
  
  printf("Vowles = %d\n",vowels);
  printf("Consonants = %d\n",consonants);
  
}

void is_exist(CharFrequency charFrequency[], char ch, int* size){
    
	for (int i = 0; i < *size; i++) {
        if (charFrequency[i].character == ch) {
            charFrequency[i].frequency++;
            return;
        }
    }

    // If character is not found in the array, add it to the array
    charFrequency[*size].character = ch;
    charFrequency[*size].frequency = 1;
    (*size)++;
}

CharFrequency highestAppearingCharacter(char* str){
	
    int length = strlen(str);
    CharFrequency* charFrequency = (CharFrequency*)malloc(length * sizeof(CharFrequency));
    int size = 0; // Number of distinct characters found

    // Calculate character frequency
    for (int i = 0; i < length; i++) {
        char ch = str[i];
        is_exist(charFrequency, ch, &size);
    }
    
    // Find the character with the highest frequency
    CharFrequency highestChar = {'\0', 0};
    for (int i = 0; i < size; i++) {
        if (charFrequency[i].frequency > highestChar.frequency) {
            highestChar = charFrequency[i];
        }
    }
    
    free(charFrequency); // Free dynamically allocated memory

    return highestChar;
}

void sort_ascending_string(char* str) {
	
    int len = strlen(str);

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) { // Compare characters directly using '>'
                char tmp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
        }
    }
    
}

void sort_array_of_strings(char* words[],int len){
  
	char* temp;
	  
	for(int i = 0;i<len-1;i++){
		for(int j = i+1;j<len;j++){
	      if(strcmp(words[i],words[j]) > 0){
	        temp = words[i];
            words[i] = words[j];
            words[j] = temp;
	      }
	    }
	}
	
	for(int i = 0;i<len;i++){
		printf("%s ",words[i]);
	}
	
}

char* extract_substring(char* str,char* substr){
	
    int len = strlen(str);
    int sublen = strlen(substr);
    int start_pos = -1;
    int end_pos = -1;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < sublen; j++) {
            if (str[i] == substr[j]) {
                int k = i;
                int l = j;
                int matched_chars = 0;
                while (k < len && l < sublen && str[k] == substr[l]) {
                    k++;
                    l++;
                    matched_chars++;
                }
                if (matched_chars == sublen) {
                    start_pos = i;
                    end_pos = k;
                    break;
                }
            }
        }
        if (start_pos != -1) {
            break;
        }
    }

    if (start_pos == -1) {
        return NULL; // Substring not found
    }

    char* extracted = (char*)malloc((end_pos - start_pos + 1) * sizeof(char));
    if (extracted == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Copy the substring to the new string
    int index = 0;
    for (int i = start_pos; i < end_pos; i++) {
        extracted[index++] = str[i];
    }
    extracted[index] = '\0';

    return extracted;
}

int common_substring_length(char* str,char* substr){
	
    int len = strlen(str);
    int sublen = strlen(substr);
    int max_length = 0;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < sublen; j++) {
            if (str[i] == substr[j]) {
                int k = i;
                int l = j;
                int current_length = 0;
                while (k < len && l < sublen && str[k] == substr[l]) {
                    k++;
                    l++;
                    current_length++;
                }
                if (current_length > max_length) {
                    max_length = current_length;
                }
            }
        }
    }

    return max_length;
}

char* lowertoUpper_uppertoLower(char* str){
	
	int len = strlen(str);
	char* string = (char*)malloc(len*sizeof(char)+1);
	
	for(int i = 0;i<len;i++){
		if(isupper(str[i])){
			string[i] = tolower(str[i]);
		}else if(islower(str[i])){
			string[i] = toupper(str[i]);
		}else if(isblank(str[i])){
			string[i] = str[i];
		}else if(ispunct(str[i])){
			string[i] = str[i];
		}
	}
	
	string[len] = '\0';
	
	return string;
		
}

int countOccurrences(char* str, char* toSearch){
	
	int len = strlen(str);
    int sublen = strlen(toSearch);
    int count = 0;
   
    for (int i = 0; i < len-sublen; i++) {
    	/* Match word with string */
        int found = 1;
        for (int j = 0; j < sublen; j++) {
        	if(str[i+j] != toSearch[j]){
        		found = 0;
        		break;
			}
        }
        
        if(found == 1){
            count++;
        }
    }
    
    return count;
}

char* removeCharactersExceptAlphabet(char* str){
	
	int len = strlen(str);
	char* string = (char*)malloc(len*sizeof(char)+1);
	
	for (int i = 0; i < len;i++) {
		if (isalpha(str[i]) || isblank(str[i])) {
            string[i] = str[i];
        }else{
            string[i] = ' '; // Replace unwanted characters with space
        }
        
        // remove all spaces here
	}
	
	string[len] = '\0';
	
	// Remove all spaces from the string
    int newLen = 0;
    for (int i = 0; i < len; i++) {
        if (!isblank(string[i])) {
            string[newLen++] = string[i];
        }
    }
    string[newLen] = '\0'; // Null-terminate the updated string
	
	return string;
}

int countOccurencesChar(char* str,char ch){
  
  int len = strlen(str);
  int cpt = 0;
  
  for(int i = 0;i<len;i++){
    if(str[i] == ch){
      cpt++;
    }
  }
  
  return cpt;
}

char* concatenate(char* str1,char* str2){
  
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  
  char* concat = (char*)malloc((len1+len2)*sizeof(char)+1);
  
  for(int i = 0;i<len1;i++){
    concat[i] = str1[i];
  }
  
  concat[len1] = ' '; // Add a space character between str1 and str2
  
  for (int i = 0; i < len2; i++) {
  	concat[len1 + 1 + i] = str2[i]; // Start copying str2 after the space character
  }
  
  concat[len1 + len2 + 1] = '\0'; // Null-terminate the concatenated string
  
  return concat;
}

void largest_smallest(char* str, char** largestWord, char** smallestWord){
    
	int len = strlen(str);
    int i = 0;
    char* token;

    char* copystr = (char*)malloc((len) * sizeof(char)+ 1);

    for (int i = 0; i < len; i++) {
        copystr[i] = str[i];
    }

    copystr[len] = '\0';

    token = strtok(copystr, " ");

    // Initialize largest and smallest to the first word in the string
    *largestWord = strdup(token);
    *smallestWord = strdup(token);

    /* walk through other tokens */
    while (token != NULL) {
        // Compare the current token with the largest and smallest words found so far
        if (strlen(token) > strlen(*largestWord)) {
            free(*largestWord); // Free the previous allocation
            *largestWord = strdup(token);
        }

        if (strlen(token) < strlen(*largestWord)) {
            free(*smallestWord); // Free the previous allocation
            *smallestWord = strdup(token);
        }

        token = strtok(NULL, " ");
    }

    free(copystr);
}

char* convert_to_uppercase(char* str){
  
  int len = strlen(str);
  
  char* upp = (char*)malloc(len*sizeof(char)+1);
  
  for(int i = 0;i<len;i++){
    if(isupper(str[i])){
      upp[i] = str[i];
    }else if(islower(str[i])){
      upp[i] = toupper(str[i]);
    }else if(isblank(str[i])){
      upp[i] = str[i];
    }
  }
  
  upp[len] = '\0';
  
  return upp;
  
}

char* convert_to_lowercase(char* str){
	
	int len = strlen(str);
  
  char* upp = (char*)malloc(len*sizeof(char)+1);
  
  for(int i = 0;i<len;i++){
    if(islower(str[i])){
      upp[i] = str[i];
    }else if(isupper(str[i])){
      upp[i] = tolower(str[i]);
    }else if(isblank(str[i])){
      upp[i] = str[i];
    }
  }
  
  upp[len] = '\0';
  
  return upp;
	
}

void digit_character(char* str,char ch){
  
  int len = strlen(str);
  int found = 0;
  for(int i = 0;i<len;i++){
    if(str[i] == ch){
      if(isdigit(str[i])){
        found = 1;
      }
    }
  }
  
  if(found == 1){
    printf("the character %c is a digit",ch);
  }else{
    printf("the character %c is not a digit",ch);
  }
  
}

void is_uppercase(char ch){
  
  bool upper;
  
  if(isupper(ch)){
    upper = true;
  }else{
    upper = false;
  }
  
  if(upper == true){
    printf("%c is an UPPERCASE",ch);
  }else{
    printf("%c is not an UPPERCASE",ch);
  }
  
}

char* replace_space_with_astrix(char* str){
  
  int len = strlen(str);
  
  char* string = (char*)malloc(len*sizeof(char)+1);
  
  for(int i = 0;i<len;i++){
    if(isblank(str[i])){
      string[i] = '*';
    }else{
      string[i] = str[i];
    }
  }
  
  string[len] = '\0';
  
  return string;
}

int numberOfPunctuations(char* str){
  
  int len = strlen(str);
  int cpt = 0;
  
  for(int i = 0;i<len;i++){
    if(ispunct(str[i])){
      cpt++;
    }
  }
  
  return cpt;
}

void print_before_newLine(char* str){
  
  int len = strlen(str);
  
  for(int i = 0;i<len;i++){
    if(isprint(str[i])){
      printf("%c",str[i]);
    }else{
      break; // Stop printing when a non-printable character is encountered else the string would be printed excpet the newline character
    }
  }
  
}

void is_lowercase(char ch){
  
  bool lower;
  
  if(islower(ch)){
    lower = true;
  }else{
    lower = false;
  }
  
  if(lower == true){
    printf("%c is a LOWERCASE",ch);
  }else{
    printf("%c is not a LOWERCASE",ch);
  }
  
}

char* delete_spaces_between_words(char* str){
  
  int len = strlen(str);
  char* string = (char*)malloc(len*sizeof(char)+1);
  
  int j = 0;
  for (int i = 0; i < len; i++) {
    if(isprint(str[i]) && !isspace(str[i])){
      string[j++] = str[i];
    }
  }
  
  string[j] = '\0';
  
  return string;
}

void is_digit(char ch){
  
  if(isdigit(ch)){
    printf("%c is a digit",ch);
  }else{
    printf("%c is not a digit",ch);
  }
  
}

void split_string(char* str){
  
  int len = strlen(str);
  
  int i = 0;
  char* token;

  char* copystr = (char*)malloc((len) * sizeof(char)+ 1);

  for (int i = 0; i < len; i++) {
    copystr[i] = str[i];
  }

  copystr[len] = '\0';

  token = strtok(copystr, " ");

  /* walk through other tokens */
  while (token != NULL) {
    // Compare the current token with the largest and smallest words found so far
    printf("%s\n",token);
    token = strtok(NULL, " ");
  }

  free(copystr);
  
}

void printCharacterAndCount(char* str){
	
    int length = strlen(str);
    CharFrequency* charFrequency = (CharFrequency*)malloc(length * sizeof(CharFrequency));
    int size = 0; // Number of distinct characters found

    // Calculate character frequency
    for (int i = 0; i < length; i++) {
        char ch = str[i];
        if (ch != ' ') {
            is_exist(charFrequency, ch, &size);
        }
    }

    printf("Character frequency in the string:\n");

    // Print each character and its count
    for (int i = 0; i < size; i++) {
        printf("%c: %d\n", charFrequency[i].character, charFrequency[i].frequency);
    }

    free(charFrequency); // Free dynamically allocated memory
}

void first_repetitive_character(char* str){
	
    int length = strlen(str);
    CharFrequency* charFrequency = (CharFrequency*)malloc(length * sizeof(CharFrequency));
    int size = 0; // Number of distinct characters found

    // Calculate character frequency
    for (int i = 0; i < length; i++) {
        char ch = str[i];
        if (ch != ' ') {
            is_exist(charFrequency, ch, &size);
        }
    }

    printf("Character frequency in the string:\n");

    // Print each character and its count
    CharFrequency highestChar = {'\0', 0};
    for (int i = 0; i < size; i++) {
        if (charFrequency[i].frequency > highestChar.frequency) {
            highestChar = charFrequency[i];
        }
    }
    
    printf("The first repetitive character is: %c with %d occurences",highestChar.character,highestChar.frequency);

    free(charFrequency); // Free dynamically allocated memory
}

char* convertVowelsToUppercase(char* str){
  
  int len = strlen(str);
  
  char* string = (char*)malloc(len*sizeof(char)+1);
  
  for(int i = 0;i<len;i++){
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u' || str[i] == 'y'){
		string[i] = toupper(str[i]);
    }else {
    	string[i] = str[i];
    }
  }
  
  string[len] = '\0';
  
  return string;
}

int longestSubstringWithoutRepeatingCharacters(char* str){
  
  int len = strlen(str);
  int longest = 0;
  
    for (int i = 0; i < len; i++) {
        int currentLength = 0;
        for (int j = i; j < len; j++) {
            int k;
            for (k = i; k < j; k++) {
                if (str[k] == str[j]) {
                    break;
                }
            }
            if (k != j) {
                break; // Repeating character found, exit inner loop
            }

            currentLength++;
        }

        if (currentLength > longest) {
            longest = currentLength;
        }
    }
  
  return longest;
}

void isValid(char* str){
	
    int len = strlen(str);
    int count = 0;
    
    for(int i = 0; i < len; i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<') {
            count++;
        }
        if(str[i] == ')' || str[i] == ']' || str[i] == '}' || str[i] == '>') {
            count--;
        }
    }

    if(count == 0) {
        printf("The string is Valid");
    } else {
        printf("The string is not Valid");
    }
	  
}

char* multiplyString(char* str,char* str1){
  
   int a = atoi(str); // The atoi function in C converts a string of characters to an integer value.
   int b = atoi(str1);

    // Calculate the product
   int product = a * b;
   
   char* res = (char*)malloc(12 * sizeof(char)); // 12 digits can represent an integer up to 10 digits and a null terminator

    // Convert the product back into a string
    snprintf(res, 12, "%d", product);
   
  return res;
}

bool isVowel(char ch){
	
  if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' ||
  ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y'){
    return true;
  }else{
    return false;
  }
  
}

char* reverseVowels(char* str){
  
  int len = strlen(str);
  int i = 0;
  int j = len-1;
  
  char temp;
  char* string = (char*)malloc(len*sizeof(char)+1);
  
  for(int i = 0;i<len;i++){
    string[i] = str[i];
  }
  
  string[len] = '\0';
  
  while(i<j){
    if(isVowel(string[i]) && isVowel(string[j])){
      temp = string[i];
      string[i] = string[j];
      string[j] = temp;
      i++;
      j--;
    }else if(isVowel(string[i])) {
      j--; // Move to the next character from the right (not a vowel)
    }else{
      i++; // Move to the next character from the left (not a vowel)
    }
    
  }
  
  return string;
}

int isPalindrome(char* str, int start, int end){
	
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    
    return 1; // Palindrome
}

char* longestPalindrome(char* str){
    int len = strlen(str);
    if (len == 0) {
        return "";
    }

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (isPalindrome(str, i, j)) {
                int currentLength = j - i + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    start = i;
                }
            }
        }
    }

    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, str + start, maxLength);
    result[maxLength] = '\0';
    
    return result;
}

char* replaceLowercaseWithTheSameUppercase(char* str){
  
  int len = strlen(str);
  char * string = (char*)malloc(len*sizeof(char)+1);
  
  for(int i =0;i<len;i++){
    if(islower(str[i])){
      string[i] = toupper(str[i]);
    }else{
      string[i] = str[i];
    }
  }
  
  return string;
}

int length_substring_length(char* str,char* str1){
	
    int len = strlen(str);
    int sublen = strlen(str1);
    int max_length = 0;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < sublen; j++) {
            if (str[i] == str1[j]) {
                int k = i;
                int l = j;
                int current_length = 0;
                while (k < len && l < sublen && str[k] == str1[l]) {
                    k++;
                    l++;
                    current_length++;
                }
                if (current_length > max_length) {
                    max_length = current_length;
                }
            }
        }
    }

    return max_length;
}

void printAscii(char* str){
	
	int len = strlen(str);
	
	for(int i = 0;i<len;i++){
		printf("ASCII Value of %c = %d\n", str[i], str[i]);
	}
	
}

char* reverse_string_without_strrev(char* str){
	
	int len = strlen(str);
	char* rev = (char*)malloc(len*sizeof(char)+1);
	int i = len-1;
	int j = 0;
	while(i>=0){
		rev[j] = str[i];
		j++;
		i--;
	}
	
	rev[len] = '\0';
	
	return rev;
}

char* reverse_string_with_strrev(char* str){
	
	int len = strlen(str);
	char* rev = (char*)malloc(len*sizeof(char)+1);
	
	for(int i = 0;i<len;i++){
    	rev[i] = str[len-i-1];
	}
	
	rev[len] = '\0';
	
	return rev;
}

void numberOfWords(char* str){
	
	int len = strlen(str);
	
	int i = 0;
	int nbr = 0;
    char* token;

    char* copystr = (char*)malloc((len) * sizeof(char)+ 1);

    for (int i = 0; i < len; i++) {
        copystr[i] = str[i];
    }

    copystr[len] = '\0';

    token = strtok(copystr, " ");

    /* walk through other tokens */
    while (token != NULL) {
    	nbr++;
        token = strtok(NULL, " ");
    }
    
    printf("Number of words in \"%s\" is: %d",str,nbr);
    
    free(copystr);
    
}

void numberOfSpaces(char* str){
	
	int len = strlen(str);
	int nbr = 0;
	
	for(int i = 0;i<len;i++){
		if(isspace(str[i])){
			nbr++;
		}
	}
	
	printf("Number of spaces in \"%s\" is: %d",str,nbr);
    
}


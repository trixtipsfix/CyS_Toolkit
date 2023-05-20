/*
	Title: Cyber Security Toolkit 

	Author: Mirza Areeb Baig

	Description: Cryprography Tool (Encryption & Decryption +Secret key), 
				Password Analyzer(How strong is your password?) and 
				Password Generator (Strong Random Password).
*/

#include <iostream>
//#include <string>
#include<ctime>
#include <cstdlib>
using namespace std;

/* For generating random strong passwords for user */

int password_generator(){
	cout<<"\t===================================="<<endl;
	cout<<"\t====>>>  Password Generator  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	char alpha_num[] = "67ghiST5j8^&:*a07WX@1ef9V2tv34d5wxQR14DOIpkJ8LZl2mMNBC9!noqYEruA#6$sy3zPbcU%FGHK"; //character array containing every digit, alphabet and special character
	int req_length, string_length = (sizeof(alpha_num) - 1);
	cout << "Enter the Length (>=10) of Password: ";
	cin >> req_length;	// taking the length of password from the user.
	// input validation
	while(req_length < 10){
		cout<<"Less than 10 is not allowed!!! \nEnter the Length (>=10) of Password:";
		cin >> req_length;
	}
	srand(time(0)); // for generating different random numbers every time program executes.
	cout << "\n=> Generated Password of Length "<<req_length<< " is :  ";
	for (int i = 0; i < req_length; i++)
		cout << alpha_num[rand() % string_length];		// selecting random characer from the string and printing it.
	// checking if the user wants to use this tool again?
	string con;
	cout<<"\n\nDo you want to continue this tool? (y/n): ";
	cin.ignore();
	getline(cin, con);
	if (con == "Y" || con=="y"){
		system("CLS"); // clearing the screen
		password_generator(); // again calls this function 
	}
	else{
		return 0; // exits the tool
	}
}

int password_analyzer(){
	
	cout<<"\t===================================="<<endl;
	cout<<"\t====>>>   Password Analyzer  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	int l_case=0, u_case=0, digit=0, special=0,strength=100; // at start strength has 100 points
	string password;
	cin.ignore();
	cout<<"\nEnter your password: ";
	getline(cin, password); // getting the complete password/phrase
	int len = password.length();
	cout<<"\n\t===================================="<<endl;
	cout<<"\t====>>>      Suggestions     <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	
	if (len <=8 ){
		cout<<"=> Password length is too SHORT"<<endl;
		strength -= 50;		// deducting 50 points on the length weakness
	}
	if (len > 8 && len <=10){
		cout<<"=> Password length could be increased more"<<endl;
		strength -= 25;		// deducting 25 points on little length weaking 
	}
	if (len > 20){
		strength += 50;		// adding 50 points for more longer length
	}
	// counting the types of character in password.
	for (int i =0 ; i < len ; i++){
		if(islower(password[i])) // lower case
      		l_case++;
    	if(isupper(password[i])) // upper case
     		u_case++;
    	if(isdigit(password[i])) // digits
      		digit++;
    	if(!isalpha(password[i]) && !isdigit(password[i]) && password[i] != ' ') // special
      		special++;  
	}
	if (l_case<=2){
		cout<<"=> Add more LOWERcase characters to increase strength!"<<endl;
		strength -= 15;	// deducting 15 points on lowercase weakness
	}
	if (u_case<=2){
		cout<<"=> Add more UPPERcase characters to increase strength!"<<endl;
		strength -= 15; // deducting 15 points on uppercase weakness
	}
	if (digit<=2){
		cout<<"=> Add more DIGITS to increase strength!"<<endl;
		strength -= 15; // deducting 15 points on digit weakness
	}
	if (special<=2){
		cout<<"=> Add more SPECIAL characters to increase strength!"<<endl;
		strength -= 15; // deducting 15 points on special character weakness
	}
	cout<<"\n\t===================================="<<endl;
	cout<<"\t====>>>   Password Analyzed  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	cout<<"=> Total Length: "<<len<<endl
		<<"=> Lowercase: "<<l_case<<endl
		<<"=> Uppercase: "<<u_case<<endl
		<<"=> Digits: "<<digit<<endl
		<<"=> Special: "<<special<<endl;
		
	cout<<"\n\t===================================="<<endl;
	cout<<"\t====>>>   Password Strength  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	cout<<strength<<"% |"; // printing the strength of the password
	for (int i = 0 ; i < int(strength/2) ; i++){
		cout<<"+";
	}
	for (int i = 0 ; i <(100-(strength) )/2; i++){
		cout<<".";
	}
	cout<<"|"<<endl<<endl;
	// checking if the user wants to use this tool again?
	string con;
	cout<<"Do you want to continue this tool? (y/n): ";
	getline(cin, con);
	if (con == "Y" || con=="y"){
		system("CLS");
		password_analyzer();
	}
	else{
		return 0;
	}
}
void encryption(){
	string plain_text;
	plain_text.clear();
	cout<<"Enter the Plain Text: "<<endl;
	cin.ignore();
	getline(cin, plain_text);
	// counting the number of words
	int len = 1;
	for (int i = 0; i<(int) plain_text.length() ; i++){
		plain_text[i] = tolower(plain_text[i]);
		if (plain_text[i]==' '){
			len++;
		}
	}
	// storing each word in an array
	string word;
	word.clear();
	string arr[len];
	int j = 0;
	for (int i=0 ; i<(int) plain_text.length();i++){
		
		if (plain_text[i] != ' '){
			word.push_back(plain_text[i]);
		}
		
		if (plain_text[i] == ' '){
			arr[j] = word;

			j++;
			word.clear();
		}
		if (i == (int) plain_text.length()-1){
			arr[j] = word;
		}

	}
	// reversing the array
	string reversed_arr[len];
	int var1 = 0;
	for (int index = len-1; index>=0 ; index-- ){
		
		reversed_arr[var1] = arr[index];

		var1++;
	}
	// getting the alphabetic secret key and converting it into its numeric value
	string secret_key;
	secret_key.clear();
	cout<<"Enter the Alphabetic Secret key: ";
	cin>>secret_key;
	int numeric_key[secret_key.length()-1];
	for (int i= 0 ; i < (int) secret_key.length() ; i++) {
		//input validation
		while(isdigit(secret_key[i])){
			cout<<"The Secret key should'nt contain any number <=\n";
			cout<<"Enter the Alphabetic Secret key: ";
			cin>>secret_key;
			int numeric_key[secret_key.length()-1];
			i=0;
		}
		numeric_key[i] = int(secret_key[i]) - 96;
	}
	cout<<endl;
	// shifting each word in the array according to its respective number
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string var2;
	int num = 0;
	string mirza_cypher_text;
	for (int l = 0 ; l < len ; l++){
		
		var2 = reversed_arr[l];
		int no = l;
		if (no>(int)(secret_key.length()-1)){
			no = no-secret_key.length();
		}
		for (int j = 0 ; j<= (int) var2.length() ; j++){
			if (isalpha(var2[j])){
				
				num = int(var2[j]) - 96;
				
				num += int(numeric_key[no]);
				if (num>26){
					num = num - 26;
				}
				var2[j] = alphabet[num-1];
		}
			var2[j] = var2[j];
			num = 0;
		}
		// appending the words in a string
		mirza_cypher_text.append(var2);
		mirza_cypher_text.append(" ");
	}
	// printing the encrypted text.
	cout<<"Encrypted Text: "<<mirza_cypher_text;
}
					
void decryption(){
	string cypher_text;
	// getting the encrypted text
	cout<<"Enter the Encrypted Text: "<<endl;
	cin.ignore();
	getline(cin, cypher_text);
	// counting the words in it.
	int len = 1;
	for (int i = 0; i<(int)cypher_text.length() ; i++){
		if (cypher_text[i]==' '){
			len++;
		}
	}
	// storing each word in an array 
	string word;
	string arr[len];
	int j = 0;
	for (int i=0 ; i<(int)cypher_text.length();i++){
		
		if (cypher_text[i] != ' '){
			word.push_back(cypher_text[i]);
		}
		
		if (cypher_text[i] == ' '){
			arr[j] = word;
			j++;
			word.clear();
		}
		if (i == (int) cypher_text.length()-1){
			arr[j] = word;
		}
		
		
	}
	// getting the secret key and converting it into its numeric value
	string secret_key;

	cout<<"Enter the Secret key: ";
	cin>>secret_key;
	int numeric_key[secret_key.length()-1];
	for (int i= 0 ; i < (int) secret_key.length() ; i++) {
		numeric_key[i] = int(secret_key[i]) - 96;
	}
	cout<<endl;
	// reversing each word in reverse manners according to its respective number
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string var2;
	int num;
	string plain_text;
	plain_text.clear();
	string arr2[len];
	for (int l = 0 ; l < len ; l++){
		
		var2 = arr[l];
		int no = l;
		if (no>(int) (secret_key.length()-1)){
			no = (no-secret_key.length());
		}
		for (int j = 0 ; j<=(int) var2.length() ; j++){
			if (isalpha(var2[j])){

				num = int(var2[j]) - 96;

				num -= int(numeric_key[no]);
				if (num<=0){
					num += 26;
				}

				var2[j] = alphabet[num-1];
		}
			var2[j] = var2[j];
			num = 0;
		}
		
		arr2[l] = var2;
	}
	// reversing the array
	string reversed_arr[len];
	int var1 = 0;
	for (int index = len-1; index>=0 ; index-- ){

		reversed_arr[var1] = arr2[index];

		var1++;
	}
	// combining each word and forming a string
	for (int index = 0; index<len ; index++ ){
		plain_text.append(reversed_arr[index]);
		plain_text.append(" ");
	}
	// print the result
	cout<<"Plain Text: "<<plain_text;
}

int cryptography_tool(){
	
	cout<<"\t===================================="<<endl;
	cout<<"\t====>>>  Cryptography Tool  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	long what;
	cout<<"What do you want to perform? "<<endl
	<<"1) Encryption "<<endl
	<<"2) Decryption "<<endl
	<<"=>";
	cin>>what;
	//input validation
	while (what<1 && what>2){
		cout<<"Invalid Option"<<endl;
		cin>>what;
	}
	switch (what){
		case 1:
			encryption();
			break;
		case 2:
			decryption();
			break;
		default:
			cout<<"Invalid Option";
	}
	// checking if the user wants to use this tool again?
	string con;
	cout<<"\nDo you want to continue this tool? (y/n): ";
	cin.ignore();
	getline(cin, con);
	if (con == "Y" || con=="y"){
		system("CLS");
		cryptography_tool();
	}
	else{
		return 0;
	}
}
int main(){
	cout<<"\t========================================"<<endl
	    <<"\t====>>>  Cyber Security Toolkit  <<<===="<<
	endl<<"\t========================================\n"<<endl;
	int what;
	// printing the menu
	cout<<"1) Cryptography Tool"<<endl
	<<"2) Password Analyzer"<<endl
	<<"3) Password Generator"<<endl
	<<"4) Exit"<<endl
	<<"=> ";
	cin>>what;
	// input validation
	while(what<1 || what >4){
		cout<<"Error!!! Invalid Option Selected"<<endl;
		cout<<"Please choose a correct option (1-4): ";
		cin>>what;
	}
	// calling functions according to the choice
	switch(what){
		case 1:
			system("CLS");
			cryptography_tool();
			break;
		case 2:
			system("CLS");
			password_analyzer();
			break;
		case 3:
			system("CLS");
			password_generator();
			break;
		case 4:
			cout<<"Thanks for using :)"<<endl;
			cout<<"Exiting......."<<endl;
			return 0;
		default:
			cout<<"Something Went Wrong!"<<endl;
	}
	system("CLS");
	main(); 
	return 0;
}

/* Function that prints the menu, asks for the option (checks if correct) and returns the option choosed*/
int menu ();

/* Function that converts the ip passed using a pointer to a string to a binary string returned using a pointer to a string*/
char* ipToBinary (char* ip);

/* Function that provides a correct input method to ask the ip to user */
char* scanfIP ();

/* Function to clear the screen based on the system running */
void clear_screen ();

/* Function that checks if an ip address passed with a pointer to a string is valid*/
int isValidIPv4 (char* ip);


void calculateNetworkAddress(char* ip, int cidr);

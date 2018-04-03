#include <stdio.h>

void scanISBN(int arr[10]){
	int i;
	char c;
	for (i=0; i < 10; ++i) {
		scanf(" %c", &c);
		arr[i] = c - '0';
	}
}

int isValidISBN(int isbn[10]) {
	int i;
	int sum = 0;
	int c = 0;
	for (i=10; i > 0; --i){
		sum = sum + (i * (isbn[c]));
		c++;
	}
	if ((sum % 11) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main (int argc, char* argv[]) {
	int i, num, a;
	int isbn[10];
	scanf(" %d", &num);
	
	for(i=0; i<10; ++i){
		scanISBN(isbn);
		
		if(isValidISBN(isbn) == 0) {
			for (a = 0; a < 10; ++a) {
				printf("%d", isbn[a]);
			}
			printf(" is not a valid ISBN Number\n", isbn);
		}
	}
	return 0;
}
#include <stdio.h>
#include <string.h>

/**
 * Helper function for initializing the lookup table as empty
 * (Note: It would be a cleaner and more efficient coding style 
 * to not define the lookup table as global but to pass it to 
 * the function as a parameter)
 */
#define EMPTY -1
#define SIZE 1000
int lookup_table[SIZE][SIZE];
void initialize() {
	for(int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			lookup_table[i][j] = EMPTY;
		}
	}
}

void print_lookup_table(char* s1, char* s2);
void print_lcs(char* s1, char* s2, int len);

/**
 * Helper function for finding the maximum of two integers
 */
int max(int a, int b) {
	return (a > b)? a : b;
}

/**
 * Finds the length of the Longest Common Subsequence (LCS) 
 * of two strings using a memoized recursive approach 
 * (= top-down dynamic programming approach)
 *
 * @param  s1  first string for which the length of the LCS shall be calculated
 * @param  s2  second string for which the length of the LCS shall be calculated
 * @param  i   length of the substring of s1 which should be considered
               (note that this parameter does *not* denote the index in the string but the length)
 * @param  j   length of the substring of s2 which should be considered
 * @pre    0 <= i <= len(s1), 0 <= j <= len(s2)
 */
int lcs(char* s1, char* s2, int i, int j) {
	if (lookup_table[i][j] == EMPTY) {
		if (i == 0 || j == 0) {
			lookup_table[i][j] = 0;
			return lookup_table[i][j];
		}
		if (s1[i-1] == s2[j-1]) {
			lookup_table[i][j] = lcs(s1, s2, i-1, j-1) + 1;
			return lookup_table[i][j];
		}
		else {
			lookup_table[i][j] = max(lcs(s1, s2, i, j-1), lcs(s1, s2, i-1, j));
			return lookup_table[i][j];
		}
	}
	else {
		return lookup_table[i][j];
	}
}

int main() {
	initialize();
	char s1[] = "CTGACA";
	char s2[] = "ACGCTAC";
	int x = strlen(s1);
	int y = strlen(s2);
	int lcs_length = lcs(s1, s2, x, y);
	printf("Length of LCS: %d\n\n", lcs_length);
	print_lookup_table(s1, s2);
	printf("\n");
	print_lcs(s1, s2, lcs_length);
	return 0;
}

/**
 * Helper function for printing the lookup table
 */
void print_lookup_table(char* s1, char* s2) {
	int x = strlen(s1);
	int y = strlen(s2);
	printf("Lookup table:\n");
	printf("    ");
	for (int i = 0; i < x; i++) {
		printf("%c ", s1[i]);
	}
	printf("\n");
	for(int j = 0; j <= y; j++) {
		if (j > 0) {
			printf("%c ", s2[j-1]);
		}
		else {
			printf("  ");
		}
		for (int i = 0; i <= x; i++) {
			if (lookup_table[i][j] == EMPTY) {
				printf("_ ");
			}
			else {
				printf("%d ", lookup_table[i][j]);
			}
		}
		printf("\n");
	}
}

/**
 * Constructs the Longest Common Subsequence as a string by 
 * traversing the lookup table and prints it
 * (Note: The function does *not* print all possible solutions but just one of them)
 */
void print_lcs(char* s1, char* s2, int len) {
	char lcs_string[len+1];
	lcs_string[len] = '\0';
	int i = strlen(s1);
	int j = strlen(s2);
	int lcs_pos = len;
	while (i > 0 && j > 0) {
		if (s1[i-1] == s2[j-1]) {
			lcs_pos--;
			lcs_string[lcs_pos] = s1[i-1];
			i--;
			j--;
		}
		else if (lookup_table[i-1][j] > lookup_table[i][j-1]) {
			i--;
		}
		else {
			j--;
		}
	}
	printf("LCS: %s", lcs_string);
}

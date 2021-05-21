#include <stdio.h>
#include <string.h>

/**
 * Helper function for finding the maximum of two integers
 */
int max(int a, int b) {
	return (a > b)? a : b;
}

/**
 * Finds the length of the Longest Common Subsequence (LCS) 
 * of two strings using a (bottom-up) dynamic programming approach
 *
 * @param  s1  first string for which the length of the LCS shall be calculated
 * @param  s2  second string for which the length of the LCS shall be calculated
 * @param  x   length of the substring of s1 which should be considered
               (note that this parameter does *not* denote the index in the string but the length)
 * @param  y   length of the substring of s2 which should be considered
 * @pre    0 <= x <= len(s1), 0 <= y <= len(s2)
 */
int lcs(char* s1, char* s2, int x, int y) {
	int lookup_table[x+1][y+1];
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (i == 0 || j == 0) {
				lookup_table[i][j] = 0;
			}
			else if (s1[i-1] == s2[j-1]) {
				lookup_table[i][j] = lookup_table[i-1][j-1] + 1;
			}
			else {
				lookup_table[i][j] = max(lookup_table[i-1][j], lookup_table[i][j-1]);
			}
		}
	}
	return lookup_table[x][y];
}

int main() {
	char s1[] = "CTGACA";
	char s2[] = "ACGCTAC";
	int x = strlen(s1);
	int y = strlen(s2);
	printf("Length of LCS: %d", lcs(s1, s2, x, y));
	return 0;
}

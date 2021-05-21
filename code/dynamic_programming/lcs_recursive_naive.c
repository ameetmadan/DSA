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
 * of two strings using a naive recursive approach
 *
 * @param  s1  first string for which the length of the LCS shall be calculated
 * @param  s2  second string for which the length of the LCS shall be calculated
 * @param  i   length of the substring of s1 which should be considered
               (note that this parameter does *not* denote the index in the string but the length)
 * @param  j   length of the substring of s2 which should be considered
 * @pre    0 <= i <= len(s1), 0 <= j <= len(s2)
 */
int lcs(char* s1, char* s2, int i, int j) {
	if (i == 0 || j == 0) {
		return 0;
	}
	if (s1[i-1] == s2[j-1]) {
		return lcs(s1, s2, i-1, j-1) + 1;
	}
	else {
		return max(lcs(s1, s2, i, j-1), lcs(s1, s2, i-1, j));
	}
}

int main() {
	char s1[] = "CTGACA";
	char s2[] = "ACGCTAC";
	int x = strlen(s1);
	int y = strlen(s2);
	printf("Length of LCS: %d", lcs(s1, s2, x, y));
	return 0;
}

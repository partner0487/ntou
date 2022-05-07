#include<stdio.h> 
#include<string.h>

int main() {
	int n = 1;
	while (n == 1) {
		int num1[255], num2[255], ans[255];
		char s1[255], s2[255];
		int n1, n2;
		memset(num1, 0, sizeof(num1)); memset(num2, 0, sizeof(num2));
		memset(ans, 0, sizeof(ans));
		printf("Enter positive integer1:");
		scanf("%s", &s1);
		printf("Enter positive integer2:");
		scanf("%s", &s2);
		printf("1. add\n2. subtraction\nplease input number to check calculate type: ");
		int calculateType;
		scanf("%d", &calculateType);
		if (calculateType == 1) {
			for (n1 = 0; s1[n1]; n1++)
				num1[n1] = s1[n1] - 48;
			for (n2 = 0; s2[n2]; n2++)
				num2[n2] = s2[n2] - 48;

			int carry = 0, k = 0, i = n1 - 1, j = n2 - 1;
			for (; i >= 0 && j >= 0; i--, j--, k++) {
				ans[k] = (num1[i] + num2[j] + carry) % 10;
				carry = (num1[i] + num2[j] + carry) / 10;
			}

			if (n1 > n2) {
				while (i >= 0) {
					ans[k++] = (num1[i] + carry) % 10;
					carry = (num1[i--] + carry) / 10;
				}
			}

			else if (n1 < n2) {
				while (j >= 0) {
					ans[k++] = (num2[j] + carry) % 10;
					carry = (num2[j--] + carry) / 10;
				}
			}

			else {
				if (carry) ans[k++] = carry;
			}

			if (ans[100]) {
				printf("overflow, input 1 to restart");
				scanf("%d",&n);
				continue;
			}
            
			printf("Result:");
			for (k--; k >= 0; k--)
				printf("%d", ans[k]);
		}
		else if (calculateType == 2) {
			int l1 = strlen(s1), l2 = strlen(s2), i, j, k = 0, t = 0, borrow = 0;
			if (l1 == l2) {
				for (i = l1 - 1; i >= 0; i--) {
					if (s1[i] < s2[i]) {
						for (j = l1 - 1; j >= 0; j--) {
							char temp;
							temp = s1[i];
							s1[i] = s2[i];
							s2[i] = temp;
						}
						int temp = l1;
						l1 = l2;
						l2 = temp;
						break;
					}
				}
			}
			for (i = 0, n1 = l1 - 1; s1[n1]; n1--, i++)
				num1[n1] = s1[i] - 48;
			for (i = 0, n2 = l2 - 1; s2[n2]; n2--, i++)
				num2[n2] = s2[i] - 48;
			i = l1 - 1, j = l2 - 1, k = l1 - 1;
			while (i >= 0 && j >= 0) {
				while(i > j){
					ans[k--] = num1[i--];
				}
				ans[k] = (num1[i]) - (num2[j]) + borrow;
				if (ans[k] < 0) {
					ans[k] += 10;
					borrow = 1;
				}
				else {
					borrow = 0;
					k--, i--, j--;
				}
			}
			
			printf("Result:");
			for (i = l1 - 1; i >= 0; i--)
				printf("%d", ans[i]);
		}
		printf("\n");
		printf("continue? ");
		scanf("%d", &n);
	}
}
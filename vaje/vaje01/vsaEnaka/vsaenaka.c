#include <stdio.h>

int main() {
	
	int n;
	scanf("%d", &n);
	
	int i, prvo;
	scanf("%d", &prvo);
	int enaka = 1;
	for(i = 0; i < n - 1; i++) {
		int novo;
		scanf("%d", &novo);
		if(novo != prvo) {
			enaka = 0;
			break;
		}
	}
	
	printf("%d", enaka);
	
	return 0;
}
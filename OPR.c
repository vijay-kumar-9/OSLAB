#include <stdio.h>

int main() {
    int p[20], f[10], n, m, i, j, k, pos, fault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
        f[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;
        for(j = 0; j < m; j++) {
            if(f[j] == p[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            pos = -1;
            for(j = 0; j < m; j++) {
                if(f[j] == -1) {
                    pos = j;
                    break;
                }
            }
            if(pos == -1) {
                int farthest = -1;

                for(j = 0; j < m; j++) {
                    for(k = i + 1; k < n; k++)
                        if(f[j] == p[k])
                            break;

                    if(k > farthest) {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            f[pos] = p[i];
            fault++;
        }
    }
    printf("Total Page Faults = %d", fault);
    return 0;
}
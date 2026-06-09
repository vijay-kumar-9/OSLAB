#include <stdio.h>
int main() {
    int frames, window, i = 0, ack;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    printf("Enter window size: ");
    scanf("%d", &window);
    while (i < frames) {
        for (int j = 0; j < window && (i + j) < frames; j++) {
            printf("Sending Frame %d\n", i + j);
        }
        printf("Enter last acknowledged frame: ");
        scanf("%d", &ack);
        if (ack < i) {
            printf("Frame lost! Retransmitting from Frame %d\n", ack + 1);
            i = ack + 1;
        } else {
            i = ack + 1;
        }
    }
    printf("All frames transmitted successfully\n");
    return 0;
}
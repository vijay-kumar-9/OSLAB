#include <stdio.h>

int main() {
    int p[20], offset, page_no, n, i, logical, physical;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter frame number for each page:\n");
    for(i = 0; i < n; i++) {
        printf("Page %d: ", i);
        scanf("%d", &p[i]);
    }

    printf("Enter logical address (page_no offset): ");
    scanf("%d %d", &page_no, &offset);

    if(page_no >= n) {
        printf("Invalid Page Number\n");
    } else {
        physical = p[page_no] * 100 + offset; // assume page size = 100
        printf("Physical Address = %d\n", physical);
    }

    return 0;
}
Paging
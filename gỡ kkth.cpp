#include <stdio.h>

int main() {
    int arr[1000];
    int size = 0; 
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang\n");
        printf("5. Them mot phan tu vao mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri cua phan tu do\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { 
                printf("Nhap so phan tu: ");
                scanf("%d", &size);
                if (size > 1000 || size <= 0) {
                    printf("So phan tu khong hop le.\n");
                    size = 0;
                } else {
                    printf("Nhap gia tri cac phan tu:\n");
                    for (int i = 0; i < size; i++) {
                        printf("Phan tu %d: ", i + 1);
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            }
            case 2: { 
                if (size == 0) {
                    printf("Mang hien tai rong.\n");
                } else {
                    printf("Cac phan tu trong mang: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: { 
                if (size == 0) {
                    printf("Mang hien tai rong.\n");
                } else {
                    int max = arr[0];
                    for (int i = 1; i < size; i++) {
                        if (arr[i] > max) {
                            max = arr[i];
                        }
                    }
                    printf("Gia tri lon nhat trong mang la: %d\n", max);
                }
                break;
            }
            case 4: { 
                if (size == 0) {
                    printf("Mang co it hon 2 phan tu, khong the tim gia tri nho thu 2.\n");
                } else {
                    printf("Cac so nguyen to trong mang: ");
                    for (int i = 0; i < size; i++) {
                        int num = arr[i], isPrime = 1;
                        if (num < 2) isPrime = 0;
                        for (int j = 2; j * j <= num; j++) {
                            if (num % j == 0) {
                                isPrime = 0;
                                break;
                            }
                        }
                        if (isPrime) printf("%d ", num);
                    }
                    printf("\n");
                }
                break;
            }
            case 5: { 
                if (size >= 1000) {
                    printf("Mang da day.\n");
                } else {
                    int value;
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    arr[size++] = value;
                    printf("Da them %d vao mang.\n", value);
                }
                break;
            }
            case 6: { 
                if (size == 0) {
                    printf("Mang hien tai rong.\n");
                } else {
                    int index;
                    printf("Nhap vi tri can xoa (0-%d): ", size - 1);
                    scanf("%d", &index);
                    if (index < 0 || index >= size) {
                        printf("Vi tri khong hop le.\n");
                    } else {
                        for (int i = index; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Da xoa phan tu tai vi tri %d.\n", index);
                    }
                }
                break;
            }
            case 7: { 
                if (size == 0) {
                    printf("Mang hien tai rong.\n");
                } 
 
                   else {
                     for (int i = 0; i < size - 1; i++) {
                     for (int j = i + 1; j < size; j++) {
                            if (arr[i] > arr[j]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                            }
                        }
                    }
                    printf("Mang da sap xep tang dan.\n");
                }
                break;
            }
            case 8: { 
                if (size == 0) {
                    printf("Mang hien tai rong.\n");
                } else {
                    int value, found = 0;
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &value);
                    for (int i = 0; i < size; i++) {
                        if (arr[i] == value) {
                            printf("Gia tri %d o vi tri %d.\n", value, i);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Khong tim thay gia tri %d trong mang.\n", value);
                    }
                }
                break;
            }
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 9);

    return 0;
}


#include <stdio.h>

// ฟังก์ชันสำหรับตรวจสอบว่าเลขมีตัวเลข 1 ที่เป็นติดกันหรือไม่
int hasAdjacentOnes(int num) {
    while (num > 0) {
        if ((num & 7) == 7 || (num & 7) == 0) // เช็คเลขประจำสถานีของทั้งสองสถานีแตกต่างกันที่หนึ่งหลักพอดี
            return 1;
        num >>= 1;
    }
    return 0;
}

// ฟังก์ชันสร้างเส้นทางเชื่อมระหว่างสถานี
void generateConnections(int d) {
    int i, j;

    // สร้างเส้นทางเชื่อมระหว่างสถานี
    for (i = 0; i < (1 << d); i++) {
        for (j = i + 1; j < (1 << d); j++) {
            if (hasAdjacentOnes(i ^ j)) // เรียกใช้ฟังก์ชัน hasAdjacentOnes เพื่อตรวจสอบเงื่อนไข
                printf("%0*d %0*d\n", d, i, d, j);
        }
    }
}

int main() {
    int d;

    // รับค่า d จากผู้ใช้
    printf("Enter the value of d: ");
    scanf("%d", &d);

    // เรียกใช้ฟังก์ชันสร้างเส้นทางเชื่อม
    generateConnections(d);

    return 0;
}
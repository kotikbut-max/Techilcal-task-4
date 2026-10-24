#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    do {
        printf("\n========================================\n");
        printf("      ЛАБОРАТОРНАЯ РАБОТА № 2 (C)       \n");
        printf("========================================\n");
        printf("1. Задание 1\n");
        printf("2. Задание 2\n");
        printf("3. Задание 3\n");
        printf("4. Задание 4\n");
        printf("5. Задание 5\n");
        printf("6. Задание 6\n");
        printf("7. Задание 7\n");
        printf("8. Задание 8\n");
        printf("0. Выход\n");
        printf("----------------------------------------\n");
        printf("Выберите номер (0-8): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                long long num;
                printf("Введите число: ");
                scanf("%lld", &num);

                if (num == 0) {
                    printf("Шестеричная запись: 0\n");
                } else {
                    long long temp = num;
                    if (temp < 0) temp = -temp;
                    char buffer[100];
                    int idx = 0;
                    while (temp > 0) {
                        buffer[idx++] = (temp % 6) + '0';
                        temp /= 6;
                    }
                    printf("Шестеричная запись: ");
                    if (num < 0) printf("-");
                    for (int i = idx - 1; i >= 0; i--) {
                        putchar(buffer[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 2: {
                long long N;
                printf("Введите N: ");
                scanf("%lld", &N);

                long long m = 0;
                int i = 0;
                while (m <= N) {
                    i++;
                    m += i;
                }
                printf("Первое число большее N: %lld (номер i = %d)\n", m, i);
                break;
            }
            case 3: {
                long long num;
                printf("Введите число: ");
                scanf("%lld", &num);
                if (num < 0) num = -num;

                int digits[20];
                int count = 0;
                if (num == 0) {
                    digits[0] = 0;
                    count = 1;
                } else {
                    long long temp = num;
                    while (temp > 0) {
                        digits[count++] = temp % 10;
                        temp /= 10;
                    }
                    for (int i = 0; i < count / 2; i++) {
                        int t = digits[i];
                        digits[i] = digits[count - 1 - i];
                        digits[count - 1 - i] = t;
                    }
                }

                if (count <= 1) {
                    printf("Число состоит из одной цифры (упорядочено).\n");
                    break;
                }

                int inc = 1, dec = 1;
                for (int i = 0; i < count - 1; i++) {
                    if (digits[i] >= digits[i+1]) inc = 0;
                    if (digits[i] <= digits[i+1]) dec = 0;
                }

                if (inc) {
                    printf("Цифры расположены по возрастанию.\n");
                } else if (dec) {
                    printf("Цифры расположены по убыванию.\n");
                } else {
                    printf("Цифры никак не упорядочены.\n");
                }
                break;
            }
            case 4: {
                printf("Введите последовательность натуральных чисел (0 для окончания):\n");
                int val;
                int index = 1;
                long long sum = 0;
                while (scanf("%d", &val) == 1 && val != 0) {
                    if (index % 3 != 0 && val % 3 == 0) {
                        sum += val;
                    }
                    index++;
                }
                printf("Сумма подходящих элементов: %lld\n", sum);
                break;
            }
            case 5: {
                printf("Трехзначные числа с уникальными цифрами:\n");
                int count = 0;
                for (int i = 100; i <= 999; i++) {
                    int h = i / 100;
                    int t = (i / 10) % 10;
                    int u = i % 10;
                    if (h != t && h != u && t != u) {
                        printf("%d ", i);
                        count++;
                        if (count % 15 == 0) printf("\n");
                    }
                }
                printf("\nВсего таких чисел: %d\n", count);
                break;
            }
            case 6: {
                long long a, b;
                printf("Введите два натуральных числа a и b: ");
                scanf("%lld %lld", &a, &b);

                if (a <= 0 || b <= 0) {
                    printf("Числа должны быть натуральными (положительными).\n");
                    break;
                }

                long long tempA = a, tempB = b;
                while (b != 0) {
                    long long rem = a % b;
                    a = b;
                    b = rem;
                }
                long long gcd = a;
                long long lcm = (tempA / gcd) * tempB;

                printf("НОД = %lld\n", gcd);
                printf("НОК = %lld\n", lcm);
                break;
            }
            case 7: {
                long long n;
                printf("Введите натуральное число n для возведения в куб: ");
                scanf("%lld", &n);

                if (n <= 0) {
                    printf("Введите положительное число.\n");
                    break;
                }

                long long K = (n * (n - 1)) / 2 + 1;
                long long start_odd = 2 * K - 1;
                long long sum = 0;

                printf("%lld^3 = ", n);
                for (long long i = 0; i < n; i++) {
                    long long current_odd = start_odd + 2 * i;
                    sum += current_odd;
                    printf("%lld", current_odd);
                    if (i < n - 1) printf(" + ");
                }
                printf(" = %lld\n", sum);
                break;
            }
            case 8: {
                long long N;
                printf("Введите натуральное число N: ");
                scanf("%lld", &N);

                if (N <= 0) {
                    printf("Число должно быть положительным.\n");
                    break;
                }

                int found = 0;
                printf("Представления в виде суммы квадратов двух натуральных чисел:\n");
                for (long long a = 1; a * a <= N; a++) {
                    long long b_sq = N - a * a;
                    long long b = 0;
                    while ((b + 1) * (b + 1) <= b_sq) {
                        b++;
                    }
                    if (b * b == b_sq && b >= 1 && a <= b) {
                        printf("%lld^2 + %lld^2 = %lld\n", a, b, N);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Нельзя представить в виде суммы квадратов двух натуральных чисел.\n");
                }
                break;
            }
            case 0:
                printf("Выход...\n");
                break;
            default:
                printf("Неверный выбор.\n");
        }
    } while (choice != 0);

    return 0;
}
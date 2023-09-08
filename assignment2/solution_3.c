#include <stdio.h>
#include <math.h>
int main(void){
    double a, b, result;
    char c;

    printf(" ");
    scanf("%lf %c %lf", &a, &c, &b);

    switch (c) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0) {
                result = a / b;
            } else {
                printf("Error: dividing by zero\n");
                return 1; // Exit with an error code
            }
            break;
	case '%':
            if (b != 0) {
                result = a - (int)(a / b) * b; 
            } else {
                printf("Error: dividing by zero\n");
                return 1; // Exit with an error code
            }
            break;
        case '^':
            result = 1.0;
            for (int i = 0; i < b; i++) {
                result *= a;
            }
            break;
        case 'r':
            if (b != 0) {
                result = pow(b, 1.0 / a);
            } else {
                printf("Error: dividing by zero\n");
                return 1; // Exit with an error code
            }
            break;
        default:
            printf("Error: Invalid operator\n");
            return 1; // Exit with an error code
    }

    printf("Result: %.2lf\n", result);

    return 0;
}

#include <stdio.h>

int main() {
    char employeeType;
    printf("Input employee type (A/S/E/P/H): ");
    scanf(" %c", &employeeType);

    double monthlySalary, annualIncome, annualTax;
    double overtimeHours = 0.0; // Initialize to zero
    double productBonus = 0.0; // Initialize to zero
    double hoursalary = monthlySalary / (8 * 20);
    switch (employeeType) {
        case 'A': {
            printf("Input monthly salary: ");
            scanf("%lf", &monthlySalary);
            annualIncome = monthlySalary * 12;
            break;
        }

        case 'S': {
            printf("Input monthly salary: ");
            scanf("%lf", &monthlySalary);
            printf("Input overtime hours each month: ");
            scanf("%lf", &overtimeHours);
	    double hoursalary = monthlySalary / (8 * 20);
	    // Cap overtime hours to a maximum of 10 hours per month
            if (overtimeHours >= 10.0) {
                annualIncome = (monthlySalary * 12) + (10 * hoursalary * 1.5) * 12;
            }else if(overtimeHours >= 0 && overtimeHours < 10){
	    	annualIncome = (monthlySalary * 12) + (overtimeHours * hoursalary * 1.5) * 12;
	    }else{
	    	annualIncome = (monthlySalary * 12);
	    }
            break;
        }

        case 'E': {
            printf("Input monthly salary: ");
            scanf("%lf", &monthlySalary);
            printf("Input overtime working hours per day: ");
            scanf("%lf", &overtimeHours);
            printf("Is the employee going to take a vacation for a month? (Y/N): ");
            char vacationChoice;
            scanf(" %c", &vacationChoice);
            printf("Input sold product number in a year: ");
            int productsSold;
	    double hoursalary = monthlySalary / (8 * 20);
            scanf("%d", &productsSold);
            productBonus = productsSold * 600.0;
	    if (vacationChoice == 'Y' || vacationChoice == 'y') {
                annualIncome = (monthlySalary + (overtimeHours * 1.35 * hoursalary)) * 11 + productBonus + monthlySalary * 0.5;
            }else{
	    	annualIncome = (monthlySalary + (overtimeHours * 1.35 * hoursalary)) * 12 + productBonus;
	    }
            break;
        }

        case 'P': {
            double weeklySalary;
	    double hoursalary = monthlySalary / (8 * 20);
            printf("Input weekly salary: ");
            scanf("%lf", &weeklySalary);
            printf("Input overtime working hours each week: ");
            scanf("%lf", &overtimeHours);
            printf("Input sold product number in a year: ");
            int productsSold;
            scanf("%d", &productsSold);
            productBonus = productsSold * 600.0;
            // Cap overtime hours to a maximum of 10 hours per week
            if (overtimeHours > 10.0) {
                overtimeHours = 10.0;
            }
            annualIncome = (weeklySalary + (overtimeHours * hoursalary)) * 48 + productBonus;
            break;
        }

        case 'H': {
            double hourlySalary;
            printf("Input hourly salary: ");
            scanf("%lf", &hourlySalary);
            double weeklyHours;
	    double hoursalary = monthlySalary / (8 * 20);
            printf("Input the number of hours worked each week: ");
            scanf("%lf", &weeklyHours);
            double overtimeHoursHourly = 0.0;

            if (weeklyHours > 10.0) {
                overtimeHoursHourly = weeklyHours - 10.0;
            }
            annualIncome = (hourlySalary * weeklyHours * 4 * 12) + (overtimeHoursHourly * hourlySalary * 52);
            break;
        }

        default:
            printf("Invalid employee type.\n");
            return 1;
    }

    char maritalStatus;
    printf("Is this employee married? (Y/N): ");
    scanf(" %c", &maritalStatus);

    if ((maritalStatus == 'Y' || maritalStatus == 'y') && annualIncome > 32000) {
        annualTax = annualIncome * 0.25;
    } else if ((maritalStatus == 'Y' || maritalStatus == 'y') && annualIncome <= 32000) {
        annualTax = annualIncome * 0.10;
    } else if ((maritalStatus == 'N' || maritalStatus == 'n') && annualIncome > 64000) {
        annualTax = annualIncome * 0.25;
    } else if ((maritalStatus == 'N' || maritalStatus == 'n') && annualIncome <= 64000) {
        annualTax = annualIncome * 0.10;
    }

    double annualIncomeAfterTax = annualIncome - annualTax;

    printf("Output: This employee's annual income is $%.2lf before tax and $%.2lf after tax.\n", annualIncome, annualIncomeAfterTax);
    return 0;
}


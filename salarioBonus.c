#include <stdio.h>
 
int main() {
 
    char name;
    double salary,totalV,salaryWithBonus;
    
    scanf("%s",&name);
    scanf("%lf",&salary);
    scanf("%lf",&totalV);
    salaryWithBonus = salary+(totalV*0.15);
    
    printf("TOTAL = R$ %.2lf\n",salaryWithBonus);

    return 0;
}
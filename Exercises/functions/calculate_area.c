#include <stdio.h>
#define PI 3.14159

float calculate_area(float radius);

int main()
{
    float circle_area, circle_radius;

    printf("Enter the radius of the circle: ");
    scanf("%f", &circle_radius);

    circle_area = calculate_area(circle_radius);

    printf("THe area of the circle is: %f", circle_area);
    return 0;

}

float calculate_area(float radius)
{
    float area;
    area = PI * radius * radius;
    return area;
}
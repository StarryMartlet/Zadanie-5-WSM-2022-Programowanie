#include <cstdlib>
#include <iostream>
# include <math.h>
float perimetr(float x, float y, float z)
{
    float p;
    p = x + y + 2 * sqrt(((x - y) / 2)*((x - y) / 2) + z*z);
    return p;
}

float ploschad(float x, float y, float z)
{
    float s;
    s = z*((x + y) / 2);
    return s;
}
int main()
{
    setlocale(LC_ALL, "eng");
    float a1, b1, h1, p1, s1, a2, b2, h2, p2, s2;

    printf("Enter two bases and the height of the first trapezoid: ");
    scanf("%f %f %f", &a1, &b1, &h1);
    printf("Enter two bases and the height of the second trapezoid: ");
    scanf("%f %f %f", &a2, &b2, &h2);

    p1=perimetr(a1, b1, h1);
    p2=perimetr(a2, b2, h2);

    printf(" Sum of perimeters = %f \n", p1+p2);

    s1=ploschad(a1, b1, h1);
    s2=ploschad(a2, b2, h2);

    printf(" Sum of area = %f \n", s1 + s2);


    system("PAUSE");
    return EXIT_SUCCESS;
}

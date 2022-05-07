/*
 * Computes the weight of a batch of flat washers.
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

double inputdata(double *hole_diameter,double *edge_diameter, double *thickness){
      //printf("Inner diameter in centimeters> ");
      scanf("%lf", hole_diameter);
      //printf("Outer diameter in centimeters> ");
      scanf("%lf", edge_diameter);
      //printf("Thickness in centimeters> ");
      scanf("%lf", thickness);
      return 0;
}

double substance(double *density, double *quantity){
      //printf("Material density in grams per cubic centimeter> ");
      scanf("%lf", density);
      //printf("Quantity in batch>");
      scanf("%lf", quantity);
      return 0;
}

double cal(double hole_diameter, double edge_diameter){
      double k, hole_radius, edge_radius;
      hole_radius = hole_diameter / 2.0;
      edge_radius = edge_diameter / 2.0;
      k = PI * edge_radius * edge_radius -
                 PI * hole_radius * hole_radius;
      return k;
}
double unit(double rim_area, double thickness, double density){
      double k;
      k=rim_area * thickness * density;
      return k;
}
double wei(double unit_weight, double quantity){
      double k;
      k=unit_weight * quantity;
      return k;
}

double print(double weight){
      printf("The expected weight of the batch is %.2f", weight);
      printf(" grams.\n");
      return 0;
}
int main(void)
{
      double hole_diameter; /* input - diameter of hole         */
      double edge_diameter; /* input - diameter of outer edge   */
      double thickness;     /* input - thickness of washer      */
      double density;       /* input - density of material used */
      double quantity;      /* input - number of washers made   */
      double weight;        /* output - weight of washer batch  */
      //double hole_radius;   /* radius of hole                   */
      //double edge_radius;   /* radius of outer edge             */
      double rim_area;      /* area of rim                      */
      double unit_weight;   /* weight of 1 washer               */
      inputdata(&hole_diameter, &edge_diameter, &thickness);
      substance(&density, &quantity);
      rim_area = cal(hole_diameter, edge_diameter);
      unit_weight = unit(rim_area, thickness, density);

      weight = wei(unit_weight, quantity);
      //printf("%lf %lf %lf %lf %lf %lf %lf %lf\n", hole_diameter, edge_diameter, thickness, density, quantity, weight, rim_area, unit_weight);
      print(weight);

      system("pause");
      return (0);
}
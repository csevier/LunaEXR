#include <iostream>
#include <fstream>
#include "Ray.hpp"
#include "vector3d.hpp"


bool hit_sphere(const luna::Vector3d& center, float radius, const luna::Ray& ray)
{
    luna::Vector3d oc = ray.Origin() - center;
    float a = ray.Direction().DotProduct(ray.Direction());
    float b = 2.0 * oc.DotProduct(ray.Direction());
    float c = oc.DotProduct(oc) - radius*radius;
    float discriminant = b*b -4*a*c;
    return (discriminant > 0);
}

luna::Vector3d color(const luna::Ray& ray)
{
   if(hit_sphere(luna::Vector3d(0,0, -1), 0.5, ray))
   {
       auto red = luna::Vector3d(1, 0, 0);
       return red;
   }
   luna::Vector3d unitDirection = ray.Direction().Normalize();
   float t = 0.5 * (unitDirection.y() + 1.0f);
   return luna::Vector3d(1.0,1.0,1.0) * (1.0-t) + luna::Vector3d(0.5, 0.7, 1.0) * t;
}

int main()
{
    int width_x =200;
    int height_y = 100;

    std::ofstream render{"render.ppm"};
    render << "P3\n" << width_x << " " << height_y << "\n255\n";
    luna::Vector3d lowerLeftCorner(-2.0, -1.0, -1.0);
    luna::Vector3d horizantal(4.0, 0.0, 0.0);
    luna::Vector3d vertical(0.0, 2.0, 0.0);
    luna::Vector3d origin(0.0, 0.0, 0.0);

    for(int j = height_y-1; j >=0; j--)
    {
        for(int i =0; i < width_x; i++)
        {
            float u = float(i) / float(width_x);
            float v = float(j) / float(height_y);
            luna::Ray ray(origin,lowerLeftCorner+ horizantal * u + vertical * v);
            luna::Vector3d col = color(ray);
            int ir = int (255.99*col.r());
            int ig = int(255.99*col.g());
            int ib = int(255.99*col.b());
            render << ir << " " << ig << " " << ib << "\n";
            render.flush();
        }
    }

    render.close();
}

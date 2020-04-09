#include <iostream>
#include <fstream>

int main()
{
    int width_x =200;
    int height_y = 100;

    std::ofstream render{"render.ppm"};
    render << "P3\n" << width_x << " " << height_y << "\n255\n";

    for(int j = height_y-1; j >=0; j--)
    {
        for(int i =0; i < width_x; i++)
        {
            float r = float(i) / float(width_x);
            float g = float(j) / float(height_y);
            float b = 0.2;
            int ir = int (255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);
            render << ir << " " << ig << " " << ib << "\n";
            render.flush();
        }
    }

    render.close();
}

class Solution {
    double xc,yc,r;
public:
    Solution(double radius, double x_center, double y_center) {
        xc=x_center;
        yc=y_center;
        r=radius;
    }
    
    vector<double> randPoint() {
        double xrand = (double)rand() / RAND_MAX;
        
        double x_min = xc - r;
        double x_max = xc + r;
        
        
        double x = x_min + xrand * (x_max - x_min);
        
        double yrand = (double)rand() / RAND_MAX;
        
        double y_min = yc - r;
        double y_max = yc + r;
        
        double y = y_min + yrand * (y_max - y_min);
        
        vector<double>v(2);
        
        if((x - xc)*(x - xc) + (y - yc) * (y - yc) < r * r  ){
            v[0] = x;
            v[1] = y;
            return v;
        }
        else 
            return randPoint();
    }
};

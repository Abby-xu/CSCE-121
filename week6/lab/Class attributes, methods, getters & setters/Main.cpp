#include <iostream>
using namespace std;

//class Color_error {};
class Color {
/* Public */
public:
    void cout_rgb (void) { 
        cout << "Color Values: (" << R << ',' << G << ',' << B << ')' << endl;
    }
    //get the value of R G B
    int get_R () {
        return R;
    }
    int get_G () {
        return G;
    }
    int get_B () {
        return B;
    }

    //set the value of R G B
    bool is_valid_val(int v) {
        if (v < 0 || v > 255)
            return false;
        else
            return true;        
    }

    void set_R (int R) {
        if (!is_valid_val(R)) {
            throw runtime_error("the value is out of range");
        }
        this -> R = R;
    }
    void set_G (int G) {
        if (!is_valid_val(G)) {
            throw runtime_error("the value is out of range");
        }
        this -> G = G;
    }
    void set_B (int B) {
        if (!is_valid_val(B)) {
            throw runtime_error("the value is out of range");
        }
        this -> B = B;
    }

/* Private */
private:
    int R = 255;
    int G = 255;
    int B = 255;
};

int main()
{
    Color color;
    color.cout_rgb();
    cout << "color.R = " << color.get_R() << endl;
    cout << "color.G = " << color.get_G() << endl;
    cout << "color.B = " << color.get_B() << endl;

    int R, G, B;
    cout << "Please enter integer values for R, G, and B: ";
    try { 
        cin >> R >> G >> B;
        color.set_R(R); 
        color.set_G(G); 
        color.set_B(B);
        color.cout_rgb();
    }
    catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
    }



 }
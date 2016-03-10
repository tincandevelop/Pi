#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<float.h>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;
double *digits = new double;

double factorial(double in){

    double out = in;

    for(int i = in; i >= 1; i--){
        out *= i;
    }
    return out;
}
/*void progressbar(int progress, double * width){
    cout << "\r" << "[";
    string print;
    double percent = *width / 50;
    for(int i = 0; i <= 50; i++){
        if(progress / percent >= i){
            cout << "=";
        }else{
            cout << " ";
        }
    }
    cout << "] " << (progress / percent) * 2 << "%";

}*/
double * pi_1(double *times){
    double *PI;
    PI = new double;
    *PI = 0.0;
    bool function = true;
    double x = 0.5;
    for(int i=0; i<= *times; i++){
        if(function == true){
            function = false;
            *PI += 4.0 / (x * 2);
        }else{
            function = true;
            *PI -= 4.0 / (x * 2);
        }
        x = x + 1;
        //progressbar(i,times);
    }
    return PI;
    delete PI;
}
double * pi_2(double *times){
    double *PI = new double(0.0);
    double *sum = new double(0.0);

    for(int i=0.0; i<= *times; i++){
        *sum += (pow(-1,i) * factorial(6 * i) * ((545140134 * i) + 12391409)) / (factorial(3 * i) * pow(factorial(i),3) * pow(pow(640320, 3 ), i + 0.5));
    }
    *PI = 1 / (12 * *sum);
    return PI;
    delete PI;
    delete sum;
}

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    int algorithm;
    while(true){
        *digits = 0.0;
        algorithm = 0;
        cout << " How many iterations of the pi algorithm? ";
        cin >> *digits;
        cout << "\n Which algorithm:\n Infinite series[1]\n :";
        cin >> algorithm;
        double * out;
        out = new double;
        if(algorithm == 1){
            out = pi_1(digits);
        }else{
            out = pi_2(digits);
        }
        string filepath = "";
        cout << " What would you like your file to be called: ";
        cin >> filepath;
        filepath = filepath + ".txt";
        const char * filename = filepath.c_str();
        ofstream pitxt(filename);
        if(pitxt.is_open()){
            pitxt << "Pi : ";
            pitxt << fixed << std::setprecision(log10(*digits) - 1) << *out;
            pitxt.close();
            cout << endl <<" Pi has been successfully saved to " + filepath << endl << endl << " Would you like to open it? [Y/N]: ";
            string open;
            cin >> open;
            if(open == "Y" || open == "y"){
                system (filename);
            }
            cout << endl << endl << endl;

        } else {
            cout << "Error occured: could not open ";
            cout << filename;
        }
        delete out;
    }
}

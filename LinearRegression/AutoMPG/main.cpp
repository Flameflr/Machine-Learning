#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    ifstream file ("auto-mpg.data");
    
    if(!file.is_open()) {

	cout << "Data konnte nicht geöffnet werden";
	return -1;
    }

    vector<double> Gpa;
    vector<double> Weight;

    double gpa;
    double weight;
    string temp;

    while (file >> gpa >> temp >> temp >> temp >> weight >> temp >> temp >> temp >> temp) {

	Gpa.push_back(gpa);
	Weight.push_back(weight);
	getline(file, temp);
    }

    double b0 = 0;
    double b1 = 0;

    double gpa_sum = 0;
    double weight_sum = 0;

    // for (auto &a : Gpa) cout << a << ' ';
    // cout << '\n';
    // for (auto &a : Weight) cout << a << ' ';
    // cout << '\n';


    for (auto &a : Gpa) gpa_sum += a;
    gpa_sum = gpa_sum / Gpa.size();
    for (auto &a : Weight) weight_sum += a;
    weight_sum = weight_sum / Weight.size();

    double b1_bottom = 0;
    for (long unsigned int i = 0; i < Gpa.size(); i++) {

	b1 += (Weight[i] - weight_sum)*(Gpa[i] - gpa_sum);
	b1_bottom += pow(Weight[i] - weight_sum, 2);
    }

    b1 = b1 / b1_bottom;

    b0 = gpa_sum - b1*weight_sum;
    
    double x = 4354;
    cout << b0 + b1*x;
}

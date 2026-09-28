#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

   ifstream file ("auto-mpg.data");
    
   if(!file.is_open()) {

	cout << "Data konnte nicht geöffnet werden";
	return -1;
   }

   vector<double> Mpg;
   vector<double> Weight;

   double mpg;
   double weight;
   string temp;

   while (file >> mpg >> temp >> temp >> temp >> weight >> temp >> temp >> temp >> temp) {

	Mpg.push_back(mpg);
	Weight.push_back(weight);
	getline(file, temp);
   }


   double mittelwert = 0;
   for (int i = 0; i < Weight.size(); i++) mittelwert += Weight[i]/Weight.size();  
      

   double std_Abw = 0;
   for (int i = 0; i < Weight.size(); i++) {
   
      std_Abw += pow(Weight[i] - mittelwert,2)/Weight.size();
   }
   std_Abw = sqrt(std_Abw);


   vector<double> Weight_scaled;
   for (int i = 0; i < Weight.size(); i++) Weight_scaled.push_back((Weight[i] - mittelwert)/std_Abw);

   double slope = 1;
   double y_intercept = 0;
   double y;
   double learningFaktor = 1e-3;
   for (int t = 0; t < 100000; t++) {
      double slope_derivation = 0;
      double y_intercept_derivation = 0;
      for (int i = 0; i < Weight_scaled.size(); i++) {
	 y = y_intercept + slope * Weight_scaled[i];

	 slope_derivation += -2*Weight_scaled[i]*(Mpg[i] - y);
	 y_intercept_derivation += -2*(Mpg[i] - y);
      }

      slope_derivation = slope_derivation / Weight_scaled.size();
      y_intercept_derivation = y_intercept_derivation / Weight_scaled.size();

      // cout << slope_derivation << ' ' << y_intercept_derivation << ' ' << slope << ' ' << y_intercept << '\n';

      slope -= slope_derivation * learningFaktor;
      y_intercept -= y_intercept_derivation * learningFaktor;
   }
   
   double testwert = 3504;
   testwert = (testwert - mittelwert)/std_Abw;
   y = y_intercept + slope * testwert;
   cout << y;

ofstream outputfile ("/home/yannick/Programmieren/Projects/MachineLearning/LinearRegression/gradient_descent_function.csv");

y_intercept = y_intercept - (slope * mittelwert) / std_Abw;
slope = slope/std_Abw;

outputfile << y_intercept << "," << slope << '\n';
}

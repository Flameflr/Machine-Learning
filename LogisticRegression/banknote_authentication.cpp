#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

   double b = 0;
   double b_gradient = 0;
   double learningrate = 1e-2;
   double estimation = 0;


   vector<vector<double>> df;
   vector<double> weights = {1,1,1,1};
   vector<double> Z;
   vector<double> Sigmoid;
   vector<double> weights_gradient;
   vector<double> testwert = {3.6216,8.6661,-2.8073,-0.44699};


   ifstream file ("banknote_authentication.data");


   if(!file.is_open()) {

	cout << "Data konnte nicht geöffnet werden";
	return -1;
   }


   double variance,skewness,curtosis,entropy, val;
   while (file >> variance >> skewness >> curtosis >> entropy >> val) df.push_back({variance, skewness, curtosis, entropy, val});
   

   for (int k = 0; k < 1000; k++) {

      Z.clear();
      Sigmoid.clear();

      for (int i = 0; i < df.size(); i++) {

	 Z.push_back(df[i][0] * weights[0] + df[i][1] * weights[1] + df[i][2] * weights[2] + df[i][3] * weights[3] + b);

	 Sigmoid.push_back(1/(1 + 1/exp(Z[i])));
      }

      weights_gradient.clear();
      for (int j = 0; j < weights.size(); j++) {

	 b_gradient = 0;
	 double temp = 0;
	 for (int i = 0; i < df.size(); i++) {
	    temp += (Sigmoid[i] - df[i][4]) * df[i][j];
	    b_gradient += (Sigmoid[i] - df[i][4]) / df.size();
	 }
	 weights_gradient.push_back(temp/df.size()); 
      }

      for (int i = 0; i < weights.size(); i++) {
	 weights[i] = weights[i] - learningrate * weights_gradient[i];
      }
      b = b - learningrate * b_gradient;


      estimation = testwert[0]*weights[0] + testwert[1]*weights[1] + testwert[2]*weights[2] + testwert[3]*weights[3] + b;
      
      estimation = 1/(1 + 1/exp(estimation));

      if (k % 100 == 0) cout << estimation << '\n';
   }
}


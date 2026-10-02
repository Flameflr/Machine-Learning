#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>
#include <climits>



using namespace std;

string line;
string column1, column2, column3,column4;

int K;
int M, B;
int right_answer, wrong_answer;
double euclidDist;
int MAXright_answer = 0;
int bestK;

vector<string> diagnosis, diagnosis_test;
vector<double> radius, radius_test, texture, texture_test;
vector<int> neighbors;

priority_queue<pair<double,string>> distances; 

int main() {

   ifstream file_training ("KNNAlgorithmDataset_training.csv");

   while (getline(file_training, line)) {

      stringstream ss(line);
      
      getline(ss, column1, ',');
      getline(ss, column2, ',');
      getline(ss, column3, ',');
      getline(ss, column4, ',');

      diagnosis.push_back(column2);
      radius.push_back(stod(column3));
      texture.push_back(stod(column4));
   }


   ifstream file_test ("KNNAlgorithmDataset_test.csv");

   while (getline(file_test, line)) {
      stringstream ss(line);
      
      getline(ss, column1, ',');
      getline(ss, column2, ',');
      getline(ss, column3, ',');
      getline(ss, column4, ',');

      diagnosis_test.push_back(column2);
      radius_test.push_back(stod(column3));
      texture_test.push_back(stod(column4));
   }

   // Best one is K: 328 right answer: 162 wrong answer: 11
   for (K = 1; K <= diagnosis.size(); K++) {

      right_answer = 0;
      wrong_answer = 0;
      for (int j = 0; j < diagnosis_test.size(); j++) {

	 for (int i = 0; i < diagnosis.size(); i++) {
	    
	    euclidDist = sqrt(pow(radius[i] - radius_test[j], 2) + pow(texture[i] - texture_test[j], 2)); 

	    if (distances.size() < K) distances.push({euclidDist, diagnosis[i]});   

	    else {

	       if (distances.top().first >= euclidDist) {
		  distances.pop();
		  distances.push({euclidDist, diagnosis[i]});
	       }
	    }
	 }

	 M = 0;
	 B = 0;
	 while(!distances.empty()) { 

	    string temp = distances.top().second;
	    distances.pop();
	    if(temp == "M") M++;
	    else B++;
	 }

	 string temp = (M > B) ? "M" : "B";
	 if (diagnosis_test[j] == temp) right_answer++;
	 else wrong_answer++;
      }
      
      if (MAXright_answer < right_answer) {
	 MAXright_answer = right_answer;
	 bestK = K;
      }
   }

   cout << "Best K: " << bestK << " right answer: " << MAXright_answer << " wrong answer: " << diagnosis_test.size() - MAXright_answer << '\n';
}

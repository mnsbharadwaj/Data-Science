
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void evaluate_model(std::vector<int> &truth, std::vector<int> &predict)
{
    int error = 0;
    for(auto t = std::begin(truth), p = std::begin(predict) ; 
        t != std::end(truth) && p != std::end(predict); ++t, ++p) 
    {
         if( *t!= *p)
            error++;          
    }
    float accuracy =   1.0- (float)error/truth.size(); 
    cout<< accuracy*100;
    
}

void confusion_matrix(vector<int> &truth, vector<int>&predict, int classId)
{
    int TP = 0;
    int FN = 0;
    int TN = 0;
    int FP = 0;
     for(auto t = std::begin(truth), p = std::begin(predict) ; 
        t != std::end(truth) && p != std::end(predict); ++t, ++p) 
    {
         if(*t == classId)
         {
          //5 was classified as 5 (it's called True Positive)
            if(*t ==*p)
                TP++;
           //5 was incorrectly classified as not 5 (it's called False Negative)
            else if(*t != *p)
                FN++;
         }
         else
         {
           //not 5 was classified as not 5 (it's called True Negative)            
            if (*t!= classId && *p!= classId)
                TN++;
            //not 5 was incorrectly classified as 5 (it's called False Positive)
            else if(*t!= classId && *p == classId)
                FP++;
          }            
    }
    
    int conf_mat[2][2] ={TP, FN,TN, FP};
    float precision = (float)TP/(TP + FP);
    float recall = (float)TP/(TP+ FN);
    
    float f1_score = (float)(2 * precision* recall)/(precision + recall);
    
    cout<<"recall :"<< recall<<endl;
    cout<<"precision :" <<precision<<endl;
    cout<< TP <<endl 
        << FN <<endl
        <<TN <<endl
        <<FP <<endl;
    cout<<"f1_score:" <<f1_score;
    
}

int main()
{
    std:: vector<int> truth {5,2,3,4,5,6,7,8,9,0,1,1,1};
    std:: vector<int> predict {1,2,3,4,5,6,7,8,9,0,1,1,1};  
    
    evaluate_model(truth, predict);
    confusion_matrix(truth, predict, 5);
}



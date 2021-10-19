/*Name:Alejandro_Rodriquez, 2001889172, As6
*Description: File I/O assignment
*Input: file name
*Output: file information in a table
*/
//libraries included
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
//prototypes
void title();
void tableHead();
int main(){
  std::cout<<std::endl;
  //propram title
  title();
  std::cout<<'\n'<<std::endl;
  while(true){
   //declaration of variables
  std::string fileName;
  std::ifstream iFile;
  std::ofstream oFile;
  //prompt user for fileName
  std::cout<<"Please enter an input filename. \n***** ";
  std::cin>>fileName;
  //ifstream file open
  iFile.open(fileName.c_str());
  while(!iFile){
    std::cout<<"ERROR opening the input file.";
    //then re-prompt user for file input
    std::cout<<"\nPlease enter an input filename. \n***** ";
    std::cin>>fileName;  
    //to open the file
    iFile.open(fileName.c_str());
  }
  //readback filename givin
  std::cout<<"\n Input file given: "<<fileName<<std::endl;
  std::cout<<"\n";
  //string variable containing file
  std::string animal;
  tableHead(); //function containing title
  double food = 0;
  double cost = 0;
  double costSum = 0; //initialized variable for total cost
  double foodSum = 0; //initialized variable for total food
  //while file is not empty
  while(iFile >> animal >> food >>cost){
      std::setfill(" ");
      std::cout << std::setw(12) << std::left << " "+ animal
                << std::setw(17) << std::right<< std::setprecision(1)
                << std::fixed << food;
                std::cout << std::setw(14) << std::right << std::setprecision(2)
                << std::fixed <<"$"<< cost << "\n";
                //for loop that checks ouptputs for even numbers
                if(cost > 0){
                costSum +=cost;
                }else{
                  costSum = costSum;
                }
                if(food> 0){
                  foodSum +=food;
                }else{
                  foodSum = foodSum;
                }
              
  }
  /********************************************
   * Beginning of ending summary containing   *
   * table totals and averages                *
   * ******************************************/
    double monthlyFood = (foodSum * 30);
    long double monthlyCost = (costSum * 30);
    //title before end summary containing totals/averages
    std::cout<<"+"<<std::setw(48)<<std::setfill('-')<<""
             <<"+"<<std::endl;
    std::cout<<"\nFeeding Totals"<<std::endl;
    std::cout<<std::setw(50)<<std::setfill('+')<<""<<std::endl;
    //daily total amount
    std::cout<<"The total zoo food today was: ";
    std::cout<<std::setprecision(1)<<foodSum;
    std::cout<<" lbs."<<std::endl;
    //estimated total monthy amount
    std::cout<<"Estimated zoo food for a month is: ";
    std::cout<< std::setprecision(1)<<monthlyFood;
    std::cout<<" lbs."<<std::endl;
    //total cost of food needed for the day
    std::cout<< "\nThe total zoo food cost today was: ";
    std::cout<<std::setprecision(2)<<costSum <<std::endl;
    //the estimated cost of food for the month
    std::cout<<"Estimated zoo food cost for a month is: ";
    std::cout<<std::setprecision(2)<<monthlyCost;
    std::cout<<std::endl;
    //beginning of safty message prompting friendly gesture to user
    std::cout<<"\n"<<std::setw(50)<<std::setfill('+')<<""<<std::endl;
    std::cout<<"                  ";
    std::cout<<"Remember to always feed safely!"<<std::endl;
    std::cout<<std::setw(50)<<std::setfill('*')<<""<<std::endl;
    std::cout<<std::endl;
    //Ask user If they would like to enter another file
    while(true){
    char userInput;
    std::cout<<"Would you like to process another datafile? Y/y/N/n"<<std::endl;
    std::cout<<"***** ";
    std::cin>>userInput;
    //if statemtent checks choice to process another file
    if(userInput == 'n' || userInput == 'N'){
    return 0;
    }else if(userInput == 'y'|| userInput == 'Y'){
      std::cout<<"\n";
    break;
    }else
    std::cout<<std::endl;
    std::cout<<"ERROR: Invalid entry. Please try again."<<std::endl;
    continue;
    }
    continue;
  }
}
/*Functions****************************
 *First title function will print title 
 *using for loops*/
void title(){
  for(int i = 1; i <61;i++){
    std::cout<<"*";
  }
  std::cout<<"\n Welcome the UNLV CS Free Range Wild Animal Park!\n";
  for(int j = 1;j< 61;j++){
    std::cout<<"+";
  }
}
/*tabeHead function will print the title head of table 
holding values which are outputed from file*/
void tableHead(){
  std::cout<<"+";
  for(int i = 1;i< 49;i++){
    std::cout<<"-";
  }
  std::cout<<"+\n";
  std::setfill(' ');
  std::cout<<std::setw(8)<<std::setfill(' ')<<"Animal"<<std::setw(23)
  <<"Food \'lbs.'"<<std::setw(18)<<"Cost \'$'\n";
  std::cout<<"++";
  for(int j = 1;j<4;j++){
    std::cout<<"---------------";
    std::cout<<"+";
  }
  std::cout<<std::endl;
}

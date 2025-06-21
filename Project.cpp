

//THIS PROGRAM IS DESIGNED TO MANAGE THE FLIGHT RESERVATION TASKS FOR AIRLINE IN AN EFFICIENT MANNER 

#include<iostream>
#include<time.h>
#include<string>
#include<cstdlib>
using namespace std;

// Function prototype

int cost(int departure, int arrival, int cost_hour);
void flights_schedule();
int section(int *cost_hour, int type);
int cargo();
int luggage(int type);
int prof(string user_name, int password);
void signp(string name, string password2, string conf_pass);
void suggestion();
void feedback();





int main(){
    //declarations
    int ans,price12;
    int opt;
    string log,user_name,user2,password2,conf_pass;
    int password,cost_hour,departure,arrival,total_cost,type;
    int luggagecost=0;

    //opening lines
    cout <<endl<<"\t \t \t\tWelcome to KAMRA INTERNATIONAL AIRLINES.\n";
    cout <<"\t \t \t\tExplore effortless travel management and seamless experiences.\n"<<endl;

    // Function calling starts from here
   do
   {
    //ask the user to login

    cout <<" If you have an account then login else sign up.\n login/sign up"<<endl;
    getline(cin,log);

    if(log =="login" || log=="log in"){
        //login function called
        prof(user_name,password);
       
    }
    else if(log =="signup" || log=="sign up"){
       //signup function called here
        signp(user2,password2,conf_pass);
    }
   }while(log!="login"&&log!="signup"&&log!="sign up");
    cout<<endl;
    //operations for cargo flight
     cout <<"\n1. Book a Passenger's flight \n2. Transport goods as cargo "<<endl;
    cout <<"Please choose an option : ";
    do
    {
    cin >>ans;
    cout <<endl;

    if(ans!=1&&ans!=2)
    {
        cout <<"Please enter from the given options : ";
    }
    }while(ans!=1&&ans!=2);

    if(ans==1){
      string list[10]={ "1. Pakistan","2. India" , "3. USA","4. England", "5. Qatar","6. UAE","7. China","8. Australia","9. Canada","10. Germany"};
      for(int i=0;i<10;i++){
        cout<<list[i]<<endl;
      }
    
    //country of departure is taken as an input
    cout<<"ENTER THE COUNRY OF DEPARTURE :\t";
    do
    {
    cin>>departure;
    if(departure>10||departure<1)
    {
        cout <<"Enter from the given options :";
    }
    }while(departure>10||departure<1);
    cout<<list[departure-1]<<endl;

    
    do
    {
        //country of arrival is taken as an input
    cout<<"ENTER THE COUNTRY OF ARRIVAL :\t";
    do
    {
    cin>>arrival;
    if(arrival>10||arrival<1)
    {
        cout <<"Enter from the given options :";
    }
    }while(arrival>10||arrival<1);
    cout<<list[arrival-1]<<endl;
 
    if(departure==arrival){
        cout<<"The departure and arrival country should be different! "<<endl;
     }
    }while(departure==arrival);
    
    // function for flight timings called here
    flights_schedule();
    int type;

    //display of classes 
    cout <<"CLASSES :"<<endl<<endl;
    cout<<"1- ECONOMY CLASS\t($125/hour) "<<endl;
    cout<<"2- PREMIUM CLASS\t($160/hour) "<<endl;
    cout<<"3- BUSSINESS CLASS\t($180/hour) "<<endl;
    cout<<"4- FIRST CLASS \t\t($200/hour) "<<endl;
    cout<<"CHOOSE THE TYPE OF CLASS YOU WANT TO TRAVEL IN : ";

    //taking the chosen class as an input
    do
    {
    cin>>type;
    if(type<=0||type>4)
    {
        cout <<"Please select from the given : ";
    }
    }while(type<=0||type>4);
    cout <<endl;
	
    //function for adjusting cost_hour according to chosen class
    section(&cost_hour,type);
    
    //this function calculates the ticketprice without luggage price addition
   int total_cost= cost(departure,arrival,cost_hour);
cout <<endl;

cout <<"LUGGAGE SECTION : "<<endl<<endl;

//function for returning luggage cost is called here
     luggagecost=luggage(type);

     //total payable price calculation
     int finalprice=(luggagecost+total_cost);
     cout <<endl;
     cout<<"The Total Payable Price is : \t";
     cout<<"$ "<<finalprice<<endl;
     
    }
     else if(ans==2)
     {
       //final price for cargo flight is returned by this function 
        price12=cargo();
     }
    cout <<endl<<"FEEDBACK : "<<endl<<endl;

    //function for feedback input is called here
      feedback();

        return 0;  
     }


//THIS FUNCTION MANAGES ALL THE COST CALCULATIONS IN ACCORDANCE TO TRAVELLING HOURS.
int cost(int departure,int arrival,int cost_hour){
int total_cost;
    
    switch (departure)
    {
        //SWITCH STATEMENT FOR HANDLING DECISIVE OPERATIONS ACCORDING TO DEPARTURE INPUT
    case 1:
    

        switch (arrival)
        {
            //SWITCH STATEMENT FOR HANDLING DECISIVE OPERATIONS ACCORDING TO ARRIVAL INPUT
        case 2:
        cout<<"Your flight will take 6 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
        total_cost=cost_hour*6;
        cout<<total_cost<<endl;

            
            
            break;
        case 3:
        cout<<"Your flight will take 18 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*26<<endl;
         total_cost=cost_hour*18;
        cout<<total_cost<<endl;
            
            break;
        case 4:
        cout<<"Your flight will take 10 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*15<<endl;
         total_cost=cost_hour*10;
        cout<<total_cost<<endl;
            
            break;
        case 5:
        cout<<"Your flight will take 5 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*5;
        cout<<total_cost<<endl;
            
            break;
        case 6:
        cout<<"Your flight will take 3 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*3;
        cout<<total_cost<<endl;
            
            break;
        case 7:
        cout<<"Your flight will take 7 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*7;
        cout<<total_cost<<endl;
            
            break;
        case 8:
        cout<<"Your flight will take 13 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*13;
        cout<<total_cost<<endl;
            
            break;
        case 9:
        cout<<"Your flight will take 15 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*15;
        cout<<total_cost<<endl;

         case 10:
        cout<<"Your flight will take 9 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*9;
        cout<<total_cost<<endl;
            
            break;


        
        default:
        return total_cost;
        }
        break;

         case 2:
    

        switch (arrival)
        {
        case 1:
        cout<<"Your flight will take 6 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*6;
        cout<<total_cost<<endl;
            
            break;
        case 3:
        cout<<"Your flight will take 18 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*18;
        cout<<total_cost<<endl;
            
            break;
        case 4:
        cout<<"Your flight will take 11 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*11;
        cout<<total_cost<<endl;
            
            break;
        case 5:
        cout<<"Your flight will take 6 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*6;
        cout<<total_cost<<endl;
            
            break;
        case 6:
        cout<<"Your flight will take 5 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*5;
        cout<<total_cost<<endl;
            
            break;
        case 7:
        cout<<"Your flight will take 6 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*6;
        cout<<total_cost<<endl;
            
            break;
        case 8:
        cout<<"Your flight will take 14 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*14;
        cout<<total_cost<<endl;
            
            break;
        case 9:
        cout<<"Your flight will take 16 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*16;
        cout<<total_cost<<endl;
            
            break;
            
            case 10:
        cout<<"Your flight will take 9 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*9;
        cout<<total_cost<<endl;
            break;
            	default:
            		return total_cost;
            
            }

            

     break;

     case 3:
    

        switch (arrival)
        {
        case 1:
        cout<<"Your flight will take 18 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*18;
        cout<<total_cost<<endl;
            
            break;
        case 2:
        cout<<"Your flight will take 17 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*17;
        cout<<total_cost<<endl;
            
            break;
        case 4:
        cout<<"Your flight will take 8 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*8;
        cout<<total_cost<<endl;
            
            break;
        case 5:
        cout<<"Your flight will take 14 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*14;
        cout<<total_cost<<endl;
            
            break;
        case 6:
        cout<<"Your flight will take 15 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*15;
        cout<<total_cost<<endl;
            
            break;
        case 7:
        cout<<"Your flight will take 16 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*16;
        cout<<total_cost<<endl;
            
            break;
        case 8:
        cout<<"Your flight will take 20 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*20;
        cout<<total_cost<<endl;
            
            break;
        case 9:
        cout<<"Your flight will take 2 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*2;
        cout<<total_cost<<endl;
            
            break;
            
        case 10:
        cout<<"Your flight will take 9 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*9;
        cout<<total_cost<<endl;
            
            break;
				default:
            		return total_cost;
            }
     break;       

     case 4:
    
        switch (arrival)
        {
        case 1:
        cout<<"Your flight will take 9 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*9;
        cout<<total_cost<<endl;
            
            break;
        case 2:
        cout<<"Your flight will take 10 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*26<<endl;
         total_cost=cost_hour*10;
        cout<<total_cost<<endl;
            
            break;
        case 3:
        cout<<"Your flight will take 8 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*15<<endl;
         total_cost=cost_hour*8;
        cout<<total_cost<<endl;
            
            break;
        case 5:
        cout<<"Your flight will take 7 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*7;
        cout<<total_cost<<endl;
            
            break;
        case 6:
        cout<<"Your flight will take 8 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*8;
        cout<<total_cost<<endl;
            
            break;
        case 7:
        cout<<"Your flight will take 11 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*11;
        cout<<total_cost<<endl;
            
            break;
        case 8:
        cout<<"Your flight will take 21 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*21;
        cout<<total_cost<<endl;
            
            break;
        case 9:
        cout<<"Your flight will take 8 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*8;
        cout<<total_cost<<endl;
            
            break;
         case 10:
        cout<<"Your flight will take 2 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*2;
        cout<<total_cost<<endl;
            
            break;
            	default:
            		return total_cost;
            
			}
     break;       
     
      case 5:
    

        switch (arrival)
        {
        case 1:
        cout<<"Your flight will take 5 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*5;
        cout<<total_cost<<endl;
            
            break;
        case 2:
        cout<<"Your flight will take 6 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*6;
        cout<<total_cost<<endl;
            
            break;
        case 3:
        cout<<"Your flight will take 14 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*14;
        cout<<total_cost<<endl;
            
            break;
        case 4:
        cout<<"Your flight will take 7 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*7;
        cout<<total_cost<<endl;
            
            break;
        case 6:
        cout<<"Your flight will take 1 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*1;
        cout<<total_cost<<endl;
            
            break;
        case 7:
        cout<<"Your flight will take 8 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*8;
        cout<<total_cost<<endl;
            
            break;
        case 8:
        cout<<"Your flight will take 16 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*16;
        cout<<total_cost<<endl;
            
            break;
        case 9:
        cout<<"Your flight will take 13 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
        total_cost=cost_hour*13;
        cout<<total_cost<<endl;
            
            break;

             case 10:
        cout<<"Your flight will take 7 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*7;
        cout<<total_cost<<endl;
            
            break;

           	default:
            		return total_cost;
                  
      }
break;
      case 6:
    

        switch (arrival)
        {
        case 1:
        cout<<"Your flight will take 4 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*4;
        cout<<total_cost<<endl;
            
            break;
        case 2:
        cout<<"Your flight will take 5 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*26<<endl;
         total_cost=cost_hour*5;
        cout<<total_cost<<endl;
            
            break;
        case 3:
        cout<<"Your flight will take 14 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*15<<endl;
         total_cost=cost_hour*14;
        cout<<total_cost<<endl;
            
            break;
        case 4:
        cout<<"Your flight will take 8 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*8;
        cout<<total_cost<<endl;
            
            break;
        case 5:
        cout<<"Your flight will take 2 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*2;
        cout<<total_cost<<endl;
            
            break;
        case 7:
        cout<<"Your flight will take 8 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*8;
        cout<<total_cost<<endl;
            
            break;
        case 8:
        cout<<"Your flight will take 15 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*15;
        cout<<total_cost<<endl;
            
            break;
        case 9:
        cout<<"Your flight will take 12 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*12;
        cout<<total_cost<<endl;
            
            break;

         case 10:
        cout<<"Your flight will take 7 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*7;
        cout<<total_cost<<endl;
            
            break;   
            	default:
            		return total_cost;
                 
      }
      break;

       case 7:
    

        switch (arrival)
        {
        case 1:
        cout<<"Your flight will take 7 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*7;
        cout<<total_cost<<endl;
            
            break;
        case 2:
        cout<<"Your flight will take 6 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*26<<endl;
         total_cost=cost_hour*6;
        cout<<total_cost<<endl;
            
            break;
        case 3:
        cout<<"Your flight will take 15 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*15<<endl;
         total_cost=cost_hour*15;
        cout<<total_cost<<endl;
            
            break;
        case 4:
        cout<<"Your flight will take 11 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*11;
        cout<<total_cost<<endl;
            
            break;
        case 5:
        cout<<"Your flight will take 9 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*9;
        cout<<total_cost<<endl;
            
            break;
        case 6:
        cout<<"Your flight will take 8 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*8;
        cout<<total_cost<<endl;
            
            break;
        case 8:
        cout<<"Your flight will take 13 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*13;
        cout<<total_cost<<endl;
            
            break;
        case 9:
        cout<<"Your flight will take 13 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*13;
        cout<<total_cost<<endl;
            
            break;
        
         case 10:
        cout<<"Your flight will take 10 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*10;
        cout<<total_cost<<endl;
            
            break;

            	default:
            		return total_cost;
                 
      }
break;
      case 8:
    

        switch (arrival)
        {
        case 1:
        cout<<"Your flight will take 12 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*12;
        cout<<total_cost<<endl;
            
            break;
        case 2:
        cout<<"Your flight will take 13 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*26<<endl;
         total_cost=cost_hour*13;
        cout<<total_cost<<endl;
            
            break;
        case 3:
        cout<<"Your flight will take 19 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*15<<endl;
         total_cost=cost_hour*19;
        cout<<total_cost<<endl;
            
            break;
        case 4:
        cout<<"Your flight will take 21 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*21;
        cout<<total_cost<<endl;
            
            break;
        case 5:
        cout<<"Your flight will take 16 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*16;
        cout<<total_cost<<endl;
            
            break;
        case 6:
        cout<<"Your flight will take 15 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*15;
        cout<<total_cost<<endl;
            
            break;
        case 7:
        cout<<"Your flight will take 13 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*13;
        cout<<total_cost<<endl;
            
            break;
        case 9:
        cout<<"Your flight will take 17 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*17;
        cout<<total_cost<<endl;
            
            break;

         case 10:
        cout<<"Your flight will take 10 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*10;
        cout<<total_cost<<endl;
            
            break;

            	default:
            		return total_cost;
                 
      }
      break;
       case 9:
    

        switch (arrival)
        {
        case 1:
        cout<<"Your flight will take 15 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*15;
        cout<<total_cost<<endl;
            
            break;
        case 2:
        cout<<"Your flight will take 16 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*26<<endl;
         total_cost=cost_hour*16;
        cout<<total_cost<<endl;
            
            break;
        case 3:
        cout<<"Your flight will take 2 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*15<<endl;
         total_cost=cost_hour*2;
        cout<<total_cost<<endl;
            
            break;
        case 4:
        cout<<"Your flight will take 8 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*8;
        cout<<total_cost<<endl;
            
            break;
        case 5:
        cout<<"Your flight will take 13 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*13;
        cout<<total_cost<<endl;
            
            break;
        case 6:
        cout<<"Your flight will take 12 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*12;
        cout<<total_cost<<endl;
            
            break;
        case 7:
        cout<<"Your flight will take 13 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*13;
        cout<<total_cost<<endl;
            
            break;
        case 8:
        cout<<"Your flight will take 17 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*17;
        cout<<total_cost<<endl;
            
            break;

         case 10:
        cout<<"Your flight will take 10 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*10;
        cout<<total_cost<<endl;
            
            break;

            	default:
            		return total_cost;
                 
      }
      break;

       case 10:
    

        switch (arrival)
        {
        case 1:
        cout<<"Your flight will take 9 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*9;
        cout<<total_cost<<endl;
            
            break;
        case 2:
        cout<<"Your flight will take 9 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*26<<endl;
         total_cost=cost_hour*9;
        cout<<total_cost<<endl;
            
            break;
        case 3:
        cout<<"Your flight will take 9 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $"<<cost_hour*15<<endl;
         total_cost=cost_hour*9;
        cout<<total_cost<<endl;
            
            break;
        case 4:
        cout<<"Your flight will take 2 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*2;
        cout<<total_cost<<endl;
            
            break;
        case 5:
        cout<<"Your flight will take 7 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*7;
        cout<<total_cost<<endl;
            
            break;
        case 6:
        cout<<"Your flight will take 7 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*7;
        cout<<total_cost<<endl;
            
            break;
        case 7:
        cout<<"Your flight will take 10 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*10;
        cout<<total_cost<<endl;
            
            break;
        case 8:
        cout<<"Your flight will take 19 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*19;
        cout<<total_cost<<endl;
            
            break;

         case 9:
        cout<<"Your flight will take 10 hours to reach the destination : "<<endl;
        cout<<"THE TICKET PRICE IS : $";
         total_cost=cost_hour*10;
        cout<<total_cost<<endl;
            
            break;    
            	default:
            		return total_cost;
                  
  }
  	default:
            		return total_cost;
            
    }
    return total_cost;

    }
    
//THIS FUNCTION DISPLAYS THE AVAILABLE FLIGHT TIMINGS AND ALLOWS THE USER TO BOOK A FLIGHT ON A CORRESPONDING TIME
void flights_schedule(){
int time;
	string days[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cout<<endl;
    cout<<"Our flights operate twice daily from your selected departure country to your chosen destination"<<endl;
    string timings[] = {
        "06:00","06:30","07:00","07:30","08:00","08:30","09:00","09:30","10:00","10:30",
        "11:00","-11:30","12:00","12:30","13:00","13:30","14:00","14:30","15:00","15:30",
        "16:00","16:30","17:00","17:30","18:00","18:30"
    };
    int n=1;
    for(int i=0;i<7; i++) {
    	cout << days[i] << ":\n";
    	for(int j=0;j<2;j++){
            //display of the list of available flights with timings
        int dep_timings=rand()%24; 
        cout<<"\t"<<n<<"- Departure Time: "<<"- "<<timings[dep_timings]<<endl;
        cout<<endl;
        n++;
        }
	}	
    //taking chosen time as an output
    do {cout<<"ENTER THE TIME YOU WANT TO CHOOSE : ";
    cin>>time;
    cout <<endl;
    if(time>14||time<=0){
        cout<<"PLEASE SELECT FROM THE GIVEN TIME OPTIONS."<<endl;
    }
    }while(time>14||time<=0);
    
	
}

//THIS FUNCTION TAKES THE CHOOSEN CLASS AS A ARGUMENT AND ASSIGNES "cost_hour" the required value
int section(int * cost_hour,int type){
 
    if(type==1){
        *cost_hour=125 ;
           return *cost_hour;
        }
        if(type==2){
        *cost_hour=160 ;
           return *cost_hour;
        }
    
    if(type==3){
        *cost_hour=180 ;
           return *cost_hour;
        }
    
    if(type==4){
        *cost_hour=200 ;
           return *cost_hour;                       
        }
        
        return 0;
  
}
//this function allows the user to opt for only shipping certain items and describes the requirment

int cargo()
{
    int tell;

    int opt,country,country2;
    double cost;
    
    cout <<endl;
    
        do
        {
    cout <<"\n1. Pakistan\n2. India\n3. USA\n4. England\n5. Qatar\n6. UAE\n7. China\n8. Australia\n9. Canada\n10. Germany"<<endl;
    cout <<"Which country you want to deliver :  ";
    do
    {
    cin >>country;
    cout <<endl;
    if(country>10||country<=0)
    {
        cout <<"Please select from the given options.";
    }
    }while(country<=0||country>10);
    
        }while(country>10);

    do
    {
    
        
        cout <<"\n1. Pakistan\n2. India\n3. USA\n4. England\n5. Qatar\n6. UAE\n7. China\n8. Australia\n9. Canada\n10. Germany"<<endl;
        cout <<"From which country you are delievering : ";
        do
        {
        cin >>country2;
        cout <<endl;
        if(country2<=0||country2>10)
        {
            cout <<"Select from the given options : ";
        }
        }while(country2<=0||country>10);

    if(country2==country)
    {
        cout <<"You can't deliever to the country where you are already present."<<endl;
    }

    }
    while(country==country2);
    do
    {
    cout <<endl;
    cout <<"Please select from the permissible items :"<<endl;
    cout <<"Permissible items for cargo shipment include:\n";
    cout <<"1. Parcels($5 per kg)\n";
    cout <<"2. Electronics and fragile items($10 per kg)\n";
    cout <<"3. Clothing and personal effects($3 per kg)\n";
    cout <<"4. Household goods and appliances($8 per kg)\n";
    cout <<"5. Non-perishable food items($6 per kg)"<<endl;
    cout <<"Please select an option : ";
    do
    {
    cin >>opt;

    if(opt<=0||opt>5)
    {
        cout <<"Select from the given options : ";
    }
    }while(opt<=0||opt>5);
    
    }
    while(opt>=6);

    int weight;
    cout <<endl;
    cout <<"Enter the weight in kilograms : ";
    do
    {
    cin >>weight;
    cout <<endl;
    if(weight<0||weight>100)
    {
        cout <<"Enter within o and 100 : ";
    }
    }while(weight<0||weight>100);
    cout <<"\nWhat type of delivery service would you prefer : \n";

    do
    {
    cout <<"1. Standard Delivery\n";
    cout <<"2. Next Day Delivery(1.5 times of amount)\n";
    cout <<"3. Same Day Delivery(2 times of amount)\n";
    cout <<"Please select any option : ";
    
    cin >>tell;
    if(tell>3||tell<=0)
    {
        cout <<"\nPlease select from the allowed options.\n";
    }
    }
    while(tell>3||tell<=0);


    cout <<endl;

    switch (opt)
    {
        case 1:
        if(tell==1)
        {
        cost=weight*5.0;
        }
        else if(tell==2)
        {
            cost=((weight*5.0)*1.5);
        }
        else
        {
            cost=((weight*5.0)*2.0);
        }
        cout <<"The cost for delievery is : $";
        cout <<cost;
        cout <<endl;
        break;
        case 2:
        if(tell==1)
        {
        cost=weight*10.0;
        }
        else if(tell==2)
        {
            cost=((weight*10.0)*1.5);
        }
        else
        {
            cost=((weight*10.0)*2.0);
        }
        cout <<"The cost for delievery is : $";
        cout <<cost;
        break;

        case 3:
        if(tell==1)
        {
        cost=weight*3.0;
        }
        else if(tell==2)
        {
            cost=((weight*3.0)*1.5);
        }
        else
        {
            cost=((weight*3.0)*2.0);
        }
        cout <<"The cost for delievery is : $";
        cout <<cost;
        break;

        case 4:
        if(tell==1)
        {
        cost=weight*8.0;
        }
        else if(tell==2)
        {
            cost=((weight*8.0)*1.5);
        }
        else
        {
            cost=((weight*8.0)*2.0);
        }
        cout <<"The cost for delievery is : $";
        cout <<cost;
        break;

        case 5:
        if(tell==1)
        {
        cost=weight*6.0;
        }
        else if(tell==2)
        {
            cost=((weight*6.0)*1.5);
        }
        else
        {
            cost=((weight*6.0)*2.0);
        }
        cout <<"The cost for delievery is : $";
        cout <<cost;
        break;
    
        default:
        break;
    }
    
   
    return cost;
}

//manages the user luggage items and describe the allowed limit of luggage that can be carried 
int luggage(int type)
{
    int carry_on,carry_on_limit,weight,weight_limit;
    int luggagecost=0;
    

    
    switch(type)
    {
        case 1:
        cout <<"The allowed weight for the luggage is 20 Kg."<<endl<<"If the luggage weighs more than this limit you'll have to pay $-35 per Kg"<<endl;
        break;

        case 2:
        cout <<"The allowed weight for the luggage 25 Kg"<<endl<<"If the luggage weighs more than this limit you'll have to pay $-50 per Kg"<<endl;
        break;

        case 3:
        cout <<"The allowed weight for the luggage is 30 Kg"<<endl<<"If the luggage weighs more than this limit you'll have to pay $-70 per Kg"<<endl;
        break;

        case 4:
        cout <<"The allowed weight for the luggage is 35 Kg"<<endl<<"If the luggage weighs more than this limit you'll have to pay $-90 per Kg"<<endl;
        break;

        default:
        break;

    }
    
    cout <<"Enter the weight of the luggage in kilograms : ";
    do
    {
    cin >>weight;
    cout <<endl;
    if(weight<0||weight>100)
    {
        cout <<"Enter within 0 and 100 : ";
    }
    }while(weight<0||weight>100);
    do
    {
    switch(type)
    {
        case 1:
        cout <<"The allowed weight as carry-on is 10 Kg"<<endl;
        carry_on_limit=10;
        break;

        case 2:
        cout <<"The allowed weight as carry-on is 12 Kg"<<endl;
        carry_on_limit=12;
        break;

        case 3:
        cout <<"The allowed weight as carry-on is 15 Kg"<<endl;
        carry_on_limit=15;
        break;

        case 4:
        cout <<"The allowed weight as carry-on is 18 Kg"<<endl;
        carry_on_limit=18;
        break;

        default:
        break;

    }

    cout <<"Please enter the weight of you carry-on luggage : ";
    do
    {
    cin >>carry_on;
    if(carry_on<0||carry_on>45)
    {
        cout <<"Please enter within 0 and 45 : ";
    }
    }while(carry_on<0||carry_on>45);
    if((type==1&&carry_on<=10)||(type==2&&carry_on<=12)||(type==3&&carry_on<=15)||(type==4&&carry_on<=18))
    {
    switch(type)
    {
        case 1:
        weight_limit=20;
        if(weight>weight_limit)
        {
            cout <<"\nYour luggage weighs more than the limit.\nOver weight fees will be charged per kilogram."<<endl;
            luggagecost=(weight-weight_limit)*35;
            cout <<"The cost_hour to pay for luggage is : $"<<luggagecost<<endl;
           return luggagecost;
        }
        else
        {
            cout <<"\nYour luggage weighs with in the limits.\nYou dont need to pay any extra amount.\n"<<endl;
        }
        break;

        case 2:
        weight_limit=25;
        if(weight>weight_limit)
        {
            cout <<"\nYour luggage weighs more than the limit.\nOver weight fees will be charged per kilogram."<<endl;
            luggagecost=(weight-weight_limit)*50;
            cout <<"The cost_hour to pay for luggage is : $"<<luggagecost<<endl;
            return luggagecost;
        }
        else
        {
            cout <<"Your luggage weighs with in the limits.\nYou dont need to pay any extra amount.\n"<<endl;
        }
        break;

        case 3:
        weight_limit=30;
        if(weight>weight_limit)
        {
            cout <<"\nYour luggage weighs more than the limit.\nOver weight fees will be charged per kilogram."<<endl;
            luggagecost=(weight-weight_limit)*70;
            cout <<"The cost_hour to pay for luggage is : $"<<luggagecost<<endl;
               return luggagecost;
        }
        else
        {
            cout <<"Your luggage weighs with in the limits.\nYou dont need to pay any extra amount.\n"<<endl;
            
        }
        break;

        case 4:
        weight_limit=35;
        if(weight>weight_limit)
        {
            cout <<"\nYour luggage weighs more than the limit.\nOver weight fees will be charged per kilogram."<<endl;
            luggagecost=(weight-weight_limit)*90;
            cout <<"The cost_hour to pay for luggage is : $"<<luggagecost<<endl;
            return luggagecost;

        }
        else
        {
            cout <<"Your luggage weighs with in the limits.\nYou don't need to pay any extra amount.\n"<<endl;
        }
        break;

        default:
        	
        break;

    }
    }
    else 
    {
        cout <<"\nYou are not allowed to carry that much laggage along with you (carry on)"<<endl;
        cout <<"Please carry weight with in the limits.\n"<<endl;
        
    }
    }
    while(!(carry_on <=carry_on_limit));

    return luggagecost;
}
void signp(string name,string password2,string conf_pass);
//this function allows the user to login in his already created profile
int prof(string user_name, int password) 
    {int pass1=1234,pass2=5678,pass3=9012,pass4=3456;
        
        cout <<endl<<"Enter username"<<endl;
         int id;
        srand(time(0));
        id =10000000+(rand()%9999999);
        cout <<"\t";cin>>user_name;
        
        if(user_name=="hamza" || user_name=="abdulrehman" || user_name=="mudassar" || user_name=="anas"){
            if(user_name=="hamza"){
            do{

        		cout <<"Enter password"<<endl;
        		cout <<"\t";cin >>password;
        
        
                if(password==pass1){
                    cout <<endl<<"Welcome back, Hamza! Ready for your next adventure?\n";
    
                    cout <<"Your travel ID is :"<<id<<endl;
        
            }
            // already logged in users
            else{
                cout <<"Enter correct password.";
            }
            }while(password!=pass1);
            }
            if(user_name=="abdulrehman"){
                do{
                	
        		cout <<"Enter password"<<endl;
        		cout <<"\t";cin >>password;
       
        
                if(password==pass2){
                    cout <<endl<<"Welcome back, Abdul Rehman! Ready for your next adventure?\n";
                    cout <<"Your travel ID is :"<<id<<endl;
            }
            else{
                cout <<"Enter correct password.";
            }
            }while(password!=pass2);

            }
            if(user_name=="mudassar"){
                do{
                	
        cout <<"Enter password"<<endl;
        cout <<"\t";cin >>password;
        
        
                if(password==pass3){
                    cout <<endl<<"Welcome back, Mudassar! Ready for your next adventure?\n";
                    cout <<"Your travel ID is :"<<id<<endl;

            }
            else{
                cout <<"Enter correct password.";
            }
            }while(password!=pass3);

            }
            if(user_name=="anas"){
                do{
                	
        cout <<"Enter password"<<endl;
        cout <<"\t";cin >>password;
        
        
                if(password==pass4){
                    cout <<endl<<"Welcome back, Anas! Ready for your next adventure?\n";
                    cout <<"Your travel ID is :"<<id<<endl;

            }
            else{
                cout <<"Enter correct password.";
            }
            }while(password!=pass4);

            }
        }
        
        else{
        	cout <<"Incorrect username.\n"<<"Please enter correct username.\n";
            return prof(user_name,password);
		}

        return 0;
    }

//allows new users to create their profile

void signp(string name,string password2,string conf_pass)
 {
    
    cout<<"Please enter username to signup :"<<endl;
    cin.ignore();
    getline(cin,name);
    

    cout<<"Enter password : ";
    cin>>password2;

     do{
    cout<<"Confirm Password : ";
    cin>>conf_pass;

    if (password2==conf_pass)
    {
        cout<<"You have sucessfully signed up to your account "<<endl;
    }
    else{
        cout<<"Your entered a wrong password.Please enter again "<<endl;
    }
    }while(password2!=conf_pass);
    cout <<endl;

    //generation of travel id
    srand(time(0));
    int  id =10000000+(rand()%9999999);
    cout <<"Your travel ID is : "<<id;

}

//recieves user defined feedback of the program

void suggestion(){
	string suggest;
    	cout <<"Drop your feedback : "<<endl;
        //getline function to input the feedback of user 
        cin.ignore();
	getline(cin,suggest);


	cout <<endl<<"Thanks for your response."<<endl;
}

//stores user defined remarks

void feedback(){
	int feed;
	string rating[]={"Excellent","Good","Satisfactory","Okay"};
	cout<<"Please share your experience below."<<endl;
	for(int i=0;i<4;i++){
		cout<<i+1<<") "<<rating[i]<<endl;
	}
	cout<<"    ";
    cout <<"Please enter : ";
	cin>>feed;
	while (feed < 1 || feed > 4) {
        cout << "Invalid input!"<<endl;
		cout<<" Please enter a number between 1 and 4: ";
        cin >> feed;
    }
    //selection of reviews
	switch(feed){
		case 1:
		cout<<"EXCELLENT"<<endl;
		break;
		case 2:
		cout<<"Good"<<endl;
		break;
		case 3:
		cout<<"Satisfactory"<<endl;
		break;
		case 4:
		cout<<"Okay"<<endl;
		break;
	}
	cout<<endl;
	
    suggestion();
	
}

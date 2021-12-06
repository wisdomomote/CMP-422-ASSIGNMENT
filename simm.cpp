#include <iostream>
#include <cmath>
using namespace std;

const int BUSY=1;
const int IDLE=0;

int  
    choice,
    WL,                           
    SS;                    

double
    MX,
    IT,
    ST,
    TM,
    AT,
    DT,
    TypeOfEvent,
    NextServiceTime,
    ProgressAT’
    ProgressDT;


void  initialize();
void  Timing();
void  Arrival();
void  Departure();
float expon(float mean);

int main() 
{   
    initialize();  
    do
    {
        cout<<"Enter your Policy: ";
        cin>>choice;
    }
    while(choice>2||choice<1);

    cout<<"'End of Simulation’ Time: "<<MX<<endll;

    while(true)
    {      Timing();   //To Determine The Next Event

            if(TM>MX)
                 break;

            switch (int(TypeOfEvent))
            {  case 1:
                    Arrival();
                    break;

            case 2:
                    Departure();
                    break;
            }
    }
    return 0;    
}

void initialize() 
{   IT=1.0;
        ST=0.5;
        TM = 0.0;
        SS = IDLE;
        WL= 0;
        AT= TM + expon(IT);              //Arriving
        NextServiceTime = expon(ST);
        DT= 1.0e+10;                        // Guaranteeing that the first event is arriving
        ProgressAT=0.0;
        ProgressDT = 0.0;
}

void Timing() 
{   
    TypeOfEvent = 0;

    if(AT < DT)
    {  
        TypeOfEvent = 1;
        TM=AT;
    }

    else
    {  
        TypeOfEvent = 2;
        TM= DT;
    }

    if (TypeOfEvent == 0)
    {
        cout<<"System Idle "<<TM;
        exit(1);
    }      
}

void Arrival() 
{
    if (SS == BUSY)
    {
        ++WL;
        ServiceTime[WL] = NextServiceTime;
    }

    else
    {
        SS = IDLE;
        DT = TM + NextServiceTime;
    }

    AT = TM + expon(IT);
    NextServiceTime = expon(ST);
}

void Departure()
{
    if (WL == 0)
    {
            SS= IDLE;
            DT = 9999;
    }
    else
    {       
        if(choice==2)
        {
            DT= TM + NextServiceTime;
        }
        --WL;  
    }    
}

